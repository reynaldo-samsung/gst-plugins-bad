/*
 * GStreamer plugin for the decoding and overlay of XSUB subtitles.
 * Copyright (C) 2010 Collabora Multimedia
 * Copyright (C) 2011 Collabora Ltd.
 *
 * @Author: Reynaldo H. Verdejo Pinochet <reynaldo@collabora.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, the contents of this file may be used under the
 * GNU Lesser General Public License Version 2.1 (the "LGPL"), in
 * which case the following provisions apply instead of the ones
 * mentioned above:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <gst/gst.h>
#include <gst/base/gstbitreader.h>
#include <gst/base/gstbytereader.h>
#include <gst/base/gstbytewriter.h>
#include <string.h>
#include <stdlib.h>

#define XSUB_ASCII2_TOI(x,y) (((x) - '0') * 10 + ((y) - '0'))
#define XSUB_ASCII3_TOI(x,y,z) (((x) - '0') * 100 + ((y) - '0') * 10 + ((z) - '0'))

#include "xsub.h"

static void xsub_parse_timing_string (GstBuffer * dest, const guint8 * t_frac);

/* Wipe background color from a spu frame row replacing it with RGB24 frame
 * color data.
 */
gboolean
xsub_wipe_background (guint8 * dest, const guint8 * spu, const guint8 * src,
    const guint32 * bg_color, guint16 stride)
{
  int i;

  for (i = 0; i < stride; i += XSUB_RGB_BPP)
    if ((GST_READ_UINT24_BE (spu + i)) == *bg_color >> 8)
      memcpy (dest + i, src + i, XSUB_RGB_BPP);
    else
      memcpy (dest + i, spu + i, XSUB_RGB_BPP);

  return TRUE;
}

/* Parses timing data from the first 27 bytes of an XSUB header
 * Data comes as a non NULL terminated ASCII string with the following format:
 * [HH:MM:SS.mmm-HH:MM:SS.mmm]
 */
static void
xsub_parse_timing_string (GstBuffer * dest, const guint8 * t_frac)
{
  GST_BUFFER_TIMESTAMP (dest) = (GstClockTime)
      ((XSUB_ASCII2_TOI (t_frac[1], t_frac[2]) * 3600
          + XSUB_ASCII2_TOI (t_frac[4], t_frac[5]) * 60
          + XSUB_ASCII2_TOI (t_frac[7], t_frac[8])) * GST_USECOND
      + XSUB_ASCII3_TOI (t_frac[10], t_frac[11], t_frac[12])) * GST_MSECOND;
  GST_BUFFER_DURATION (dest) = (GstClockTime)
      ((XSUB_ASCII2_TOI (t_frac[14], t_frac[15]) * 3600
          + XSUB_ASCII2_TOI (t_frac[17], t_frac[18]) * 60
          + XSUB_ASCII2_TOI (t_frac[20], t_frac[21])) * GST_USECOND
      + XSUB_ASCII3_TOI (t_frac[23], t_frac[24], t_frac[25])) * GST_MSECOND
      - GST_BUFFER_TIMESTAMP (dest);
}

/* Parses the XSUB header from a XSUB packet */
gboolean
xsub_parse_header (GstPad * pad, GstXSubData * dest, const GstBuffer * src)
{
  GstByteReader *header;
  gboolean ret = TRUE;
  gboolean has_time = FALSE;
  guint8 *src_data;
  const guint8 *t_frac;

  /* Quick sanity check */
  if (src->size < XSUB_RLE_IMG_START) {
    GST_ERROR_OBJECT (pad, "src->size < XSUB_RLE_IMG_START");
    return FALSE;
  }

  src_data = GST_BUFFER_DATA (src);

  /* FIXME: fix demuxer to correctly parse xsub timing data and do:
   * dest->buf->timestamp = src->timestamp;
   * dest->buf->duration = src->duration;
   * instead of all this time-parsing mambojambo
   */

  header = gst_byte_reader_new (src_data, XSUB_RLE_IMG_START);

  /* Parse timing data if present */
  if (src_data[0] == '[' && src_data[26] == ']') {

    has_time = TRUE;

    if (!gst_byte_reader_get_data (header, XSUB_SIZE_DATA_START, &t_frac)) {
      GST_DEBUG_OBJECT (pad, "Error geting timing data");
      ret = FALSE;
    } else {
      xsub_parse_timing_string (dest->buf, t_frac);
      GST_DEBUG_OBJECT (pad, "SPU TIMING: ts:%" GST_TIME_FORMAT " duration:%"
          GST_TIME_FORMAT, GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (dest->buf)),
          GST_TIME_ARGS (GST_BUFFER_DURATION (dest->buf)));
    }
  }

  if (!gst_byte_reader_get_int16_le (header, &dest->width) ||
      !gst_byte_reader_get_int16_le (header, &dest->height) ||
      !gst_byte_reader_get_int16_le (header, &dest->coords[0]) ||
      !gst_byte_reader_get_int16_le (header, &dest->coords[1]) ||
      !gst_byte_reader_get_int16_le (header, &dest->coords[2]) ||
      !gst_byte_reader_get_int16_le (header, &dest->coords[3]) ||
      !gst_byte_reader_get_int16_le (header, &dest->rle_length) ||
      !gst_byte_reader_get_uint24_be (header, &dest->color_tab[0]) ||
      !gst_byte_reader_get_uint24_be (header, &dest->color_tab[1]) ||
      !gst_byte_reader_get_uint24_be (header, &dest->color_tab[2]) ||
      !gst_byte_reader_get_uint24_be (header, &dest->color_tab[3])) {
    GST_ERROR_OBJECT (pad, "Error byte-reading header data");
    ret = FALSE;
  }

  dest->header_size = gst_byte_reader_get_pos (header);

  if (!has_time)
    dest->header_size -= XSUB_SIZE_DATA_START;

  gst_byte_reader_free (header);

  return ret;
}

/* Decodes RLE'd SPU data from a XSUB SPU frame whos header has
 * already been parsed and puts RGB24 data for it in dest->buf
 */
gboolean
xsub_parse_spu (GstPad * pad, GstXSubData * dest, const GstBuffer * src)
{
  gint16 row, col;
  guint16 needle;
  guint16 run_length;
  gint32 spu_size;
  guint8 *src_data, *dest_data;
  GstBitReader *haystack;
  GstByteWriter *spu_frame;

  int color_index, i, j;

  src_data = GST_BUFFER_DATA (src);

  /* Note that a full RLEd row of 1 color takes a ~byte */
  if (!dest->width || !dest->height || dest->rle_length < dest->height) {
    GST_ERROR_OBJECT (pad, "Wrong size or rle_length missmatch rle_length:%d",
        dest->rle_length);
    return FALSE;
  }

  /* FIXME, this is drafted over RGB 24bpp output
   * Should probably get bpp from upstream and then
   * build this image so its format preserves that depth
   */
  spu_size = dest->width * dest->height * XSUB_RGB_BPP;
  GST_BUFFER_SIZE (dest->buf) = spu_size;
  GST_BUFFER_MALLOCDATA (dest->buf) = g_malloc (spu_size);
  dest_data = GST_BUFFER_DATA (dest->buf) = GST_BUFFER_MALLOCDATA (dest->buf);

  /* SPU decoding */

  /* By the time we get here we know buffer has at least header_size bytes */
  haystack = gst_bit_reader_new (src_data + dest->header_size,
      dest->rle_length);
  spu_frame = gst_byte_writer_new_with_data (dest_data, dest->buf->size, TRUE);

  needle = 0;
  for (row = 0; row < dest->height; row++) {

    col = 0;
    while (col < dest->width) {
      run_length = 0;
      for (i = 1; i < 5; i++) {
        gst_bit_reader_get_bits_uint16
            (haystack, &needle, i * XSUB_RLE_CHUNK_NBITS);

        if (!(needle >> 2 * i)) {
          if (i != 4)
            gst_bit_reader_set_pos (haystack,
                gst_bit_reader_get_pos (haystack) - XSUB_RLE_CHUNK_NBITS * i);
          continue;
        } else {
          break;
        }
      }

      run_length = (i == 5) ? dest->width - col : needle >> 2;
      color_index = needle & 0x3;

      /* Save background color
       * We asume first pixel in will have the bg_color set */
      if (!col && !row)
        dest->bg_color = &(dest->color_tab)[color_index];

      for (j = 0; j < run_length; j++)
        gst_byte_writer_put_uint24_be (spu_frame,
            (dest->color_tab)[color_index]);

      col += run_length;
    }

    gst_bit_reader_skip_to_byte (haystack);
  }

  gst_bit_reader_free (haystack);
  gst_byte_writer_free (spu_frame);

  return TRUE;
}

// vim: set expandtab tabstop=2 shiftwidth=2 autoindent smartindent:

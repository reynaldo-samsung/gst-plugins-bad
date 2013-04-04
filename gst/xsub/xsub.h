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

#ifndef __XSUB_H__
#define __XSUB_H__

#include <gst/gst.h>

#define XSUB_SIZE_DATA_START 27
#define XSUB_RLE_IMG_START 53
#define XSUB_RLE_CHUNK_NBITS 4
#define XSUB_RGB_BPP 3

GST_DEBUG_CATEGORY_EXTERN (xsub_debug);
#define GST_CAT_DEFAULT xsub_debug

G_BEGIN_DECLS typedef struct GstXSubData GstXSubData;

struct GstXSubData
{
  GstBuffer *buf;
  gint16 coords[4];             //< top(x,y), bottom(x,y)
  gint16 width;
  gint16 height;
  gint16 rle_length;
  guint32 color_tab[4];
  guint32 *bg_color;
  guint8 *bgless_row;
  guint header_size;
};

gboolean
xsub_wipe_background (guint8 * dest, const guint8 * spu, const guint8 * src,
    const guint32 * bg_color, guint16 stride);
gboolean xsub_parse_header (GstPad * pad, GstXSubData * dest, GstBuffer * src);
gboolean xsub_parse_spu (GstPad * pad, GstXSubData * dest, GstBuffer * src);

G_END_DECLS
#endif /* __XSUB_H__ */
// vim: set expandtab tabstop=2 shiftwidth=2 autoindent smartindent:

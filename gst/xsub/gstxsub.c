/*
 * GStreamer plugin for the decoding and overlay of XSUB subtitles.
 * Copyright (C) 2010 Collabora Multimedia
 * Copyright (C) 2011-2013 Collabora Ltd.
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

/**
 * SECTION:element-xsub
 *
 * GStreamer plugin for the decoding and bliting of XSUB encoded
 * SPU frames.
 *
 * <refsect2>
 * <title>Example launch line</title>
 * |[
 * gst-launch-1.0 -v xsub name=overlay show-background=FALSE ! videoconvert
 * ! videorate ! eglglessink filesrc location=/path/to/file.divx
 * ! avidemux name=d d.video_0 ! queue ! mpeg4videoparse ! avdec_mpeg4
 * ! videoconvert !  overlay.video_sink d.video_1 ! queue
 * ! overlay.xsub_sink
 * ]|
 * </refsect2>
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gst/gst.h>
#include <gst/video/video.h>
#include <glib.h>

#include "xsub.h"
#include "gstxsub.h"

GST_DEBUG_CATEGORY (xsub_debug);
#define DEFAULT_SHOWBG FALSE

enum
{
  PROP_0,
  PROP_SHOWBG
};

/* The capabilities of the inputs and outputs.
 */
static GstStaticPadTemplate sink_factory_xsub =
GST_STATIC_PAD_TEMPLATE ("xsub_sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("subpicture/x-xsub")
    );

static GstStaticPadTemplate sink_factory_pict =
GST_STATIC_PAD_TEMPLATE ("video_sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (GST_VIDEO_CAPS_MAKE ("RGB"))
    );

static GstStaticPadTemplate src_factory_mixed = GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (GST_VIDEO_CAPS_MAKE ("RGB"))
    );

G_DEFINE_TYPE (GstXSub, gst_xsub, GST_TYPE_ELEMENT);

static void gst_xsub_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec);
static void gst_xsub_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec);

static gboolean gst_xsub_set_caps (GstPad * pad, GstCaps * caps);
static GstFlowReturn gst_xsub_frame_chain (GstPad * pad, GstObject * parent,
    GstBuffer * buf);
static GstFlowReturn gst_xsub_spu_chain (GstPad * pad, GstObject * parent,
    GstBuffer * buf);
static gboolean xsub_sink_event_spu (GstPad * pad, GstObject * parent,
    GstEvent * event);
static gboolean xsub_sink_event_pic (GstPad * pad, GstObject * parent,
    GstEvent * event);

/* GObject vmethod implementations */

/* Initialize the xsub's class */
static void
gst_xsub_class_init (GstXSubClass * klass)
{
  GObjectClass *gobject_class = (GObjectClass *) klass;
  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);

  gst_element_class_set_metadata (element_class,
      "XSub",
      "Mixer/Video/Overlay/Subtitle",
      "Decodes and Overlays XSUB Subtitles",
      "Reynaldo H. Verdejo Pinochet <reynaldo@collabora.com>");

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&src_factory_mixed));
  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&sink_factory_xsub));
  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&sink_factory_pict));

  gobject_class->set_property = gst_xsub_set_property;
  gobject_class->get_property = gst_xsub_get_property;

  g_object_class_install_property (gobject_class, PROP_SHOWBG,
      g_param_spec_boolean ("show-background", "Showbg",
          "Show SPU Background ?", DEFAULT_SHOWBG, G_PARAM_READWRITE));
}

/* Initialize the new element
 * instantiate pads and add them to element
 * set pad calback functions
 * initialize instance structure
 */
static void
gst_xsub_init (GstXSub * filter)
{
  g_mutex_init (&filter->lock);
  filter->spu_queue = g_queue_new ();
  filter->show_bg = DEFAULT_SHOWBG;

  /* Picture in */
  filter->video_sink = gst_pad_new_from_static_template (&sink_factory_pict,
      "video_sink");
  GST_PAD_SET_PROXY_CAPS (filter->video_sink);
  gst_pad_set_chain_function (filter->video_sink,
      GST_DEBUG_FUNCPTR (gst_xsub_frame_chain));
  gst_pad_set_event_function (filter->video_sink,
      GST_DEBUG_FUNCPTR (xsub_sink_event_pic));

  /* Subpicture in */
  filter->xsub_sink = gst_pad_new_from_static_template (&sink_factory_xsub,
      "xsub_sink");
  gst_pad_set_chain_function (filter->xsub_sink,
      GST_DEBUG_FUNCPTR (gst_xsub_spu_chain));
  gst_pad_set_event_function (filter->xsub_sink,
      GST_DEBUG_FUNCPTR (xsub_sink_event_spu));

  /* Mixed out */
  filter->src = gst_pad_new_from_static_template (&src_factory_mixed, "src");

  gst_element_add_pad (GST_ELEMENT (filter), filter->xsub_sink);
  gst_element_add_pad (GST_ELEMENT (filter), filter->video_sink);
  gst_element_add_pad (GST_ELEMENT (filter), filter->src);
}

/* Drop all events on spu sink pad for now */
static gboolean
xsub_sink_event_spu (GstPad * pad, GstObject * parent, GstEvent * event)
{
  return gst_pad_event_default (pad, parent, event);
}

/* Handle events on picture sink pad */
static gboolean
xsub_sink_event_pic (GstPad * pad, GstObject * parent, GstEvent * event)
{
  GstCaps *caps;

  switch (GST_EVENT_TYPE (event)) {
    case GST_EVENT_CAPS:
      gst_event_parse_caps (event, &caps);
      if (!gst_xsub_set_caps (pad, caps))
        return FALSE;
      break;
    default:
      break;
  }

  return gst_pad_event_default (pad, parent, event);
}

static void
gst_xsub_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec)
{
  GstXSub *filter = GST_XSUB (object);

  switch (prop_id) {
    case PROP_SHOWBG:
      g_atomic_int_set (&filter->show_bg, g_value_get_boolean (value));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
gst_xsub_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec)
{
  GstXSub *filter = GST_XSUB (object);

  switch (prop_id) {
    case PROP_SHOWBG:
      g_value_set_boolean (value, g_atomic_int_get (&filter->show_bg));
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

/* GstElement vmethod implementations */

/* This function handles the link with other elements */
static gboolean
gst_xsub_set_caps (GstPad * pad, GstCaps * caps)
{
  GstXSub *filter;
  GstStructure *structure = gst_caps_get_structure (caps, 0);

  filter = GST_XSUB (gst_pad_get_parent (pad));

  gst_structure_get_int (structure, "width", &filter->width);
  gst_structure_get_int (structure, "height", &filter->height);

  gst_object_unref (filter);

  return TRUE;
}

/* Chain function for frame data
 *
 * This function blends frame data with subpicture data when needed,
 * otherwise it just copies frame data to output pad.
 */
static GstFlowReturn
gst_xsub_frame_chain (GstPad * pad, GstObject * parent, GstBuffer * buf)
{
  GstXSub *filter;
  GstXSubData *spu;
  GstMapInfo pict_map, spu_map;
  int i;

  filter = GST_XSUB (parent);

  GST_DEBUG_OBJECT (pad, "Frame chain in width:%d height:%d", filter->width,
      filter->height);

  /* Here comes the blending logic */

  g_mutex_lock (&filter->lock);

  while ((spu = g_queue_peek_head (filter->spu_queue))) {

    if (GST_BUFFER_TIMESTAMP (buf) >= GST_BUFFER_TIMESTAMP (spu->buf)) {
      if (GST_BUFFER_TIMESTAMP (buf) <= GST_BUFFER_TIMESTAMP (spu->buf) +
          GST_BUFFER_DURATION (spu->buf))
        break;

      gst_buffer_unref (spu->buf);
      g_slice_free1 (spu->width * 3, spu->bgless_row);
      g_queue_remove (filter->spu_queue, spu);
      g_slice_free1 (sizeof (GstXSubData), spu);
      continue;
    }

    /* We assume SPU packets to be ordered as they come */
    spu = NULL;
    break;
  }

  if (spu) {
    GST_DEBUG_OBJECT (pad, "Have SPU data for this frame");
    buf = gst_buffer_make_writable (buf);
    if (!gst_buffer_map (buf, &pict_map, GST_MAP_WRITE)) {
      GST_ERROR_OBJECT (pad, "Map failed on picture buffer");
      goto PUSH;
    }

    if (!gst_buffer_map (spu->buf, &spu_map, GST_MAP_READ)) {
      GST_ERROR_OBJECT (pad, "Map failed on spu buffer");
      gst_buffer_unmap (buf, &pict_map);
      goto PUSH;
    }

    GST_DEBUG_OBJECT (pad, "pict/spu map succeed");

    /* Overwrite coords if off bounds */

    if (spu->coords[0] + spu->width > filter->width) {
      GST_WARNING_OBJECT (pad, "X coord %hi off bounds, using 0 instead",
          spu->coords[0]);
      spu->coords[0] = 0;
      spu->coords[2] = spu->width - 1;
    }

    if (spu->coords[1] + spu->height > filter->height) {
      GST_WARNING_OBJECT (pad, "Y coord %hi off bounds, using 0 instead",
          spu->coords[1]);
      spu->coords[1] = 0;
      spu->coords[3] = spu->height - 1;
    }

    /* FIXME: This should use the new overlay API */
    if (filter->show_bg)
      /* blit with background in */
      for (i = 0; i < spu->height; i++)
        memcpy (pict_map.data + (i * filter->width +
                spu->coords[0]) * XSUB_RGB_BPP,
            spu_map.data + i * spu->width * XSUB_RGB_BPP,
            spu->width * XSUB_RGB_BPP);
    else
      /* blit without background */
      for (i = 0; i < spu->height; i++) {
        xsub_wipe_background (spu->bgless_row,
            spu_map.data + i * spu->width * XSUB_RGB_BPP,
            pict_map.data + (i * filter->width + spu->coords[0]) * XSUB_RGB_BPP,
            spu->bg_color, spu->width * XSUB_RGB_BPP);

        memcpy (pict_map.data + (i * filter->width +
                spu->coords[0]) * XSUB_RGB_BPP, spu->bgless_row,
            spu->width * XSUB_RGB_BPP);
      }

    GST_DEBUG_OBJECT (pad, "Blitted a spu!");
    gst_buffer_unmap (buf, &pict_map);
    gst_buffer_unmap (spu->buf, &spu_map);
  }

PUSH:
  g_mutex_unlock (&filter->lock);
  return gst_pad_push (filter->src, buf);
}


/* Chain function for subpicture data
 *
 * This function asks for the decoding of XSUB packets
 * as they come and fills the SPU buffer
 */
static GstFlowReturn
gst_xsub_spu_chain (GstPad * pad, GstObject * parent, GstBuffer * buf)
{
  GstXSub *filter;
  GstXSubData *parsed;

  filter = GST_XSUB (parent);

  GST_DEBUG_OBJECT (pad, "SPU in");

  parsed = g_slice_new (GstXSubData);
  parsed->buf = gst_buffer_new ();

  /* SPU decoding begins here */
  if (!xsub_parse_header (pad, parsed, buf) ||
      !xsub_parse_spu (pad, parsed, buf)) {

    GST_ERROR_OBJECT (pad, "Parsing of header/spu data failed!");
    gst_buffer_unref (parsed->buf);
    g_slice_free (GstXSubData, parsed);
  } else {
    /* Save parsed data into spu_queue */
    parsed->bgless_row = g_slice_alloc (parsed->width * XSUB_RGB_BPP);
    g_mutex_lock (&filter->lock);
    g_queue_push_tail (filter->spu_queue, parsed);

    GST_DEBUG_OBJECT (pad, "Parsed #%d: [(%hu,%hu)-(%hu,%hu)] Size: %zu",
        g_queue_get_length (filter->spu_queue),
        parsed->coords[0], parsed->coords[1], parsed->coords[2],
        parsed->coords[3], gst_buffer_get_size (parsed->buf));
    g_mutex_unlock (&filter->lock);
  }

  return GST_FLOW_OK;
}

/* Entry point to initialize the plug-in
 *
 * Initialize the plug-in itself & register element factories and
 * other features
 */
static gboolean
xsub_init (GstPlugin * xsub)
{
  /* debug category for filtering log messages */

  GST_DEBUG_CATEGORY_INIT (xsub_debug, "xsub", 0, "xsub");

  return gst_element_register (xsub, "xsub", GST_RANK_NONE, GST_TYPE_XSUB);
}

/* GStreamer looks for this structure to register xsubs
 */
GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    xsub,
    "GStreamer plugin for the decoding and overlay of XSUB subtitles",
    xsub_init, VERSION, "LGPL", GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN)
// vim: set expandtab tabstop=2 shiftwidth=2 autoindent smartindent:

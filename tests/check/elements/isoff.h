#ifndef __DASH_ISOFF_H__
#define __DASH_ISOFF_H__

#include <glib.h>

static const guint8 moof1[] = {
  0x00, 0x00, 0x04, 0xdc, 0x6d, 0x6f, 0x6f, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x6d, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x04, 0xc4, 0x74, 0x72, 0x61, 0x66, 0x00, 0x00, 0x00, 0x14,
  0x74, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01,
  0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x14, 0x74, 0x66, 0x64, 0x74,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x04, 0x94, 0x74, 0x72, 0x75, 0x6e, 0x01, 0x00, 0x0e, 0x01,
  0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x04, 0xe4, 0x00, 0x00, 0x00, 0xd1,
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x05, 0xa5,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x09, 0x47,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x07, 0xdd,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0a, 0x70,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x06, 0xb4,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x92,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x9b,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x8f,
  0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* Fragments taken from http://www.bok.net/dash/tears_of_steel/cleartext/stream.mpd
 *
 * Audio stream (aac)
 * Header (moov only) + first fragment (moof only) + second fragment (moof only)
 */

/* http://www.bok.net/dash/tears_of_steel/cleartext/audio/en/init.mp4 (except for ftyp box) */
static const guint8 init_mp4[] = {
  0x00, 0x00, 0x02, 0x50, 0x6d, 0x6f, 0x6f, 0x76, 0x00, 0x00, 0x00, 0x6c,
  0x6d, 0x76, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe8, 0x00, 0x0b, 0x33, 0xd7,
  0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0xa4,
  0x74, 0x72, 0x61, 0x6b, 0x00, 0x00, 0x00, 0x5c, 0x74, 0x6b, 0x68, 0x64,
  0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x33, 0xbc,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x40, 0x6d, 0x64, 0x69, 0x61, 0x00, 0x00, 0x00, 0x20,
  0x6d, 0x64, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xac, 0x44, 0x00, 0x00, 0x00, 0x00,
  0x15, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x68, 0x64, 0x6c, 0x72,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x6f, 0x75, 0x6e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x42, 0x65, 0x6e, 0x74, 0x6f, 0x34, 0x20, 0x53, 0x6f, 0x75, 0x6e, 0x64,
  0x20, 0x48, 0x61, 0x6e, 0x64, 0x6c, 0x65, 0x72, 0x00, 0x00, 0x00, 0x00,
  0xe3, 0x6d, 0x69, 0x6e, 0x66, 0x00, 0x00, 0x00, 0x10, 0x73, 0x6d, 0x68,
  0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x24, 0x64, 0x69, 0x6e, 0x66, 0x00, 0x00, 0x00, 0x1c, 0x64, 0x72, 0x65,
  0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x0c, 0x75, 0x72, 0x6c, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0xa7, 0x73, 0x74, 0x62, 0x6c, 0x00, 0x00, 0x00, 0x5b, 0x73, 0x74, 0x73,
  0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x4b, 0x6d, 0x70, 0x34, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x00, 0xac, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x27, 0x65, 0x73, 0x64, 0x73, 0x00, 0x00, 0x00, 0x00, 0x03, 0x19, 0x00,
  0x00, 0x00, 0x04, 0x11, 0x40, 0x15, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf4,
  0x01, 0x00, 0x01, 0xf4, 0x01, 0x05, 0x02, 0x12, 0x10, 0x06, 0x01, 0x02,
  0x00, 0x00, 0x00, 0x14, 0x73, 0x74, 0x73, 0x7a, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
  0x73, 0x74, 0x73, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x10, 0x73, 0x74, 0x74, 0x73, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x73, 0x74, 0x63, 0x6f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
  0x6d, 0x76, 0x65, 0x78, 0x00, 0x00, 0x00, 0x10, 0x6d, 0x65, 0x68, 0x64,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x33, 0xd7, 0x00, 0x00, 0x00, 0x20,
  0x74, 0x72, 0x65, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

/* http://www.bok.net/dash/tears_of_steel/cleartext/audio/en/seg-1.m4f (except for mdat box) */
static const guint8 seg_1_m4f[] = {
  0x00, 0x00, 0x04, 0x60, 0x6d, 0x6f, 0x6f, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x6d, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x04, 0x48, 0x74, 0x72, 0x61, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x74, 0x66, 0x68, 0x64, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x14, 0x74, 0x66, 0x64, 0x74, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x1c,
  0x74, 0x72, 0x75, 0x6e, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x81,
  0x00, 0x00, 0x04, 0x68, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x73,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x74, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xdd, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x12,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xe9, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xce, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xb9,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa5, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa4, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x9a,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x92, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x8e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x82, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x82,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x71, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x72, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x63,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x78, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x50, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x55,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x66, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x9f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x82,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x82,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x66, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x94,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x56, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x69, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x69, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x86,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x67,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x68, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x89,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x61, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x81, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x59, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x9e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x74, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x71, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x91,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x87, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x4d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x53,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa7, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x57, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xbd,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa9, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa6, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x9f,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x96, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x85, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xba,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xb0, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x87, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x81,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x53, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x15, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x25,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x3c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x47, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x35,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x85, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x67, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xab,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x46, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa4, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x97,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x3c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa3,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x83, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x46,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x48, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x58,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa9, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x49, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x93, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x3a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x70, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x85, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x75, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x56, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x57,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x70, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xb4, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x67,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x60, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x69, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa3, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xaa, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x91, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x46, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x9b, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x52, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x59
};
static const guint seg_1_m4f_len = 1120;

static const guint seg_1_sample_sizes[] = {
  371, 372, 477, 530, 489, 462, 441, 421, 420, 410, 402, 398, 381, 381, 386,
  386, 369, 370, 362, 346, 357, 355, 376, 336, 341, 358, 350, 362, 333, 415,
  386, 364, 344, 386, 358, 365, 404, 342, 361, 366, 361, 350, 390, 348, 366,
  359, 357, 360, 349, 356, 365, 393, 353, 385, 381, 348, 345, 414, 372, 369,
  401, 391, 333, 339, 423, 343, 445, 425, 422, 415, 406, 389, 395, 375, 356,
  442, 432, 391, 385, 339, 277, 293, 316, 327, 309, 389, 359, 427, 326, 420,
  407, 316, 362, 419, 349, 387, 326, 328, 367, 344, 425, 329, 379, 403, 314,
  397, 368, 389, 380, 373, 342, 343, 368, 436, 359, 352, 361, 366, 350, 419,
  331, 426, 401, 382, 326, 411, 364, 338, 345
};

/* http://www.bok.net/dash/tears_of_steel/cleartext/audio/en/seg-2.m4f (except for mdat box) */
static const guint8 seg_2_m4f[] = {
  0x00, 0x00, 0x04, 0x60, 0x6d, 0x6f, 0x6f, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x6d, 0x66, 0x68, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
  0x00, 0x00, 0x04, 0x48, 0x74, 0x72, 0x61, 0x66, 0x00, 0x00, 0x00, 0x10,
  0x74, 0x66, 0x68, 0x64, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x14, 0x74, 0x66, 0x64, 0x74, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x04, 0x1c,
  0x74, 0x72, 0x75, 0x6e, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x81,
  0x00, 0x00, 0x04, 0x68, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x45,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x79, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x90,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6b, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x98,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x75, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x82, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa8,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x47, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x54,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xaf, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x60,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x66, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x59,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x98, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x72,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x62, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x65, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa0, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x70,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xab,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x74, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x7c, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x61, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x64,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x62, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x63,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6b, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x67, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x64, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6f,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x71,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6f, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6e, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x70,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x82,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x77, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x76, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x76,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xc8, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x64,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xbc, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xad, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa6,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa5, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x9a, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x95,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x89, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x75, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8e,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x51, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x3c, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x66,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x3b, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x50, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x45,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5e, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x5d, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x65,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6e, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x60, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x59, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x51, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5f, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xdd, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x6c,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x92, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xbc, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x59,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x97, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa5, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0xa2,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x89, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x91, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x60,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7c, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x35, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x48,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x89, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x7b,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x87, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xb1, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8a,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x51, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x75,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x73, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x95, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x89,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4d, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x48, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x79,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x8a, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x49, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x78,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x94, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0xa2, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x86,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x4f, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x4f, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x5d,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x60, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x00, 0x01, 0x59
};
static const guint seg_2_m4f_len = 1120;

static const guint seg_2_sample_sizes[] = {
  325, 357, 377, 400, 344, 363, 408, 373, 386, 424, 327, 351, 340, 362, 431,
  352, 362, 358, 345, 408, 375, 370, 354, 357, 364, 356, 416, 382, 362, 366,
  368, 350, 375, 427, 372, 380, 364, 353, 362, 356, 354, 351, 355, 363, 365,
  363, 359, 356, 367, 365, 375, 369, 367, 366, 368, 364, 364, 386, 375, 374,
  374, 364, 456, 356, 444, 429, 422, 421, 410, 405, 393, 373, 398, 337, 316,
  358, 315, 336, 325, 350, 349, 357, 366, 352, 396, 345, 337, 364, 351, 477,
  364, 402, 444, 345, 407, 421, 418, 393, 401, 352, 380, 309, 328, 344, 393,
  379, 391, 433, 394, 333, 337, 373, 371, 405, 393, 333, 328, 377, 394, 329,
  376, 404, 418, 390, 335, 335, 349, 352, 345
};

/* in timescale */
static const GstClockTime seg_sample_duration = 1024;
static const guint32 seg_timescale = 44100;

#endif

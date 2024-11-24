/*******************************************************************************
 * Size: 30 px
 * Bpp: 4
 * Opts: --bpp 4 --size 30 --no-compress --font RobotoFlex-Regular.ttf --symbols 0123456789C°%HPa --format lvgl -o roboto_30.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ROBOTO_30
#define ROBOTO_30 1
#endif

#if ROBOTO_30

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0025 "%" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8d, 0xff,
    0xb4, 0x0, 0x0, 0x0, 0x0, 0x1, 0xd5, 0x0,
    0x0, 0x0, 0xc, 0xff, 0xff, 0xff, 0x50, 0x0,
    0x0, 0x0, 0xa, 0xfe, 0x0, 0x0, 0x0, 0x7f,
    0xf9, 0x45, 0xdf, 0xf1, 0x0, 0x0, 0x0, 0x4f,
    0xf5, 0x0, 0x0, 0x0, 0xcf, 0xb0, 0x0, 0x2f,
    0xf5, 0x0, 0x0, 0x0, 0xef, 0xb0, 0x0, 0x0,
    0x0, 0xff, 0x70, 0x0, 0xe, 0xf8, 0x0, 0x0,
    0x9, 0xff, 0x10, 0x0, 0x0, 0x0, 0xff, 0x60,
    0x0, 0xd, 0xf9, 0x0, 0x0, 0x3f, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0xff, 0x60, 0x0, 0xd, 0xf9,
    0x0, 0x0, 0xdf, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0x70, 0x0, 0xe, 0xf8, 0x0, 0x7, 0xff,
    0x20, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xb0, 0x0,
    0x2f, 0xf5, 0x0, 0x2f, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xf9, 0x45, 0xdf, 0xf1, 0x0,
    0xcf, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xff, 0xff, 0x50, 0x6, 0xff, 0x40, 0x3,
    0xbf, 0xfe, 0x80, 0x0, 0x0, 0x8d, 0xff, 0xb4,
    0x0, 0x1f, 0xf9, 0x0, 0x4f, 0xff, 0xff, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0xe1,
    0x0, 0xef, 0xd5, 0x48, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x4, 0xff, 0x50, 0x4, 0xff, 0x30,
    0x0, 0xaf, 0xd0, 0x0, 0x0, 0x0, 0x0, 0xe,
    0xfb, 0x0, 0x7, 0xff, 0x0, 0x0, 0x6f, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1, 0x0, 0x7,
    0xfe, 0x0, 0x0, 0x5f, 0xf1, 0x0, 0x0, 0x0,
    0x3, 0xff, 0x70, 0x0, 0x7, 0xfe, 0x0, 0x0,
    0x5f, 0xf1, 0x0, 0x0, 0x0, 0xd, 0xfc, 0x0,
    0x0, 0x7, 0xff, 0x0, 0x0, 0x6f, 0xf0, 0x0,
    0x0, 0x0, 0x7f, 0xf2, 0x0, 0x0, 0x4, 0xff,
    0x30, 0x0, 0xaf, 0xd0, 0x0, 0x0, 0x2, 0xff,
    0x80, 0x0, 0x0, 0x0, 0xef, 0xd5, 0x48, 0xff,
    0x80, 0x0, 0x0, 0xc, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0x4f, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0,
    0x7, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x3, 0xbf,
    0xfe, 0x80, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+0030 "0" */
    0x0, 0x0, 0x7c, 0xef, 0xec, 0x60, 0x0, 0x0,
    0x2, 0xef, 0xff, 0xff, 0xff, 0xd2, 0x0, 0x1,
    0xef, 0xfc, 0x75, 0x7c, 0xff, 0xd0, 0x0, 0x9f,
    0xf9, 0x0, 0x0, 0xa, 0xff, 0x80, 0xf, 0xfe,
    0x0, 0x0, 0x0, 0x1f, 0xfe, 0x4, 0xff, 0xa0,
    0x0, 0x0, 0x0, 0xbf, 0xf3, 0x5f, 0xf7, 0x0,
    0x0, 0x0, 0x8, 0xff, 0x46, 0xff, 0x70, 0x0,
    0x0, 0x0, 0x8f, 0xf5, 0x6f, 0xf7, 0x0, 0x0,
    0x0, 0x8, 0xff, 0x56, 0xff, 0x70, 0x0, 0x0,
    0x0, 0x8f, 0xf5, 0x6f, 0xf7, 0x0, 0x0, 0x0,
    0x8, 0xff, 0x56, 0xff, 0x70, 0x0, 0x0, 0x0,
    0x8f, 0xf5, 0x6f, 0xf7, 0x0, 0x0, 0x0, 0x8,
    0xff, 0x56, 0xff, 0x70, 0x0, 0x0, 0x0, 0x8f,
    0xf5, 0x6f, 0xf7, 0x0, 0x0, 0x0, 0x8, 0xff,
    0x55, 0xff, 0x70, 0x0, 0x0, 0x0, 0x8f, 0xf4,
    0x4f, 0xf9, 0x0, 0x0, 0x0, 0xb, 0xff, 0x30,
    0xff, 0xe0, 0x0, 0x0, 0x1, 0xff, 0xe0, 0x9,
    0xff, 0x90, 0x0, 0x0, 0xaf, 0xf8, 0x0, 0x1e,
    0xff, 0xc6, 0x57, 0xcf, 0xfd, 0x10, 0x0, 0x2e,
    0xff, 0xff, 0xff, 0xfd, 0x20, 0x0, 0x0, 0x7,
    0xcf, 0xfe, 0xc6, 0x0, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x0, 0x5b, 0xb0, 0x0, 0x28, 0xef,
    0xfb, 0x6, 0xcf, 0xff, 0xff, 0xb7, 0xff, 0xff,
    0xaf, 0xfb, 0x7f, 0xe7, 0x11, 0xff, 0xb5, 0x50,
    0x0, 0x1f, 0xfb, 0x0, 0x0, 0x1, 0xff, 0xb0,
    0x0, 0x0, 0x1f, 0xfb, 0x0, 0x0, 0x1, 0xff,
    0xb0, 0x0, 0x0, 0x1f, 0xfb, 0x0, 0x0, 0x1,
    0xff, 0xb0, 0x0, 0x0, 0x1f, 0xfb, 0x0, 0x0,
    0x1, 0xff, 0xb0, 0x0, 0x0, 0x1f, 0xfb, 0x0,
    0x0, 0x1, 0xff, 0xb0, 0x0, 0x0, 0x1f, 0xfb,
    0x0, 0x0, 0x1, 0xff, 0xb0, 0x0, 0x0, 0x1f,
    0xfb, 0x0, 0x0, 0x1, 0xff, 0xb0, 0x0, 0x0,
    0x1f, 0xfb, 0x0, 0x0, 0x1, 0xff, 0xb0, 0x0,
    0x0, 0x1f, 0xfb,

    /* U+0032 "2" */
    0x0, 0x0, 0x5b, 0xef, 0xfc, 0x70, 0x0, 0x0,
    0x1, 0xcf, 0xff, 0xff, 0xff, 0xd2, 0x0, 0x0,
    0xdf, 0xfd, 0x75, 0x7c, 0xff, 0xe1, 0x0, 0x9f,
    0xf9, 0x0, 0x0, 0xa, 0xff, 0x80, 0xf, 0xfd,
    0x0, 0x0, 0x0, 0x1f, 0xfe, 0x4, 0xff, 0x80,
    0x0, 0x0, 0x0, 0xbf, 0xf1, 0x4d, 0xd5, 0x0,
    0x0, 0x0, 0xb, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xef, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5f, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1e, 0xfe, 0x10, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0xa, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff, 0xb0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x5, 0xff, 0xd1, 0x0, 0x0, 0x0,
    0x0, 0x4, 0xff, 0xd1, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0xe2, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xef, 0xe2, 0x0, 0x0, 0x0, 0x0, 0x1, 0xef,
    0xfa, 0x77, 0x77, 0x77, 0x77, 0x74, 0x6f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xa6, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfa,

    /* U+0033 "3" */
    0x0, 0x2, 0x9d, 0xff, 0xea, 0x40, 0x0, 0x0,
    0x5, 0xff, 0xff, 0xff, 0xff, 0xa0, 0x0, 0x4,
    0xff, 0xf9, 0x65, 0x8e, 0xff, 0x90, 0x0, 0xdf,
    0xf2, 0x0, 0x0, 0x1e, 0xff, 0x20, 0x2f, 0xf9,
    0x0, 0x0, 0x0, 0x7f, 0xf6, 0x1, 0x77, 0x30,
    0x0, 0x0, 0x5, 0xff, 0x70, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0xf5, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xd, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x5d, 0xff, 0x50, 0x0, 0x0, 0x1, 0xff, 0xff,
    0xfd, 0x40, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xff,
    0xd5, 0x0, 0x0, 0x0, 0x0, 0x44, 0x58, 0xef,
    0xfa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf,
    0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xff,
    0x22, 0x33, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf4,
    0xcf, 0xf0, 0x0, 0x0, 0x0, 0xa, 0xff, 0x3a,
    0xff, 0x30, 0x0, 0x0, 0x0, 0xef, 0xf0, 0x4f,
    0xfd, 0x10, 0x0, 0x0, 0x9f, 0xf9, 0x0, 0xaf,
    0xff, 0x96, 0x57, 0xdf, 0xfe, 0x10, 0x0, 0xaf,
    0xff, 0xff, 0xff, 0xfc, 0x20, 0x0, 0x0, 0x4a,
    0xdf, 0xfe, 0xb5, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xe, 0xff, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0xff,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x4, 0xff, 0xef,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xdf, 0xe7,
    0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf4,
    0x6f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf9,
    0x6, 0xff, 0x40, 0x0, 0x0, 0x0, 0xd, 0xfe,
    0x10, 0x6f, 0xf4, 0x0, 0x0, 0x0, 0x8, 0xff,
    0x50, 0x6, 0xff, 0x40, 0x0, 0x0, 0x3, 0xff,
    0xa0, 0x0, 0x6f, 0xf4, 0x0, 0x0, 0x0, 0xdf,
    0xe1, 0x0, 0x6, 0xff, 0x40, 0x0, 0x0, 0x8f,
    0xf5, 0x0, 0x0, 0x6f, 0xf4, 0x0, 0x0, 0x3f,
    0xfb, 0x0, 0x0, 0x6, 0xff, 0x40, 0x0, 0xd,
    0xff, 0x65, 0x55, 0x55, 0x9f, 0xf7, 0x55, 0x14,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3,
    0x4f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x30, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
    0xff, 0x40, 0x0,

    /* U+0035 "5" */
    0x0, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x0,
    0xd, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50, 0x0,
    0xff, 0xc8, 0x88, 0x88, 0x88, 0x82, 0x0, 0x1f,
    0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xf0, 0x3,
    0x54, 0x20, 0x0, 0x0, 0x8, 0xff, 0x8e, 0xff,
    0xff, 0xc4, 0x0, 0x0, 0xaf, 0xff, 0xff, 0xff,
    0xff, 0xf7, 0x0, 0xc, 0xff, 0xc4, 0x10, 0x28,
    0xff, 0xf5, 0x0, 0x18, 0x70, 0x0, 0x0, 0x5,
    0xff, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff,
    0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xf6,
    0x7d, 0xd2, 0x0, 0x0, 0x0, 0x8, 0xff, 0x46,
    0xff, 0x60, 0x0, 0x0, 0x0, 0xef, 0xf1, 0x1f,
    0xfe, 0x20, 0x0, 0x0, 0xaf, 0xf9, 0x0, 0x8f,
    0xff, 0xa6, 0x57, 0xdf, 0xfd, 0x10, 0x0, 0x8f,
    0xff, 0xff, 0xff, 0xfc, 0x10, 0x0, 0x0, 0x39,
    0xdf, 0xfe, 0xb5, 0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x0, 0x5, 0x9d, 0xef, 0x30, 0x0,
    0x0, 0x0, 0x6e, 0xff, 0xff, 0xf3, 0x0, 0x0,
    0x0, 0xbf, 0xff, 0xd9, 0x65, 0x10, 0x0, 0x0,
    0xcf, 0xfc, 0x40, 0x0, 0x0, 0x0, 0x0, 0x9f,
    0xf9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfb,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xff, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xb0, 0x1,
    0x45, 0x30, 0x0, 0x0, 0x4f, 0xf6, 0x2b, 0xff,
    0xff, 0xf9, 0x0, 0x7, 0xff, 0x7f, 0xff, 0xff,
    0xff, 0xfd, 0x10, 0x9f, 0xff, 0xf8, 0x20, 0x4,
    0xcf, 0xfb, 0xa, 0xff, 0xf3, 0x0, 0x0, 0x0,
    0xdf, 0xf4, 0xbf, 0xf7, 0x0, 0x0, 0x0, 0x4,
    0xff, 0x9a, 0xff, 0x20, 0x0, 0x0, 0x0, 0xf,
    0xfc, 0x9f, 0xf2, 0x0, 0x0, 0x0, 0x0, 0xef,
    0xd7, 0xff, 0x40, 0x0, 0x0, 0x0, 0xf, 0xfd,
    0x4f, 0xf8, 0x0, 0x0, 0x0, 0x1, 0xff, 0xb0,
    0xef, 0xe1, 0x0, 0x0, 0x0, 0x7f, 0xf7, 0x7,
    0xff, 0xb0, 0x0, 0x0, 0x3f, 0xfe, 0x10, 0xb,
    0xff, 0xe8, 0x56, 0x9f, 0xff, 0x50, 0x0, 0xa,
    0xff, 0xff, 0xff, 0xff, 0x50, 0x0, 0x0, 0x3,
    0xae, 0xff, 0xd8, 0x10, 0x0,

    /* U+0037 "7" */
    0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6d,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x56,
    0x66, 0x66, 0x66, 0x66, 0x6c, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x90, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6f, 0xf3, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0x60, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xaf, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xf9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xff, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xff, 0x90, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x9f, 0xf3, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xff, 0x60, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xcf, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xf9, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa, 0xff, 0x20, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xf6, 0x0, 0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x5b, 0xef, 0xeb, 0x50, 0x0, 0x0,
    0x1, 0xcf, 0xff, 0xff, 0xff, 0xb0, 0x0, 0x0,
    0xcf, 0xfd, 0x75, 0x7d, 0xff, 0xb0, 0x0, 0x5f,
    0xfc, 0x0, 0x0, 0xc, 0xff, 0x40, 0xa, 0xff,
    0x20, 0x0, 0x0, 0x3f, 0xf9, 0x0, 0xcf, 0xf0,
    0x0, 0x0, 0x0, 0xff, 0xb0, 0xc, 0xff, 0x0,
    0x0, 0x0, 0xf, 0xfb, 0x0, 0x8f, 0xf3, 0x0,
    0x0, 0x4, 0xff, 0x70, 0x2, 0xff, 0xc0, 0x0,
    0x0, 0xcf, 0xf1, 0x0, 0x5, 0xff, 0xd7, 0x57,
    0xdf, 0xf5, 0x0, 0x0, 0x4, 0xff, 0xff, 0xff,
    0xe4, 0x0, 0x0, 0x2, 0xcf, 0xff, 0xff, 0xff,
    0xc2, 0x0, 0x3, 0xff, 0xe6, 0x10, 0x16, 0xef,
    0xe2, 0x0, 0xdf, 0xe2, 0x0, 0x0, 0x2, 0xff,
    0xc0, 0x4f, 0xf8, 0x0, 0x0, 0x0, 0x9, 0xff,
    0x37, 0xff, 0x40, 0x0, 0x0, 0x0, 0x5f, 0xf6,
    0x7f, 0xf5, 0x0, 0x0, 0x0, 0x6, 0xff, 0x64,
    0xff, 0xa0, 0x0, 0x0, 0x0, 0xbf, 0xf3, 0xe,
    0xff, 0x50, 0x0, 0x0, 0x6f, 0xfe, 0x0, 0x5f,
    0xff, 0xb6, 0x56, 0xbf, 0xff, 0x50, 0x0, 0x6f,
    0xff, 0xff, 0xff, 0xff, 0x50, 0x0, 0x0, 0x18,
    0xcf, 0xff, 0xc7, 0x10, 0x0,

    /* U+0039 "9" */
    0x0, 0x2, 0x8d, 0xff, 0xd9, 0x30, 0x0, 0x0,
    0x6, 0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x6,
    0xff, 0xf9, 0x65, 0x9e, 0xff, 0xa0, 0x1, 0xff,
    0xe2, 0x0, 0x0, 0x1c, 0xff, 0x50, 0x8f, 0xf6,
    0x0, 0x0, 0x0, 0x1f, 0xfd, 0xc, 0xff, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xf2, 0xef, 0xe0, 0x0,
    0x0, 0x0, 0x5, 0xff, 0x6e, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xf8, 0xdf, 0xf0, 0x0, 0x0,
    0x0, 0x4, 0xff, 0x9a, 0xff, 0x30, 0x0, 0x0,
    0x0, 0x8f, 0xfa, 0x5f, 0xfc, 0x0, 0x0, 0x0,
    0x4f, 0xff, 0x90, 0xcf, 0xfc, 0x40, 0x3, 0x9f,
    0xff, 0xf8, 0x1, 0xef, 0xff, 0xff, 0xff, 0xe7,
    0xff, 0x70, 0x1, 0xaf, 0xff, 0xff, 0xb2, 0x7f,
    0xf3, 0x0, 0x0, 0x14, 0x54, 0x10, 0xc, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0x90,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xf1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xbf, 0xf7, 0x0, 0x0,
    0x0, 0x0, 0x4, 0xdf, 0xfb, 0x0, 0x0, 0x1,
    0x57, 0x9d, 0xff, 0xfa, 0x0, 0x0, 0x0, 0x4f,
    0xff, 0xff, 0xe6, 0x0, 0x0, 0x0, 0x4, 0xfe,
    0xc9, 0x50, 0x0, 0x0, 0x0,

    /* U+0043 "C" */
    0x0, 0x0, 0x1, 0x7c, 0xef, 0xfd, 0x94, 0x0,
    0x0, 0x0, 0x0, 0x6f, 0xff, 0xff, 0xff, 0xff,
    0xb1, 0x0, 0x0, 0x8, 0xff, 0xfc, 0x86, 0x7a,
    0xff, 0xfd, 0x10, 0x0, 0x6f, 0xfe, 0x40, 0x0,
    0x0, 0x1b, 0xff, 0xa0, 0x1, 0xff, 0xf3, 0x0,
    0x0, 0x0, 0x0, 0xdf, 0xf3, 0x7, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0xf8, 0xd, 0xff,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfa, 0xf,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x21,
    0x3f, 0xfa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4f, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x5f, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5f, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4f, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xfa, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x21, 0xd,
    0xff, 0x20, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xf9,
    0x7, 0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0x8f,
    0xf5, 0x1, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xe0, 0x0, 0x6f, 0xff, 0x50, 0x0, 0x0,
    0x2d, 0xff, 0x70, 0x0, 0x8, 0xff, 0xfc, 0x86,
    0x7a, 0xff, 0xfb, 0x0, 0x0, 0x0, 0x6f, 0xff,
    0xff, 0xff, 0xff, 0xa0, 0x0, 0x0, 0x0, 0x1,
    0x7c, 0xef, 0xfd, 0x93, 0x0, 0x0,

    /* U+0048 "H" */
    0x8f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xe8, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xfe, 0x8f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xe8, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xfe, 0x8f, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xe8, 0xff, 0x40, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xfe, 0x8f, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xe8, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xfe, 0x8f, 0xf4, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xe8, 0xff, 0x85, 0x55,
    0x55, 0x55, 0x55, 0x5f, 0xfe, 0x8f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe8, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x8f, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xe8, 0xff,
    0x40, 0x0, 0x0, 0x0, 0x0, 0xf, 0xfe, 0x8f,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xe8,
    0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0xf, 0xfe,
    0x8f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xe8, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xfe, 0x8f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xe8, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xfe, 0x8f, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xe8, 0xff, 0x40, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xfe,

    /* U+0050 "P" */
    0x8f, 0xff, 0xff, 0xff, 0xfd, 0x93, 0x0, 0x8,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x8f,
    0xf8, 0x55, 0x55, 0x69, 0xff, 0xf8, 0x8, 0xff,
    0x40, 0x0, 0x0, 0x2, 0xef, 0xf2, 0x8f, 0xf4,
    0x0, 0x0, 0x0, 0x6, 0xff, 0x88, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x1f, 0xfc, 0x8f, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xd8, 0xff, 0x40, 0x0,
    0x0, 0x0, 0xf, 0xfc, 0x8f, 0xf4, 0x0, 0x0,
    0x0, 0x4, 0xff, 0x98, 0xff, 0x40, 0x0, 0x0,
    0x0, 0xcf, 0xf4, 0x8f, 0xf4, 0x0, 0x0, 0x14,
    0xcf, 0xfb, 0x8, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0x10, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xe8,
    0x0, 0x8, 0xff, 0x85, 0x55, 0x54, 0x20, 0x0,
    0x0, 0x8f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x8, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x8f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8,
    0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+0061 "a" */
    0x0, 0x2, 0x9d, 0xff, 0xeb, 0x50, 0x0, 0x0,
    0x5f, 0xff, 0xff, 0xff, 0xfb, 0x0, 0x3, 0xff,
    0xe7, 0x33, 0x5c, 0xff, 0x70, 0x9, 0xff, 0x30,
    0x0, 0x1, 0xef, 0xe0, 0x5, 0x76, 0x0, 0x0,
    0x0, 0xaf, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x9f, 0xf1, 0x0, 0x5, 0xad, 0xef, 0xff, 0xff,
    0xf2, 0x2, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xf2,
    0xd, 0xff, 0x93, 0x0, 0x0, 0x9f, 0xf2, 0x6f,
    0xf7, 0x0, 0x0, 0x0, 0x9f, 0xf2, 0xaf, 0xf1,
    0x0, 0x0, 0x0, 0xaf, 0xf2, 0xaf, 0xf1, 0x0,
    0x0, 0x0, 0xef, 0xf2, 0x8f, 0xf6, 0x0, 0x0,
    0xb, 0xff, 0xf2, 0x2f, 0xff, 0x83, 0x36, 0xdf,
    0xef, 0xf2, 0x6, 0xff, 0xff, 0xff, 0xfa, 0x6f,
    0xf5, 0x0, 0x3a, 0xef, 0xfc, 0x50, 0x2f, 0xf9,

    /* U+00B0 "°" */
    0x0, 0x2a, 0xdc, 0x50, 0x0, 0x3f, 0xff, 0xff,
    0x60, 0xc, 0xf7, 0x4, 0xff, 0x0, 0xfd, 0x0,
    0x9, 0xf4, 0xf, 0xc0, 0x0, 0x8f, 0x40, 0xdf,
    0x50, 0x2e, 0xf1, 0x4, 0xff, 0xef, 0xf8, 0x0,
    0x4, 0xcf, 0xe7, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 433, .box_w = 26, .box_h = 24, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 312, .adv_w = 271, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 271, .box_w = 9, .box_h = 22, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 271, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 741, .adv_w = 271, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 906, .adv_w = 271, .box_w = 17, .box_h = 22, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1093, .adv_w = 271, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1258, .adv_w = 271, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1423, .adv_w = 271, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1588, .adv_w = 271, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1753, .adv_w = 271, .box_w = 15, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1918, .adv_w = 319, .box_w = 18, .box_h = 22, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2116, .adv_w = 342, .box_w = 17, .box_h = 22, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2303, .adv_w = 281, .box_w = 15, .box_h = 22, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2468, .adv_w = 259, .box_w = 14, .box_h = 16, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2580, .adv_w = 179, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 14}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11,
    0x12, 0x13, 0x14, 0x1e, 0x23, 0x2b, 0x3c, 0x8b
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 37, .range_length = 140, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 16, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_30;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t roboto_30 = {
#else
lv_font_t roboto_30 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 24,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_30,
#endif
    .user_data = NULL,
};



#endif /*#if ROBOTO_30*/

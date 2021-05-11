/*
 * LCGE - A Lightweight C Game Engine
 * Copyright (C) 2021  Satvik Reddy
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 * USA
 *
 * Satvik Reddy <reddy.satvik@gmail.com>
 */

#ifndef _INPUT_H
#define _INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "export.h"

/* Same values as GLFW keys */
#define LCGE_KEY_SPACE	       32
#define LCGE_KEY_APOSTROPHE    39 /* ' */
#define LCGE_KEY_COMMA	       44 /* , */
#define LCGE_KEY_MINUS	       45 /* - */
#define LCGE_KEY_PERIOD	       46 /* . */
#define LCGE_KEY_SLASH	       47 /* / */
#define LCGE_KEY_0	       48
#define LCGE_KEY_1	       49
#define LCGE_KEY_2	       50
#define LCGE_KEY_3	       51
#define LCGE_KEY_4	       52
#define LCGE_KEY_5	       53
#define LCGE_KEY_6	       54
#define LCGE_KEY_7	       55
#define LCGE_KEY_8	       56
#define LCGE_KEY_9	       57
#define LCGE_KEY_SEMICOLON     59 /* ; */
#define LCGE_KEY_EQUAL	       61 /* = */
#define LCGE_KEY_A	       65
#define LCGE_KEY_B	       66
#define LCGE_KEY_C	       67
#define LCGE_KEY_D	       68
#define LCGE_KEY_E	       69
#define LCGE_KEY_F	       70
#define LCGE_KEY_G	       71
#define LCGE_KEY_H	       72
#define LCGE_KEY_I	       73
#define LCGE_KEY_J	       74
#define LCGE_KEY_K	       75
#define LCGE_KEY_L	       76
#define LCGE_KEY_M	       77
#define LCGE_KEY_N	       78
#define LCGE_KEY_O	       79
#define LCGE_KEY_P	       80
#define LCGE_KEY_Q	       81
#define LCGE_KEY_R	       82
#define LCGE_KEY_S	       83
#define LCGE_KEY_T	       84
#define LCGE_KEY_U	       85
#define LCGE_KEY_V	       86
#define LCGE_KEY_W	       87
#define LCGE_KEY_X	       88
#define LCGE_KEY_Y	       89
#define LCGE_KEY_Z	       90
#define LCGE_KEY_LEFT_BRACKET  91 /* [ */
#define LCGE_KEY_BACKSLASH     92 /* \ */
#define LCGE_KEY_RIGHT_BRACKET 93 /* ] */
#define LCGE_KEY_GRAVE_ACCENT  96 /* ` */
#define LCGE_KEY_WORLD_1       161 /* non-US #1 */
#define LCGE_KEY_WORLD_2       162 /* non-US #2 */

#define LCGE_KEY_ESCAPE	       256
#define LCGE_KEY_ENTER	       257
#define LCGE_KEY_TAB	       258
#define LCGE_KEY_BACKSPACE     259
#define LCGE_KEY_INSERT	       260
#define LCGE_KEY_DELETE	       261
#define LCGE_KEY_RIGHT	       262
#define LCGE_KEY_LEFT	       263
#define LCGE_KEY_DOWN	       264
#define LCGE_KEY_UP	       265
#define LCGE_KEY_PAGE_UP       266
#define LCGE_KEY_PAGE_DOWN     267
#define LCGE_KEY_HOME	       268
#define LCGE_KEY_END	       269
#define LCGE_KEY_CAPS_LOCK     280
#define LCGE_KEY_SCROLL_LOCK   281
#define LCGE_KEY_NUM_LOCK      282
#define LCGE_KEY_PRINT_SCREEN  283
#define LCGE_KEY_PAUSE	       284
#define LCGE_KEY_F1	       290
#define LCGE_KEY_F2	       291
#define LCGE_KEY_F3	       292
#define LCGE_KEY_F4	       293
#define LCGE_KEY_F5	       294
#define LCGE_KEY_F6	       295
#define LCGE_KEY_F7	       296
#define LCGE_KEY_F8	       297
#define LCGE_KEY_F9	       298
#define LCGE_KEY_F10	       299
#define LCGE_KEY_F11	       300
#define LCGE_KEY_F12	       301
#define LCGE_KEY_F13	       302
#define LCGE_KEY_F14	       303
#define LCGE_KEY_F15	       304
#define LCGE_KEY_F16	       305
#define LCGE_KEY_F17	       306
#define LCGE_KEY_F18	       307
#define LCGE_KEY_F19	       308
#define LCGE_KEY_F20	       309
#define LCGE_KEY_F21	       310
#define LCGE_KEY_F22	       311
#define LCGE_KEY_F23	       312
#define LCGE_KEY_F24	       313
#define LCGE_KEY_F25	       314
#define LCGE_KEY_KP_0	       320
#define LCGE_KEY_KP_1	       321
#define LCGE_KEY_KP_2	       322
#define LCGE_KEY_KP_3	       323
#define LCGE_KEY_KP_4	       324
#define LCGE_KEY_KP_5	       325
#define LCGE_KEY_KP_6	       326
#define LCGE_KEY_KP_7	       327
#define LCGE_KEY_KP_8	       328
#define LCGE_KEY_KP_9	       329
#define LCGE_KEY_KP_DECIMAL    330
#define LCGE_KEY_KP_DIVIDE     331
#define LCGE_KEY_KP_MULTIPLY   332
#define LCGE_KEY_KP_SUBTRACT   333
#define LCGE_KEY_KP_ADD	       334
#define LCGE_KEY_KP_ENTER      335
#define LCGE_KEY_KP_EQUAL      336
#define LCGE_KEY_LEFT_SHIFT    340
#define LCGE_KEY_LEFT_CONTROL  341
#define LCGE_KEY_LEFT_ALT      342
#define LCGE_KEY_LEFT_SUPER    343
#define LCGE_KEY_RIGHT_SHIFT   344
#define LCGE_KEY_RIGHT_CONTROL 345
#define LCGE_KEY_RIGHT_ALT     346
#define LCGE_KEY_RIGHT_SUPER   347
#define LCGE_KEY_MENU	       348

#define LCGE_KEY_PRESSED  1
#define LCGE_KEY_RELEASED -1

LCGE_EXPORT int lcge_get_key(int key);
#ifdef __cplusplus
}
#endif

#endif
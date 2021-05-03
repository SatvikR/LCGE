// The MIT License (MIT)

// Copyright (c) 2021 Satvik Reddy

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#ifndef _INPUT_H
#define _INPUT_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Same values as GLFW keys */
#define LCGE_KEY_SPACE              32
#define LCGE_KEY_APOSTROPHE         39  /* ' */
#define LCGE_KEY_COMMA              44  /* , */
#define LCGE_KEY_MINUS              45  /* - */
#define LCGE_KEY_PERIOD             46  /* . */
#define LCGE_KEY_SLASH              47  /* / */
#define LCGE_KEY_0                  48
#define LCGE_KEY_1                  49
#define LCGE_KEY_2                  50
#define LCGE_KEY_3                  51
#define LCGE_KEY_4                  52
#define LCGE_KEY_5                  53
#define LCGE_KEY_6                  54
#define LCGE_KEY_7                  55
#define LCGE_KEY_8                  56
#define LCGE_KEY_9                  57
#define LCGE_KEY_SEMICOLON          59  /* ; */
#define LCGE_KEY_EQUAL              61  /* = */
#define LCGE_KEY_A                  65
#define LCGE_KEY_B                  66
#define LCGE_KEY_C                  67
#define LCGE_KEY_D                  68
#define LCGE_KEY_E                  69
#define LCGE_KEY_F                  70
#define LCGE_KEY_G                  71
#define LCGE_KEY_H                  72
#define LCGE_KEY_I                  73
#define LCGE_KEY_J                  74
#define LCGE_KEY_K                  75
#define LCGE_KEY_L                  76
#define LCGE_KEY_M                  77
#define LCGE_KEY_N                  78
#define LCGE_KEY_O                  79
#define LCGE_KEY_P                  80
#define LCGE_KEY_Q                  81
#define LCGE_KEY_R                  82
#define LCGE_KEY_S                  83
#define LCGE_KEY_T                  84
#define LCGE_KEY_U                  85
#define LCGE_KEY_V                  86
#define LCGE_KEY_W                  87
#define LCGE_KEY_X                  88
#define LCGE_KEY_Y                  89
#define LCGE_KEY_Z                  90
#define LCGE_KEY_LEFT_BRACKET       91  /* [ */
#define LCGE_KEY_BACKSLASH          92  /* \ */
#define LCGE_KEY_RIGHT_BRACKET      93  /* ] */
#define LCGE_KEY_GRAVE_ACCENT       96  /* ` */
#define LCGE_KEY_WORLD_1            161 /* non-US #1 */
#define LCGE_KEY_WORLD_2            162 /* non-US #2 */

#define LCGE_KEY_PRESSED  1
#define LCGE_KEY_RELEASED -1

int lcge_get_key(int key);
#ifdef __cplusplus
}
#endif

#endif
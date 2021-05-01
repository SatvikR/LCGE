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

#ifndef LCGE_H
#define LCGE_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct LCGE_window LCGE_window;

#define LCGE_WINDOW_OPEN   1
#define LCGE_WINDOW_CLOSED 0

#define LCGE_INIT_ERR -1
#define LCGE_INIT_OK   0

#define LCGE_RESIZEABLE     1
#define LCGE_NON_RESIZEABLE 0

#define LCGE_CONTEXT_ERR -1
#define LCGE_CONTEXT_OK   1

/**
 * Initializes LCGE
 *
 * Returns LCGE_INIT_ERR if there was an error
 * if not, returns LCGE_INIT_OK
 */
extern int lcge_init(const char *lcge_res_dir);

/**
 * Create a window and get back a handle
 *
 * width and height are in pixels
 * resizeable is either LCGE_RESIZEABLE or LCGE_NON_RESIZEABLE
 */
extern int lcge_create_context(unsigned int width, unsigned int height,
                               const char *title, int resizable);

/**
 * Returns LCGE_WINDOW_CLOSED if the window should be closed
 * if not, returns LCGE_WINDOW_OPEN
 */
extern int lcge_window_is_open();

/* Terminates LCGE */
extern void lcge_exit();

/* Clears the color buffer on the window */
extern void lcge_clear_window();

/* Swaps front and back buffers and polls for process events */
extern void lcge_update_window();

typedef struct LCGE_rect LCGE_rect;

/**
 * Takes in x, y coordinates and width and height
 * (0, 0) is considered to be at the top left of the window
 *
 * Width and height are in pixels.
 */
extern LCGE_rect* lcge_rect_load(float x, float y, float width, float height);
extern void lcge_rect_delete(LCGE_rect *rect);

/* Draw a rectangle given (r, g, b) color values */
extern void lcge_rect_draw(LCGE_rect *rect, float r, float g, float b);

#ifdef __cplusplus
}
#endif

#endif
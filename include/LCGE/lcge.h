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
extern void lcge_window_clear();

/* Swaps front and back buffers and polls for process events */
extern void lcge_window_update();

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
extern void lcge_rect_set(LCGE_rect *rect, float x, float y, float width,
                          float height);

typedef struct LCGE_image LCGE_image;

/* Loads image from filepath given top left coordinates */
extern LCGE_image* lcge_image_load(const char *filepath, float x, float y, float width,
                            float height);
extern void lcge_image_delete(LCGE_image *image);

extern void lcge_image_set(LCGE_image *image, float x, float y, float width,
                           float height);
extern void lcge_image_draw(LCGE_image *image);

extern float lcge_image_get_x(LCGE_image *image);
extern float lcge_image_get_y(LCGE_image *image);
extern float lcge_image_get_width(LCGE_image *image);
extern float lcge_image_get_height(LCGE_image *image);

typedef struct LCGE_clock LCGE_clock;

/* Creates a clock given a max fps */
extern LCGE_clock* lcge_clock_create(unsigned int fps);
extern void lcge_clock_delete(LCGE_clock *clock);

/* Ticks the clock to get as close to the max fps as possible */
extern void lcge_clock_tick(LCGE_clock *clock);

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
#define LCGE_KEY_ESCAPE             256
#define LCGE_KEY_ENTER              257
#define LCGE_KEY_TAB                258
#define LCGE_KEY_BACKSPACE          259
#define LCGE_KEY_INSERT             260
#define LCGE_KEY_DELETE             261
#define LCGE_KEY_RIGHT              262
#define LCGE_KEY_LEFT               263
#define LCGE_KEY_DOWN               264
#define LCGE_KEY_UP                 265
#define LCGE_KEY_PAGE_UP            266
#define LCGE_KEY_PAGE_DOWN          267
#define LCGE_KEY_HOME               268
#define LCGE_KEY_END                269
#define LCGE_KEY_CAPS_LOCK          280
#define LCGE_KEY_SCROLL_LOCK        281
#define LCGE_KEY_NUM_LOCK           282
#define LCGE_KEY_PRINT_SCREEN       283
#define LCGE_KEY_PAUSE              284
#define LCGE_KEY_F1                 290
#define LCGE_KEY_F2                 291
#define LCGE_KEY_F3                 292
#define LCGE_KEY_F4                 293
#define LCGE_KEY_F5                 294
#define LCGE_KEY_F6                 295
#define LCGE_KEY_F7                 296
#define LCGE_KEY_F8                 297
#define LCGE_KEY_F9                 298
#define LCGE_KEY_F10                299
#define LCGE_KEY_F11                300
#define LCGE_KEY_F12                301
#define LCGE_KEY_F13                302
#define LCGE_KEY_F14                303
#define LCGE_KEY_F15                304
#define LCGE_KEY_F16                305
#define LCGE_KEY_F17                306
#define LCGE_KEY_F18                307
#define LCGE_KEY_F19                308
#define LCGE_KEY_F20                309
#define LCGE_KEY_F21                310
#define LCGE_KEY_F22                311
#define LCGE_KEY_F23                312
#define LCGE_KEY_F24                313
#define LCGE_KEY_F25                314
#define LCGE_KEY_KP_0               320
#define LCGE_KEY_KP_1               321
#define LCGE_KEY_KP_2               322
#define LCGE_KEY_KP_3               323
#define LCGE_KEY_KP_4               324
#define LCGE_KEY_KP_5               325
#define LCGE_KEY_KP_6               326
#define LCGE_KEY_KP_7               327
#define LCGE_KEY_KP_8               328
#define LCGE_KEY_KP_9               329
#define LCGE_KEY_KP_DECIMAL         330
#define LCGE_KEY_KP_DIVIDE          331
#define LCGE_KEY_KP_MULTIPLY        332
#define LCGE_KEY_KP_SUBTRACT        333
#define LCGE_KEY_KP_ADD             334
#define LCGE_KEY_KP_ENTER           335
#define LCGE_KEY_KP_EQUAL           336
#define LCGE_KEY_LEFT_SHIFT         340
#define LCGE_KEY_LEFT_CONTROL       341
#define LCGE_KEY_LEFT_ALT           342
#define LCGE_KEY_LEFT_SUPER         343
#define LCGE_KEY_RIGHT_SHIFT        344
#define LCGE_KEY_RIGHT_CONTROL      345
#define LCGE_KEY_RIGHT_ALT          346
#define LCGE_KEY_RIGHT_SUPER        347
#define LCGE_KEY_MENU               348

#define LCGE_KEY_PRESSED  1
#define LCGE_KEY_RELEASED -1

extern int lcge_get_key(int key);
#ifdef __cplusplus
}
#endif

#endif
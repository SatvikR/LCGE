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

#ifndef LCGE_H
#define LCGE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#define LCGE_IMPORT __declspec(dllimport)
#else
#define LCGE_IMPORT
#endif

#define LCGE_WINDOW_OPEN   1
#define LCGE_WINDOW_CLOSED 0

#define LCGE_INIT_ERR -1
#define LCGE_INIT_OK  0

#define LCGE_RESIZEABLE	    1
#define LCGE_NON_RESIZEABLE 0

#define LCGE_CONTEXT_ERR -1
#define LCGE_CONTEXT_OK	 1

/**
 * @mainpage LCGE Docs
 *
 * @section intro What is LCGE?
 * A Lightweight C game engine built with OpenGL.
 *
 * @section build_info Build
 * @code{.sh}
 * git clone --recursive https://github.com/SatvikR/LCGE.git
 * cmake -B ./build .
 * cmake --build ./build
 * @endcode
 *
 * @section usage Basic Usage
 *
 * @code{.c}
 * #include <LCGE/lcge.h>
 *
 * int main(int argc, char const *argv[])
 * {
 *     // Initialize LCGE with the path to the res directory of LCGE
 *     if (lcge_init("vendor/LCGE/res") == LCGE_INIT_ERR)
 *     {
 *         lcge_exit();
 *         return -1;
 *     }
 *
 *     // Create a window
 *     int success = lcge_create_context(500, 500, "LCGE Example",
 *                                       LCGE_NON_RESIZEABLE);
 *
 *     // Create clock with a max fps
 *     LCGE_clock *clock = lcge_clock_create(60);
 *
 *     // Check if there was an error creating the window
 *     if (success == LCGE_CONTEXT_ERR)
 *     {
 *         lcge_exit();
 *         return -1;
 *     }
 *
 *     while (lcge_window_is_open())
 *     {
 *         // Do any udpating here
 *
 *         // Do any drawing here
 *         lcge_window_clear();
 *
 *         // Get ready for next iteration
 *         lcge_clock_tick(clock);
 *         lcge_window_udpate();
 *     }
 *
 *     // Clean up
 *     lcge_clock_delete(clock);
 *
 *     lcge_exit();
 *
 *     return 0;
 * }
 *
 * @endcode
 * @section license_info License
 *
 * LCGE is licensed under the GNU Lesser General Public License v2.1
 */

/**
 * @file lcge.h
 * @author Satvik Reddy
 * @brief Header file to include when using the LCGE engine
 *
 * LCGE is a 2D game engine written in C that uses the OpenGL graphics API.
 */

/**
 * @brief Initializes LCGE.
 *
 * This function will setup GLFW, as well as save the LCGE asset directory
 * in memory, which will be used later to load shaders
 */
LCGE_IMPORT extern int lcge_init(const char *lcge_res_dir);

/**
 * @brief Create a window and get back a handle.
 *
 * Takes in width and height in pixels
 * resizeable is either LCGE_RESIZEABLE or LCGE_NON_RESIZEABLE
 */
LCGE_IMPORT extern int lcge_create_context(unsigned int width,
					   unsigned int height,
					   const char *title, int resizable);

/**
 * @brief Returns whether or not the window is still open.
 *
 * Returns LCGE_WINDOW_CLOSED if the window should be closed
 * if not, returns LCGE_WINDOW_OPEN
 */
LCGE_IMPORT extern int lcge_window_is_open();

/**
 * @brief Exits lcge.
 *
 * Delets any leftover garbage from the engine. this DOES NOT delete user
 * created memory. Delete those yourself.
 */
LCGE_IMPORT extern void lcge_exit();

/**
 * @brief Clears the window.
 *
 * This will clear the color buffer and set the screen to all black
 */
LCGE_IMPORT extern void lcge_window_clear();

/**
 * @brief Updates the window and polls for events.
 */
LCGE_IMPORT extern void lcge_window_update();

/**
 * @brief A 2D rectangle.
 *
 * @see lcge_rect_load
 * @see lcge_rect_draw
 */
typedef struct LCGE_IMPORT LCGE_rect LCGE_rect;

/**
 * @brief Loads rectangle data and returns a handle.
 *
 * Takes in x, y coordinates and width and height
 * (0, 0) is considered to be at the top left of the window
 *
 * Width and height are in pixels.
 */
LCGE_IMPORT extern LCGE_rect *lcge_rect_load(float x, float y, float width,
					     float height);

/**
 * @brief Deletes a rectangle.
 */
LCGE_IMPORT extern void lcge_rect_delete(LCGE_rect *rect);

/**
 * @brief Draw a loaded rectangle to the screen.
 *
 * Takes r, g, b (0 to 255) color values as input.
 */
LCGE_IMPORT extern void lcge_rect_draw(LCGE_rect *rect, float r, float g,
				       float b);

/**
 * @brief Updates rectangle data for a loaded rectangle.
 *
 * This function allows you to set new x, y, width, and height values for your
 * rectangle
 */
LCGE_IMPORT extern void lcge_rect_set(LCGE_rect *rect, float x, float y,
				      float width, float height);

/**
 * @brief Rotates a loaded rectangle.
 *
 * Takes in an angle in degrees. Rotates counterclockwise.
 */
LCGE_IMPORT extern void lcge_rect_rotate(LCGE_rect *rect, float angle);

/**
 * @brief Gets the rectangle x value.
 */
LCGE_IMPORT extern float lcge_rect_get_x(LCGE_rect *rect);

/**
 * @brief Gets the rectangle y value.
 */
LCGE_IMPORT extern float lcge_rect_get_y(LCGE_rect *rect);

/**
 * @brief Gets the rectangle width.
 */
LCGE_IMPORT extern float lcge_rect_get_width(LCGE_rect *rect);

/**
 * @brief Gets the rectangle height.
 */
LCGE_IMPORT extern float lcge_rect_get_height(LCGE_rect *rect);

/**
 * @brief A 2D image
 *
 * @see lcge_image_load
 * @see lcge_image_draw
 */
typedef struct LCGE_IMPORT LCGE_image LCGE_image;

/**
 * @brief Loads an image from a file.
 *
 * Takes in a filepath, x/y coordinates, and a width and height to use when
 * drawing
 */
LCGE_IMPORT extern LCGE_image *lcge_image_load(const char *filepath, float x,
					       float y, float width,
					       float height);

/**
 * @brief Deletes an image.
 */
LCGE_IMPORT extern void lcge_image_delete(LCGE_image *image);

/**
 * @brief Rotates an image.
 *
 * Takes in the angle in degrees.
 */
LCGE_IMPORT extern void lcge_image_rotate(LCGE_image *image, float angle);

/**
 * @brief Sets new data for a loaded image.
 *
 * Lets you set x, y, width, and height values
 */
LCGE_IMPORT extern void lcge_image_set(LCGE_image *image, float x, float y,
				       float width, float height);

/**
 * @brief Draws a loaded image to the screen
 */
LCGE_IMPORT extern void lcge_image_draw(LCGE_image *image);

/**
 * @brief Gets image x.
 */
LCGE_IMPORT extern float lcge_image_get_x(LCGE_image *image);

/**
 * @brief Gets image y.
 */
LCGE_IMPORT extern float lcge_image_get_y(LCGE_image *image);

/**
 * @brief Gets image width.
 */
LCGE_IMPORT extern float lcge_image_get_width(LCGE_image *image);

/**
 * @brief Gets image height.
 */
LCGE_IMPORT extern float lcge_image_get_height(LCGE_image *image);

/**
 * @brief Basic FPS clock.
 *
 * @see lcge_clock_create
 * @see lcge_clock_tick
 */
typedef struct LCGE_IMPORT LCGE_clock LCGE_clock;

/**
 * @brief Creates a clock.
 *
 * Takes in an fps. The clock will make sure that your window's fps is as close
 * to the target fps as possible.
 */
LCGE_IMPORT extern LCGE_clock *lcge_clock_create(unsigned int fps);

/**
 * @brief Deletes a clock.
 */
LCGE_IMPORT extern void lcge_clock_delete(LCGE_clock *clock);

/**
 * @brief tickst the clock.
 *
 * Ticks the clock to get as close to the max fps as possible
 */
LCGE_IMPORT extern void lcge_clock_tick(LCGE_clock *clock);

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

/**
 * @brief Gets the input status of a key.
 *
 * Takes in a key code, eg. LCGE_KEY_<key_name>
 */
LCGE_IMPORT extern int lcge_get_key(int key);

/**
 * @brief A true type font.
 *
 * @see lcge_font_load
 */
typedef struct LCGE_IMPORT LCGE_font LCGE_font;

/**
 * @brief Loads a font.
 *
 * Takes in a path to a .ttf file and the height of characters to be rendered in
 * pixels.
 */
LCGE_IMPORT LCGE_font *lcge_font_load(const char *filepath, float height);

/**
 * @brief Deletes a font.
 */
LCGE_IMPORT extern void lcge_font_delete(LCGE_font *font);

/**
 * @brief 2D text.
 *
 * @see lcge_text_load
 * @see lcge_text_draw
 */
typedef struct LCGE_IMPORT LCGE_text LCGE_text;

/**
 * @brief Loads a 2D text struct.
 *
 * Takes in text as a string, x/y coordinates, and the font
 */
LCGE_IMPORT LCGE_text *lcge_text_load(const char *text, float x, float y,
				      LCGE_font *font);

/**
 * @brief Deletes a text struct.
 */
LCGE_IMPORT void lcge_text_delete(LCGE_text *text);

/**
 * @brief Draws 2D text.
 *
 * Takes in the loaded text, and r, g, b color values
 */
LCGE_IMPORT void lcge_text_draw(LCGE_text *text, float r, float g, float b);

/**
 * @brief Set new data for text.
 *
 * Lets you specify new x and y values
 */
LCGE_IMPORT void lcge_text_set(LCGE_text *text, float x, float y);

/**
 * @brief Gets x value of text.
 *
 * x value is the top left.
 */
LCGE_IMPORT float lcge_text_get_x(LCGE_text *text);

/**
 * @brief Gets y value of text.
 *
 * y value is the top left.
 */
LCGE_IMPORT float lcge_text_get_y(LCGE_text *text);

/**
 * @brief Gets the width of the text.
 */
LCGE_IMPORT float lcge_text_get_width(LCGE_text *text);

/**
 * @brief Gets the height of the text.
 */
LCGE_IMPORT float lcge_text_get_height(LCGE_text *text);

#ifdef __cplusplus
}
#endif

#endif
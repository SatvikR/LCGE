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

#include <LCGE/lcge.h>

#include <stdio.h>

#define WIN_WIDTH  800
#define WIN_HEIGHT 800

#define SPRITE_WIDTH  (326.0f * 0.75f)
#define SPRITE_HEIGHT (296.0f * 0.75f)

int main(int argc, char const *argv[])
{
    // Initialize LCGE
    if (lcge_init("res/") == LCGE_INIT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Create a window
    int success = lcge_create_context(WIN_WIDTH, WIN_HEIGHT,
                                      "LCGE Input Example (Use arrow keys)",
                                      LCGE_NON_RESIZEABLE);

    // Create clock with 60 max fps
    LCGE_clock *clock = lcge_clock_create(60);

    // Check if there was an error creating the window
    if (success == LCGE_CONTEXT_ERR)
    {
        lcge_exit();
        return -1;
    }

    float speed = 10;

    LCGE_image *image = lcge_image_load("tests/images/player_sprite.png",
                                        (WIN_WIDTH - SPRITE_WIDTH) / 2,
                                        (WIN_HEIGHT - SPRITE_HEIGHT) / 2,
                                        SPRITE_WIDTH, SPRITE_HEIGHT);
    LCGE_rect *background = lcge_rect_load(0, 0, WIN_WIDTH, WIN_HEIGHT);

    int count = 0;

    while (lcge_window_is_open())
    {
        // Do any drawing here
        lcge_window_clear();
        lcge_rect_draw(background, 29, 43, 83);
        float curr_x = lcge_image_get_x(image);
        float curr_y = lcge_image_get_y(image);

        if (lcge_get_key(LCGE_KEY_LEFT) == LCGE_KEY_PRESSED)
        {
            if (curr_x >= speed)
            {
                curr_x -= speed;
                lcge_image_set(image, curr_x, curr_y, SPRITE_WIDTH,
                               SPRITE_HEIGHT);
            }
        }
        if (lcge_get_key(LCGE_KEY_RIGHT) == LCGE_KEY_PRESSED)
        {
            if ((curr_x + SPRITE_WIDTH) <= (WIN_WIDTH - speed))
            {
                curr_x += speed;
                lcge_image_set(image, curr_x, curr_y, SPRITE_WIDTH,
                               SPRITE_HEIGHT);
            }
        }
        if (lcge_get_key(LCGE_KEY_UP) == LCGE_KEY_PRESSED)
        {
            if (curr_y >= speed)
            {
                curr_y -= speed;
                lcge_image_set(image, curr_x, curr_y, SPRITE_WIDTH,
                               SPRITE_HEIGHT);
            }
        }
        if (lcge_get_key(LCGE_KEY_DOWN) == LCGE_KEY_PRESSED)
        {
            if ((curr_y + SPRITE_HEIGHT) <= (WIN_HEIGHT - speed))
            {
                curr_y += speed;
                lcge_image_set(image, curr_x, curr_y, SPRITE_WIDTH,
                               SPRITE_HEIGHT);
            }
        }

        lcge_image_draw(image);

        // Get ready for next iteration
        lcge_clock_tick(clock);
        lcge_window_update();
    }
    lcge_clock_delete(clock);

    lcge_exit();

    return 0;
}

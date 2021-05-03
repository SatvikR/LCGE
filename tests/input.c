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
    int success = lcge_create_context(800, 800,
                                      "LCGE Input Example (Use Arrow Keys)",
                                      LCGE_NON_RESIZEABLE);

    // Create clock with 60 max fps
    LCGE_clock *clock = lcge_clock_create(60);

    // Check if there was an error creating the window
    if (success == LCGE_CONTEXT_ERR)
    {
        lcge_exit();
        return -1;
    }

    float x = (800 - SPRITE_WIDTH) / 2;
    float y = (800 - SPRITE_HEIGHT) / 2;
    float speed = 10;

    LCGE_image *image = lcge_image_load("tests/images/player_sprite.png", x, y,
                                        SPRITE_WIDTH, SPRITE_HEIGHT);

    while (lcge_window_is_open())
    {
        // Do any drawing here
        lcge_window_clear();
        if (lcge_get_key(LCGE_KEY_LEFT) == LCGE_KEY_PRESSED)
        {
            if (x >= speed)
            {
                x -= speed;
                lcge_image_set(image, x, y, SPRITE_WIDTH, SPRITE_HEIGHT);
            }
        }
        if (lcge_get_key(LCGE_KEY_RIGHT) == LCGE_KEY_PRESSED)
        {
            if ((x + SPRITE_WIDTH) <= (800 - speed))
            {
                x += speed;
                lcge_image_set(image, x, y, SPRITE_WIDTH, SPRITE_HEIGHT);
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

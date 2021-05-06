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

#define WIDTH  300
#define HEIGHT 300

int main(int argc, char const *argv[])
{
    // Initialize LCGE
    if (lcge_init("res/") == LCGE_INIT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Create a window
    int success = lcge_create_context(WIDTH, HEIGHT, "LCGE Ninjastar Example",
                                      LCGE_NON_RESIZEABLE);

    // Check if there was an error creating the window
    if (success == LCGE_CONTEXT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Create clock with 60 max fps
    LCGE_clock *clock = lcge_clock_create(60);

    LCGE_image *star1
                = lcge_image_load("tests/images/ninjastar.png", 0, 0, 100, 100);
    LCGE_image *star2
                = lcge_image_load("tests/images/ninjastar.png", 200, 0, 100, 100);

    LCGE_image *star3
                = lcge_image_load("tests/images/ninjastar.png", 100, 100, 100, 100);
    LCGE_image *star4
                = lcge_image_load("tests/images/ninjastar.png", 0, 200, 100, 100);
    LCGE_image *star5
                = lcge_image_load("tests/images/ninjastar.png", 200, 200, 100, 100);
    while (lcge_window_is_open())
    {
        lcge_image_rotate(star1, 5);
        lcge_image_rotate(star2, 5);
        lcge_image_rotate(star3, 5);
        lcge_image_rotate(star4, 5);
        lcge_image_rotate(star5, 5);
        lcge_window_clear();
        // Do any drawing here
        lcge_image_draw(star1);
        lcge_image_draw(star2);
        lcge_image_draw(star3);
        lcge_image_draw(star4);
        lcge_image_draw(star5);

        // Get ready for next iteration
        lcge_clock_tick(clock);
        lcge_window_update();
    }
    lcge_clock_delete(clock);
    lcge_image_delete(star1);
    lcge_image_delete(star2);
    lcge_image_delete(star3);
    lcge_image_delete(star4);
    lcge_image_delete(star5);

    lcge_exit();

    return 0;
}

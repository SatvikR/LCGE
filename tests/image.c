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

int main(int argc, char const *argv[])
{
    // Initialize LCGE
    if (lcge_init("res/") == LCGE_INIT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Create a window
    int success = lcge_create_context(1000, 800, "LCGE Image Example",
                                      LCGE_NON_RESIZEABLE);

    // Create clock with 60 max fps
    LCGE_clock *clock = lcge_clock_create(60);

    // Check if there was an error creating the window
    if (success == LCGE_CONTEXT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Load image_one
    LCGE_image *image_one = lcge_image_load("tests/images/player_sprite.png",
                                            100, 100);

    // Load image_two
    LCGE_image *image_two = lcge_image_load("tests/images/player_sprite.png",
                                            500, 400);
    while (lcge_window_is_open())
    {
        lcge_window_clear();
        // Do any drawing here
        lcge_image_draw(image_one);
        lcge_image_draw(image_two);

        // Get ready for next iteration
        lcge_clock_tick(clock);
        lcge_window_update();
    }

    // clean up
    lcge_image_delete(image_one);
    lcge_image_delete(image_two);

    lcge_clock_delete(clock);

    lcge_exit();

    return 0;
}

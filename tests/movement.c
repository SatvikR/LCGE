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
    int success = lcge_create_context(800, 800, "LCGE Movement Example",
                                      LCGE_NON_RESIZEABLE);

    // Create clock with 60 max fps
    LCGE_clock *clock = lcge_clock_create(60);

    // Check if there was an error creating the window
    if (success == LCGE_CONTEXT_ERR)
    {
        lcge_exit();
        return -1;
    }

    float x = 50;
    float inc = 10.0f;
    LCGE_rect *rect = lcge_rect_load(50, 325, 150, 200);

    float width = lcge_rect_get_width(rect);
    float height = lcge_rect_get_height(rect);

    while (lcge_window_is_open())
    {
        // update
        x += inc;

        // Reverse the rectangle once it hits the edge of the window
        if ((x + width) > 800 || x < 0)
            inc = -1.0f * inc;
        lcge_rect_set(rect, x, lcge_rect_get_y(rect), width, height);

        // draw
        lcge_window_clear();
        lcge_rect_draw(rect, 108, 92, 231);

        // Get ready for next iteration
        lcge_clock_tick(clock);
        lcge_window_update();
    }

    lcge_rect_delete(rect);
    lcge_clock_delete(clock);

    lcge_exit();

    return 0;
}

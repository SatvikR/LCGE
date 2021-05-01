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
    if (lcge_init() == LCGE_INIT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Create a window
    int success = lcge_create_context(800, 800, "LCGE Squares Example",
                                      LCGE_NON_RESIZEABLE);

    // Check if there was an error creating the window
    if (success == LCGE_CONTEXT_ERR)
    {
        lcge_exit();
        return -1;
    }

    // Load rectangle data
    LCGE_rect *rect_1 = lcge_rect_load(200, 200, 400, 400);
    LCGE_rect *rect_2 = lcge_rect_load(300, 300, 200, 200);

    while (lcge_window_is_open())
    {
        lcge_clear_window();

        // Draw rectangle with teal and purple
        lcge_rect_draw(rect_1, 0, 206, 201);
        lcge_rect_draw(rect_2, 108, 92, 231);

        // Get ready for next iteration
        lcge_update_window();
    }
    lcge_rect_delete(rect_1);    
    lcge_rect_delete(rect_2);    

    lcge_exit();

    return 0;
}
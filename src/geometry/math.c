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

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "math.h"
#include "../core.h"

static double to_rad(float deg) {
    return deg * (M_PI / 180.0f);
}

LCGE_coordinate lcge_coordinate_translate(float x, float y)
{
    LCGE_coordinate coordinate =
    {
        ((x / g_state->window->width * 2.0f) - 1.0f),
        (-1.0f * ((y / g_state->window->height * 2.0f) - 1.0f))
    };

    return coordinate;
}

LCGE_coordinate lcge_coordinate_rotate(float x0, float y0, float xc, float yc,
                                       float angle)
{
    float cos_a = (float)cos(to_rad(angle));
    float sin_a = (float)sin(to_rad(angle));

    LCGE_coordinate coordinate =
    {
        ((x0-xc)*cos_a - (y0-yc)*sin_a) + xc,
        (x0 - xc) * sin_a + (y0 - yc) * cos_a + yc
    };

    return coordinate;
}


float lcge_coordinate_distance(LCGE_coordinate v1, LCGE_coordinate v2)
{
    return (float)sqrt((float)pow(v2.x - v1.x, 2) + (float)pow(v2.y - v1.y, 2));
}

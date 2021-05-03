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

#ifndef _GEOMETRY_RECT_H_
#define _GEOMETRY_RECT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "../renderer/renderer.h"

typedef struct LCGE_rect
{
    LCGE_vertex_array *va;
    LCGE_vertex_buffer *vb;
    LCGE_index_buffer *ib;
    LCGE_shader *shader;
} LCGE_rect;

LCGE_rect* lcge_rect_load(float x, float y, float width, float height);
void lcge_rect_delete(LCGE_rect *rect);

void lcge_rect_draw(LCGE_rect *rect, float r, float g, float b);
void lcge_rect_set(LCGE_rect *rect, float x, float y, float width,
                          float height);

#ifdef __cplusplus
}
#endif

#endif
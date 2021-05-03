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

#ifndef _GEOMETRY_IMAGE_H
#define _GEOMETRY_IMAGE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "../renderer/renderer.h"

typedef struct LCGE_image
{
    LCGE_vertex_array *va;
    LCGE_vertex_buffer *vb;
    LCGE_index_buffer *ib;
    LCGE_shader *shader;
    LCGE_texture *texture;

    float x;
    float y;
    float width;
    float height;
} LCGE_image;

LCGE_image* lcge_image_load(const char *filepath, float x, float y, float width,
                            float height);
void lcge_image_delete(LCGE_image *image);

void lcge_image_set(LCGE_image *image, float x, float y, float width,
                    float height);
void lcge_image_draw(LCGE_image *image);

float lcge_image_get_x(LCGE_image *image);
float lcge_image_get_y(LCGE_image *image);
float lcge_image_get_width(LCGE_image *image);
float lcge_image_get_height(LCGE_image *image);

#ifdef __cplusplus
}
#endif

#endif
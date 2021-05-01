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

#ifndef _RENDERER_VERTEX_ARRAY_H
#define _RENDERER_VERTEX_ARRAY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <glad/glad.h>

#include "vertexbuffer.h"

typedef struct LCGE_vertex_array
{
    GLuint renderer_id;
} LCGE_vertex_array;

LCGE_vertex_array* lcge_vertex_array_create();

/* this is a fat function */
void lcge_vertex_array_layout(LCGE_vertex_array *vertex_array, 
                              LCGE_vertex_buffer *vertex_buffer, GLint size, 
                              GLenum type);

void lcge_vertex_array_bind(LCGE_vertex_array *vertex_array);
void lcge_vertex_array_unbind(LCGE_vertex_array *vertex_array);

void lcge_vertex_array_delete(LCGE_vertex_array *vertex_array);

#ifdef __cplusplus
}
#endif

#endif
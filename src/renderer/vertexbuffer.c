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

#include <stdlib.h>

#include "vertexbuffer.h"
#include "../glerror.h"

LCGE_vertex_buffer* lcge_vertex_buffer_create(void *data, GLuint size)
{
    LCGE_vertex_buffer *vb = malloc(sizeof(LCGE_vertex_buffer));

    GLCALL(glGenBuffers(1, &vb->renderer_id));
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, vb->renderer_id));
    GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));

    return vb;
}

void lcge_vertex_buffer_update(LCGE_vertex_buffer *vertex_buffer, void *data,
                               GLuint size)
{
    lcge_vertex_buffer_bind(vertex_buffer);
    GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
}

void lcge_vertex_buffer_delete(LCGE_vertex_buffer *vertex_buffer)
{
    GLCALL(glDeleteBuffers(1, &vertex_buffer->renderer_id));
    free(vertex_buffer);
}

void lcge_vertex_buffer_bind(LCGE_vertex_buffer *vertex_buffer)
{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->renderer_id));
}

void lcge_vertex_buffer_unbind(LCGE_vertex_buffer *vertex_buffer)
{
    GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
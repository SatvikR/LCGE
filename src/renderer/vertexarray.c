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

#include <glad/glad.h>

#include <stdlib.h>

#include "vertexarray.h"
#include "../glerror.h"

LCGE_vertex_array* lcge_vertex_array_create()
{
    LCGE_vertex_array *vertex_array = malloc(sizeof(LCGE_vertex_array));
    GLCALL(glGenVertexArrays(1, &vertex_array->renderer_id));

    return vertex_array;
}
void lcge_vertex_array_delete(LCGE_vertex_array *vertex_array)
{
    GLCALL(glDeleteVertexArrays(1, &vertex_array->renderer_id));
    free(vertex_array);
}

void lcge_vertex_array_layout(LCGE_vertex_array *vertex_array,
                              LCGE_vertex_buffer *vertex_buffer, GLint size,
                              GLenum type, GLuint index, GLuint offset,
                              GLsizei stride)
{
    lcge_vertex_array_bind(vertex_array);

    lcge_vertex_buffer_bind(vertex_buffer);

    GLCALL(glEnableVertexAttribArray(index));
    GLCALL(glVertexAttribPointer(index, size, type, GL_FALSE,
                                 stride, (const GLvoid*)offset));
}

void lcge_vertex_array_bind(LCGE_vertex_array *vertex_array)
{
    GLCALL(glBindVertexArray(vertex_array->renderer_id));
}

void lcge_vertex_array_unbind(LCGE_vertex_array *vertex_array)
{
    GLCALL(glBindVertexArray(0));
}
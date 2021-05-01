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

#include "renderer/vertexbuffer.h"
#include "renderer/vertexarray.h"
#include "renderer/indexbuffer.h"
#include "renderer/shader.h"
#include "glerror.h"

typedef struct LCGE_rect
{
    LCGE_vertex_array *va;
    LCGE_vertex_buffer *vb;
    LCGE_index_buffer *ib;
    LCGE_shader *shader;
} LCGE_rect;

LCGE_rect* lcge_load_square()
{
    GLfloat positions[8] = {
        -0.5f, -0.5f,  // bottom left
        -0.5f, 0.5f,   // top left
        0.5f, 0.5f,    // top right
        0.5f, -0.5f,   // bottom right
    };
    

    GLuint indeces[6] = {
        0, 1, 2, // triangle 1
        0, 2, 3  // triangle 2
    };
    

    LCGE_vertex_array *va = lcge_vertex_array_create();
    
    LCGE_vertex_buffer *vb = lcge_vertex_buffer_create(positions, 
                                                       8 * sizeof(GLfloat));
    

    lcge_vertex_array_layout(va, vb, 2, GL_FLOAT);
    
    LCGE_index_buffer *ib = lcge_index_buffer_create(6 * sizeof(GLuint), 
                                                     indeces);
    

    LCGE_shader *shader = lcge_shader_create("res/shaders/", "basic_geo");
    

    LCGE_rect *rect = malloc(sizeof(LCGE_rect));
    

    rect->va = va;
    rect->vb = vb;
    rect->ib = ib;
    rect->shader = shader;
    

    lcge_vertex_array_unbind(va);
    
    lcge_vertex_buffer_unbind(vb);
    
    lcge_index_buffer_unbind(ib);
    
    lcge_shader_unbind(shader);
    

    return rect;
}

void lcge_draw_square(LCGE_rect *rect)
{
    lcge_shader_bind(rect->shader);
    lcge_shader_set_uniform_4f(rect->shader, "u_color", 1.0f, 1.0f, 1.0f, 1.0f);

    printf("%d\n", rect->shader->renderer_id);

    lcge_vertex_array_bind(rect->va);
    lcge_index_buffer_bind(rect->ib);
    GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL));
}
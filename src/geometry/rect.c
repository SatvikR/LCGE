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

#include "../renderer/renderer.h"
#include "../glerror.h"
#include "../core.h"
#include "rect.h"
#include "math.h"


LCGE_rect* lcge_rect_load(float x, float y, float width, float height)
{
    LCGE_coordinate top_l = lcge_coordinate_translate(x, y);
    LCGE_coordinate top_r = lcge_coordinate_translate(x + width, y);
    LCGE_coordinate bottom_l = lcge_coordinate_translate(x, y + height);
    LCGE_coordinate bottom_r = lcge_coordinate_translate(x + width, y + height);

    GLfloat positions[8] = {
        bottom_l.x, bottom_r.y, // bottom left
        top_l.x, top_l.y ,      // top left
        top_r.x, top_r.y,       // top right
        bottom_r.x, bottom_r.y, // bottom right
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


    LCGE_rect *rect = malloc(sizeof(LCGE_rect));


    rect->va = va;
    rect->vb = vb;
    rect->ib = ib;
    rect->shader = g_state->basic_geo;


    lcge_vertex_array_unbind(va);

    lcge_vertex_buffer_unbind(vb);

    lcge_index_buffer_unbind(ib);

    lcge_shader_unbind(rect->shader);


    return rect;
}

void lcge_rect_draw(LCGE_rect *rect, float r, float g, float b)
{
    lcge_shader_bind(rect->shader);
    lcge_shader_set_uniform_4f(rect->shader, "u_color", r / 255.0f, g / 255.0f,
                               b / 255.0f, 1.0f);

    lcge_vertex_array_bind(rect->va);
    lcge_index_buffer_bind(rect->ib);
    GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL));
}

void lcge_rect_set(LCGE_rect *rect, float x, float y, float width,
                   float height)
{
    LCGE_coordinate top_l = lcge_coordinate_translate(x, y);
    LCGE_coordinate top_r = lcge_coordinate_translate(x + width, y);
    LCGE_coordinate bottom_l = lcge_coordinate_translate(x, y + height);
    LCGE_coordinate bottom_r = lcge_coordinate_translate(x + width, y + height);

    GLfloat positions[8] = {
        bottom_l.x, bottom_r.y, // bottom left
        top_l.x, top_l.y ,      // top left
        top_r.x, top_r.y,       // top right
        bottom_r.x, bottom_r.y, // bottom right
    };

    lcge_vertex_array_bind(rect->va);
    lcge_vertex_buffer_update(rect->vb, positions, 8 * sizeof(GLfloat));
}

void lcge_rect_delete(LCGE_rect *rect)
{
    // unbind everything
    lcge_vertex_array_unbind(rect->va);
    lcge_vertex_buffer_unbind(rect->vb);
    lcge_index_buffer_unbind(rect->ib);
    lcge_shader_unbind(rect->shader);

    // delete everthing
    lcge_vertex_array_delete(rect->va);
    lcge_vertex_buffer_delete(rect->vb);
    lcge_index_buffer_delete(rect->ib);

    // delete rectangle
    free(rect);
}
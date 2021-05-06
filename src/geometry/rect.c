/*
    LCGE - A Lightweight C Game Engine
    Copyright (C) 2021  Satvik Reddy

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
    USA

    Satvik Reddy <reddy.satvik@gmail.com>
*/

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
        bottom_l.x, bottom_l.y, // bottom left
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


    lcge_vertex_array_layout(va, vb, 2, GL_FLOAT, 0, 0, sizeof(GLfloat) * 2);

    LCGE_index_buffer *ib = lcge_index_buffer_create(6 * sizeof(GLuint),
                                                     indeces);


    LCGE_rect *rect = malloc(sizeof(LCGE_rect));


    rect->va = va;
    rect->vb = vb;
    rect->ib = ib;
    rect->shader = g_state->basic_geo;

    rect->top_l = top_l;
    rect->top_r = top_r;
    rect->bottom_l = bottom_l;
    rect->bottom_r = bottom_r;

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
        bottom_l.x, bottom_l.y, // bottom left
        top_l.x, top_l.y ,      // top left
        top_r.x, top_r.y,       // top right
        bottom_r.x, bottom_r.y, // bottom right
    };

    rect->top_l = top_l;
    rect->top_r = top_r;
    rect->bottom_l = bottom_l;
    rect->bottom_r = bottom_r;

    lcge_vertex_array_bind(rect->va);
    lcge_vertex_buffer_update(rect->vb, positions, 8 * sizeof(GLfloat));
}

void lcge_rect_rotate(LCGE_rect *rect, float angle)
{
    LCGE_coordinate center =
    {
        (rect->top_l.x + rect->bottom_r.x) / 2.0f,
        (rect->top_l.y + rect->bottom_r.y) / 2.0f,
    };

    LCGE_coordinate top_l
                    = lcge_coordinate_rotate(rect->top_l.x, rect->top_l.y,
                                             center.x, center.y, angle);
    LCGE_coordinate top_r
                    = lcge_coordinate_rotate(rect->top_r.x, rect->top_r.y,
                                             center.x, center.y, angle);
    LCGE_coordinate bottom_l
                    = lcge_coordinate_rotate(rect->bottom_l.x, rect->bottom_l.y,
                                             center.x, center.y, angle);
    LCGE_coordinate bottom_r
                    = lcge_coordinate_rotate(rect->bottom_r.x, rect->bottom_r.y,
                                             center.x, center.y, angle);
    GLfloat positions[8] = {
        bottom_l.x, bottom_l.y, // bottom left
        top_l.x, top_l.y ,      // top left
        top_r.x, top_r.y,       // top right
        bottom_r.x, bottom_r.y, // bottom right
    };

    rect->top_l = top_l;
    rect->top_r = top_r;
    rect->bottom_l = bottom_l;
    rect->bottom_r = bottom_r;

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

float lcge_rect_get_x(LCGE_rect *rect)
{
    return (rect->top_l.x + 1) / 2.0f * g_state->window->width;
}

float lcge_rect_get_y(LCGE_rect *rect)
{
    return (rect->top_l.y * -1.0f + 1.0f) * g_state->window->height / 2.0f;
}

float lcge_rect_get_width(LCGE_rect *rect)
{
    return lcge_coordinate_distance(rect->bottom_l, rect->bottom_r) / 2 *
                                                        g_state->window->width;
}

float lcge_rect_get_height(LCGE_rect *rect)
{
    return lcge_coordinate_distance(rect->bottom_l, rect->top_l) / 2 *
                                                        g_state->window->height;
}
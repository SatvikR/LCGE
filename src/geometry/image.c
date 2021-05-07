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
#include <stb/stb_image.h>

#include <stdlib.h>

#include "image.h"
#include "math.h"
#include "../core.h"
#include "../glerror.h"

LCGE_EXPORT LCGE_image* lcge_image_load(const char *filepath, float x, float y, float width,
                            float height)
{

    LCGE_texture *texture
                    = lcge_texture_create(filepath);

    LCGE_coordinate top_l
                    = lcge_coordinate_translate(x, y);
    LCGE_coordinate top_r
                    = lcge_coordinate_translate(x + width, y);
    LCGE_coordinate bottom_l
                    = lcge_coordinate_translate(x, y + height);
    LCGE_coordinate bottom_r
                    = lcge_coordinate_translate(x + width, y + height);

    GLfloat positions[16] = {
        bottom_l.x, bottom_l.y, 0.0f, 0.0f, // bottom left
        top_l.x, top_l.y, 0.0f, 1.0f,       // top left
        top_r.x, top_r.y, 1.0f, 1.0f,       // top right
        bottom_r.x, bottom_r.y, 1.0f, 0.0f  // bottom right
    };

    GLuint indeces[6] = {
        0, 1, 2, // triangle 1
        0, 2, 3  // triangle 2
    };

    LCGE_vertex_array *va = lcge_vertex_array_create();

    LCGE_vertex_buffer *vb = lcge_vertex_buffer_create(positions,
                                                       16 * sizeof(GLfloat));


    lcge_vertex_array_layout(va, vb, 2, GL_FLOAT, 0, 0, sizeof(GLfloat) * 4);
    lcge_vertex_array_layout(va, vb, 2, GL_FLOAT, 1,
                            sizeof(GLfloat) * 2, sizeof(GLfloat) * 4);

    LCGE_index_buffer *ib = lcge_index_buffer_create(6 * sizeof(GLuint),
                                                     indeces);

    LCGE_image *image = malloc(sizeof(LCGE_image));

    image->va = va;
    image->vb = vb;
    image->ib = ib;
    image->texture = texture;
    image->shader = g_state->texture;

    image->top_l = top_l;
    image->top_r = top_r;
    image->bottom_l = bottom_l;
    image->bottom_r = bottom_r;

    return image;
}

LCGE_EXPORT void lcge_image_delete(LCGE_image *image)
{
    // unbind everything
    lcge_vertex_array_unbind(image->va);
    lcge_vertex_buffer_unbind(image->vb);
    lcge_index_buffer_unbind(image->ib);
    lcge_texture_unbind(image->texture);
    lcge_shader_unbind(image->shader);

    // delete everthing
    lcge_vertex_array_delete(image->va);
    lcge_vertex_buffer_delete(image->vb);
    lcge_index_buffer_delete(image->ib);
    lcge_texture_delete(image->texture);

    free(image);
}

LCGE_EXPORT void lcge_image_set(LCGE_image *image, float x, float y, float width,
                    float height)
{
    LCGE_coordinate top_l
                    = lcge_coordinate_translate(x, y);
    printf("top_ly: %f, %f, %f\n", x, y, (lcge_coordinate_translate(x, y)).y);
    LCGE_coordinate top_r
                    = lcge_coordinate_translate(x + width, y);
    LCGE_coordinate bottom_l
                    = lcge_coordinate_translate(x, y + height);
    LCGE_coordinate bottom_r
                    = lcge_coordinate_translate(x + width, y + height);

    GLfloat positions[16] = {
        bottom_l.x, bottom_l.y, 0.0f, 0.0f, // bottom left
        top_l.x, top_l.y, 0.0f, 1.0f,       // top left
        top_r.x, top_r.y, 1.0f, 1.0f,       // top right
        bottom_r.x, bottom_r.y, 1.0f, 0.0f  // bottom right
    };

    lcge_vertex_array_bind(image->va);
    lcge_vertex_buffer_update(image->vb, positions, 16 * sizeof(GLfloat));

    image->top_l = top_l;
    image->top_r = top_r;
    image->bottom_l = bottom_l;
    image->bottom_r = bottom_r;
}

LCGE_EXPORT void lcge_image_draw(LCGE_image *image)
{
    lcge_texture_bind(image->texture);

    lcge_shader_bind(image->shader);
    lcge_shader_set_uniform_1i(image->shader, "u_texture", 0);

    lcge_vertex_array_bind(image->va);
    lcge_index_buffer_bind(image->ib);

    GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL));
}

LCGE_EXPORT void lcge_image_rotate(LCGE_image *image, float angle)
{
    LCGE_coordinate center =
    {
        (image->top_l.x + image->bottom_r.x) / 2.0f,
        (image->top_l.y + image->bottom_r.y) / 2.0f,
    };

    LCGE_coordinate top_l
                    = lcge_coordinate_rotate(image->top_l.x, image->top_l.y,
                                             center.x, center.y, angle);
    LCGE_coordinate top_r
                    = lcge_coordinate_rotate(image->top_r.x, image->top_r.y,
                                             center.x, center.y, angle);
    LCGE_coordinate bottom_l
                    = lcge_coordinate_rotate(image->bottom_l.x, image->bottom_l.y,
                                             center.x, center.y, angle);
    LCGE_coordinate bottom_r
                    = lcge_coordinate_rotate(image->bottom_r.x, image->bottom_r.y,
                                             center.x, center.y, angle);

    GLfloat positions[16] = {
        bottom_l.x, bottom_l.y, 0.0f, 0.0f, // bottom left
        top_l.x, top_l.y, 0.0f, 1.0f,       // top left
        top_r.x, top_r.y, 1.0f, 1.0f,       // top right
        bottom_r.x, bottom_r.y, 1.0f, 0.0f  // bottom right
    };

    lcge_vertex_array_bind(image->va);
    lcge_vertex_buffer_update(image->vb, positions, 16 * sizeof(GLfloat));

    image->top_l = top_l;
    image->top_r = top_r;
    image->bottom_l = bottom_l;
    image->bottom_r = bottom_r;
}

LCGE_EXPORT float lcge_image_get_x(LCGE_image *image)
{
    return (image->top_l.x + 1) / 2.0f * g_state->window->width;
}

LCGE_EXPORT float lcge_image_get_y(LCGE_image *image)
{
    return (image->top_l.y * -1.0f + 1.0f) * g_state->window->height / 2.0f;
}

LCGE_EXPORT float lcge_image_get_width(LCGE_image *image)
{
    return lcge_coordinate_distance(image->top_l, image->top_r) / 2.0f *
                                                        g_state->window->width;
}

LCGE_EXPORT float lcge_image_get_height(LCGE_image *image)
{
    return lcge_coordinate_distance(image->top_l, image->bottom_l) / 2.0f *
                                                        g_state->window->height;
}
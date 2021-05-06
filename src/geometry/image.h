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

#ifndef _GEOMETRY_IMAGE_H
#define _GEOMETRY_IMAGE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "math.h"
#include "../renderer/renderer.h"

typedef struct LCGE_image
{
    LCGE_vertex_array *va;
    LCGE_vertex_buffer *vb;
    LCGE_index_buffer *ib;
    LCGE_shader *shader;
    LCGE_texture *texture;

    LCGE_coordinate top_l;
    LCGE_coordinate top_r;
    LCGE_coordinate bottom_l;
    LCGE_coordinate bottom_r;
} LCGE_image;

LCGE_image* lcge_image_load(const char *filepath, float x, float y, float width,
                            float height);
void lcge_image_delete(LCGE_image *image);

void lcge_image_rotate(LCGE_image *image, float angle);
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
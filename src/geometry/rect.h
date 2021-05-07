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

#ifndef _GEOMETRY_RECT_H_
#define _GEOMETRY_RECT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "../renderer/renderer.h"
#include "../export.h"
#include "math.h"

LCGE_EXPORT typedef struct LCGE_rect
{
    LCGE_vertex_array *va;
    LCGE_vertex_buffer *vb;
    LCGE_index_buffer *ib;
    LCGE_shader *shader;

    LCGE_coordinate top_l;
    LCGE_coordinate top_r;
    LCGE_coordinate bottom_l;
    LCGE_coordinate bottom_r;
} LCGE_rect;

LCGE_EXPORT LCGE_rect* lcge_rect_load(float x, float y, float width, float height);
LCGE_EXPORT void lcge_rect_delete(LCGE_rect *rect);

LCGE_EXPORT void lcge_rect_draw(LCGE_rect *rect, float r, float g, float b);
LCGE_EXPORT void lcge_rect_set(LCGE_rect *rect, float x, float y, float width,
                   float height);

LCGE_EXPORT void lcge_rect_rotate(LCGE_rect *rect, float angle);
LCGE_EXPORT float lcge_rect_get_width(LCGE_rect *rect);
LCGE_EXPORT float lcge_rect_get_height(LCGE_rect *rect);
LCGE_EXPORT float lcge_rect_get_x(LCGE_rect *rect);
LCGE_EXPORT float lcge_rect_get_y(LCGE_rect *rect);

#ifdef __cplusplus
}
#endif

#endif
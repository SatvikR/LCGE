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

#ifndef _GEOMETRY_LINE_H
#define _GEOMETRY_LINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../renderer/renderer.h"
#include "../export.h"

typedef struct LCGE_line {
	LCGE_vertex_array *va;
	LCGE_vertex_buffer *vb;
	LCGE_shader *shader;
} LCGE_line;

LCGE_EXPORT LCGE_line *lcge_line_load(float x0, float y0, float x1, float y1);
LCGE_EXPORT void lcge_line_delete(LCGE_line *line);

LCGE_EXPORT void lcge_line_draw(LCGE_line *line, float r, float g, float b);
LCGE_EXPORT void lcge_line_set(LCGE_line *line, float x0, float y0, float x1,
			       float y1);

#ifdef __cplusplus
}
#endif

#endif
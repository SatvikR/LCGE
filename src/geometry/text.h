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

#ifndef _GEOMETRY_TEXT_H
#define _GEOMETRY_TEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../renderer/renderer.h"
#include "../export.h"

LCGE_EXPORT typedef struct LCGE_font {
	LCGE_ttftexture *texture;
} LCGE_font;

LCGE_EXPORT LCGE_font *lcge_font_load(const char *filepath, float height);
LCGE_EXPORT void lcge_font_delete(LCGE_font *font);

LCGE_EXPORT typedef struct LCGE_text {
	LCGE_font *font;

	size_t len;

	LCGE_shader *shader;
	LCGE_vertex_array **vas;
	LCGE_vertex_buffer **vbs;
	LCGE_index_buffer *ib;

	float x0;
	float y0;
	float x1;
	float y1;

	const char *data;
} LCGE_text;

LCGE_EXPORT LCGE_text *lcge_text_load(const char *text, float x, float y,
				      LCGE_font *font);
LCGE_EXPORT void lcge_text_delete(LCGE_text *text);

LCGE_EXPORT void lcge_text_draw(LCGE_text *text, float r, float g, float b);

LCGE_EXPORT void lcge_text_set(LCGE_text *text, const char *n_text, float x,
			       float y);

LCGE_EXPORT float lcge_text_get_x(LCGE_text *text);
LCGE_EXPORT float lcge_text_get_y(LCGE_text *text);
LCGE_EXPORT float lcge_text_get_width(LCGE_text *text);
LCGE_EXPORT float lcge_text_get_height(LCGE_text *text);

#ifdef __cplusplus
}
#endif

#endif
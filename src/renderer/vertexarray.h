/*
 * LCGE - A Lightweight C Game Engine
 * Copyright (C) 2021  Satvik Reddy
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 * USA
 *
 * Satvik Reddy <reddy.satvik@gmail.com>
 */

#ifndef _RENDERER_VERTEX_ARRAY_H
#define _RENDERER_VERTEX_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <glad/glad.h>

#include "vertexbuffer.h"

typedef struct LCGE_vertex_array {
	GLuint renderer_id;
} LCGE_vertex_array;

LCGE_vertex_array *lcge_vertex_array_create();

/* this is a fat function */
void lcge_vertex_array_layout(LCGE_vertex_array *vertex_array,
			      LCGE_vertex_buffer *vertex_buffer, GLint size,
			      GLenum type, GLuint index, GLuint offset,
			      GLsizei stride);

void lcge_vertex_array_bind(LCGE_vertex_array *vertex_array);
void lcge_vertex_array_unbind(LCGE_vertex_array *vertex_array);

void lcge_vertex_array_delete(LCGE_vertex_array *vertex_array);

#ifdef __cplusplus
}
#endif

#endif
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

#include <glad/glad.h>

#include <stdlib.h>

#include "vertexarray.h"
#include "../glerror.h"

LCGE_vertex_array *lcge_vertex_array_create()
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
	GLCALL(glVertexAttribPointer(index, size, type, GL_FALSE, stride,
				     (const void *)(uintptr_t)offset));
}

void lcge_vertex_array_bind(LCGE_vertex_array *vertex_array)
{
	GLCALL(glBindVertexArray(vertex_array->renderer_id));
}

void lcge_vertex_array_unbind(LCGE_vertex_array *vertex_array)
{
	GLCALL(glBindVertexArray(0));
}
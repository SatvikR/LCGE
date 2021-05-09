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

#ifndef _RENDERER_VERTEX_BUFFER_H
#define _RENDERER_VERTEX_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <glad/glad.h>

typedef struct LCGE_vertex_buffer {
	GLuint renderer_id;
} LCGE_vertex_buffer;

LCGE_vertex_buffer *lcge_vertex_buffer_create(void *data, GLuint size);

void lcge_vertex_buffer_delete(LCGE_vertex_buffer *vertex_buffer);

void lcge_vertex_buffer_bind(LCGE_vertex_buffer *vertex_buffer);
void lcge_vertex_buffer_unbind(LCGE_vertex_buffer *vertex_buffer);

void lcge_vertex_buffer_update(LCGE_vertex_buffer *vertex_buffer, void *data,
			       GLuint size);
#ifdef __cplusplus
}
#endif

#endif
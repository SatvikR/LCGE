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

#include "indexbuffer.h"
#include "../glerror.h"

LCGE_index_buffer *lcge_index_buffer_create(GLsizeiptr size, const GLvoid *data)
{
	LCGE_index_buffer *index_buffer = malloc(sizeof(index_buffer));

	GLCALL(glGenBuffers(1, &index_buffer->renderer_id));
	lcge_index_buffer_bind(index_buffer);
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data,
			    GL_DYNAMIC_DRAW));

	return index_buffer;
}

void lcge_index_buffer_update(LCGE_index_buffer *index_buffer, GLsizeiptr size,
			      const GLvoid *data)
{
	lcge_index_buffer_bind(index_buffer);
	GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data,
			    GL_DYNAMIC_DRAW));
}

void lcge_index_buffer_delete(LCGE_index_buffer *index_buffer)
{
	GLCALL(glDeleteBuffers(1, &index_buffer->renderer_id));
	free(index_buffer);
}

void lcge_index_buffer_bind(LCGE_index_buffer *index_buffer)
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
			    index_buffer->renderer_id));
}

void lcge_index_buffer_unbind(LCGE_index_buffer *index_buffer)
{
	GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

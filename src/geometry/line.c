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

#include "line.h"
#include "math.h"
#include "../core.h"
#include "../glerror.h"


LCGE_EXPORT LCGE_line *lcge_line_load(float x0, float y0, float x1, float y1)
{
	LCGE_line *line = calloc(1, sizeof(LCGE_line));

	LCGE_coordinate pos0 = lcge_coordinate_translate(x0, y0);
	LCGE_coordinate pos1 = lcge_coordinate_translate(x1, y1);

	GLfloat positions[4] = {
		pos0.x, pos0.y, // First point
		pos1.x, pos1.y // Second point
	};

	line->va = lcge_vertex_array_create();
	line->vb = lcge_vertex_buffer_create((void *)positions,
					     sizeof(GLfloat) * 4);

	lcge_vertex_array_layout(line->va, line->vb, 2, GL_FLOAT, 0, 0,
				 sizeof(GLfloat) * 2);

	line->shader = g_state->basic_geo;
	return line;
}

LCGE_EXPORT void lcge_line_delete(LCGE_line *line)
{
	lcge_vertex_array_unbind(line->va);
	lcge_vertex_buffer_unbind(line->vb);
	lcge_shader_unbind(line->shader);

	lcge_vertex_array_delete(line->va);
	lcge_vertex_buffer_delete(line->vb);

	free(line);
}

LCGE_EXPORT void lcge_line_draw(LCGE_line *line, float r, float g, float b)
{
	lcge_vertex_array_bind(line->va);

	lcge_shader_bind(line->shader);
	lcge_shader_set_uniform_4f(line->shader, "u_color", r / 255.0f,
				  g / 255.0f, b / 255.0f, 1.0f);

	GLCALL(glDrawArrays(GL_LINES, 0, 2));
}

LCGE_EXPORT void lcge_line_set(LCGE_line *line, float x0, float y0, float x1,
			       float y1)
{
	LCGE_coordinate pos0 = lcge_coordinate_translate(x0, y0);
	LCGE_coordinate pos1 = lcge_coordinate_translate(x1, y1);

	GLfloat positions[4] = {
		pos0.x, pos0.y, // First point
		pos1.x, pos1.y // Second point
	};

	lcge_vertex_buffer_update(line->vb, positions, sizeof(GLfloat) * 4);
}
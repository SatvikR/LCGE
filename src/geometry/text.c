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
#include <stdio.h>

#include <string.h>

#include "text.h"
#include "math.h"
#include "../core.h"
#include "../glerror.h"

LCGE_EXPORT LCGE_font *lcge_font_load(const char *filepath, float height)
{
	LCGE_font *font = calloc(1, sizeof(LCGE_font));

	font->texture = lcge_ttftexture_load(filepath, height);

	return font;
}

LCGE_EXPORT void lcge_font_delete(LCGE_font *font)
{
	lcge_ttftexture_delete(font->texture);
	free(font);
}

LCGE_EXPORT LCGE_text *lcge_text_load(const char *text, float x, float y,
				      LCGE_font *font)
{
	LCGE_text *m_text = calloc(1, sizeof(LCGE_text));

	size_t len = strlen(text);

	m_text->vbs = calloc(1, sizeof(LCGE_vertex_buffer *) * len);
	m_text->vas = calloc(1, sizeof(LCGE_vertex_array *) * len);
	m_text->font = font;
	m_text->shader = g_state->text;
	m_text->len = len;
	m_text->data = text;

	int i;
	for (i = 0; i < len; i++) {
		stbtt_aligned_quad q = lcge_ttftexture_get_char(
			font->texture, text[i], &x, &y);

		if (i == 0) {
			m_text->x0 = q.x0;
			m_text->y0 = q.y0;
		} else if (i == (len - 1)) {
			m_text->x1 = q.x1;
			m_text->y1 = q.y1;
		}

		LCGE_coordinate top_l = lcge_coordinate_translate(q.x0, q.y0);
		LCGE_coordinate top_r = lcge_coordinate_translate(q.x1, q.y0);
		LCGE_coordinate bottom_l =
			lcge_coordinate_translate(q.x0, q.y1);
		LCGE_coordinate bottom_r =
			lcge_coordinate_translate(q.x1, q.y1);

		GLfloat positions[16] = {
			bottom_l.x, bottom_l.y, q.s0, q.t1, // bottom left
			top_l.x,    top_l.y,	q.s0, q.t0, // top left
			top_r.x,    top_r.y,	q.s1, q.t0, // top right
			bottom_r.x, bottom_r.y, q.s1, q.t1 // bottom right
		};

		m_text->vas[i] = lcge_vertex_array_create();

		m_text->vbs[i] = lcge_vertex_buffer_create(
			positions, 16 * sizeof(GLfloat));

		lcge_vertex_array_layout(m_text->vas[i], m_text->vbs[i], 2,
					 GL_FLOAT, 0, 0, sizeof(GLfloat) * 4);
		lcge_vertex_array_layout(m_text->vas[i], m_text->vbs[i], 2,
					 GL_FLOAT, 1, sizeof(GLfloat) * 2,
					 sizeof(GLfloat) * 4);
	}

	GLuint indeces[6] = {
		0, 1, 2, // triangle 1
		0, 2, 3 // triangle 2
	};

	m_text->ib = lcge_index_buffer_create(sizeof(GLfloat) * 6, indeces);

	return m_text;
}

LCGE_EXPORT void lcge_text_delete(LCGE_text *text)
{
	// unbind all
	lcge_ttftexture_unbind(text->font->texture);
	lcge_vertex_array_unbind((LCGE_vertex_array *)NULL);
	lcge_index_buffer_unbind(text->ib);
	lcge_shader_unbind(text->shader);

	// delete all
	lcge_index_buffer_delete(text->ib);

	int i;
	for (i = 0; i < text->len; i++) {
		lcge_vertex_buffer_delete(text->vbs[i]);
		lcge_vertex_array_delete(text->vas[i]);
	}

	free(text->vas);
	free(text->vbs);
	free(text);
}

LCGE_EXPORT void lcge_text_draw(LCGE_text *text, float r, float g, float b)
{
	lcge_ttftexture_bind(text->font->texture);
	lcge_index_buffer_bind(text->ib);
	lcge_shader_bind(text->shader);

	lcge_shader_set_uniform_1i(text->shader, "u_texture", 0);
	lcge_shader_set_inform_3f(text->shader, "u_color", r / 255.0f,
				  g / 255.0f, b / 255.0f);

	int i;
	for (i = 0; i < text->len; i++) {
		lcge_vertex_array_bind(text->vas[i]);
		lcge_index_buffer_bind(text->ib);
		GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL));
	}
}

LCGE_EXPORT void lcge_text_set(LCGE_text *text, float x, float y)
{
	int i;
	for (i = 0; i < text->len; i++) {
		stbtt_aligned_quad q = lcge_ttftexture_get_char(
			text->font->texture, text->data[i], &x, &y);

		if (i == 0) {
			text->x0 = q.x0;
			text->y0 = q.y0;
		} else if (i == (text->len - 1)) {
			text->x1 = q.x1;
			text->y1 = q.y1;
		}

		LCGE_coordinate top_l = lcge_coordinate_translate(q.x0, q.y0);
		LCGE_coordinate top_r = lcge_coordinate_translate(q.x1, q.y0);
		LCGE_coordinate bottom_l =
			lcge_coordinate_translate(q.x0, q.y1);
		LCGE_coordinate bottom_r =
			lcge_coordinate_translate(q.x1, q.y1);

		GLfloat positions[16] = {
			bottom_l.x, bottom_l.y, q.s0, q.t1, // bottom left
			top_l.x,    top_l.y,	q.s0, q.t0, // top left
			top_r.x,    top_r.y,	q.s1, q.t0, // top right
			bottom_r.x, bottom_r.y, q.s1, q.t1 // bottom right
		};

		lcge_vertex_array_bind(text->vas[i]);
		lcge_vertex_buffer_update(text->vbs[i], positions,
					  16 * sizeof(GLfloat));
	}
}

LCGE_EXPORT float lcge_text_get_x(LCGE_text *text)
{
	return text->x0;
}

LCGE_EXPORT float lcge_text_get_y(LCGE_text *text)
{
	return text->y0;
}

LCGE_EXPORT float lcge_text_get_width(LCGE_text *text)
{
	return text->x1 - text->x0;
}

LCGE_EXPORT float lcge_text_get_height(LCGE_text *text)
{
	return text->y1 - text->y0;
}
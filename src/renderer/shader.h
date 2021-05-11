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

#ifndef _RENDERER_SHADER_H
#define _RENDERER_SHADER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LCGE_shader {
	GLuint renderer_id;
	struct {
		char *key;
		GLint value;
	} * uniform_cache;
} LCGE_shader;

LCGE_shader *lcge_shader_create(const char *path, const char *name);
void lcge_shader_delete(LCGE_shader *shader);

void lcge_shader_bind(LCGE_shader *shader);
void lcge_shader_unbind(LCGE_shader *shader);

GLint lcge_shader_set_uniform_4f(LCGE_shader *shader, const char *name,
				 GLfloat a, GLfloat b, GLfloat c, GLfloat d);

GLint lcge_shader_set_uniform_1i(LCGE_shader *shader, const char *name,
				 GLint v0);

GLint lcge_shader_set_inform_3f(LCGE_shader *shader, const char *name,
				GLfloat v0, GLfloat v1, GLfloat v2);

#ifdef __cplusplus
}
#endif

#endif
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
#include <stb/stb_ds.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "shader.h"
#include "../glerror.h"

#define UNIFORM_CACHE_DEFAULT -2

static GLuint compile_shader(const char *path, GLenum type)
{
	FILE *f;
	char *text;
	unsigned long len;

	f = fopen(path, "rb");
	if (f == NULL) {
		fprintf(stderr, "Shader %s failed to load\n", path);
		exit(1);
	}

	fseek(f, 0, SEEK_END);
	len = ftell(f);

	// Make sure there is some shader code
	ASSERT((len > 0));

	fseek(f, 0, SEEK_SET);
	text = calloc(1, sizeof(char) * len);
	fread(text, 1, len, f);
	fclose(f);

	GLuint id = glCreateShader(type);
	glShaderSource(id, 1, (const GLchar **)&text, (const GLint *)&len);
	glCompileShader(id);

	GLint status;
	glGetShaderiv(id, GL_COMPILE_STATUS, &status);

	if (status == GL_FALSE) {
		GLint len;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
		GLchar *error_message = malloc(sizeof(char) * len);

		glGetShaderInfoLog(id, len, &len, error_message);

		fprintf(stderr,
			"Compilation of shader %s failed. Error message: %s\n",
			path, error_message);

		glDeleteShader(id);

		free(error_message);
	}

	free(text);

	return id;
}

LCGE_shader *lcge_shader_create(const char *path, const char *name)
{
	size_t path_len = strlen(path);
	size_t name_len = strlen(name);

	char *vert_full_path =
		calloc(1, sizeof(char) * (path_len + name_len + 11));
	char *frag_full_path =
		calloc(1, sizeof(char) * (path_len + name_len + 11));

	strcat(vert_full_path, path);
	strcat(vert_full_path, name);
	strcat(vert_full_path, ".vert.glsl");

	strcat(frag_full_path, path);
	strcat(frag_full_path, name);
	strcat(frag_full_path, ".frag.glsl");

	LCGE_shader *shader = malloc(sizeof(LCGE_shader));

	GLuint program = glCreateProgram();
	GLuint vs = compile_shader(vert_full_path, GL_VERTEX_SHADER);
	GLuint fs = compile_shader(frag_full_path, GL_FRAGMENT_SHADER);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	shader->renderer_id = program;
	shader->uniform_cache = NULL;
	shdefault(shader->uniform_cache, UNIFORM_CACHE_DEFAULT);

	glDeleteShader(vs);
	glDeleteShader(fs);

	free(vert_full_path);
	free(frag_full_path);

	return shader;
}

void lcge_shader_delete(LCGE_shader *shader)
{
	GLCALL(glDeleteProgram(shader->renderer_id));

	shfree(shader->uniform_cache);
	free(shader);
}

void lcge_shader_bind(LCGE_shader *shader)
{
	GLCALL(glUseProgram(shader->renderer_id));
}

void lcge_shader_unbind(LCGE_shader *shader)
{
	GLCALL(glUseProgram(0));
}

static GLint get_uniform_location(LCGE_shader *shader, const char *name)
{
	GLint location;
	location = shget(shader->uniform_cache, name);
	if (location == UNIFORM_CACHE_DEFAULT) {
		GLCALL(location =
			       glGetUniformLocation(shader->renderer_id, name));
		shput(shader->uniform_cache, name, location);
	}

	if (location == -1) {
		printf("Warning: uniform %s does not exist\n", name);
	}

	return location;
}

GLint lcge_shader_set_uniform_4f(LCGE_shader *shader, const char *name,
				 GLfloat a, GLfloat b, GLfloat c, GLfloat d)
{
	GLint location = get_uniform_location(shader, name);

	GLCALL(glUniform4f(location, a, b, c, d));
	return location;
}

GLint lcge_shader_set_uniform_1i(LCGE_shader *shader, const char *name,
				 GLint v0)
{
	GLint location = get_uniform_location(shader, name);

	GLCALL(glUniform1i(location, v0));
	return location;
}

GLint lcge_shader_set_inform_3f(LCGE_shader *shader, const char *name,
				GLfloat v0, GLfloat v1, GLfloat v2)
{
	GLint location = get_uniform_location(shader, name);

	GLCALL(glUniform3f(location, v0, v1, v2));
	return location;
}
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
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include "window.h"
#include "core.h"
#include "glerror.h"

LCGE_EXPORT int lcge_create_context(unsigned int width, unsigned int height,
				    const char *title, int resizable)
{
	// Argument validation
	if (resizable != LCGE_RESIZEABLE && resizable != LCGE_NON_RESIZEABLE)
		return LCGE_CONTEXT_ERR;

	LCGE_window *window = malloc(sizeof(LCGE_window));

	window->width = width;
	window->height = height;

	// Turn off vsync for unlimited FPS
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, resizable);
	window->_window = glfwCreateWindow(window->width, window->height, title,
					   NULL, NULL);

	g_state->window = window;
	glfwMakeContextCurrent(window->_window);

	// Load opengl functions
	int gladInitRes = gladLoadGL();
	if (!gladInitRes) {
		glfwDestroyWindow(window->_window);
		glfwTerminate();
		return LCGE_CONTEXT_ERR;
	}

	// Enable blending
	GLCALL(glEnable(GL_BLEND));
	GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	// Enable smooth lines
	GLCALL(glEnable(GL_LINE_SMOOTH));
	GLCALL(glHint(GL_LINE_SMOOTH_HINT, GL_NICEST));

	// Store the total texture slots
	GLCALL(glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS,
			     &g_state->total_textures));

	g_state->next_available_texture = 0;

	printf("OpenGL %s\n", glGetString(GL_VERSION));

	// Load shaders
	g_state->basic_geo = lcge_shader_create(g_state->res_dir, "basic_geo");
	g_state->texture = lcge_shader_create(g_state->res_dir, "texture");
	g_state->text = lcge_shader_create(g_state->res_dir, "text");

	return LCGE_CONTEXT_OK;
}

LCGE_EXPORT int lcge_window_is_open()
{
	return !glfwWindowShouldClose(g_state->window->_window);
}

LCGE_EXPORT void lcge_window_clear()
{
	GLCALL(glClear(GL_COLOR_BUFFER_BIT));
}

LCGE_EXPORT void lcge_window_update()
{
	glfwSwapBuffers(g_state->window->_window);
	glfwPollEvents();
}
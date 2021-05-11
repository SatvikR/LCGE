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

#ifndef _WINDOW_H
#define _WINDOW_H

#ifdef __cplusplus
extern "C" {
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "export.h"

#define LCGE_WINDOW_OPEN   1
#define LCGE_WINDOW_CLOSED 0

#define LCGE_INIT_ERR -1
#define LCGE_INIT_OK  0

#define LCGE_RESIZEABLE	    1
#define LCGE_NON_RESIZEABLE 0

#define LCGE_CONTEXT_ERR -1
#define LCGE_CONTEXT_OK	 1

typedef LCGE_EXPORT struct LCGE_window {
	unsigned int width;
	unsigned int height;

	GLFWwindow *_window;
} LCGE_window;

LCGE_EXPORT int lcge_create_context(unsigned int width, unsigned int height,
				    const char *title, int resizable);

LCGE_EXPORT int lcge_window_is_open();

LCGE_EXPORT void lcge_window_clear();

LCGE_EXPORT void lcge_window_update();

#ifdef __cplusplus
}
#endif

#endif
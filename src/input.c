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

#include "input.h"
#include "core.h"

LCGE_EXPORT int lcge_get_key(int key)
{
	// GLFW keys are mapped the same way as LCGE keys
	int state = glfwGetKey(g_state->window->_window, key);
	if (state == GLFW_PRESS || state == GLFW_REPEAT)
		return LCGE_KEY_PRESSED;
	return LCGE_KEY_RELEASED;
}

LCGE_EXPORT int lcge_get_mouse_button(int button)
{
	int state = glfwGetMouseButton(g_state->window->_window, button);
	if (state == GLFW_PRESS) {
		return LCGE_MOUSE_BUTTON_PRESSED;
	}
	return LCGE_MOUSE_BUTTON_RELEASED;
}
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

#include "clock.h"

LCGE_EXPORT LCGE_clock *lcge_clock_create(unsigned int fps)
{
	LCGE_clock *clock = calloc(1, sizeof(LCGE_clock));

	// Initialize time
	clock->prev_time = glfwGetTime();
	clock->fps = fps;

	return clock;
}

LCGE_EXPORT void lcge_clock_delete(LCGE_clock *clock)
{
	free(clock);
}

LCGE_EXPORT void lcge_clock_tick(LCGE_clock *clock)
{
	// Halt until the delta time is greater than or equal to the target fps
	while (glfwGetTime() - clock->prev_time < (1.0f / clock->fps))
		;

	clock->prev_time = glfwGetTime();
}
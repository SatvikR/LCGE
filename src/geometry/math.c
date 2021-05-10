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

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "math.h"
#include "../core.h"

static double to_rad(float deg)
{
	return deg * (M_PI / 180.0f);
}

LCGE_coordinate lcge_coordinate_translate(float x, float y)
{
	LCGE_coordinate coordinate = {
		x / g_state->window->width * 2.0f - 1.0f,
		-1.0f * (y / g_state->window->height * 2.0f - 1.0f)
	};

	return coordinate;
}

LCGE_coordinate lcge_coordinate_rotate(float x0, float y0, float xc, float yc,
				       float angle)
{
	float cos_a = (float)cos(to_rad(angle));
	float sin_a = (float)sin(to_rad(angle));

	LCGE_coordinate coordinate = {
		(x0 - xc) * cos_a - (y0 - yc) * sin_a + xc,
		(x0 - xc) * sin_a + (y0 - yc) * cos_a + yc
	};

	return coordinate;
}

float lcge_coordinate_distance(LCGE_coordinate v1, LCGE_coordinate v2)
{
	return (float)sqrt((float)pow(v2.x - v1.x, 2) +
			   (float)pow(v2.y - v1.y, 2));
}

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

#ifndef _GEOMETRY_MATH_H
#define _GEOMETRY_MATH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <glad/glad.h>

// Wrapper for a 2D coordinate
typedef struct LCGE_coordinate {
	GLfloat x;
	GLfloat y;
} LCGE_coordinate;

LCGE_coordinate lcge_coordinate_translate(float x, float y);
LCGE_coordinate lcge_coordinate_rotate(float x0, float y0, float xc, float yc,
				       float angle);
float lcge_coordinate_distance(LCGE_coordinate v1, LCGE_coordinate v2);

#ifdef __cplusplus
}
#endif

#endif
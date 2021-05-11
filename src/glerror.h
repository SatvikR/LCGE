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

#ifndef _GLERROR_H
#define _GLERROR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>
#include "debug.h"

#ifndef NDEBUG
#ifdef _MSC_VER
#define ASSERT(x)                                                              \
	if (!(x))                                                              \
		__debugbreak();
#else
#include <signal.h>
#define ASSERT(x)                                                              \
	if (!(x))                                                              \
		raise(SIGTRAP);
#endif
#define GLCALL(x)                                                              \
	GL_clear_error();                                                      \
	x;                                                                     \
	ASSERT(GL_log_call(__FILE__, __LINE__))
#else
#define ASSERT(x) x;
#define GLCALL(x) x;
#endif

#include "export.h"

LCGE_EXPORT void GL_clear_error();

LCGE_EXPORT bool GL_log_call(const char *file, int line);

#ifdef __cplusplus
}
#endif
#endif
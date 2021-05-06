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

#ifndef _CORE_H
#define _CORE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <LCGE/lcge.h>
#include "window.h"
#include "renderer/shader.h"

typedef struct LCGE_state
{
    int initialized;
    char *res_dir;
    LCGE_window *window;
    LCGE_shader *basic_geo;
    LCGE_shader *texture;
} LCGE_state;

extern LCGE_state *g_state;

int lcge_init(const char *lcge_res_dir);
void lcge_exit();

#ifdef __cplusplus
}
#endif

#endif
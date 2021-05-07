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

#ifndef _CLOCK_H
#define _CLOCK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "export.h"

typedef LCGE_EXPORT struct LCGE_clock
{
    double prev_time;
    unsigned int fps;
} LCGE_clock;

LCGE_EXPORT LCGE_clock* lcge_clock_create(unsigned int fps);
LCGE_EXPORT void lcge_clock_delete(LCGE_clock *clock);

LCGE_EXPORT void lcge_clock_tick(LCGE_clock *clock);

#ifdef __cplusplus
}
#endif

#endif
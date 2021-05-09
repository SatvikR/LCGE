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


#ifndef _RENDERER_TEXTURE_H
#define _RENDERER_TEXTURE_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct LCGE_texture
{
    int width;
    int height;
    int comp_per_pixel;

    unsigned int renderer_id;
    unsigned int texture_slot;
} LCGE_texture;

LCGE_texture* lcge_texture_create(const char *filepath);
void lcge_texture_delete(LCGE_texture *texture);

void lcge_texture_bind(LCGE_texture *texture);
void lcge_texture_unbind(LCGE_texture *texture);

#ifdef __cplusplus
}
#endif

#endif
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


#ifndef _RENDERER_TTFTEXTURE_H
#define _RENDERER_TTFTEXTURE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <glad/glad.h>
#include <stb/stb_truetype.h>

typedef struct LCGE_ttftexture
{
    GLuint renderer_id;
    stbtt_bakedchar *data;
} LCGE_ttftexture;

LCGE_ttftexture* lcge_ttftexture_create(const char *filepath);
void lcge_ttftexture_delete(LCGE_ttftexture *texture);

void lcge_ttftexture_bind(LCGE_ttftexture *texture);
void lcge_ttftexture_unbind(LCGE_ttftexture *texture);

stbtt_aligned_quad lcge_ttftexture_get_char(LCGE_ttftexture *texture,
                                            const char c, float x, float y);

#ifdef __cplusplus
}
#endif

#endif
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

#include <stdlib.h>
#include <stdio.h>

#include "ttftexture.h"
#include "../glerror.h"

LCGE_ttftexture* lcge_ttftexture_load(const char *filepath)
{
    LCGE_ttftexture* texture = calloc(1, sizeof(LCGE_ttftexture));

    // ASCII 32 through 126 is 95
    texture->data = calloc(1, sizeof(stbtt_bakedchar) * 96);

    // temp data buffers
    unsigned char *ttf_buffer = malloc(sizeof(unsigned char) * (1<<20));
    unsigned char *temp_bitmap = malloc(sizeof(unsigned char) * (512*512));

    FILE *f = fopen(filepath, "rb");
    if (f == NULL)
    {
        printf("Failed to load font from %s\n", filepath);
        exit(-1);
    }
    fread(ttf_buffer, 1, 1<<20, f);
    fclose(f);

    stbtt_BakeFontBitmap(ttf_buffer, 0, 32.0f, temp_bitmap, 512, 512, 32, 96,
                         texture->data);

    GLCALL(glGenTextures(1, &texture->renderer_id));
    GLCALL(glBindTexture(GL_TEXTURE_2D, texture->renderer_id));

    // Enable resizing
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 512, 512, 0, GL_RED,
                        GL_UNSIGNED_BYTE, temp_bitmap));

    free(ttf_buffer);
    free(temp_bitmap);

    return texture;
}

void lcge_ttftexture_delete(LCGE_ttftexture *texture)
{
    lcge_ttftexture_unbind(texture);
    GLCALL(glDeleteTextures(1, &texture->renderer_id));
    free(texture->data);
    free(texture);
}

void lcge_ttftexture_bind(LCGE_ttftexture *texture)
{
    GLCALL(glActiveTexture(GL_TEXTURE0));
    GLCALL(glBindTexture(GL_TEXTURE_2D, texture->renderer_id));
}
void lcge_ttftexture_unbind(LCGE_ttftexture *texture)
{
    GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

stbtt_aligned_quad lcge_ttftexture_get_char(LCGE_ttftexture *texture,
                                            const char c, float *x, float *y)
{
    stbtt_aligned_quad q;

    stbtt_GetBakedQuad(texture->data, 512, 512, c-32, x, y, &q, 1);

    return q;
}

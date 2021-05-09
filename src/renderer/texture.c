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
#include <stb/stb_image.h>

#include <stdlib.h>

#include "texture.h"
#include "../glerror.h"
#include "../core.h"

LCGE_texture* lcge_texture_create(const char *filepath)
{
    LCGE_texture *texture = calloc(1, sizeof(LCGE_texture));

    stbi_set_flip_vertically_on_load(1);

    unsigned char *data = stbi_load(filepath, &texture->width, &texture->height,
                                    &texture->comp_per_pixel, 4);

    GLCALL(glGenTextures(1, &texture->renderer_id));
    GLCALL(glBindTexture(GL_TEXTURE_2D, texture->renderer_id));
    texture->texture_slot = g_state->next_available_texture;
    lcge_update_texture_slot();

    // Enable resizing
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture->width,
                        texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));

    GLCALL(glBindTexture(GL_TEXTURE_2D, 0));

    if (data)
        stbi_image_free(data);

    return texture;
}
void lcge_texture_delete(LCGE_texture *texture)
{
    GLCALL(glDeleteTextures(1, &texture->renderer_id));
    free(texture);
}

void lcge_texture_bind(LCGE_texture *texture)
{
    GLCALL(glActiveTexture(GL_TEXTURE0 + texture->texture_slot));
    GLCALL(glBindTexture(GL_TEXTURE_2D, texture->renderer_id));
}

void lcge_texture_unbind(LCGE_texture *texture)
{
    GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}

// The MIT License (MIT)

// Copyright (c) 2021 Satvik Reddy

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include <glad/glad.h>
#include <stb/stb_image.h>

#include <stdlib.h>

#include "texture.h"
#include "../glerror.h"

LCGE_texture* lcge_texture_create(const char *filepath)
{
    LCGE_texture *texture = calloc(1, sizeof(LCGE_texture));

    stbi_set_flip_vertically_on_load(1);

    unsigned char *data = stbi_load(filepath, &texture->width, &texture->height,
                                    &texture->comp_per_pixel, 4);

    GLCALL(glGenTextures(1, &texture->renderer_id));
    GLCALL(glBindTexture(GL_TEXTURE_2D, texture->renderer_id));

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
    GLCALL(glActiveTexture(GL_TEXTURE0));
    GLCALL(glBindTexture(GL_TEXTURE_2D, texture->renderer_id));
}

void lcge_texture_unbind(LCGE_texture *texture)
{
    GLCALL(glBindTexture(GL_TEXTURE_2D, NULL));
}

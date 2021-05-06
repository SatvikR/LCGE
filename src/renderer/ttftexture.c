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

#include <stdlib.h>
#include <stdio.h>

#include "ttftexture.h"
#include "../glerror.h"

LCGE_ttftexture* lcge_ttftexture_create(const char *filepath)
{
    LCGE_ttftexture* texture = calloc(1, sizeof(LCGE_ttftexture));

    // ASCII 32 through 126 is 95
    texture->data = calloc(1, sizeof(stbtt_bakedchar) * 96);

    // temp data buffers
    unsigned char *ttf_buffer = malloc(sizeof(unsigned char) * (1<<20));
    unsigned char *temp_bitmap = malloc(sizeof(unsigned char) * (512*512));

    fread(ttf_buffer, 1, 1<<20, fopen(filepath, "rb"));
    stbtt_BakeFontBitmap(ttf_buffer, 0, 32.0f, temp_bitmap, 512, 512, 32, 96,
                         texture->data);

    GLCALL(glGenTextures(1, &texture->renderer_id));
    GLCALL(glBindTexture(GL_TEXTURE_2D, texture->renderer_id));

    // Enable resizing
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, 512, 512, 0, GL_ALPHA,
                        GL_UNSIGNED_BYTE, temp_bitmap));

    free(ttf_buffer);
    free(temp_bitmap);

    return texture;
}

void lcge_ttftexture_delete(LCGE_ttftexture *texture)
{
    GLCALL(glDeleteTextures(1, &texture->renderer_id));
    free(texture->data);
    free(texture);
}

void lcge_ttftexture_bind(LCGE_ttftexture *texture)
{
    GLCALL(glActiveTexture(GL_TEXTURE0));
    GLCALL(glBindTexture(1, texture->renderer_id));
}
void lcge_ttftexture_unbind(LCGE_ttftexture *texture)
{
    GLCALL(glBindTexture(1, 0));
}

stbtt_aligned_quad lcge_ttftexture_get_char(LCGE_ttftexture *texture,
                                            const char c, float x, float y)
{
    stbtt_aligned_quad q;

    stbtt_GetBakedQuad(texture->data, 512, 512, c-32, &x, &y, &q, 1);

    return q;
}

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
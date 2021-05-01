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


#ifndef _RENDERER_SHADER_H
#define _RENDERER_SHADER_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct LCGE_shader
{
    GLuint renderer_id;
} LCGE_shader;

LCGE_shader* lcge_shader_create(const char *path, const char *name);
void lcge_shader_delete(LCGE_shader *shader);

void lcge_shader_bind(LCGE_shader *shader);
void lcge_shader_unbind(LCGE_shader *shader);

GLint lcge_shader_set_uniform_4f(LCGE_shader *shader, const char *name,
                                GLfloat a, GLfloat b, GLfloat c, GLfloat d);

#ifdef __cplusplus
}
#endif

#endif
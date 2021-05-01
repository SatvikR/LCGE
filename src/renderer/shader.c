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

#include <string.h>

#include "shader.h"
#include "../glerror.h"

static GLuint compile_shader(const char* path, GLenum type)
{
    FILE *f;
    char *text;
    unsigned long len;

    f = fopen(path, "rb");
    if (f == NULL)
    {
        fprintf(stderr, "Shader %s failed to load\n", path);
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    len = ftell(f);

    // Make sure there is some shader code
    ASSERT(len > 0);

    fseek(f, 0, SEEK_SET);
    text = calloc(1, sizeof(char) * len);
    fread(text, 1, len , f);
    fclose(f);

    GLuint id = glCreateShader(type);
    glShaderSource(id, 1, (const GLchar**) &text, (const GLint*) &len);
    glCompileShader(id);
    
    GLint status;
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);

    if (status == GL_FALSE)
    {
        GLint len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        GLchar *error_message = malloc(sizeof(char) * len);

        glGetShaderInfoLog(id, len, &len, error_message);

        fprintf(stderr, "Compilation of shader %s failed. Error message: %s\n",
                path, error_message);

        glDeleteShader(id);

        free(error_message);
    }

    free(text);

    return id;
}

LCGE_shader* lcge_shader_create(const char *path, const char *name)
{
    int path_len = strlen(path);
    int name_len = strlen(name);

    char *vert_full_path = calloc(1, sizeof(char) * (path_len + name_len + 3));
    char *frag_full_path = calloc(1, sizeof(char) * (path_len + name_len + 3));

    strcat(vert_full_path, path); 
    strcat(vert_full_path, name); 
    strcat(vert_full_path, ".vs"); 

    strcat(frag_full_path, path); 
    strcat(frag_full_path, name); 
    strcat(frag_full_path, ".fs"); 

    LCGE_shader *shader = malloc(sizeof(LCGE_shader));
    
    GLuint program = glCreateProgram();
    GLuint vs = compile_shader(vert_full_path, GL_VERTEX_SHADER);
    GLuint fs = compile_shader(frag_full_path, GL_FRAGMENT_SHADER);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    shader->renderer_id = program;

    glDeleteShader(vs);
    glDeleteShader(fs);

    free(vert_full_path);
    free(frag_full_path);

    return shader;
} 

void lcge_shader_delete(LCGE_shader *shader)
{
    GLCALL(glDeleteProgram(shader->renderer_id));

    free(shader);
}

void lcge_shader_bind(LCGE_shader *shader)
{
    GLCALL(glUseProgram(shader->renderer_id));
}

void lcge_shader_unbind(LCGE_shader *shader)
{
    GLCALL(glUseProgram(0));
}

GLint lcge_shader_set_uniform_4f(LCGE_shader *shader, const char *name, 
                                GLfloat a, GLfloat b, GLfloat c, GLfloat d)
{
    GLint location;
    GLCALL(location = glGetUniformLocation(shader->renderer_id, name));

    if (location == -1)
    {
        printf("Warning: uniform %s does not exist\n", name);
    }

    return location;
}
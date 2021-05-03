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

#include <LCGE/lcge.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "core.h"

LCGE_state *g_state;

int lcge_init(const char *lcge_res_dir)
{
    g_state = malloc(sizeof(LCGE_state));

    // create glfw window
    if (!glfwInit())
    {
        g_state->initialized = LCGE_INIT_ERR;
        return g_state->initialized;
    }

    size_t res_dir_len = strlen(lcge_res_dir);
    size_t shader_name_len = strlen("shaders/");

    if (lcge_res_dir[res_dir_len-1] != '/')
    {
        g_state->res_dir = calloc(1, sizeof(char) *
                                     (res_dir_len + shader_name_len + 2));

        strcat(g_state->res_dir, lcge_res_dir);
        strcat(g_state->res_dir, "/");
        strcat(g_state->res_dir, "shaders/");
    }
    else
    {
        g_state->res_dir = calloc(1, sizeof(char) *
                                     (res_dir_len + shader_name_len + 1));

        strcat(g_state->res_dir, lcge_res_dir);
        strcat(g_state->res_dir, "shaders/");
    }

    g_state->initialized = LCGE_INIT_OK;
    return g_state->initialized;
}

static void lcge_clean_up()
{
    if (g_state->initialized == LCGE_INIT_OK)
    {
        lcge_shader_delete(g_state->basic_geo);
        lcge_shader_delete(g_state->texture);

        glfwTerminate();
        glfwDestroyWindow(g_state->window->_window);

        free(g_state->res_dir);
        free(g_state->window);
        return;
    }

    glfwTerminate();
}

void lcge_exit()
{
    lcge_clean_up();

    free(g_state);
}
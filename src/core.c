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

#include "core.h"

LCGE_state *g_state;

int lcge_init()
{
    g_state = malloc(sizeof(LCGE_state));

    // create glfw window
    if (!glfwInit())
    {
        g_state->initialized = LCGE_INIT_ERR;
        return g_state->initialized;
    }

    g_state->initialized = LCGE_INIT_OK; 
    return g_state->initialized;
}

static void lcge_clean_up()
{
    if (g_state->initialized == LCGE_INIT_OK)
    {
        // delete global shaders
        lcge_shader_delete(g_state->basic_geo);

        glfwTerminate();
        glfwDestroyWindow(g_state->window->_window);

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
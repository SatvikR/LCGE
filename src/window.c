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
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include "window.h"
#include "core.h"
#include "glerror.h"

LCGE_window* lcge_create_window(unsigned int width, unsigned int height, 
                                const char *title, int resizable)
{
    if (resizable != LCGE_RESIZEABLE && resizable != LCGE_NON_RESIZEABLE)
        return NULL;

    LCGE_window *window = malloc(sizeof(LCGE_window));

    window->width = width;
    window->height = height;

    // glfwWindowHint(GLFW_DOUBLEBUFFER, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, resizable);
    window->_window = glfwCreateWindow(window->width, window->height, title, 
                                       NULL, NULL);

    g_state->window = window;
    glfwMakeContextCurrent(window->_window);
    
    // Load opengl functions
    int gladInitRes = gladLoadGL();
    if (!gladInitRes)
    {
        glfwDestroyWindow(window->_window);
        glfwTerminate();
        return NULL;
    }
    return window;
}

int lcge_window_is_open(LCGE_window *window)
{
    return !glfwWindowShouldClose(window->_window);
}

void lcge_clear_window(LCGE_window *window)
{
    GLCALL(glClear(GL_COLOR_BUFFER_BIT));
}

void lcge_update_window(LCGE_window *window)
{
    glfwSwapBuffers(window->_window);
    glfwPollEvents();
}
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
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "core.h"
#include "export.h"

LCGE_state *g_state;

LCGE_EXPORT int lcge_init(const char *lcge_res_dir)
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
        lcge_shader_delete(g_state->text);

        glfwTerminate();
        glfwDestroyWindow(g_state->window->_window);

        free(g_state->res_dir);
        free(g_state->window);
        return;
    }

    glfwTerminate();
}

LCGE_EXPORT void lcge_exit()
{
    lcge_clean_up();

    free(g_state);
}
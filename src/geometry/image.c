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

#include "image.h"
#include "math.h"
#include "../core.h"
#include "../glerror.h"

LCGE_image* lcge_image_load(const char *filepath, float x, float y)
{

    LCGE_texture *texture = lcge_texture_create(filepath);

    LCGE_coordinate top_l = lcge_coordinate_translate(x, y);
    LCGE_coordinate top_r = lcge_coordinate_translate(
                                                    x + texture->width,
                                                    y);
    LCGE_coordinate bottom_l = lcge_coordinate_translate(x,
                                                    y + texture->height);
    LCGE_coordinate bottom_r = lcge_coordinate_translate(
                                                     x + texture->width,
                                                     y + texture->height);
    GLfloat positions[16] = {
        bottom_l.x, bottom_r.y, 0.0f, 0.0f, // bottom left
        top_l.x, top_l.y, 0.0f, 1.0f,       // top left
        top_r.x, top_r.y, 1.0f, 1.0f,       // top right
        bottom_r.x, bottom_r.y, 0.0f, 1.0f  // bottom right
    };

    printf("%d\n, %d\n", texture->width, texture->height);

    int i;
    for (i = 0; i < 16; i += 4)
    {
        printf("(%f, %f), (%f, %f)\n", positions[i], positions[i + 1], positions[i + 2], positions[i + 3]);
    }

    GLuint indeces[6] = {
        0, 1, 2, // triangle 1
        0, 2, 3  // triangle 2
    };

    LCGE_vertex_array *va = lcge_vertex_array_create();

    LCGE_vertex_buffer *vb = lcge_vertex_buffer_create(positions,
                                                       16 * sizeof(GLfloat));


    lcge_vertex_array_layout(va, vb, 2, GL_FLOAT, 0, NULL);
    lcge_vertex_array_layout(va, vb, 2, GL_FLOAT, 1,
                            (size_t)NULL + sizeof(GLfloat) * 2);

    LCGE_index_buffer *ib = lcge_index_buffer_create(6 * sizeof(GLuint),
                                                     indeces);

    LCGE_image *image = malloc(sizeof(LCGE_image));

    image->va = va;
    image->vb = vb;
    image->ib = ib;
    image->texture = texture;
    image->shader = g_state->texture;

    return image;
}

void lcge_image_delete(LCGE_image *image)
{
    // unbind everything
    lcge_vertex_array_unbind(image->va);
    lcge_vertex_buffer_unbind(image->vb);
    lcge_index_buffer_unbind(image->ib);
    lcge_texture_unbind(image->texture);
    lcge_shader_unbind(image->shader);

    // delete everthing
    lcge_vertex_array_delete(image->va);
    lcge_vertex_buffer_delete(image->vb);
    lcge_index_buffer_delete(image->ib);
    lcge_texture_delete(image->texture);

    free(image);
}

void lcge_image_draw(LCGE_image *image)
{
    lcge_texture_bind(image->texture);

    lcge_shader_bind(image->shader);
    lcge_shader_set_uniform_1i(image->shader, "u_texture", 0);

    lcge_vertex_array_bind(image->va);
    lcge_index_buffer_bind(image->ib);

    GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL));
}
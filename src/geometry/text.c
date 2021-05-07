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

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "text.h"
#include "math.h"

LCGE_EXPORT LCGE_font* lcge_font_load(const char *filepath)
{
    LCGE_font *font = calloc(1, sizeof(LCGE_font));

    font->texture = lcge_ttftexture_load(filepath);

    return font;
}

LCGE_EXPORT void lcge_font_delete(LCGE_font *font)
{
    lcge_ttftexture_delete(font->texture);
    free(font);
}

LCGE_EXPORT LCGE_text* lcge_text_load(const char *text, float x, float y,
                                      LCGE_font *font)
{
    LCGE_text *m_text = calloc(1, sizeof(LCGE_text));

    size_t len = strlen(text);

    m_text->vbs = calloc(1, sizeof(LCGE_vertex_buffer*) * len);
    m_text->va = lcge_vertex_array_create();
    m_text->font = font;

    int i;
    for (i = 0; i < len; i++)
    {
        stbtt_aligned_quad q =
                           lcge_ttftexture_get_char(font->texture, text[i]-32,
                                                    &x, &y);

        LCGE_coordinate top_l
                        = lcge_coordinate_translate(q.x0, q.y0);
        LCGE_coordinate top_r
                        = lcge_coordinate_translate(q.x1, q.y0);
        LCGE_coordinate bottom_l
                        = lcge_coordinate_translate(q.x0, q.y1);
        LCGE_coordinate bottom_r
                        = lcge_coordinate_translate(q.x1, q.y1);

        GLfloat positions[16] = {
            bottom_l.x, bottom_l.y, q.s0, q.t1, // bottom left
            top_l.x, top_l.y, q.s0, q.t0,       // top left
            top_r.x, top_r.y, q.s1, q.t0,       // top right
            bottom_r.x, bottom_r.y, q.s1, q.t1  // bottom right
        };

        m_text->vbs[i] = lcge_vertex_buffer_create(positions,
                                                   16 * sizeof(GLfloat));

        lcge_vertex_array_layout(m_text->va, m_text->vbs[i], 2, GL_FLOAT, 0, 0,
                                 sizeof(GLfloat) * 4);
        lcge_vertex_array_layout(m_text->va, m_text->vbs[i], 2, GL_FLOAT, 1,
                                 sizeof(GLfloat) * 2, sizeof(GLfloat) * 4);
    }

    GLuint indeces[6] = {
        0, 1, 2, // triangle 1
        0, 2, 3  // triangle 2
    };

    m_text->ib = lcge_index_buffer_create(sizeof(GLfloat) * 6, indeces);

    return m_text;
}

LCGE_EXPORT void lcge_text_delete(LCGE_text *text)
{
    free(text);
}

LCGE_EXPORT void lcge_text_draw(LCGE_text *text)
{

}
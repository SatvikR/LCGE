#version 330 core

layout (location = 0) in vec4 m_position;
layout (location = 1) in vec2 m_texture_coord;

out vec2 texture_coord;

void main()
{
    gl_Position = m_position;
    texture_coord = m_texture_coord;
}
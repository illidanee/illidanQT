#version 330 core

uniform	mat4 uView;
uniform	mat4 uProjection;

layout (location = 0) in vec3 position;

out vec3 vTexCoord;

void main()
{
    gl_Position = uProjection * uView * vec4(position, 1.0f);
    gl_Position = gl_Position.xyww;
    vTexCoord = position;
}
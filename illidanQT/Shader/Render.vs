#version 330 core

uniform	mat4 uModel;
uniform	mat4 uView;
uniform	mat4 uProjection;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec3 vNormal;
out vec2 vUv;

void main()
{
    gl_Position = uProjection * uView * uModel * vec4(position, 1.0);
    vNormal = normal;
    vUv = uv;
}
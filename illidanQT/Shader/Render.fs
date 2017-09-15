#version 330 core

uniform sampler2D tex;

in vec3 vNormal;
in vec2 vUv;

out vec4 color;

void main()
{
    color = texture(tex, vUv);
    if (color.a < 0.02)
        discard;
} 
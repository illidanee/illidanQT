#version 330 core

uniform sampler2D tex;

in vec3 vNormal;
in vec2 vUv;

out vec4 color;

void main()
{
    //color = vec4(1.0, 0.2, 0.2, 1.0);
    color = texture(tex, vUv);
} 
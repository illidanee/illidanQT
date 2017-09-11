#version 330 core

uniform samplerCube uSkybox;

in vec3 vTexCoord;

out vec4 color;

void main()
{
	color = texture(uSkybox, vTexCoord);
}
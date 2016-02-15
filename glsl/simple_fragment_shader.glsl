#version 450

in vec2 fragUV;

out vec4 outColor;

uniform sampler2D sampler;

void main()
{
	outColor = texture(sampler,fragUV);
}
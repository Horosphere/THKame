#version 450

in vec2 position;
in vec2 uv;

out vec2 fragUV;

uniform mat4 matrix;

void main()
{
	gl_Position = matrix * vec4(position,0.0,1.0);
	fragUV = uv;
}
#pragma once

#define png_infopp_NULL (png_infopp)NULL
#define int_p_NULL (int*)NULL

#include <GL/glew.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "config.hpp"

namespace thk
{

float const quadVertices[] = {
	-0.5f,  0.5f, 0.0f, 0.0f,
	0.5f,  0.5f, 1.0f, 0.0f,
	0.5f, -0.5f, 1.0f, 1.0f,
	-0.5f, -0.5f, 0.0f, 1.0f
};
GLuint const quadElements[] = {
	0,1,2,
	2,3,0
};

// Convert THKame position to OpenGL position [-W/2, W/2] x [-H/2, H/2] -> [-1,1] x [-1,1]
glm::vec3 kamePosition(float x, float y);
// Convert raster image to OpenGL image
glm::mat4 matrixKame(float width, float height);
GLuint glLoadShader(char const* vertexPath, char const* fragmentPath);
GLuint glLoadBMP(char const* const path);
GLuint glLoadPNG(char const* const path);

} // namespace thk

// Implementations
inline glm::vec3 thk::kamePosition(float x, float y)
{
	return glm::vec3(x / windowW2, y / windowH2, 0.f);
}
inline glm::mat4 thk::matrixKame(float width, float height)
{
	return glm::scale(glm::vec3(1 / width, 1 / height, 1.f));
}
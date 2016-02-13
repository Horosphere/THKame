#pragma once

#define png_infopp_NULL (png_infopp)NULL
#define int_p_NULL (int*)NULL

#include <GL/glew.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

namespace thk
{


GLuint glLoadBMP(char const* const path);
GLuint glLoadPNG(char const* const path);

} // namespace thk

// THKamechinjiru.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <conio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "core/thkame.hpp"
#include "core/gl.hpp"

int main(int argc,char* argv[])
{
	using namespace glm;

	std::cout << "Initialising OpenGL" << std::endl;

	if (!glfwInit()) exit(EXIT_FAILURE);
//	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Open a window and create its OpenGL context
	GLFWwindow* window;
	window = glfwCreateWindow(640, 480, "Touhou Kamechinjiru", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	
	// Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	// Initialisation complete

	// Registering callbacks
	glfwSetKeyCallback(window, &thk::THKame::callbackKeys);


	thk::THKame::instance().init(window);
	thk::THKame::instance().loop();
	thk::THKame::instance().terminate();

	glfwTerminate();

	return 0;
}


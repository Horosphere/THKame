#include "thkame.hpp"

#include <iostream>

// Ctor and Dtor
thk::THKame::~THKame() {}

void thk::THKame::init(GLFWwindow* window)
{
	std::cout << "Initialising THKame" << std::endl;

	this->window = window;
}
void thk::THKame::terminate()
{
}
void thk::THKame::loop()
{
	glm::vec3 position(0.f,0.f,5.f);
	double timeStamp = glfwGetTime();
	do // Drawing loop
	{

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		   && !glfwWindowShouldClose(window));
}
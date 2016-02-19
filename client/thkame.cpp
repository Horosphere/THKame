#include "thkame.hpp"

#include <iostream>

#include "../server/thkameserver.hpp"

// Ctor and Dtor
thk::THKame::~THKame() {}

void thk::THKame::init(GLFWwindow* window)
{
	std::cout << "Initialising THKame" << std::endl;

	this->window = window;

	// Register OpenGL related parts

	// One vao is enough for 2D games
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &quadVBO); // Generate 1 buffer
	glGenBuffers(1, &quadEBO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadElements), quadElements, GL_STATIC_DRAW);
	quadShader = thk::glLoadShader("glsl/simple_vertex_shader.glsl",
								   "glsl/simple_fragment_shader.glsl");
	glBindFragDataLocation(quadShader, 0, "outColor");
	glUseProgram(quadShader);

	loopMenu();
}
void thk::THKame::terminate()
{
}

void thk::THKame::loopMenu()
{
	do // Drawing loop
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (state == IN_GAME) break;
	}
	while (!glfwWindowShouldClose(window));

	loopInGame();
}
void thk::THKame::loopInGame()
{
	THKameServer server(window);

	do // Drawing loop
	{
		glClear(GL_COLOR_BUFFER_BIT);

		server.update();

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (state == MAIN_MENU) break;
	}
	while (!glfwWindowShouldClose(window));

	loopMenu();
}
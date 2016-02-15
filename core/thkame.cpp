#include "thkame.hpp"

#include <iostream>

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

}
void thk::THKame::terminate()
{
}
void thk::THKame::loop()
{
	glm::vec2 position(124.f, 124.f);
	double timeStamp = glfwGetTime();
	do // Drawing loop
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		   && !glfwWindowShouldClose(window));
}
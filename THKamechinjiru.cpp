// THKamechinjiru.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "core/thkame.hpp"
#include "core/gl.hpp"

void test(GLFWwindow* window);

int main(int argc,char* argv[])
{
	using namespace glm;

	std::cout << "Initialising OpenGL" << std::endl;

	if (!glfwInit()) exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	GLFWwindow* window;
	window = glfwCreateWindow(thk::windowW, thk::windowH, "Touhou Kamechinjiru", nullptr, nullptr);
	if (window == NULL)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	
	// Initialize GLEW
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	// Initialisation complete
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	test(window);

	glfwTerminate();
	return 0;

	// Registering callbacks
	glfwSetKeyCallback(window, &thk::THKame::callbackKeys);


	thk::THKame::instance().init(window);
	thk::THKame::instance().loop();
	thk::THKame::instance().terminate();

	glfwTerminate();

	return 0;
}

// OpenGL Experimental method
void test(GLFWwindow* window)
{
	float vertices[] = {
		-0.5f,  0.5f, 0.0f, 0.0f,
		 0.5f,  0.5f, 1.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 1.0f 
	};
	GLuint tris[] = {
		0,1,2,
		2,3,0
	};
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	GLuint ebo;
	glGenBuffers(1, &ebo);


	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tris), tris, GL_STATIC_DRAW);

	GLuint shader = thk::glLoadShader("glsl/simple_vertex_shader.glsl",
									  "glsl/simple_fragment_shader.glsl");
	GLuint texture = thk::glLoadPNG("textures/title_logo.png");
	glBindFragDataLocation(shader, 0, "outColor");
	glUseProgram(shader);


	GLint vertexPositionA = glGetAttribLocation(shader, "position");
	glVertexAttribPointer(vertexPositionA, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GL_FLOAT), 0);
	glEnableVertexAttribArray(vertexPositionA);
	GLint vertexUVA = glGetAttribLocation(shader, "uv");
	glVertexAttribPointer(vertexUVA, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GL_FLOAT), (void*)(2 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(vertexUVA);
	GLint vertexMatrixA = glGetUniformLocation(shader, "matrix");

//	glActiveTexture(GL_TEXTURE0);
	glUniform1i(texture, 0);

	float px = 0;
	float py = 0;
	auto time0 = std::chrono::high_resolution_clock::now();
	do // Drawing loop
	{
		glClear(GL_COLOR_BUFFER_BIT);

		auto time = std::chrono::high_resolution_clock::now();
		float dt = std::chrono::duration_cast<std::chrono::duration<float>>(time - time0).count();
		time0 = time;

		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
			py += thk::playerSpeed * dt;
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
			py -= thk::playerSpeed * dt;
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
			px += thk::playerSpeed * dt;
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
			px -= thk::playerSpeed * dt;

		glm::mat4 matrix = glm::translate(thk::kamePosition(px, py));
		glUniformMatrix4fv(vertexMatrixA, 1, GL_FALSE, &matrix[0][0]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		   && !glfwWindowShouldClose(window));

	glDeleteProgram(shader);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);

	glDeleteVertexArrays(1, &vao);
}


#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include "config.hpp"
#include "gl.hpp"

namespace thk
{

class THKame final
{
private:
	THKame();
	~THKame();

	GLFWwindow* window;

	GLuint quadVBO, quadEBO;
	GLuint quadShader;
public:
	void init(GLFWwindow* window);
	void terminate();
	void loop();

	// Callback functions
	static void callbackKeys(GLFWwindow*, int key, int scancode, int action, int mods);

	static THKame& instance();
};

} // namespace thk

// Implementations
inline thk::THKame::THKame() {}
inline void thk::THKame::callbackKeys(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

inline thk::THKame& thk::THKame::instance()
{
	static THKame thkame;
	return thkame;
}
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include "config.hpp"
#include "gl.hpp"

namespace thk
{

enum State
{
	MAIN_MENU = 0,
	IN_GAME,
	TRANSITIONING
};

class THKame final
{
private:
	THKame();
	~THKame();

	// One time initialised constants
	GLFWwindow* window;

	GLuint quadVBO, quadEBO;
	GLuint quadShader;

	// Game variables
	bool isPaused;
	State state;

	void loopMenu(); // Main menu
	void loopInGame(); // In game
public:
	void init(GLFWwindow* window);
	void terminate();


	// Callback functions
	static void callbackKeys(GLFWwindow*, int key, int scancode, int action, int mods);

	static THKame& instance();
};

} // namespace thk

// Implementations
inline thk::THKame::THKame(): state(MAIN_MENU) {}
inline void thk::THKame::callbackKeys(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

inline thk::THKame& thk::THKame::instance()
{
	static THKame thkame;
	return thkame;
}
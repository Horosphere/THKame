#pragma once

#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace thk
{

struct Bullet
{
	unsigned char type;
	float x, y; // Coordinates
	float vx, vy; // Velocity
};

class THKameServer final
{
private:
	GLFWwindow* window;

	float playerX;
	float playerY;
	std::chrono::time_point<std::chrono::steady_clock> timeStamp;
public:
	THKameServer(GLFWwindow* window);
	
	void update();
};

} // namespace thk

// Implementations

inline thk::THKameServer::THKameServer(GLFWwindow* window): window(window)
{
	timeStamp = std::chrono::high_resolution_clock::now();
}
#pragma once

#include <chrono>


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

	float playerX;
	float playerY;
	std::chrono::time_point<std::chrono::steady_clock> timeStamp;
public:
	THKameServer();
	
	void update();
};

} // namespace thk

// Implementations

inline thk::THKameServer::THKameServer()
{
	timeStamp = std::chrono::high_resolution_clock::now();
}
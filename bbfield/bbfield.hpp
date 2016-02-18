#pragma once

#include <vector>

// TODO: merge into THKameServer
namespace thk
{

float const playerRadiusSq = 8.f;
float const playerRadius = 2.82f;
float bulletRadius[10] = { 1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f };
float bulletRadiusSq[10] = { 1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f };

struct Bullet
{
	unsigned char type;
	float x, y; // Coordinates
	float vx, vy; // Velocity
};

class BBField
{
public:
	BBField();
	~BBField();

	bool collides(float px, float py); // Inputs: player position
private:

	std::vector<Bullet> bullets0; // Type 0, Circular bullets
	std::vector<Bullet> bullets1; // Type 1, Line bullets

};

} // namespace thk

// Implementations

inline thk::BBField::BBField() {}
#include "thkameserver.hpp"

void thk::THKameServer::update()
{
	auto time = std::chrono::high_resolution_clock::now();
}

// Collision detection:
/*
bool thk::BBField::collides(float px, float py)
{
	for (auto&& b : bullets0) // Circle-Circle collision
	{
		if (((px - b.x) * (px - b.x) + (px - b.x) * (px - b.x))
			<= playerRadiusSq + 2 * playerRadius * bulletRadius[b.type] + bulletRadiusSq[b.type]) return true;
	}
	for (auto&& b : bullets1) // Circle-Line collision
	{
		float normV = sqrtf(b.vx * b.vx + b.vy * b.vy);
		float dx = b.vx / normV; // Directions
		float dy = b.vy / normV;

		float seg0x = b.x + bulletRadius[b.type] * dx;
		float seg0y = b.y + bulletRadius[b.type] * dy;
		float ux = px - seg0x;
		float uy = py - seg0y;

		// Dot product
		float dot = dx * ux + dy * uy;
		float nx = 0.f, ny = 0.f; // Nearest point
		if (dot <= 0)
		{ // Centre of circle behind first point
			nx = seg0x;
			ny = seg0y;
		}
		else if (dot >= 2 * bulletRadius[b.type])
		{ // Centre of circle exceeds second point
			nx = b.x - bulletRadius[b.type] * dx;
			ny = b.y - bulletRadius[b.type] * dy;
		}
		else
		{ // Nearest point falls on line segment
			nx = seg0x - dx * dot;
			ny = seg0y - dy * dot;
		}
		if ((px - nx) * (px - nx) + (py - ny) * (py - ny) <= playerRadiusSq)
			return true;
	}
	return false;
}
*/
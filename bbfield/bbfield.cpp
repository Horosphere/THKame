#include "bbfield.hpp"

thk::BBField::~BBField()
{
}

bool thk::BBField::collides(float px, float py)
{
	for (auto&& b : bullets0)
	{
		if (((px - b.x) * (px - b.x) + (px - b.x) * (px - b.x))
			<= playerRadiusSq + 2 * playerRadius * bulletRadius[b.type]+ bulletRadiusSq[b.type]) return true;
	}
	for (auto&& b : bullets1)
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
		{
			nx = seg0x;
			ny = seg0y;
		}
		else if (dot >= 2 * bulletRadius[b.type])
		{
			nx = b.x - bulletRadius[b.type] * dx;
			ny = b.y - bulletRadius[b.type] * dy;
		}
		else
		{
			nx = seg0x - dx * dot;
			ny = seg0y - dy * dot;
		}
		if ((px - nx) * (px - nx) + (py - ny) * (py - ny) <= playerRadiusSq)
			return true;
	}
	return false;
}
#ifndef _THKAME_WORLD_WORLDDEFS_HPP__
#define _THKAME_WORLD_WORLDDEFS_HPP__

#include <string>

namespace thk
{


struct BulletClass final
{
	enum HitType
	{
		Circle,
		Line
	};
	std::string name;
	HitType hitType;
	double hitRadius;
};
struct EntityClass final
{
	std::string name;
	int hitPoints; ///< -1 hitpoint = immune to bullets
};

constexpr int const INDEX_NIL = -1;

struct Bullet
{
	int index; /// index = -1 -> nonexistent
	double pX, pY;
	double vX, vY;
};

struct Entity
{
	int index; 
	double pX, pY;
	double vX, vY;
	int hitPoints;
};

} // namespace thk


#endif // !_THKAME_WORLD_WORLDDEFS_HPP__

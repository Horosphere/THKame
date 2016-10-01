#ifndef _THKAME_WORLD_WORLD_HPP__
#define _THKAME_WORLD_WORLD_HPP__

#include <vector>

#include "entities.hpp"
#include "Generator.hpp"

namespace thk
{

class World final
{
public:
	World(real minX, real maxX, real minY, real maxY) noexcept:
		minX(minX), maxX(maxX), minY(minY), maxY(maxY) {}

	void tick(int duration);

	std::vector<BulletAutomatic> bulletsAutomatic;
	std::vector<Generator> generators;

private:
	real minX, maxX, minY, maxY;
};

} // namespace thk

#endif // !_THKAME_WORLD_WORLD_HPP__

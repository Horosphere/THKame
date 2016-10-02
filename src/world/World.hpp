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
	/**
	 * @brief Create the world boundaries. Bullets outside of the boundary will
	 *	be deleted
	 */
	World(real minX, real maxX, real minY, real maxY) noexcept:
		minX(minX), maxX(maxX), minY(minY), maxY(maxY) {}

	/**
	 * @brief Update the world
	 */
	void tick(int duration);

	std::vector<BulletAutomatic> bulletsAutomatic;
	std::vector<Generator> generators;

private:
	real minX, maxX, minY, maxY;
};

} // namespace thk

#endif // !_THKAME_WORLD_WORLD_HPP__

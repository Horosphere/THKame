#ifndef _THKAME_WORLD_ENTITIES_HPP__
#define _THKAME_WORLD_ENTITIES_HPP__

#include "../math/numbers.hpp"

namespace thk
{

/**
 * @brief The data of a single bullet
 */
struct BulletAutomatic
{
	int id;
	real x, y; // Position
	real vx, vy; // Velocity
};

} // namespace thk

#endif // !_THKAME_WORLD_ENTITIES_HPP__

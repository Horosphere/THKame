#ifndef _THKAME_ENTITIES_ENTITY_HPP__
#define _THKAME_ENTITIES_ENTITY_HPP__

#include "../math/numbers.hpp"

namespace thk
{

class World;


/**
 * @brief Base class for all things moving and having a hitbox
 */
class Entity
{
public:
	virtual ~Entity() = default;

	Entity(World* world, real x, real y):
		world(world), x(x), y(y), vx(0), vy(0), erasable(true) {}

	virtual void tick(int duration);

	World* world;
	real x,y;
	real vx,vy;
	/**
	 * If set to true, entity will be deleted when leaving the world
	 */
	bool erasable;
};


// Implementations

inline void
Entity::tick(int duration)
{
	x += duration * vx;
	y += duration * vy;
}

} // namespace thk

#endif // !_THKAME_ENTITIES_ENTITY_HPP__

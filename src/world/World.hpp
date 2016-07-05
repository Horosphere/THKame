#ifndef _THKAME_WORLD_WORLD_HPP__
#define _THKAME_WORLD_WORLD_HPP__

#include <vector>

#include "worlddefs.hpp"

namespace thk
{

class World final
{
public:
	static constexpr std::size_t const MAX_BULLETS = 512;
	static constexpr std::size_t const MAX_ENTITIES = 128;

	World();

	/**
	 * Any bullet escaping the region [-hw, hw] * [-hh, hh] will be removed.
	 */
	void setBoundary(double hw, double hh);

	void tick();

	void insertBullets(std::vector<Bullet> const&);
	void insertEntities(std::vector<Entity> const&);

	Bullet bullets[MAX_BULLETS];
	Entity entities[MAX_ENTITIES];
private:
	double halfWidth, halfHeight;
};

} // namespace thk


// Implementations

inline void thk::World::setBoundary(double hw, double hh)
{
	halfWidth = hw;
	halfHeight = hh;
}
inline void thk::World::insertBullets(std::vector<Bullet> const& b)
{
	auto it = b.cbegin();
	for (Bullet& bullet: bullets)
	{
		if (bullet.index == INDEX_NIL)
		{
			if (it == b.cend()) break;
			bullet = *it;
			++it;
		}
	}
}
inline void thk::World::insertEntities(std::vector<Entity> const& e)
{
	auto it = e.cbegin();
	for (Entity& entity: entities)
	{
		if (entity.index == INDEX_NIL)
		{
			if (it == e.cend()) break;
			entity = *it;
			++it;
		}
	}
}

#endif // !_THKAME_WORLD_WORLD_HPP__

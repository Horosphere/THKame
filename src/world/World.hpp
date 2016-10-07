#ifndef _THKAME_WORLD_WORLD_HPP__
#define _THKAME_WORLD_WORLD_HPP__

#include <vector>
#include <functional>

#include "../entities/Entity.hpp"
#include "../entities/Player.hpp"

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
		player(nullptr),
		minX(minX), maxX(maxX), minY(minY), maxY(maxY) {}
	~World();

	/**
	 * @brief Update the world
	 */
	void tick(int duration);

	/**
	 * Introduce a new entity into the world
	 */
	void addEntity(Entity*);
	/**
	 * Sets the player
	 */
	void setPlayer(Player*);
	Player* getPlayer();


	Player const* getClientPlayer() const;
	void iterateEntities(std::function<void (Entity const*)>) const;
private:
	std::vector<Entity*> entities;
	Player* player;

	real minX, maxX, minY, maxY;
};


// Implementations

inline void World::addEntity(Entity* e)
{
	entities.push_back(e);
}
inline void World::setPlayer(Player* p)
{
	player = p;
}
inline Player* World::getPlayer() 
{
	return player;
}
inline Player const* World::getClientPlayer() const
{
	return player;
}
inline void
World::iterateEntities(std::function<void (Entity const*)> f) const
{
	for (auto entity: entities) f(entity);
}

} // namespace thk

#endif // !_THKAME_WORLD_WORLD_HPP__

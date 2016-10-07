#include "World.hpp"

namespace thk
{

World::~World()
{
	for (auto entity: entities) delete entity;
	delete player;
}

void World::tick(int duration)
{
	for (auto entity = entities.begin(); entity != entities.end();)
	{
		(*entity)->tick(duration);
		if ((*entity)->erasable)
		{
			if ((*entity)->x < minX || maxX < (*entity)->y ||
			    (*entity)->y < minY || maxY < (*entity)->y)
			{
				delete(*entity);
				entity = entities.erase(entity);
			}
			else
				++entity;
		}
	}
	if (player)
		player->tick(duration);
}

} // namespace thk

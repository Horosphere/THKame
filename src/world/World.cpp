#include "World.hpp"

thk::World::World(): halfWidth(100.0), halfHeight(100.0)
{
	for (Bullet& bullet: bullets)
	{
		bullet.index = INDEX_NIL;
	}
	for (Entity& entity: entities)
	{
		entity.index = INDEX_NIL;
	}
}

void thk::World::tick()
{
	for (Bullet& bullet: bullets)
	{
		if (bullet.index == INDEX_NIL) continue;
		bullet.pX += bullet.vX;
		bullet.pY += bullet.vY;
		if (bullet.pX < -halfWidth || halfWidth < bullet.pX ||
				bullet.pY < -halfHeight || halfHeight < bullet.pY)
			bullet.index = INDEX_NIL;
	}
	for (Entity& entity: entities)
	{
		if (entity.index == INDEX_NIL) continue;
		entity.pX += entity.vX;
		entity.pY += entity.vY;
	}
}

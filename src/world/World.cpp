#include "World.hpp"

namespace thk
{

void World::tick(int duration)
{
	for (auto bullet = bulletsAutomatic.begin();
	     bullet != bulletsAutomatic.end();)
	{
		bullet->x += bullet->vx * duration;
		bullet->y += bullet->vy * duration;
		if (bullet->x < minX || maxX < bullet->y ||
		    bullet->y < minY || maxY < bullet->y)
			bullet = bulletsAutomatic.erase(bullet);
		else
			++bullet;
	}

	// Max limit for bullets
	if (bulletsAutomatic.size() < 4096)
		for (auto& generator: generators)
		{
			generator.tick(duration, bulletsAutomatic);
		}
}

} // namespace thk

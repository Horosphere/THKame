#include "Player.hpp"

#include "Bullet.hpp"
#include "../world/World.hpp"

namespace thk
{

void Player::tick(int duration)
{
	Entity::tick(duration);
	x = clamp(x, -1, 1);
	y = clamp(y, -1, 1);

	// Emit bullets
	time += duration;
	if (time < period) return;
	time -= period;

	if (!firing) return;
	Bullet* bullet = new Bullet(world, x - 0.02, y);
	bullet->vx = vx * 0.3;
	bullet->vy = -0.003 + vy * 0.3;
	world->addEntity(bullet);

	bullet = new Bullet(world, x + 0.02, y);
	bullet->vx = vx * 0.3;
	bullet->vy = -0.003 + vy * 0.3;
	world->addEntity(bullet);
};

} // namespace thk

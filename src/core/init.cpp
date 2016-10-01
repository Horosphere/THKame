#include "init.hpp"

namespace thk
{

std::vector<Bullet> Bullet::bullets;

void init()
{
	Bullet::bullets.push_back(Bullet("Circle", Bullet::Circle, 0.05));
}

} // namespace thk

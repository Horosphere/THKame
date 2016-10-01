#include "init.hpp"

namespace thk
{

void init()
{
	Bullet::bullets["BuLi"] = Bullet(Bullet::Circle, 0.05);
}

} // namespace thk

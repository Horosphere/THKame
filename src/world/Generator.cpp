#include "Generator.hpp"

namespace thk
{

void Generator::tick(int duration, std::vector<BulletAutomatic>& b)
{
	time += duration;
	if (time < period) return;
	time -= period;

	if (!enabled) return;
	BulletAutomatic bullet;
	bullet.id = 0;
	bullet.x = x - 0.02;
	bullet.y = y;
	bullet.vx = 0;
	bullet.vy = -0.003;
	b.push_back(bullet);
	bullet.x = x + 0.02;
	b.push_back(bullet);

};

} // namespace thk

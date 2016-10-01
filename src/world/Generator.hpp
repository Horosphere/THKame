#ifndef _THKAME_WORLD_GENERATOR_HPP__
#define _THKAME_WORLD_GENERATOR_HPP__

#include <vector>

#include "entities.hpp"

namespace thk
{

class Generator
{
public:
	Generator(int period): period(period), time(0), enabled(true) {}

	void tick(int duration, std::vector<BulletAutomatic>& bullets);
	void setEnabled(bool e) { enabled = e; }

	int period;
	real x, y;
private:
	int time;
	bool enabled;
};

} // namespace thk

#endif // !_THKAME_WORLD_GENERATOR_HPP__

#ifndef _THKAME_ENTITIES_PLAYER_HPP__
#define _THKAME_ENTITIES_PLAYER_HPP__

#include <vector>

#include "Entity.hpp"

namespace thk
{

class Player: public Entity
{
public:
	Player(World* world, real x, real y): Entity(world, x, y),
		period(30), time(0), firing(false)
	{
		erasable = false;
	}
	void setFiring(bool e) { firing = e; }

	virtual void tick(int duration) override;

private:
	int period;
	int time;
	bool firing;
};

} // namespace thk

#endif // !_THKAME_ENTITIES_PLAYER_HPP__

#ifndef _THKAME_CORE_INIT_HPP__
#define _THKAME_CORE_INIT_HPP__

#include <map>

#include "../math/numbers.hpp"

namespace thk
{

void init();

class Bullet final
{
public:
	enum HitType
	{
		Circle,
		Line
	};

	Bullet(HitType ht, real radius) noexcept:
		ht(ht), radius(radius) {}

	HitType ht;
	real radius;

	static std::map<std::string, Bullet> bullets;
};


} // namespace thk

#endif // !_THKAME_CORE_INIT_HPP__

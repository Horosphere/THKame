#ifndef _THKAME_CORE_INIT_HPP__
#define _THKAME_CORE_INIT_HPP__

#include <vector>
#include <string>

#include "../math/numbers.hpp"

namespace thk
{

void init();

/**
 * @brief Each Bullet instance represents one type of bullet, not one single
 *	bullet.
 */
class Bullet final
{
public:
	enum HitType
	{
		Circle,
		Line
	};

	Bullet(std::string name, HitType ht, real radius) noexcept:
		name(name), ht(ht), radius(radius) {}

	std::string name;
	HitType ht;
	real radius;

	static std::vector<Bullet> bullets;
};


} // namespace thk

#endif // !_THKAME_CORE_INIT_HPP__

#ifndef _THKAME_CORE_DANMAKU_HPP__
#define _THKAME_CORE_DANMAKU_HPP__

#include <iostream>
#include <vector>
#include <string>

#include "../world/worlddefs.hpp"

namespace thk
{

class Danmaku final
{
public:
	Danmaku();
	/**
	 * Loads Danmaku configuration from XML stream
	 */
	void load(std::istream& stream);

	std::vector<BulletClass> bulletClasses;
	std::vector<EntityClass> entityClasses;
};


} // namespace thk

// Implementations



#endif // !_THKAME_CORE_DANMAKU_HPP__

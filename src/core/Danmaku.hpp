#ifndef _THKAME_CORE_DANMAKU_HPP__
#define _THKAME_CORE_DANMAKU_HPP__

#include <iostream>
#include <vector>
#include <string>

namespace thk
{

class Danmaku final
{
public:
	/**
	 * @brief Each instance of Bullet represents a type of bullets. This struct
	 *	only stores invariant properties about a bullet and does not store
	 *	position/velocity.
	 */
	struct Bullet final
	{
		enum HitType
		{
			Circle,
			Line
		};

		std::string name;
		HitType hitType;
		double hitRadius;
	};
	Danmaku();
	/**
	 * Loads Danmaku configuration from XML stream
	 */
	void load(std::istream& stream);

	std::vector<Bullet> bullets;
};


} // namespace thk

// Implementations




#endif // !_THKAME_CORE_DANMAKU_HPP__

#ifndef _THKAME_CORE_SCENE_HPP__
#define _THKAME_CORE_SCENE_HPP__

#include <SFML/Graphics.hpp>

#include "../client/Resources.hpp"
#include "../math/Transform.hpp"
#include "../world/World.hpp"

namespace thk
{

class Scene final
{
public:
	Scene();

	void calculate(int duration);
	void draw(sf::RenderWindow* const,
	          Resources const&) const;

private:
	float posX, posY;
	/**
	 * Scene to screen transformation
	 */
	Transform sts;
	World world;
};


} // namespace thk

#endif // !_THKAME_CORE_SCENE_HPP__

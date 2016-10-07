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

	/**
	 * @brief Updates the scene
	 * @param[in] duration Amount of time in ms elapsed from last update
	 */
	void tick(int duration);
	void draw(sf::RenderWindow* const,
	          Resources const&) const;

private:
	/**
	 * Scene to screen transformation
	 */
	Transform sts;
	World world;
};


} // namespace thk

#endif // !_THKAME_CORE_SCENE_HPP__

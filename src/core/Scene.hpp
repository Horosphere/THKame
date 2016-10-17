#ifndef _THKAME_CORE_SCENE_HPP__
#define _THKAME_CORE_SCENE_HPP__

#include <typeindex>
#include <typeinfo>
#include <map>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "../client/render/Render.hpp"
#include "../client/Resources.hpp"
#include "../math/Transform.hpp"
#include "../world/World.hpp"

namespace thk
{

class Scene final
{
public:
	Scene();
	~Scene();

	/**
	 * @brief Updates the scene
	 * @param[in] duration Amount of time in ms elapsed from last update
	 */
	void tick(int duration);
	void draw(sf::RenderWindow* const,
	          Resources const&) const;
	template <typename T>
	void registerRenderer(Render* render)
	{
		renders[typeid(T)] = render;
	}

private:
	/**
	 * Scene to screen transformation
	 */
	Transform sts;
	World world;
	std::map<std::type_index, Render*> renders;
};

} // namespace thk

#endif // !_THKAME_CORE_SCENE_HPP__

#ifndef _THKAME_CORE_SCENE_HPP__
#define _THKAME_CORE_SCENE_HPP__

#include <SFML/Graphics.hpp>

#include "Resources.hpp"

namespace thk
{

class Scene final
{
public:
	Scene();

	/**
	 * @return true if Scene exited successfully. false if window is closed.
	 */
	bool start(sf::RenderWindow* const,
	           Resources const&,
	           int nThreads);

	void draw(sf::RenderWindow* const,
	          Resources const&) const;

private:
	float posX, posY;

	float fps;
};


} // namespace thk

#endif // !_THKAME_CORE_SCENE_HPP__

#ifndef _THKAME_CORE_SCENE_HPP__
#define _THKAME_CORE_SCENE_HPP__

#include <SFML/Graphics.hpp>

namespace thk
{

class Scene final
{
public:
	/**
	 * @return true if Scene exited successfully. false if window is closed.
	 */
	bool start(sf::RenderWindow* const, int nThreads);

	void draw(sf::RenderWindow* const);

};


} // namespace thk

#endif // !_THKAME_CORE_SCENE_HPP__

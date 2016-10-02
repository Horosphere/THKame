#ifndef _THKAME_CLIENT_THKAME_HPP__
#define _THKAME_CLIENT_THKAME_HPP__

#include <stack>

#include "Resources.hpp"
#include "Menu.hpp"
#include "../core/Scene.hpp"

namespace thk
{

/**
 * The client
 */
class THKame final
{
public:
	THKame() noexcept;
	/**
	 * Loads all resources and create window
	 */
	bool init();
	/**
	 * The game loop
	 */
	void exec();	

private:
	Scene* scene;

	Resources resources;
	sf::RenderWindow window;
	std::stack<Menu*> menus; // Should be empty only if scene != NULL

	float fps; // Frame/Second
	/**
	 * The amount of time passed after the last fps update
	 */
	int fpsDisplayDuration;
};

} // namespace thk

#endif // !_THKAME_CLIENT_THKAME_HPP__

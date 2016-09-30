#ifndef _THKAME_CLIENT_THKAME_HPP__
#define _THKAME_CLIENT_THKAME_HPP__

#include <stack>

#include "Resources.hpp"
#include "Menu.hpp"
#include "../core/Scene.hpp"

namespace thk
{

class THKame final
{
public:
	THKame() noexcept;
	/**
	 * Loads all resources and create window
	 */
	bool init();
	/**
	 * Start the game loop
	 */
	void exec();	

private:
	Scene* scene;

	Resources resources;
	sf::RenderWindow window;
	std::stack<Menu*> menus;

	float fps;
};

} // namespace thk

#endif // !_THKAME_CLIENT_THKAME_HPP__

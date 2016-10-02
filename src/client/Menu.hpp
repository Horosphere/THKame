#ifndef _THKAME_CLIENT_MENU_HPP__
#define _THKAME_CLIENT_MENU_HPP__

#include <stack>

#include <SFML/Graphics.hpp>

#include "../core/Scene.hpp"
#include "Resources.hpp"

namespace thk
{

/**
 * @brief Base class for all menues
 */
class Menu
{
public:
	virtual ~Menu() = default;

	/**
	 * @brief Called upon keyboard event
	 * @param[key] The key id pressed
	 * @param[menuStack] The menu stack. This function is allowed to push new
	 *	menus onto the stack or pop menus off the stack, but the stack shall
	 *	never be emptied by the function.
	 * @return A scene if the menu starts a new game. In this case, the whole
	 *	menustack will be cleared
	 */
	virtual Scene* keyPressed(sf::Keyboard::Key key,
	                          std::stack<Menu*>* const menuStack) = 0;
	/**
	 * @brief Draw the menu onto a window.
	 */
	virtual void draw(sf::RenderWindow* const,
	                  Resources const&) const = 0;
};

} // namespace thk

#endif // !_THKAME_CLIENT_MENU_HPP__

#ifndef _THKAME_CLIENT_MENU_HPP__
#define _THKAME_CLIENT_MENU_HPP__

#include <stack>

#include <SFML/Graphics.hpp>

#include "../core/Scene.hpp"
#include "Resources.hpp"

namespace thk
{

class Menu
{
public:
	virtual ~Menu() = default;

	virtual Scene* keyPressed(sf::Keyboard::Key,
	                          std::stack<Menu*>* const) = 0;
	virtual void draw(sf::RenderWindow* const,
	                  Resources const&) const = 0;
};

} // namespace thk

#endif // !_THKAME_CLIENT_MENU_HPP__

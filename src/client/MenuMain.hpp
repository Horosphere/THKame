#ifndef _THKAME_CLIENT_MENUMAIN_HPP__
#define _THKAME_CLIENT_MENUMAIN_HPP__

#include "Menu.hpp"

namespace thk
{

class MenuMain final: public Menu
{
public:
	MenuMain(): index(0) {}

	Scene* keyPressed(sf::Keyboard::Key,
	                  std::stack<Menu*>* const);
	void draw(sf::RenderWindow* const,
	          Resources const&) const;

private:
	static constexpr unsigned const nKeys = 3;
	unsigned index;
};

} // namespace thk

#endif // !_THKAME_CLIENT_MENUMAIN_HPP__

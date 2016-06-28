#ifndef _THKAME_CLIENT_MENU_HPP__
#define _THKAME_CLIENT_MENU_HPP__

#include <cstddef>

#include "ResourceManager.hpp"
#include "../core/ServerSetup.hpp"

namespace thk
{
class Client;

/**
 * Class for a menu in THKame.
 * Each menu does not store its state showing up in the client.
 */
class Menu
{
	enum Type
	{
		Main,

		max
	};
public:
	virtual ~Menu();

	virtual std::size_t getNKeys() const = 0;
	/**
	 * "Click" on the menu item. The entire state of the client is passed to do
	 * useful work.
	 */
	virtual void exec(Client&) = 0;
	/**
	 * Triggered when Esc key is pressed.
	 * The default behaviour is to delete the top element of the menu stack.
	 * a.k.a. self-destroy. This is overridden by the main menu.
	 */
	virtual void escape(Client&) const;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const = 0;
};

} // namespace thk


#endif // !_THKAME_CLIENT_MENU_HPP__

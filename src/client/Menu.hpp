#ifndef _THKAME_CLIENT_MENU_HPP__
#define _THKAME_CLIENT_MENU_HPP__

#include <cstddef>

#include "ResourceManager.hpp"
#include "../core/ServerSetup.hpp"

class THKameClient;

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
	virtual void exec(THKameClient&) const = 0;
	/**
	 * Triggered when Esc key is pressed.
	 * The default behaviour is to delete the top element of the menu stack.
	 * a.k.a. self-destroy. This is overridden by the main menu.
	 */
	virtual void escape(THKameClient&) const;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const = 0;
};

/**
 * The main menu. Does not explicitly store a state
 */
class MenuMain final: public Menu
{
public:
	virtual std::size_t getNKeys() const;
	virtual void exec(THKameClient&) const;
	virtual void escape(THKameClient&) const;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const;

private:
};

/**
 * The first (Hence 0) level menu for selecting a player.
 */
class MenuPlayer0 final: public Menu
{
public:
	// The ServerSetup object is passed on to further submenues.
	MenuPlayer0(ServerSetup);

	virtual std::size_t getNKeys() const;
	virtual void exec(THKameClient&) const;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const;

private:
	ServerSetup setup;
};

// Implementations

inline MenuPlayer0::MenuPlayer0(ServerSetup setup):
	setup(setup)
{
}
#endif // !_THKAME_CLIENT_MENU_HPP__

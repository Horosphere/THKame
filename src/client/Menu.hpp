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


/**
 * The main menu. Does not explicitly store a state
 */
class MenuMain final: public Menu
{
public:
	virtual std::size_t getNKeys() const override;
	virtual void exec(Client&) override;
	virtual void escape(Client&) const override;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const override;

private:
};

class MenuDifficulty final: public Menu
{
public:
	// The ServerSetup object is passed on to further submenues.
	MenuDifficulty(ServerSetup);

	virtual std::size_t getNKeys() const override { return 4; }
	virtual void exec(Client&) override;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const override;

private:
	ServerSetup setup;
};
/**
 * The first (Hence 0) level menu for selecting a player.
 */
class MenuCharacter final: public Menu
{
public:
	// The ServerSetup object is passed on to further submenues.
	MenuCharacter(ServerSetup);

	virtual std::size_t getNKeys() const override { return 3; }
	virtual void exec(Client&) override;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const override;

private:
	ServerSetup setup;
};
class MenuWeapon final: public Menu
{
public:
	// The ServerSetup object is passed on to further submenues.
	MenuWeapon(ServerSetup);

	virtual std::size_t getNKeys() const override { return 2; }
	virtual void exec(Client&) override;
	virtual void draw(sf::RenderWindow&, ResourceManager&,
			std::size_t selected) const override ;

private:
	ServerSetup setup;
};

} // namespace thk

// Implementations

inline thk::MenuCharacter::MenuCharacter(ServerSetup setup):
	setup(setup)
{
}
inline thk::MenuWeapon::MenuWeapon(ServerSetup setup):
	setup(setup)
{
}
inline thk::MenuDifficulty::MenuDifficulty(ServerSetup setup):
	setup(setup)
{
}
#endif // !_THKAME_CLIENT_MENU_HPP__

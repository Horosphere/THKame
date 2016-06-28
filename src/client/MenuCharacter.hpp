#ifndef _THKAME_CLIENT_MENUCHARACTER_HPP__
#define _THKAME_CLIENT_MENUCHARACTER_HPP__

#include "Menu.hpp"

namespace thk
{

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
#endif // !_THKAME_CLIENT_MENUCHARACTER_HPP__

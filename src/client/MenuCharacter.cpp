#include "MenuCharacter.hpp"

#include "Client.hpp"
#include "../core/Server.hpp"

// Character selection menus
void thk::MenuDifficulty::exec(Client& client)
{
	setup.difficulty = client.state.menuSelected;
	client.state.menuSelected = 0;
	client.menuStack.push(new MenuCharacter(setup));
}
void thk::MenuDifficulty::draw(sf::RenderWindow& window,
                       ResourceManager& rm,
                       std::size_t key) const
{
	window.draw(rm.sTitle1);
	// Start at 240, 224
	rm.sDifficultiesInactive.setPosition(240, 224);
	window.draw(rm.sDifficultiesInactive);
	rm.sDifficultiesActive.setTextureRect(sf::IntRect(0, 160 * key, 512, 160));
	rm.sDifficultiesActive.setPosition(240, 224 + 160 * key);
	window.draw(rm.sDifficultiesActive);

	
}
void thk::MenuCharacter::exec(Client& client)
{
	setup.player = client.state.menuSelected;
	client.state.menuSelected = 0;
	client.menuStack.push(new MenuWeapon(setup));
}

void thk::MenuCharacter::draw(sf::RenderWindow& window,
                       ResourceManager& rm,
                       std::size_t key) const
{
	window.draw(rm.sTitle1);
	sf::Sprite* sButton;

	// Start at 240, 224
	int startX = 240 - (int) key * 800;
	for (std::size_t i = 0; i < getNKeys(); ++i)
	{
		sButton = &rm.sCharacters[i];
		sButton->setPosition(startX + (int)i * 800, 224);
		window.draw(*sButton);
	}
	
}

void thk::MenuWeapon::exec(Client& client)
{
	setup.weapon = client.state.menuSelected;
	client.state.menuSelected = 0;
	// Initialise the server
	Server* server = new Server(setup);
	client.launchServer(server);
}

void thk::MenuWeapon::draw(sf::RenderWindow& window,
                       ResourceManager& rm,
                       std::size_t key) const
{
	window.draw(rm.sTitle1);
	sf::Sprite* sButton;

	// Start at 240, 224
	int startX = 240 - (int) key * 800;
	for (std::size_t i = 0; i < getNKeys(); ++i)
	{
		sButton = &rm.sWeapons[i + setup.player * 2];
		sButton->setPosition(startX + (int)i * 800, 224);
		window.draw(*sButton);
	}
	
}

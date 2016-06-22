#include "Menu.hpp"

#include <iostream>

#include "Client.hpp"

thk::Menu::~Menu()
{
}

void thk::Menu::escape(Client& client) const
{
	delete client.menuStack.top();
	client.menuStack.pop();
}


// MenuMain

std::size_t thk::MenuMain::getNKeys() const
{
	return 3;
}
void thk::MenuMain::exec(Client& client)
{
	// Use if-else clause since variables need to be instantiated inside
	if (client.state.menuSelected == 0)
	{
		client.menuStack.push(new MenuDifficulty(ServerSetup()));
	}
	else if (client.state.menuSelected == 1)
	{
		std::cout << "Music triggered\n";
	}
	else
	{
		std::cout << "Options triggered\n";
	}
}
void thk::MenuMain::escape(Client&) const
{
	// Does nothing since main menu is the highest
}

void thk::MenuMain::draw(sf::RenderWindow& window,
                    ResourceManager& rm,
                    std::size_t key) const
{
	static ResourceManager::Texture const keys[] =
	{
		ResourceManager::Texture::SL_Player,
		ResourceManager::Texture::SL_Music,
		ResourceManager::Texture::SL_Option
	};
	window.draw(rm.sTitle0);
	// Buttons start at 180, 200
	(void) key;
	sf::Sprite* sButton;
	for (std::size_t i = 0; i < getNKeys(); ++i)
	{
		sButton = &rm.getSLButton(keys[i]);
		sButton->setPosition(180, 200 + (int)i * 140);
		if (i == key)
			sButton->setScale(1.1f, 1.1f);
		else
			sButton->setScale(1.f, 1.f);
		window.draw(*sButton);
	}

}


// Character selection menus
void thk::MenuDifficulty::exec(Client& client)
{
	setup.difficulty = client.state.menuSelected;
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
	(void) client;
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

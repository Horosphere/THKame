#include "MenuMain.hpp"

#include <iostream>

#include "MenuCharacter.hpp"
#include "Client.hpp"

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

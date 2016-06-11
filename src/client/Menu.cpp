#include "Menu.hpp"

#include <iostream>

#include "THKameClient.hpp"

Menu::~Menu()
{
}

void Menu::escape(THKameClient& client) const
{
	delete client.menuStack.top();
	client.menuStack.pop();
}


// MenuMain

std::size_t MenuMain::getNKeys() const
{
	return 3;
}
void MenuMain::exec(THKameClient& client) const
{
	// Use if-else clause since variables need to be instantiated inside
	if (client.state.menuSelected == 0)
	{
		MenuPlayer0* p0 = new MenuPlayer0(ServerSetup());
		client.menuStack.push(p0);
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
void MenuMain::escape(THKameClient&) const
{
	// Does nothing since main menu is the highest
}

void MenuMain::draw(sf::RenderWindow& window,
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


std::size_t MenuPlayer0::getNKeys() const
{
	return 3;
}
void MenuPlayer0::exec(THKameClient& client) const
{
	switch (client.state.menuSelected)
	{
	case 0:
		std::cout << "Player0 triggered\n";
		break;
	case 1:
		std::cout << "Player1 triggered\n";
		break;
	case 2:
		std::cout << "Player2 triggered\n";
	}
}

void MenuPlayer0::draw(sf::RenderWindow& window,
                       ResourceManager& rm,
                       std::size_t key) const
{
	window.draw(rm.sTitle1);
	(void) key;
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

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
	constexpr int const left = 180;
	constexpr int const top = 200;
	constexpr int const step = 140;

	static Texture const buttons[] =
	{
		Texture::SL_Player,
		Texture::SL_Music,
		Texture::SL_Option
	};
	window.draw(sf::Sprite(rm.getTexture(Texture::Title0)));
	sf::Sprite sprite;
	for (std::size_t i = 0; i < getNKeys(); ++i)
	{
		sprite.setTexture(rm.getTexture(buttons[i]));
		sprite.setPosition(left, top + (int)i * step);

		// Enlarge the selected button
		if (i == key)
			sprite.setScale(1.1f, 1.1f);
		else
			sprite.setScale(1.f, 1.f);
		window.draw(sprite);
	}

}

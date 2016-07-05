#include "MenuCharacter.hpp"

#include "Client.hpp"

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
	constexpr int const left = 240;
	constexpr int const top = 224;

	window.draw(sf::Sprite(rm.getTexture(Texture::Title1)));

	// Draw inactive menu
	sf::Sprite sprite(rm.getTexture(Texture::Difficulties));
	sprite.setTextureRect(sf::IntRect(512, 0, 640, 1024));
	sprite.setPosition(left, top);
	window.draw(sprite);

	// Draw active menu option.
	sprite.setTextureRect(sf::IntRect(0, 160 * key, 512, 160));
	sprite.setPosition(left, top + 160 * key);
	window.draw(sprite);

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
	constexpr int const left = 240;
	constexpr int const top = 224;
	constexpr int const step = 800;
	static Texture const buttons[] =
	{
		Texture::Character0,
		Texture::Character1,
		Texture::Character2
	};

	window.draw(sf::Sprite(rm.getTexture(Texture::Title1)));

	sf::Sprite sprite;

	// Start at 240, 224
	int x = left - (int) key * step;

	for (std::size_t i = 0; i < getNKeys(); ++i)
	{
		sprite.setTexture(rm.getTexture(buttons[i]));
		sprite.setPosition(x, top);
		window.draw(sprite);
		x += step;
	}

}

void thk::MenuWeapon::exec(Client& client)
{
	setup.weapon = client.state.menuSelected;
	client.state.menuSelected = 0;
	// Initialise the server
	client.launchServer(setup);
}

void thk::MenuWeapon::draw(sf::RenderWindow& window,
                           ResourceManager& rm,
                           std::size_t key) const
{
	constexpr int const left = 240;
	constexpr int const top = 224;
	constexpr int const step = 800;
	static Texture const buttons[] =
	{
		Texture::Weapon0,
		Texture::Weapon0b,
		Texture::Weapon1,
		Texture::Weapon1b,
		Texture::Weapon2,
		Texture::Weapon2b
	};


	window.draw(sf::Sprite(rm.getTexture(Texture::Title1)));
	sf::Sprite sprite;

	int startX = left - (int) key * step;
	for (std::size_t i = 0; i < getNKeys(); ++i)
	{
		sprite.setTexture(rm.getTexture(buttons[i + setup.player * 2]));
		sprite.setPosition(startX + (int)i * step, top);
		window.draw(sprite);
	}

}

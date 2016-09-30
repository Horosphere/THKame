#include "MenuMain.hpp"

#include <iostream>

#include "../math/numbers.hpp"

namespace thk
{

Scene* MenuMain::keyPressed(sf::Keyboard::Key key,
                            std::stack<Menu*>* const menus)
{
	(void) menus;

	switch (key)
	{
	case sf::Keyboard::Up:
		index = circularDecrease(index, nKeys);
		break;
	case sf::Keyboard::Down:
		index = circularIncrease(index, nKeys);
		break;
	case sf::Keyboard::Space:
		return new Scene;
	default:
		break;
	}
	return nullptr;
}
void MenuMain::draw(sf::RenderWindow* const window,
                    Resources const& resources) const
{
	constexpr int const left = 180;
	constexpr int const top = 200;
	constexpr int const step = 140;

	static Resources::TextureId const buttons[] =
	{
		Resources::SL_Player,
		Resources::SL_Music,
		Resources::SL_Option
	};

	sf::Sprite sprite;
	sprite.setTexture(resources.texture(Resources::Title0));
	window->draw(sprite);

	for (std::size_t i = 0; i < nKeys; ++i)
	{
		sprite.setTexture(resources.texture(buttons[i]));
		sprite.setPosition(left, top + (int)i * step);

		// Enlarge the selected button
		if (i == index)
			sprite.setScale(1.1f, 1.1f);
		else
			sprite.setScale(1.f, 1.f);
		window->draw(sprite);
	}
}

} // namespace thk

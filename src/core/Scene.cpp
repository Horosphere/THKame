#include "Scene.hpp"

#include <cmath>
#include <iostream>

#include "../client/text.hpp"
#include "../core/init.hpp"

namespace thk
{

Scene::Scene(): posX(0.0), posY(0.0)
{
}

void Scene::calculate(int duration)
{
	// Calculate

	constexpr float const speed = 0.005f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		posX -= duration * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		posX += duration * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		posY -= duration * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		posY += duration * speed;

	
	posX = clamp(posX, 0, 1);
	posY = clamp(posY, 0, 1);
}

void Scene::draw(sf::RenderWindow* const window,
                 Resources const& r) const
{
	(void) r;
	sf::CircleShape test(120);
	test.setFillColor(sf::Color(0, 128, 255));
	test.setOutlineThickness(32);
	test.setOutlineColor(sf::Color(24, 65, 125));
	test.setPointCount(64);
	test.setPosition(sts.trX(posX) - 60, sts.trY(posY) - 60);
	window->draw(test);
}

} // namespace thk

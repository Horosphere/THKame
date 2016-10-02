#include "Scene.hpp"

#include <cmath>
#include <iostream>

#include "../client/text.hpp"
#include "../core/init.hpp"

namespace thk
{

Scene::Scene(): posX(0.0), posY(0.0), world(-2.0, 2.0, -2.0, 2.0)
{
	/**
	 * Push the default generator onto the generators
	 */
	Generator gen(10);
	world.generators.push_back(gen);
}

void Scene::tick(int duration)
{
	// Calculate

	// Move the player
	constexpr float const speed = 0.005f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		posX -= duration * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		posX += duration * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		posY -= duration * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		posY += duration * speed;

	posX = clamp(posX, -1, 1);
	posY = clamp(posY, -1, 1);

	// Emit bullets from the player's position
	world.generators[0].setEnabled(sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
	world.generators[0].x = posX;
	world.generators[0].y = posY;

	world.tick(duration);
}

void Scene::draw(sf::RenderWindow* const window,
                 Resources const& r) const
{
	(void) r;

	// Draw the player
	
	sf::CircleShape player(50);
	player.setFillColor(sf::Color(0, 128, 255));
	player.setOutlineThickness(12);
	player.setOutlineColor(sf::Color(24, 65, 125));
	player.setPointCount(32);
	player.setPosition(sts.trX(posX) - 53, sts.trY(posY) - 53);
	window->draw(player);

	// Draw bullets
	sf::CircleShape bullet0(6);
	bullet0.setFillColor(sf::Color::White);
	
	for (auto& bullet: world.bulletsAutomatic)
	{
		bullet0.setPosition(sts.trX(bullet.x) - 6, sts.trY(bullet.y) - 6);
		window->draw(bullet0);
	}
	
}

} // namespace thk

#include "Scene.hpp"

#include <cmath>
#include <iostream>

#include "../client/text.hpp"
#include "../core/init.hpp"

namespace thk
{

Scene::Scene(): world(-2.0, 2.0, -2.0, 2.0)
{
	Player* player = new Player(&world, 0, 0);
	world.setPlayer(player);
}

void Scene::tick(int duration)
{
	// Calculate

	// Move the player
	Player* player = world.getPlayer();
	constexpr float const speed = 0.0005;
	player->vx = player->vy = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player->vx = -speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player->vx = speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player->vy = -speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player->vy = speed;

	player->setFiring(sf::Keyboard::isKeyPressed(sf::Keyboard::Z));

	world.tick(duration);
}

void Scene::draw(sf::RenderWindow* const window,
                 Resources const& r) const
{
	(void) r;

	// Draw the player

	Player const* p = world.getClientPlayer();
	sf::CircleShape player(50);
	player.setFillColor(sf::Color(0, 128, 255));
	player.setOutlineThickness(12);
	player.setOutlineColor(sf::Color(24, 65, 125));
	player.setPointCount(32);
	player.setPosition(sts.trX(p->x) - 53, sts.trY(p->y) - 53);
	window->draw(player);

	// Draw bullets
	sf::CircleShape bullet0(6);
	bullet0.setFillColor(sf::Color::White);

	auto entityRender = [&](Entity const* e)
	{
		bullet0.setPosition(sts.trX(e->x) - 6, sts.trY(e->y) - 6);
		window->draw(bullet0);
	};
	world.iterateEntities(entityRender);
}

} // namespace thk

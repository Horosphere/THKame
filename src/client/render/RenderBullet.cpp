#include "RenderBullet.hpp"

namespace thk
{

void RenderBullet::draw(Entity const* const entity) const 
{
	auto bullet = static_cast<Bullet const* const>(entity);

	sf::CircleShape circle(6);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(toScreen->trX(bullet->x) - 6, toScreen->trY(bullet->y) - 6);
	window->draw(circle);
}

} // namespace thk

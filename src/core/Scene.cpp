#include "Scene.hpp"

#include <iostream>

namespace thk
{

bool Scene::start(sf::RenderWindow* const window, int nThreads)
{
	(void) nThreads;

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				return false;
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "Escape" << std::endl;
				}
				else
					std::cout << "Key pressed" << std::endl;
				break;
			default:
				break;
			}
		}

		// Calculate

		draw(window);
	}

	return window->isOpen();
}

void Scene::draw(sf::RenderWindow* const window)
{
	window->clear(sf::Color::Black);

	sf::CircleShape test(120);
	test.setFillColor(sf::Color(0, 128, 255));
	test.setOutlineThickness(32);
	test.setOutlineColor(sf::Color(24, 65, 125));
	test.setPointCount(64);
	window->draw(test);

	window->display();
}

} // namespace thk

#include "Scene.hpp"

#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

#include "text.hpp"

namespace thk
{

Scene::Scene(): fps(0.f)
{
}
bool Scene::start(sf::RenderWindow* const window,
		Resources const& resources,
		int nThreads)
{
	(void) nThreads;

	pos = 0;
	auto timeLast = std::chrono::high_resolution_clock::now();

	while (window->isOpen())
	{
		int duration = std::chrono::duration_cast<std::chrono::milliseconds>
		               (std::chrono::high_resolution_clock::now() - timeLast).count();
		fps = 1000.f / duration;
		timeLast = std::chrono::high_resolution_clock::now();

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
		pos += duration / 3.f;
		pos = fmod(pos, window->getSize().x);

		draw(window, resources);
	}

	return window->isOpen();
}

void Scene::draw(sf::RenderWindow* const window,
		Resources const& r) const
{
	window->clear(sf::Color::Black);

	// Draw fps
	sf::Text textFPS;
	textFPS.setFont(r.fontMonospace);
	textFPS.setString(floatToString(fps, 4));
	textFPS.setCharacterSize(50);
	textFPS.setFillColor(sf::Color::White);
	window->draw(textFPS);

	sf::CircleShape test(120);
	test.setFillColor(sf::Color(0, 128, 255));
	test.setOutlineThickness(32);
	test.setOutlineColor(sf::Color(24, 65, 125));
	test.setPointCount(64);
	test.setPosition(pos - 60, 300);
	window->draw(test);

	window->display();
}

} // namespace thk

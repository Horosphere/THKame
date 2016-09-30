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

	posX = posY = 0.f;
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
		
		constexpr float const speed = 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			posX -= duration * speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			posX += duration * speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			posY -= duration * speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			posY += duration * speed;

		posX = fmod(posX, window->getSize().x);
		posY = fmod(posY, window->getSize().y);

		draw(window, resources);
	}

	return window->isOpen();
}

void Scene::draw(sf::RenderWindow* const window,
		Resources const& r) const
{
	window->clear(sf::Color::Black);


	sf::CircleShape test(120);
	test.setFillColor(sf::Color(0, 128, 255));
	test.setOutlineThickness(32);
	test.setOutlineColor(sf::Color(24, 65, 125));
	test.setPointCount(64);
	test.setPosition(posX - 60, posY - 60);
	window->draw(test);

	// Draw fps
	sf::Text textFPS;
	textFPS.setFont(r.fontMonospace);
	textFPS.setString(floatToString(fps, 4));
	textFPS.setCharacterSize(50);
	textFPS.setFillColor(sf::Color::White);
	window->draw(textFPS);

	window->display();
}

} // namespace thk

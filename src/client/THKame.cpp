#include "THKame.hpp"

#include <iostream>
#include <chrono>
#include <thread>

#include "MenuMain.hpp"
#include "text.hpp"

namespace thk
{

THKame::THKame() noexcept: scene(nullptr)
{
}
bool THKame::init()
{
	sf::ContextSettings cs;
	cs.antialiasingLevel = 8;

	window.create(sf::VideoMode(1280, 960),
	              "THKame",
	              sf::Style::Default,
	              cs);

	thk::Resources r;
	if (!r.load("../resources/"))
	{
		std::cout << "Unable to load resources. Quit" << std::endl;
		return false;
	}
	menus.push(new MenuMain);

	return true;
}
void THKame::exec()
{
	auto timeLast = std::chrono::high_resolution_clock::now();
	while (window.isOpen())
	{
		/*
		 * Calculate time between frames in milliseconds and update fps
		 */
		int duration = std::chrono::duration_cast<std::chrono::milliseconds>
		               (std::chrono::high_resolution_clock::now() - timeLast).count();
		fps = 1000.f / duration;
		timeLast = std::chrono::high_resolution_clock::now();

		sf::Event event;
		if (menus.empty()) // Scene must be up
		{
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					delete scene;
					return;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
					{
						delete scene;
						menus.push(new MenuMain);
						continue;
					}
					break;
				default:
					break;
				}
			}
		}
		else // Menus must be up
		{
			while (window.pollEvent(event))
			{
				Scene* temp;

				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					delete scene;
					return;
				case sf::Event::KeyPressed:
					temp = menus.top()->keyPressed(event.key.code, &menus);
					if (temp)
					{
						std::cout << "Init scene" << std::endl;
						// Assign scene and pop all menus
						scene = temp;
						while (!menus.empty())
						{
							delete menus.top();
							menus.pop();
						}
					}
					break;
				default:
					break;
				}
			}
		}

		if (scene) scene->calculate(duration);

		// Draw
		window.clear();
		if (menus.empty())
		{
			std::cout << "Menu empty" << std::endl;
			scene->draw(&window, resources);
		}
		else
		{
			//menus.top()->draw(&window, resources);
		}

		// Draw fps
		sf::Text textFPS;
		textFPS.setFont(resources.fontMonospace);
		textFPS.setString(floatToString(fps, 4));
		textFPS.setCharacterSize(120);
		textFPS.setFillColor(sf::Color::White);

		window.draw(textFPS);

		window.display();
	}
}

} // namespace thk

#include "THKame.hpp"

#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>

#include "MenuMain.hpp"
#include "text.hpp"
#include "render/RenderBullet.hpp"

namespace thk
{

THKame::THKame() noexcept: scene(nullptr)
{
}
bool THKame::init()
{
	sf::ContextSettings cs;
	cs.antialiasingLevel = 8; // Enable antialiasing

	window.create(sf::VideoMode(1280, 960),
	              "THKame",
	              sf::Style::Default,
	              cs);

	if (!resources.load("../resources/"))
	{
		std::cout << "Unable to load resources. Quit" << std::endl;
		return false;
	}

	// Push main menu onto the menustack
	menus.push(new MenuMain);

	std::cout << "Client initialised" << std::endl;

	return true;
}
void THKame::exec()
{
	fpsDisplayDuration = 0; // Reset duration

	auto timeLast = std::chrono::high_resolution_clock::now();
	while (window.isOpen())
	{
		/*
		 * Calculate time between frames in milliseconds and update fps
		 */
		int duration = std::chrono::duration_cast<std::chrono::milliseconds>
		               (std::chrono::high_resolution_clock::now() - timeLast).count();

		// Update fps every 250ms
		fpsDisplayDuration += duration;
		if (fpsDisplayDuration > 250)
		{
			fps = 1000.f / duration;
			fpsDisplayDuration = 0;
		}
		timeLast = std::chrono::high_resolution_clock::now();

		// Receive events from SFML

		sf::Event event;
		if (menus.empty()) // Scene must be up
		{
			assert(scene);

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
						scene = nullptr;
						menus.push(new MenuMain);
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
					if (temp) initScene(temp);
					break;
				default:
					break;
				}
			}
		}

		if (scene) scene->tick(duration);

		// Draw

		window.clear();

		if (scene)
			scene->draw(&window, resources);

		if (!menus.empty())
			menus.top()->draw(&window, resources);
		assert(scene || !menus.empty());

		// Draw fps on top-left corner
		sf::Text textFPS;
		textFPS.setFont(resources.fontMonospace);
		textFPS.setString(floatToString(fps, 4));
		textFPS.setCharacterSize(60);
		textFPS.setFillColor(sf::Color::White);

		window.draw(textFPS);

		window.display();
	}
}

void THKame::initScene(Scene* s)
{
	scene = s;
	s->registerRenderer<Bullet>(new RenderBullet(&window, &resources, &toScreen));
	while (!menus.empty())
	{
		delete menus.top();
		menus.pop();
	}
}
} // namespace thk

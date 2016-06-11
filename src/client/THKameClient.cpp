#include "THKameClient.hpp"

#include <iostream>

THKameClient::THKameClient():
	// Using a 1280x960 window since that is the dimension of our BG
	window(sf::VideoMode(1280, 960), "THKame"),
	server(nullptr)
{
	// Avoid busy waiting in drawing cycles.
	window.setVerticalSyncEnabled(true);
	std::cout << "Initialising THKame Client\n";
	state.mode = THKameState::MAIN_MENU;
	state.menuSelected = 0;
}

void THKameClient::start()
{
	if (!rm.init("resources/"))
	{
		std::cout << "Resource Initialisation failed\n";
		return;
	}
	std::cout << "THKame client starting...\n";
	// Push Main menu into the menu stack
	menuStack.push(new MenuMain);
	while (window.isOpen())
	{
		handleEvents();
		draw();
	}
	std::cout << "THKame client shutting down...\n";

	// Pops all menus and clean up
	while (!menuStack.empty())
	{
		delete menuStack.top();
		menuStack.pop();
	}
}

void THKameClient::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				++state.menuSelected;
				if (state.menuSelected == menuStack.top()->getNKeys())
					state.menuSelected = 0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				state.menuSelected = state.menuSelected == 0 ?
					menuStack.top()->getNKeys() - 1 : state.menuSelected - 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				menuStack.top()->exec(*this);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				menuStack.top()->escape(*this);
			}
		}
	}
}

void THKameClient::draw()
{
	window.clear();
	
	if (!menuStack.empty())
	{
		menuStack.top()->draw(window, rm, state.menuSelected);
	}
	// This needs to be cleaned up
	
	// Draws a circle
	// sf::CircleShape shape(100.f);
	// shape.setFillColor(sf::Color::Green);

	window.display();
}

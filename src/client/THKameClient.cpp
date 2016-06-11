#include "THKameClient.hpp"

#include <iostream>

#include "client.hpp"

THKameClient::THKameClient():
	window(sf::VideoMode(1280, 960), "THKame")
{
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
		}
	}
}

void THKameClient::draw()
{
	window.clear();

	// This needs to be cleaned up
	if (state.mode == THKameState::MAIN_MENU)
	{
		window.draw(rm.sTitle1);
		sf::Sprite& sButton = rm.getSLButton(ResourceManager::Texture::SL_Option);
		sButton.setPosition(127.0,127.0);
		window.draw(sButton);


		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		window.draw(shape);
	}
	else if (state.mode == THKameState::IN_GAME)
	{
	}

	window.display();
}

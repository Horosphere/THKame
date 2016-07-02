#include "Client.hpp"

#include <iostream>
#include <thread>
#include <boost/thread.hpp>

#include "MenuMain.hpp"

thk::Client::Client():
	// Using a 1280x960 window since that is the dimension of our BG
	window(sf::VideoMode(1280, 960), "THKame"),
	server(nullptr)
{
	// Avoid busy waiting in drawing cycles.
	window.setVerticalSyncEnabled(true);
	std::cout << "Initialising THKame Client\n";
	state.mode = ClientState::MAIN_MENU;
	state.menuSelected = 0;
}

void thk::Client::launchServer(Server* s)
{
	// Removes all menus from the menu stack
	while (!menuStack.empty())
	{
		delete menuStack.top();
		menuStack.pop();
	}
	server = s;
	std::thread serverThread(&Server::start, server);
	serverThread.detach();
}
void thk::Client::start()
{
	if (!rm.init("resources/"))
	{
		std::cout << "Resource Initialisation failed\n";
		return;
	}
	spriteTest.setTexture(rm.getTexture(Texture::SL_Rank));
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

void thk::Client::handleEvents()
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
			if (menuStack.empty()) // Server must be up
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				{
					// Do not delete the server here. The server deletes itself.
					server->stop();
					server = nullptr;
					menuStack.push(new MenuMain);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					server->pushCommand(Command::Up);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					server->pushCommand(Command::Down);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					server->pushCommand(Command::Left);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					server->pushCommand(Command::Right);
			}
			else // Server offline or not receiving keyboard instructions.
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
						sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					++state.menuSelected;
					if (state.menuSelected == menuStack.top()->getNKeys())
						state.menuSelected = 0;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
						sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
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
}

void thk::Client::draw()
{
	window.clear();

	if (server)
	{
		spriteTest.setPosition(server->pX, server->pY);
		window.draw(spriteTest);
	}
	if (!menuStack.empty())
	{
		menuStack.top()->draw(window, rm, state.menuSelected);
	}
	// This needs to be cleaned up


	window.display();
}

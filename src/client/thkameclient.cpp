#include "thkameclient.hpp"

THKameClient::THKameClient(THKLog* const log):
	log(log),
	window(sf::VideoMode(200, 200), "THKame")
{
	log->write("Initialising THKame Client\n");
	state.mode = THKameState::MAIN_MENU;
	state.menuSelected = 0;
}

void THKameClient::start()
{
	log->write("THKame client starting...\n");
	while (window.isOpen())
	{
		/*
		 * Processes events
		 */
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		draw();
	}
	log->write("THKame client shutting down...\n");
}

void THKameClient::draw()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window.clear();
	window.draw(shape);
	window.display();
}

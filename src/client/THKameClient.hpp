#ifndef _THKAME_CLIENT_THKAMECLIENT_HPP__
#define _THKAME_CLIENT_THKAMECLIENT_HPP__

#include <stack>
#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "Menu.hpp"
#include "../core/THKame.hpp"

struct THKameState final
{
	enum
	{
		MAIN_MENU,
		IN_GAME
	} mode;
	uint8_t menuSelected;

};

class THKameClient final
{
public:
	THKameClient();

	void start();
	
	THKameState state;
private:
	
	void handleEvents();
	void draw();

	sf::RenderWindow window;

	/*
	 * This is not const since the draw function makes reference to its sprites.
	 */
	ResourceManager rm;

	std::stack<Menu const*> menuStack;

	// Server
	THKame* server;

};

#endif // !_THKAME_CLIENT_THKAMECLIENT_HPP__

#ifndef _THKAME_CLIENT_CLIENT_HPP__
#define _THKAME_CLIENT_CLIENT_HPP__

#include <stack>
#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "Menu.hpp"
#include "../core/Server.hpp"

namespace thk
{

struct ClientState final
{
	enum
	{
		MAIN_MENU,
		IN_GAME
	} mode;
	uint8_t menuSelected;

};

class Client final
{
public:
	Client();

	void start();
	
	ClientState state;
	std::stack<Menu*> menuStack;
private:
	
	void handleEvents();
	void draw();

	sf::RenderWindow window;

	/*
	 * This is not const since the draw function makes reference to its sprites.
	 */
	ResourceManager rm;

	// Server
	Server* server;

};

} // namespace thk

#endif // !_THKAME_CLIENT_CLIENT_HPP__

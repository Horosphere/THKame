#ifndef _THKAME_CLIENT_THKAMECLIENT_HPP__
#define _THKAME_CLIENT_THKAMECLIENT_HPP__

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "../core/THKLog.hpp"

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
	THKameClient(THKLog* const);

	void start();
	
private:
	THKameState state;
	
	void draw();
	THKLog* const log;

	sf::RenderWindow window;
	ResourceManager rm;

};

#endif // !_THKAME_CLIENT_THKAMECLIENT_HPP__

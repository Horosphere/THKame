#ifndef THKAMECLIENT_HPP
#define THKAMECLIENT_HPP

#include <SFML/Graphics.hpp>

#include "../core/thklog.hpp"

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

};

#endif // !THKAMECLIENT_HPP

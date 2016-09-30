
#include <iostream>

#include "core/Scene.hpp"

int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;

	sf::ContextSettings cs;
	cs.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600),
	                        "THKame",
	                        sf::Style::Default,
	                        cs);

	thk::Resources r;
	if (!r.load("../resources/"))
	{
		std::cout << "Unable to load resources. Quit" << std::endl;
		return -1;
	}

	thk::Scene scene;
	scene.start(&window, r, 4);

	return 0;
}


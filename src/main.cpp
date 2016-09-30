
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

	thk::Scene scene;
	scene.start(&window, 4);

	return 0;
}


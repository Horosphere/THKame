#include <SFML/Graphics.hpp>

#include "client/Client.hpp"

int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;
	
	thk::Client client;
	client.start();

	return 0;
}


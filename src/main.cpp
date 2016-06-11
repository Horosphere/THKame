#include <SFML/Graphics.hpp>

#include "client/THKameClient.hpp"

int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;
	
	THKameClient client;
	client.start();

	return 0;
}


#include <SFML/Graphics.hpp>

#include "client/THKameClient.hpp"

int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;
	
	THKLog log("thkame.log");
	THKameClient client(&log);
	client.start();

	return 0;
}


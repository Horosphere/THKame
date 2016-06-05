#include <SFML/Graphics.hpp>

#include "client/thkameclient.hpp"

int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;
	
	THKLog log("thkame.log");
	THKameClient client(&log);
	client.start();

	return 0;
}


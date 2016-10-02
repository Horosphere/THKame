/**
 * Main entry of the application
 */
#include <iostream>

#include "client/THKame.hpp"

int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;

	thk::THKame application;
	if (!application.init()) return -1;

	application.exec(); // Main loop

	return 0;

}


#include <iostream>

#include "client/THKame.hpp"
#include "client/MenuMain.hpp"

int main(int argc, char* argv[])
{
	(void) argc;
	(void) argv;

	thk::THKame application;
	if (!application.init()) return -1;

	application.exec();

	return 0;

}

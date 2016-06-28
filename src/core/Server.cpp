#include "Server.hpp"

#include <thread>

thk::Server::Server(ServerSetup setup): setup(setup), running(false)
{
}

void thk::Server::start()
{
	running = true;
	while (running)
	{
		Command command;
		while (commandQueue.pop(command))
		{
		}
		pauseMutex.lock();
		pauseMutex.unlock();

		// TODO: Use a timer to ensure that each loop proceeds minimally 10ms
		std::this_thread::yield();
	}
	delete this;
}

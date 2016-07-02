#include "Server.hpp"

#include <thread>

thk::Server::Server(ServerSetup setup): setup(setup), running(false)
{
}

void thk::Server::start()
{
	pX = pY = 0.0;
	/*
	 * "Minimal Loop Duration": The minimum time for one loop
	 */
	static std::chrono::milliseconds mld(10);
	running = true;
	while (running)
	{
		timeStamp = std::chrono::steady_clock::now();
		Command command;
		while (commandQueue.pop(command))
		{
			switch (command)
			{
			case Command::Up:
				pY -= 10.0;
				break;
			case Command::Down:
				pY += 10.0;
				break;
			case Command::Left:
				pX -= 10.0;
				break;
			case Command::Right:
				pX += 10.0;
				break;
			}
		}
		pauseMutex.lock();
		pauseMutex.unlock();

		// TODO: Use a timer to ensure that each loop proceeds minimally 10ms
		std::this_thread::sleep_until(timeStamp + mld);
	}
	delete this;
}

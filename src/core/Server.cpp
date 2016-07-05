#include "Server.hpp"

#include <thread>

thk::Server::Server(ServerSetup setup, Danmaku const* const danmaku): 
	setup(setup), danmaku(danmaku), running(false)
{
	world.setBoundary(600, 600);
}

void thk::Server::start()
{
	player.pX = player.pY = 0.0;
	Bullet playerBullet;
	playerBullet.vX = 0.0;
	playerBullet.vY = -50.0;

	/*
	 * "Minimal Loop Duration": The minimum time for one loop
	 */
	static std::chrono::milliseconds mld(10);
	running = true;
	while (running)
	{
		timeStamp = std::chrono::steady_clock::now();
		
		std::vector<Bullet> bullets;
		
		Command command;
		while (commandQueue.pop(command))
		{
			switch (command)
			{
			case Command::Up:
				player.pY -= 10.0;
				break;
			case Command::Down:
				player.pY += 10.0;
				break;
			case Command::Left:
				player.pX -= 10.0;
				break;
			case Command::Right:
				player.pX += 10.0;
				break;
			case Command::Emit:
				playerBullet.index = 0;
				playerBullet.pX = player.pX;
				playerBullet.pY = player.pY;
				bullets.push_back(playerBullet);
				break;
			}
		}

		world.insertBullets(bullets);
		world.tick();
		
		pauseMutex.lock();
		pauseMutex.unlock();

		// TODO: Use a timer to ensure that each loop proceeds minimally 10ms
		std::this_thread::sleep_until(timeStamp + mld);
	}
	delete this;
}

#ifndef _THKAME_CORE_SERVER_HPP__
#define _THKAME_CORE_SERVER_HPP__

#include <atomic>
#include <mutex>
#include <chrono>

#include <boost/lockfree/spsc_queue.hpp>

#include "ServerSetup.hpp"
#include "Danmaku.hpp"
#include "../world/World.hpp"

namespace thk
{

enum struct Command
{
	Up,
	Down,
	Left,
	Right,
	Emit
};

struct Player final
{
	double pX, pY;
};

class Server final
{
public:
	/**
	 * @warning Servers should only be created using new and deleted with stop().
	 */
	Server(ServerSetup, Danmaku const* const);

	/**
	 * @brief Starts the Server loop. This should be ran in a different thread.
	 */
	void start();
	/**
	 * @brief Stops the server and deletes itself.
	 */
	void stop() noexcept;


	/**
	 * @warning May cause a deadlock if called from several threads.
	 * @brief Blocks the Server loop so it cannot do further calculations.
	 */
	void pause() noexcept;
	/**
	 * @brief Unblocks the server loop.
	 */
	void unpause() noexcept;
	
	bool isRunning() const noexcept;
	/**
	 * @brief Pushes a command into the command queue.
	 */
	void pushCommand(Command);

	Player player;
	World world;
private:
	ServerSetup const setup;
	Danmaku const* const danmaku;

	// Dynamic
	
	// A 16 element queue should be enough
	boost::lockfree::spsc_queue<Command, boost::lockfree::capacity<16>> commandQueue;
	std::mutex pauseMutex;

	// Dynamic variables
	std::atomic_bool running;
	std::chrono::time_point<std::chrono::steady_clock> timeStamp;
};


} // namespace thk

// Implementations

inline void thk::Server::stop() noexcept
{
	running = false;
	pauseMutex.unlock();
}
inline void thk::Server::pause() noexcept
{
	pauseMutex.lock();
}
inline void thk::Server::unpause() noexcept
{
	pauseMutex.unlock();
}
inline bool thk::Server::isRunning() const noexcept
{
	return running;
}

inline void thk::Server::pushCommand(Command command)
{
	commandQueue.push(command);
}
#endif // !_THKAME_CORE_SERVER_HPP__

#ifndef _THKAME_CORE_SERVER_HPP__
#define _THKAME_CORE_SERVER_HPP__

#include <mutex>
#include <boost/lockfree/spsc_queue.hpp>

#include "ServerSetup.hpp"

namespace thk
{

enum struct Command
{
	Exit = 0,
	Up,
	Down,
	Left,
	Right
};

/**
 * @brief The core of THKame. This thread is responsible for handling in term
 */
class Server final
{
public:
	/**
	 * @warning Servers should only be created using new and deleted with stop().
	 */
	Server(ServerSetup);

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
private:
	ServerSetup setup;

	// Dynamic
	
	// A 16 element queue should be enough
	boost::lockfree::spsc_queue<Command, boost::lockfree::capacity<16>> commandQueue;
	std::mutex pauseMutex;
	bool running;
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

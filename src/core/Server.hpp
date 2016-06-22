#ifndef _THKAME_CORE_SERVER_HPP__
#define _THKAME_CORE_SERVER_HPP__

#include "ServerSetup.hpp"

namespace thk
{

/**
 * @brief The core of THKame. This thread is responsible for handling in term
 */
class Server
{
public:
	Server(ServerSetup);

private:
	ServerSetup setup;
};


} // namespace thk

#endif // !_THKAME_CORE_SERVER_HPP__

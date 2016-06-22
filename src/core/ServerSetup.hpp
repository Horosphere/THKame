#ifndef _THKAME_CORE_SERVERSETUP_HPP__
#define _THKAME_CORE_SERVERSETUP_HPP__

#include <cstdint>

namespace thk
{

struct ServerSetup
{
	ServerSetup();

	uint8_t difficulty; // Combinations: 4
	uint8_t player; // Combinations: 3
	uint8_t weapon; // Combinations: 2
};

} // namespace thk

// Implementations

inline thk::ServerSetup::ServerSetup():
	difficulty(0), player(0), weapon(0)
{
}

#endif // !_THKAME_CORE_SERVERSETUP_HPP__

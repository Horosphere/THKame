#ifndef _THKAME_CORE_TEXT_HPP__
#define _THKAME_CORE_TEXT_HPP__

#include <string>

namespace thk
{

std::string floatToString(float, int size);


// Implementations

inline std::string
floatToString(float f, int size)
{
	std::string str = std::to_string(f);
	str.resize(size);
	return str;
}

} // namespace thk

#endif // !_THKAME_CORE_TEXT_HPP__

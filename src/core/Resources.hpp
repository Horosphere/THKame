#ifndef _THKAME_CORE_RESOURCES_HPP__
#define _THKAME_CORE_RESOURCES_HPP__

#include <string>

#include <SFML/Graphics.hpp>

namespace thk
{

class Resources
{
public:
	bool load(std::string directory);

	sf::Font fontMonospace;
};

} // namespace thk

#endif // !_THKAME_CORE_RESOURCES_HPP__

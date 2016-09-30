#include "Resources.hpp"


namespace thk
{

bool Resources::load(std::string directory)
{
	bool flag;

	flag = fontMonospace.loadFromFile(directory + "LiberationMono.ttf");
	if (!flag) return false;

	return true;
}

} // namespace thk

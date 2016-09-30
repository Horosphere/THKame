#include "Resources.hpp"

#include <iostream>

namespace thk
{

bool Resources::load(std::string directory)
{
	bool flag;

	flag = fontMonospace.loadFromFile(directory + "LiberationMono.ttf");
	if (!flag) return false;

#define LOAD_TEXTURE(key, fileName) \
	flag = textures[(std::size_t) key].loadFromFile(directory + fileName); \
	if (!flag) \
	{ \
		std::cout << "Unable to load texture: " \
		          << directory + fileName << std::endl; \
		return false; \
	}

	LOAD_TEXTURE(Title0, "ui/title_bk00.png");
	LOAD_TEXTURE(Title1, "ui/title_bk01.png");
	LOAD_TEXTURE(Difficulties, "ui/difficulties.png");
	LOAD_TEXTURE(Character0, "ui/player_00.png");
	LOAD_TEXTURE(Character1, "ui/player_01.png");
	LOAD_TEXTURE(Character2, "ui/player_02.png");
	LOAD_TEXTURE(Weapon0, "ui/weapon_00.png");
	LOAD_TEXTURE(Weapon0b, "ui/weapon_00b.png");
	LOAD_TEXTURE(Weapon1, "ui/weapon_01.png");
	LOAD_TEXTURE(Weapon1b, "ui/weapon_01b.png");
	LOAD_TEXTURE(Weapon2, "ui/weapon_01.png");
	LOAD_TEXTURE(Weapon2b, "ui/weapon_01b.png");

	return true;
}

} // namespace thk

#ifndef _THKAME_CLIENT_RESOURCES_HPP__
#define _THKAME_CLIENT_RESOURCES_HPP__

#include <string>

#include <SFML/Graphics.hpp>

namespace thk
{

class Resources
{
public:
	bool load(std::string directory);

	enum TextureId
	{
		Title0,
		Title1,
		Difficulties,
		Character0,
		Character1,
		Character2,
		Weapon0,
		Weapon0b,
		Weapon1,
		Weapon1b,
		Weapon2,
		Weapon2b,

		SL_KeyConfig,
		SL_Manual,
		SL_Music,
		SL_Option,
		SL_Player,
		SL_PlayerData,
		SL_Rank,
		SL_Regist,
		SL_Replay,
		SL_SaveReplay,
		SL_Spell,
		SL_Stage,
		SL_Weapon,

		TidMax
	};
	sf::Texture const& texture(TextureId) const;
	sf::Font fontMonospace;

private:
	sf::Texture textures[(std::size_t)TidMax];
};


// Implementations

inline sf::Texture const&
Resources::texture(Resources::TextureId tid) const
{
	return textures[tid];
}

} // namespace thk

#endif // !_THKAME_CLIENT_RESOURCES_HPP__

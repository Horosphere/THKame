#ifndef _THKAME_CORE_RESOURCEMANAGER_HPP__
#define _THKAME_CORE_RESOURCEMANAGER_HPP__

#include <SFML/Graphics.hpp>

class ResourceManager final
{
public:
	/**
	 * This enum struct is used to index an array of textures.
	 *
	 * The last element Texture::max is the number of valid elements in the enum.
	 */
	enum struct Texture
	{
		Title0 = 0,
		Title1,
		Player0,
		Player1,
		Player2,

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

		max
	};
	ResourceManager();

	/**
	 * Initialises all resources.
	 * @param[in] folder The resource folder. It should include a slash at the
	 *	end.
	 * @return true if successful
	 */
	bool init(std::string folder);

	/**
	 * Queries a texture based on a enumeration index.
	 *
	 * @return The texture. Must be sf::Texture const&. Otherwise problems occur.
	 */
	sf::Texture const& getTexture(Texture index) const
	{
		return textures[(std::size_t) index];
	}

	
	sf::Sprite sTitle0;
	sf::Sprite sTitle1;
	sf::Sprite sPlayers[3];

	/**
	 * @param[in] index The texture corresponding to the button. Must lie within
	 *	valid range [SL_KeyConfig, SL_Weapon]
	 */
	sf::Sprite& getSLButton(Texture index)
	{
		return sButtons[(std::size_t)index - (std::size_t)Texture::SL_KeyConfig];
	}
	
	
private:
	sf::Texture textures[(std::size_t)Texture::max];
	sf::Sprite sButtons[(std::size_t)Texture::SL_Weapon - (std::size_t)Texture::SL_KeyConfig + 1];

};
#endif // !_THKAME_CORE_RESOURCEMANAGER_HPP__

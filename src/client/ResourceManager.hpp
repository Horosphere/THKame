#ifndef _THKAME_CORE_RESOURCEMANAGER_HPP__
#define _THKAME_CORE_RESOURCEMANAGER_HPP__

#include <SFML/Graphics.hpp>

namespace thk
{

	enum struct Texture
	{
		Title0 = 0,
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

		max
	};
class ResourceManager final
{
public:
	/**
	 * This enum struct is used to index an array of textures.
	 *
	 * The last element Texture::max is the number of valid elements in the enum.
	 */
	ResourceManager();

	/**
	 * Initialises all resources.
	 * @param[in] folder The resource folder. It should include a slash at the
	 *	end.
	 * @return true if successful
	 */
	bool init(std::string folder);

	/**
	 * Quaries a texture based on a enumeration index.
	 *
	 * @return The texture. Must be sf::Texture const&. Otherwise problems occur.
	 */
	sf::Texture const& getTexture(Texture index) const
	{
		return textures[(std::size_t) index];
	}

	// Sprites
private:
	sf::Texture textures[(std::size_t)Texture::max];

};

} // namespace thk

#endif // !_THKAME_CORE_RESOURCEMANAGER_HPP__

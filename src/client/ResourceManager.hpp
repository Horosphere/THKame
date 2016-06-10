#ifndef _THKAME_CORE_RESOURCEMANAGER_HPP__
#define _THKAME_CORE_RESOURCEMANAGER_HPP__

#include <SFML/Graphics.hpp>

class ResourceManager
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
	sf::Sprite players[3];
	
private:
	sf::Texture textures[(std::size_t)Texture::max];

};
#endif // !_THKAME_CORE_RESOURCEMANAGER_HPP__

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

		TidMax
	};
	sf::Texture texture(TextureId) const;
	sf::Font fontMonospace;

private:
	sf::Texture textures[(std::size_t)TidMax];
};


// Implementations

inline sf::Texture
Resources::texture(Resources::TextureId tid) const
{
	return textures[tid];
}

} // namespace thk

#endif // !_THKAME_CLIENT_RESOURCES_HPP__

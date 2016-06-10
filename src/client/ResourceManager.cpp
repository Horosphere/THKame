#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
}


bool ResourceManager::init(std::string folder)
{
	// Textures
	if (!textures[(std::size_t)Texture::Title0]
			.loadFromFile(folder + "ui/title_bk00.png")) goto fail;
	if (!textures[(std::size_t)Texture::Title1]
			.loadFromFile(folder + "ui/title_bk01.png")) goto fail;
	if (!textures[(std::size_t)Texture::Player0]
			.loadFromFile(folder + "ui/player_00.png")) goto fail;
	if (!textures[(std::size_t)Texture::Player1]
			.loadFromFile(folder + "ui/player_01.png")) goto fail;
	if (!textures[(std::size_t)Texture::Player2]
			.loadFromFile(folder + "ui/player_02.png")) goto fail;

	// Sprites
	sTitle0.setTexture(getTexture(Texture::Title0));
	sTitle1.setTexture(getTexture(Texture::Title1));
	players[0].setTexture(getTexture(Texture::Player0));	
	players[1].setTexture(getTexture(Texture::Player1));	
	players[2].setTexture(getTexture(Texture::Player2));	
	
	return true;
fail:

	return false;
}

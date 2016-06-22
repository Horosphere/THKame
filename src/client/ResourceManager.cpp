#include "ResourceManager.hpp"

thk::ResourceManager::ResourceManager()
{
}

#define INITIALISE_TEXTURE_SIMPLE(key, path) \
	if (!textures[(std::size_t)Texture::key] \
			.loadFromFile(folder + path)) goto fail


bool thk::ResourceManager::init(std::string folder)
{
	// Textures
	INITIALISE_TEXTURE_SIMPLE(Title0, "ui/title_bk00.png");
	INITIALISE_TEXTURE_SIMPLE(Title1, "ui/title_bk01.png");
	INITIALISE_TEXTURE_SIMPLE(Difficulties, "ui/difficulties.png");
	INITIALISE_TEXTURE_SIMPLE(Character0, "ui/player_00.png");
	INITIALISE_TEXTURE_SIMPLE(Character1, "ui/player_01.png");
	INITIALISE_TEXTURE_SIMPLE(Character2, "ui/player_02.png");
	INITIALISE_TEXTURE_SIMPLE(Weapon0, "ui/weapon_00.png");
	INITIALISE_TEXTURE_SIMPLE(Weapon0b, "ui/weapon_00b.png");
	INITIALISE_TEXTURE_SIMPLE(Weapon1, "ui/weapon_01.png");
	INITIALISE_TEXTURE_SIMPLE(Weapon1b, "ui/weapon_01b.png");
	INITIALISE_TEXTURE_SIMPLE(Weapon2, "ui/weapon_01.png");
	INITIALISE_TEXTURE_SIMPLE(Weapon2b, "ui/weapon_01b.png");
	INITIALISE_TEXTURE_SIMPLE(SL_KeyConfig, "ui/sl/sl_keyconfig.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Manual, "ui/sl/sl_manual.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Music, "ui/sl/sl_music.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Option, "ui/sl/sl_option.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Player, "ui/sl/sl_player.png");
	INITIALISE_TEXTURE_SIMPLE(SL_PlayerData, "ui/sl/sl_playerdata.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Rank, "ui/sl/sl_rank.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Regist, "ui/sl/sl_regist.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Replay, "ui/sl/sl_replay.png");
	INITIALISE_TEXTURE_SIMPLE(SL_SaveReplay, "ui/sl/sl_savereplay.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Spell, "ui/sl/sl_spell.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Stage, "ui/sl/sl_stage.png");
	INITIALISE_TEXTURE_SIMPLE(SL_Weapon, "ui/sl/sl_weapon.png");

	// Sprites
	sTitle0.setTexture(getTexture(Texture::Title0));
	sTitle1.setTexture(getTexture(Texture::Title1));
	sDifficultiesInactive.setTexture(getTexture(Texture::Difficulties));
	sDifficultiesInactive.setTextureRect(sf::IntRect(512, 0, 640, 1024));
	sDifficultiesActive.setTexture(getTexture(Texture::Difficulties));
	sCharacters[0].setTexture(getTexture(Texture::Character0));	
	sCharacters[1].setTexture(getTexture(Texture::Character1));	
	sCharacters[2].setTexture(getTexture(Texture::Character2));	
	sWeapons[0].setTexture(getTexture(Texture::Weapon0));	
	sWeapons[1].setTexture(getTexture(Texture::Weapon0b));	
	sWeapons[2].setTexture(getTexture(Texture::Weapon1));	
	sWeapons[3].setTexture(getTexture(Texture::Weapon1b));	
	sWeapons[4].setTexture(getTexture(Texture::Weapon2));	
	sWeapons[5].setTexture(getTexture(Texture::Weapon2b));	

	for (std::size_t i = (std::size_t)Texture::SL_KeyConfig;
			i <= (std::size_t)Texture::SL_Weapon; ++i)
	{
		sButtons[i - (std::size_t)Texture::SL_KeyConfig].setTexture(textures[i]);
	}
	
	
	return true;
fail:

	return false;
}

#undef INITIALISE_TEXTURE_SIMPLE



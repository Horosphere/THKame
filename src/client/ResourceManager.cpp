#include "ResourceManager.hpp"

thk::ResourceManager::ResourceManager()
{
}

#define INITIALISE_TEXTURE(key, path) \
	if (!textures[(std::size_t)Texture::key] \
			.loadFromFile(folder + path)) goto fail


bool thk::ResourceManager::init(std::string folder)
{
	// Textures
	INITIALISE_TEXTURE(Title0, "ui/title_bk00.png");
	INITIALISE_TEXTURE(Title1, "ui/title_bk01.png");
	INITIALISE_TEXTURE(Difficulties, "ui/difficulties.png");
	INITIALISE_TEXTURE(Character0, "ui/player_00.png");
	INITIALISE_TEXTURE(Character1, "ui/player_01.png");
	INITIALISE_TEXTURE(Character2, "ui/player_02.png");
	INITIALISE_TEXTURE(Weapon0, "ui/weapon_00.png");
	INITIALISE_TEXTURE(Weapon0b, "ui/weapon_00b.png");
	INITIALISE_TEXTURE(Weapon1, "ui/weapon_01.png");
	INITIALISE_TEXTURE(Weapon1b, "ui/weapon_01b.png");
	INITIALISE_TEXTURE(Weapon2, "ui/weapon_01.png");
	INITIALISE_TEXTURE(Weapon2b, "ui/weapon_01b.png");
	INITIALISE_TEXTURE(SL_KeyConfig, "ui/sl/sl_keyconfig.png");
	INITIALISE_TEXTURE(SL_Manual, "ui/sl/sl_manual.png");
	INITIALISE_TEXTURE(SL_Music, "ui/sl/sl_music.png");
	INITIALISE_TEXTURE(SL_Option, "ui/sl/sl_option.png");
	INITIALISE_TEXTURE(SL_Player, "ui/sl/sl_player.png");
	INITIALISE_TEXTURE(SL_PlayerData, "ui/sl/sl_playerdata.png");
	INITIALISE_TEXTURE(SL_Rank, "ui/sl/sl_rank.png");
	INITIALISE_TEXTURE(SL_Regist, "ui/sl/sl_regist.png");
	INITIALISE_TEXTURE(SL_Replay, "ui/sl/sl_replay.png");
	INITIALISE_TEXTURE(SL_SaveReplay, "ui/sl/sl_savereplay.png");
	INITIALISE_TEXTURE(SL_Spell, "ui/sl/sl_spell.png");
	INITIALISE_TEXTURE(SL_Stage, "ui/sl/sl_stage.png");
	INITIALISE_TEXTURE(SL_Weapon, "ui/sl/sl_weapon.png");

	return true;
fail:
	return false;
}

#undef INITIALISE_TEXTURE



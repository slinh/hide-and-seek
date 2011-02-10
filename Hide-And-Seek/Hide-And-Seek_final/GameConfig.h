#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include "config.h"

#define XML_EN					"ms0:/PSP/GAME/Hide-And-Seek/Data/xml/gui_release.xml"
#define XML_FR					"ms0:/PSP/GAME/Hide-And-Seek/Data/xml/gui_fr_release.xml"


#define SPEED_CREDITS				115
#define SPEED_FADE_SPLASH_SCREEN	20
#define NUDGE_TRIGGER				10

typedef enum LevelDifficulty_
{
	LD_EASY		= 1,
	LD_NORMAL	= 2

} LevelDifficulty;

typedef enum Language_
{
	L_EN	= 1,
	L_FR	= 2

} Language;

typedef enum NumberOfPlayers_
{
	NP_SOLO		= 1,
	NP_MULTI	= 2

} NumberOfPlayers;

typedef enum CinematicVideo_
{
	CINEMATIC_1		= 1,
	CINEMATIC_2		= 2

} CinematicVideo;


namespace psp {

class TGameConfig 
{
public:
	TGameConfig():
	FLevelDifficulty(LD_EASY),
	FLanguage(L_EN),
	FMusicLevelVolume(50),
	FSoundEffectLevelVolume(50),
	FGameDuration(3*60*1000),
	FNumberOfPlayers(NP_SOLO),
	FGUILoaded(false)
	{}

	~TGameConfig(){}
	
	GETTER_SETTER(LevelDifficulty, LevelDifficulty)
	GETTER_SETTER(Language, Language)
	GETTER_SETTER(u8, MusicLevelVolume)
	GETTER_SETTER(u8, SoundEffectLevelVolume)
	GETTER_SETTER(u32, GameDuration)
	GETTER_SETTER(NumberOfPlayers, NumberOfPlayers)
	GETTER_SETTER(bool, GUILoaded)

private:
	LevelDifficulty FLevelDifficulty;
	Language		FLanguage;
	u8				FMusicLevelVolume;
	u8				FSoundEffectLevelVolume;
	u32				FGameDuration;
	NumberOfPlayers FNumberOfPlayers;
	bool			FGUILoaded;
	bool			FChooseLanguageLoaded;
	bool			FSoundLoaded;
};

} // psp namespace

#endif

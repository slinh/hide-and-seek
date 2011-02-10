#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "config.h"
#include "LoggerTypes.h"

#ifdef COMPILE_PSP
#include <oslib/oslib.h>
#endif

#ifdef COMPILE_PSP
#define SYSTEM_SOUND_CHANNELS 8
#else
#define SYSTEM_SOUND_CHANNELS 8
#endif

#define MUSIC_FEAR		"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/fear.bgm"
#define MUSIC_TENSION	"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/tension.bgm"
#define MUSIC_VICTIM	"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/victim.bgm"
#define MUSIC_MENU		"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/menu.bgm"

#define SOUND_CURSOR			"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/menu_cursor.wav"
#define SOUND_SELECT			"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/menu_select.wav"
#define SOUND_CRACK				"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/crack.wav"
#define SOUND_GLASS				"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/glass.wav"
#define SOUND_GRINCE			"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/grince.wav"
#define SOUND_LEFT_FOOT_GIRL	"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/left_foot_girl.wav"
#define SOUND_RIGHT_FOOT_GIRL	"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/right_foot_girl.wav"
#define SOUND_LEFT_FOOT_MAN		"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/left_foot_man.wav"
#define SOUND_RIGHT_FOOT_MAN	"ms0:/PSP/GAME/Hide-And-Seek/Data/sound/right_foot_man.wav"

#ifdef COMPILE_PSP
typedef OSL_SOUND system_sound;
#else
typedef c8* system_sound;
#endif

struct SoundItem
{
	SoundItem():
	SoundFile(NULL),
	IsPlaying(false)
	{}

	system_sound*	SoundFile;
	bool			IsPlaying;
};

namespace psp { namespace engine { namespace sound {

class TSoundManager
{
private:
	core::array<SoundItem> FSounds;			// sound files
	int FChannels[SYSTEM_SOUND_CHANNELS];	// channel to play sounds

	u8	FIndexFear;						
	u8	FIndexTension;					
	u8	FIndexVictim;					
	u8	FIndexMenu;						
	
	u8	FIndexCursor;	
	u8	FIndexSelect;						
	u8	FIndexCrack;					
	u8	FIndexGlass;					
	u8	FIndexGrince;
	u8	FIndexLFGirl;						
	u8	FIndexRFGirl;					
	u8	FIndexLFMan;					
	u8	FIndexRFMan;		

public:
	TSoundManager();
	~TSoundManager();

	void InitializeSoundGame();

	GETTER_SETTER(core::array<SoundItem>, Sounds)

	GETTER_SETTER(u8, IndexFear)
	GETTER_SETTER(u8, IndexTension)
	GETTER_SETTER(u8, IndexVictim)
	GETTER_SETTER(u8, IndexMenu)

	GETTER_SETTER(u8, IndexCursor)
	GETTER_SETTER(u8, IndexSelect)
	GETTER_SETTER(u8, IndexCrack)
	GETTER_SETTER(u8, IndexGlass)
	GETTER_SETTER(u8, IndexGrince)
	GETTER_SETTER(u8, IndexLFGirl)
	GETTER_SETTER(u8, IndexRFGirl)
	GETTER_SETTER(u8, IndexLFMan)
	GETTER_SETTER(u8, IndexRFMan)

	s32 LoadSound(const c8* fileURL, bool IsBGMusic=false);
	bool PlaySound(const u32& parSoundIndex);
	void StopSound(const u32& parSoundIndex);
	//u32 PauseSound(const u32& soundIndex, u8 mode);

	bool IsSoundPlaying(const u32& parId);

	//void SetChannel(const u32& voice, const u32& index);
	void NotifyStopSound(system_sound* parSound, const u32& parVoice);

	void Update();
	void UnloadMusic();
	
};
} // sound namespace
} // engine namespace
} // psp namespace

#ifdef COMPILE_PSP
int WrapperNotifyStopSound(OSL_SOUND *s, int voice);
#endif

#endif
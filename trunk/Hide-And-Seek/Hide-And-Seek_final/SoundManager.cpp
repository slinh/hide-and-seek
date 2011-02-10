#include "Common.h"
#include "SoundManager.h"
#include "GameConfig.h"
#include "Game.h"

namespace psp { namespace engine { namespace sound {
		
TSoundManager::TSoundManager()
{
	// Init channels
	for(u8 i=0; i<SYSTEM_SOUND_CHANNELS; ++i)
		FChannels[i] = -1;
}

TSoundManager::~TSoundManager()
{}

void TSoundManager::InitializeSoundGame()
{
	// musics
	FIndexMenu		= LoadSound(MUSIC_MENU, true);
	FIndexFear		= LoadSound(MUSIC_FEAR, true);
	FIndexVictim	= LoadSound(MUSIC_VICTIM, true);

	// sounds
	FIndexCursor	= LoadSound(SOUND_CURSOR, false);
	FIndexSelect	= LoadSound(SOUND_SELECT, false);
	FIndexCrack		= LoadSound(SOUND_CRACK, false);
	FIndexGlass		= LoadSound(SOUND_GLASS, false);
	FIndexGrince	= LoadSound(SOUND_GRINCE, false);
	FIndexLFGirl	= LoadSound(SOUND_LEFT_FOOT_GIRL, false);
	FIndexRFGirl	= LoadSound(SOUND_RIGHT_FOOT_GIRL, false);
	FIndexLFMan		= LoadSound(SOUND_LEFT_FOOT_MAN, false);
	FIndexRFMan		= LoadSound(SOUND_RIGHT_FOOT_MAN, false);
}

s32 TSoundManager::LoadSound(const c8* fileURL, bool IsBGMusic)
{
	core::stringc regex(fileURL);

	s32 pointIndex = regex.findLast('.');

	regex = regex.subString(pointIndex+1, regex.size()-1);
	regex.make_upper();

	SoundItem locSoundItem;
	system_sound* locSound = NULL;

	if(IsBGMusic)
	{
		if(regex == "BGM")
		{
#ifdef COMPILE_PSP
			locSound = oslLoadSoundFile(fileURL, OSL_FMT_NONE);
#endif
			if(locSound == NULL)
				return 0;
		}
	}
	else
	{
		if(regex == "WAV")
		{
#ifdef COMPILE_PSP
			locSound = oslLoadSoundFile(fileURL, OSL_FMT_NONE);
#endif
			if(locSound == NULL)
				return 0;
		}
	}

#ifdef COMPILE_PSP
	oslSetSoundEndCallback(locSound, WrapperNotifyStopSound);
#endif

	locSoundItem.SoundFile = locSound;
	FSounds.push_back(locSoundItem);
	
	return FSounds.size()-1;
}

// TODO : Return bool to know id music playing succeeded
bool TSoundManager::PlaySound(const u32& parSoundIndex)
{
	LAssert(FSounds[parSoundIndex].SoundFile != NULL);

	s32 locChannel;

	for(locChannel=0; locChannel<SYSTEM_SOUND_CHANNELS; ++locChannel)
	{
		if(FChannels[locChannel] == -1)
		{
			FChannels[locChannel] = parSoundIndex;
#ifdef COMPILE_PSP
			oslPlaySound(FSounds[parSoundIndex].SoundFile, locChannel);
#endif
			FSounds[parSoundIndex].IsPlaying = true;

			break;
		}
	}

	if(locChannel >= SYSTEM_SOUND_CHANNELS)
	{
		LOGC_SOUND("No channel available to play sound n%d", parSoundIndex);
		return false;
	}
	else return true;

}

void TSoundManager::StopSound(const u32& parSoundIndex)
{
	LAssert(parSoundIndex < FSounds.size());
	LAssert(FSounds[parSoundIndex].SoundFile != NULL);

	LOGC("Ask stop sound with id %d\n", parSoundIndex);

#ifdef COMPILE_PSP
	oslStopSound(FSounds[parSoundIndex].SoundFile);
#endif
	// Search channel where the sound was played
	bool Found = false;
	s32 i = 0;

	while(!Found && (i < SYSTEM_SOUND_CHANNELS))
	{
		if(FChannels[i] == static_cast<s32>(parSoundIndex))
		{
			FChannels[i] = -1;
			Found = true;
		}
		else
			++i;
	}

	LAssert(Found);
	FSounds[parSoundIndex].IsPlaying = false;
}

bool TSoundManager::IsSoundPlaying(const u32& parId)
{
	LAssert(parId < FSounds.size());

	return (FSounds[parId].SoundFile != NULL) && FSounds[parId].IsPlaying;
}

void TSoundManager::NotifyStopSound(system_sound* parSound, const u32& parVoice)
{
	FSounds[FChannels[parVoice]].IsPlaying = false;

	//LOGC("stop sound with id %d on voice %d\n", FChannels[parVoice], parVoice);

	FChannels[parVoice] = -1;
}

void TSoundManager::Update()
{
#ifdef COMPILE_PSP
	oslAudioVSync();
#endif
}

void TSoundManager::UnloadMusic()
{
	for(u32 i=0; i < FSounds.size(); ++i)
	{
		if(FSounds[i].IsPlaying)
			StopSound(i);

		if(FSounds[i].SoundFile)
		{
#ifdef COMPILE_PSP
			oslDeleteSound(FSounds[i].SoundFile);
#endif
		}
	}
}

} // sound namespace
} // engine namespace
} // psp namespace

// -----------------------------------------------------------------------------------------
//		Auxiliary functions
// -----------------------------------------------------------------------------------------
int WrapperNotifyStopSound(system_sound* parSound, int parVoice)
{
	psp::game::TGame::Instance().GetSoundManager()->NotifyStopSound(parSound, parVoice);

	return 0;
}
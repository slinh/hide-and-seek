#include "Common.h"
#include "VideoManager.h"

namespace psp { namespace engine { namespace video {

TVideoManager::TVideoManager():
FVideoInitialized(false)
{}

TVideoManager::~TVideoManager()
{}

bool TVideoManager::IsVideoPlaying()
{
#ifdef COMPILE_PSP
	return pmp_isplaying();
#else
	return false;
#endif
}

// TODO : return a boolean to know if initialization succeeded
void TVideoManager::InitializeVideo(CinematicVideo parVideo)
{
	const c8* locFileVideo;
	if(parVideo & CINEMATIC_1)
		locFileVideo = VIDEO_CINEMATIC_1;
	else
		locFileVideo = VIDEO_CINEMATIC_2;
	
	// Init video
	// TODO : see if init is necessary just once on initialization or each time you want to read a video
#ifdef COMPILE_PSP
	c8* result = pmp_init();
#else
	c8* result = NULL
#endif

	if (result != NULL)
	{
		LOGC("in VideoManager::InitializeVideo => pmp_init : %s\n", result);
	}

	// Playback can always be interrupted by pressing START
#ifdef COMPILE_PSP
	result = pmp_play(const_cast<char*>(locFileVideo), 1, GU_PSM_5650);
#else
	result = NULL
#endif

	if (result != NULL)
	{
		LOGC( "ERROR in VideoManager::InitializeVideo => pmp_play: %s\n", result);
	}
	
	FVideoInitialized = true;
}

void TVideoManager::PlayVideo()
{
	if (IsVideoPlaying())
	{
#ifdef COMPILE_PSP
		sceKernelDelayThread(100*1000); // Wait 1 seconds. keep up the loop until done
#endif
		return;
	}
	
	StopVideo();
}

void TVideoManager::StopVideo()
{
#ifdef COMPILE_PSP
	pmp_stop();	

	sceGuSync(0,0);
	sceDisplayWaitVblankStart();	
	sceGuDisplay(GU_TRUE);
#endif

	FVideoInitialized = false;
}

} // namespace video
} // namespace engine
} // namespace psp


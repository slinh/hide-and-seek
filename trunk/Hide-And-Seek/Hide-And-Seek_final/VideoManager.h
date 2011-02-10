#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include "config.h"
#include "GameConfig.h"
#ifdef COMPILE_PSP
#include <pspgu.h>
#include <malloc.h>
#include <pmp.h>
#endif

#define VIDEO_CINEMATIC_1 "ms0:/PSP/GAME/Hide-And-Seek/Data/video/cinematic1.pmp"
#define VIDEO_CINEMATIC_2 "ms0:/PSP/GAME/Hide-And-Seek/Data/video/cinematic2.pmp"

namespace psp { namespace engine { namespace video {

class TVideoManager
{
public:
	TVideoManager();
	~TVideoManager();

	bool IsVideoPlaying();
	void InitializeVideo(CinematicVideo parVideo);
	void PlayVideo();
	void StopVideo();

	GETTER_SETTER(bool, VideoInitialized);
private:
	bool FVideoInitialized;
};

} // namespace video
} // namespace engine
} // namespace psp

#endif

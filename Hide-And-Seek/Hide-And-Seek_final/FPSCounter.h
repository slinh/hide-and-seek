#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include "config.h"

namespace psp { namespace engine { namespace video {

class TFPSCounter
{
public:
	TFPSCounter(u32 parRefreshTime = 1000);
	~TFPSCounter();

	GETTER(u32, Fps)

	void RegisterFrame(const u32& parNowTime);

private:
	u32 FRefreshTime;
	u32 FFps;
	u32 FStartTime;
	u32 FFrameCount;
};

} // namespace video
} // namespace engine
} // namespace psp

#endif

#include "Common.h"
#include "FPSCounter.h"

namespace psp { namespace engine { namespace video {

TFPSCounter::TFPSCounter(u32 parRefreshTime):
FRefreshTime(parRefreshTime), FFps(0), FStartTime(0), FFrameCount(0)
{}

TFPSCounter::~TFPSCounter()
{}

void TFPSCounter::RegisterFrame(const u32& parNowTime)
{
	++FFrameCount;

	u32 locMs = parNowTime - FStartTime;

	if(locMs > 1000)
	{
		FFps = (u32)(FFrameCount / (locMs / 1000.0f));

		FStartTime = parNowTime;
		FFrameCount = 0;
	}
}

} // namespace video
} // namespace engine
} // namespace psp

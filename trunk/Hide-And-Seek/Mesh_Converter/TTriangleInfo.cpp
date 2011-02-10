#include <Common.h>
#include "TTriangleInfo.h"

namespace psp {	
	
bool TTriangleInfo::SetPointInfo(const u32 &id,const TPointInfo &PInfo)
{
	LAssert(id < 3);
	FPInfo[id] = PInfo;
	return true;
}
	
} // psp namespace
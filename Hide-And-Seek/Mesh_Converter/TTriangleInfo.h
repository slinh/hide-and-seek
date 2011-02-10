#ifndef TTRIANGLEINFO_H
#define TTRIANGLEINFO_H

#include <config.h>
#include "TPointInfo.h"

namespace psp {

class TTriangleInfo
{
	private:
		TPointInfo FPInfo[3];

	public:
		bool SetPointInfo(const u32 &parId,const TPointInfo &parPInfo);

		TPointInfo& GetPointInfo(const u32 &parId)
		{
			LAssert(parId < 3);
			return FPInfo[parId];
		}

};

}

#endif
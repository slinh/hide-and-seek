#include <Common.h>
#include "TPointInfo.h"

namespace psp{

TPointInfo::TPointInfo()
{
	FIds[0] = -1;
	FIds[1] = -1;
	FIds[2] = -1;
}

TPointInfo::TPointInfo(const u32 &v, const u32 &vt, const u32 &vn)
{
	FIds[0] = v;
	FIds[1] = vt;
	FIds[2] = vn;
}


void TPointInfo::Set(const u32& parId, const u32& parValue)
{
	FIds[parId] = parValue;
}

void TPointInfo::Write(std::fstream& parFile)
{
	LAssert(FIds[0] != -1);
	parFile << FIds[0];
	if(FIds[1] != -1) parFile << '/' << FIds[1] ;
	if(FIds[2] != -1) parFile << '/' << FIds[2] ;
}

} // psp namespace

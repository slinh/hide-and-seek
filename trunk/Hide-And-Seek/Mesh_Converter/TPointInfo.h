#ifndef TPOINTINFO_H
#define TPOINTINFO_H

#include <config.h>
#include <iostream>
#include <fstream>

namespace psp {

class TPointInfo
{
	private:
		/*u32 vId;
		u32 vtId;
		u32 vnId;*/
		u32 FIds[3];

	public :
	TPointInfo();
	TPointInfo(const u32 &v, const u32 &vt, const u32 &vn);
	void Set(const u32& parId, const u32& parValue);
	void Write(std::fstream& parFile);

};

}

#endif
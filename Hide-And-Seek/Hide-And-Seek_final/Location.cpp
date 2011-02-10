
#include "Common.h"
#include "Location.h"

namespace psp { namespace engine { namespace gui {

TLocation::TLocation()
	:FImageFile(NULL),
	FPosX(0),
	FPosY(0),
	FWidth(0),
	FHeight(0),
	FPosU(0),
	FPosV(0)
{}

TLocation::TLocation(core::stringc& parImageFile, u8 parPosX, u8 parPosY, u16 parWidth, u16 parHeight, u16 parPosU, u16 parPosV)
	:FImageFile(parImageFile),
	FPosX(parPosX),
	FPosY(parPosY),
	FWidth(parWidth),
	FHeight(parHeight),
	FPosU(parPosU),
	FPosV(parPosV)
{}


TLocation::~TLocation()
{}

} // gui namespace
} // engine namespace
} // psp namespace

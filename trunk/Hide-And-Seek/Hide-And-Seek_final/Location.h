#ifndef TLOCATION_H
#define TLOCATION_H

#include "config.h"
#ifdef COMPILE_PSP
#include <oslib/oslib.h>
#endif

namespace psp { namespace engine { namespace gui {

class TLocation
{
public:
	TLocation();
	TLocation(core::string<c8>& parImageFile, u8 parPosX, u8 parPosY, u16 parWidth, u16 parHeight, u16 parPosU, u16 parPosV);
	~TLocation();

	// DO GETTER_SETTER_PTR macro for pointer
	GETTER_SETTER(core::string<c8>, ImageFile)
	GETTER_SETTER(u8, PosX)
	GETTER_SETTER(u8, PosY)
	GETTER_SETTER(u16, Height)
	GETTER_SETTER(u16, Width)
	GETTER_SETTER(u16, PosU)
	GETTER_SETTER(u16, PosV)

#ifdef COMPILE_PSP
	GETTER_SETTER_PTR(OSL_IMAGE, Sprite)
#endif

private:

#ifdef COMPILE_PSP
	OSL_IMAGE *			FSprite;		// sprite file
#endif

	core::string<c8>	FImageFile;		// sprite url
	u8					FPosX;			// y position in sprite 
	u8					FPosY;			// y position in sprite 
	u16					FWidth;			// width of label
	u16					FHeight;		// height og label
	u16					FPosU;			// u position in gui
	u16					FPosV;			// v position in gui
};

} // gui namespace
} // engine namespace
} // psp namespace

#endif 

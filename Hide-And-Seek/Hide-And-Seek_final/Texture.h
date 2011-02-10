#ifndef TEXTURE_H
#define TEXTURE_H

#include "config.h"
#include "Point2D.h"

namespace psp { namespace engine { namespace video {

// ----------------------------------------------------------------
// COLOR_FORMAT
// ----------------------------------------------------------------

enum COLOR_FORMAT
{
	//! 16 bit color format used by the software driver, and thus preferred
	//! by all other engine engine video drivers. There are 5 bits for every
	//! color component, and a single bit is left for alpha information.
	CF_A1R5G5B5 = 0,	

	//! Standard 16 bit color format.
	CF_R5G6B5,

	//! Default 32 bit color format. 8 bits are used for every component:
	//! red, green, blue and alpha.
	CF_A8R8G8B8
};

// ----------------------------------------------------------------
// ITexture
// ----------------------------------------------------------------

class ITexture
{
public:
	VIRTUAL_DESTRUCTOR(ITexture);

	//: Return Color format of texure
	virtual COLOR_FORMAT GetColorFormat() = 0;

	//! Returns width and height of image data.
	virtual const core::p2Di& GetDimension() = 0;

	//! Returns bits per pixel. 
	virtual s32 GetBitsPerPixel() = 0;

	//! Returns bytes per pixel
	virtual s32 GetBytesPerPixel() = 0;

	//! returns pitch of image
	virtual u32 GetPitch() = 0;
};

} // namespace video
} // namespace engine
} // namespace psp

#endif

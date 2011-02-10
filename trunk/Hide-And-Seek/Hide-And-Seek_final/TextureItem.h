#ifndef TEXTURE_ITEM_H
#define TEXTURE_ITEM_H

#include "Texture.h"
#include "Functions.h"

namespace psp { namespace engine { namespace video {

struct TColor;

class TTextureItem : public ITexture
{
public:
	TTextureItem();
	TTextureItem(const c8* parFile, COLOR_FORMAT parFormat);
	virtual ~TTextureItem();

	void Load(const c8* parFile, COLOR_FORMAT parFormat, const u32& parMode = PXM_REVERSE);
	void LoadWithTransparentColor(const c8* parFile, COLOR_FORMAT parFormat, const TColor& parTransparentColor, const u32& parMode = PXM_REVERSE);

	virtual COLOR_FORMAT GetColorFormat();

	virtual const core::p2Di& GetDimension();

	virtual s32 GetBitsPerPixel();

	virtual s32 GetBytesPerPixel();

	virtual u32 GetPitch();

	virtual void Free();

	GETTER_PTR(s16, Image);
	GETTER(bool, IsSwizzled)

private:
	void ConvertToA1R5G5B5();
	void ConvertToA8R8G8B8();
	void Swizzle();
	
#ifdef COMPILE_PSP
	s16* __attribute__((aligned(16)))	FImage;
#else
	s16*								FImage;
#endif
	COLOR_FORMAT						FColorFormat;
	core::p2Di							FDimension;
	u32									FPitch;
	bool								FIsSwizzled;
};

} // namespace video
} // namespace engine
} // namespace psp

#endif

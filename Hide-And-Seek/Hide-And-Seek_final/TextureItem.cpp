#include "Common.h"
#include "TextureItem.h"
#include "Color.h"
#include "vram.h"

namespace psp { namespace engine { namespace video {

TTextureItem::TTextureItem():
FImage(NULL),
FColorFormat(CF_A1R5G5B5), FPitch(0),
FIsSwizzled(false)
{}

TTextureItem::TTextureItem(const c8* parFile, COLOR_FORMAT parFormat):
FImage(NULL),
FColorFormat(parFormat), FPitch(0),
FIsSwizzled(false)
{
	// Read picture and write converted format on the same array to scope a new
	c8* locImage = LoadPXM(parFile, FDimension.X, FDimension.Y);

#ifdef WITH_SWIZZLE_TEXTURE
	FImage = NEW_IN_DOMAIN(Video) s16[FDimension.X*FDimension.Y];
#else
	FImage = (s16*)getStaticVramTexture(FDimension.X, FDimension.Y, parFormat);
#endif

	for(s32 i=0; i<FDimension.Y*FDimension.X; ++i)
		FImage[i] = ARGB16((u8)0xffffffff, (u8)locImage[i*3], (u8)locImage[i*3+1], (u8)locImage[i*3+2]);

	delete locImage;

#if defined(COMPILE_PSP) && defined(WITH_SWIZZLE_TEXTURE)
	Swizzle();
#endif
}

TTextureItem::~TTextureItem()
{
	
}

void TTextureItem::Load(const c8* parFile, COLOR_FORMAT parFormat, const u32& parMode)
{
	// Read picture and write converted format on the same array to scope a new
	c8* locImage = LoadPXM(parFile, FDimension.X, FDimension.Y, parMode);

#ifdef WITH_SWIZZLE_TEXTURE
	FImage = NEW_IN_DOMAIN(Video) s16[FDimension.X*FDimension.Y];
#else
	FImage = (s16*)getStaticVramTexture(FDimension.X, FDimension.Y, parFormat);
#endif

	for(s32 i=0; i<FDimension.Y*FDimension.X; ++i)
		FImage[i] = ARGB16((u8)0xffffffff, (u8)locImage[i*3], (u8)locImage[i*3+1], (u8)locImage[i*3+2]);

	delete locImage;

#if defined(COMPILE_PSP) && defined(WITH_SWIZZLE_TEXTURE)
	Swizzle();
#endif
}

void TTextureItem::LoadWithTransparentColor(const c8* parFile, COLOR_FORMAT parFormat, const TColor& parTransparentColor, const u32& parMode)
{
	// Read picture and write converted format on the same array to scope a new
	u8* locImage = (u8*)LoadPXM(parFile, FDimension.X, FDimension.Y, parMode);
#ifdef WITH_SWIZZLE_TEXTURE
	FImage = NEW_IN_DOMAIN(Video) s16[FDimension.X*FDimension.Y];
#else
	FImage = (s16*)getStaticVramTexture(FDimension.X, FDimension.Y, parFormat);
#endif

	for(s32 i=0; i<FDimension.Y*FDimension.X; ++i)
	{
		if(
			(parTransparentColor.GetR() == locImage[i*3]) &&
			(parTransparentColor.GetG() == locImage[i*3+1]) &&
			(parTransparentColor.GetB() == locImage[i*3+2])
		  )
		{
			FImage[i] = ARGB16(0x0, locImage[i*3], locImage[i*3+1], locImage[i*3+2]);
		}
		else
		{
			FImage[i] = ARGB16(0xff, locImage[i*3], locImage[i*3+1], locImage[i*3+2]);
		}
	}

	delete locImage;

#if defined(COMPILE_PSP) && defined(WITH_SWIZZLE_TEXTURE)
	// TODO check why Swizzle don't work if it use a second time
	Swizzle();
#endif
}

COLOR_FORMAT TTextureItem::GetColorFormat() {return FColorFormat;}

const core::p2Di& TTextureItem::GetDimension() {return FDimension;}

s32 TTextureItem::GetBitsPerPixel()
{
	return (FColorFormat==CF_A1R5G5B5) || (FColorFormat==CF_R5G6B5)? 16 :
		   (FColorFormat==CF_A8R8G8B8)? 32 : 0;
}

s32 TTextureItem::GetBytesPerPixel()
{
	return (FColorFormat==CF_A1R5G5B5) || (FColorFormat==CF_R5G6B5)? 2 :
		   (FColorFormat==CF_A8R8G8B8)? 3 : 0;
}

u32 TTextureItem::GetPitch() {return FPitch;}

void TTextureItem::Swizzle()
{
	if(FIsSwizzled)
		return;

	u32 locWidth = FDimension.X*GetBytesPerPixel();
	u32 locHeight = FDimension.Y;

	// Allocate output memory texture
	//unsigned long* locOutput = (unsigned long*)getStaticVramTexture(locWidth, locHeight, GU_PSM_T8);
	unsigned int locMemorySize = getMemorySize(locWidth, locHeight, GU_PSM_T8);
	unsigned long* locOutput = (unsigned long*)(NEW_IN_DOMAIN(Video) c8[locMemorySize]);

	unsigned int locWidthBlocks		= (locWidth / 16);
	unsigned int locHeightBlocks	= (locHeight / 8);

	unsigned int locSrcPitch		= (locWidth-16)/4;
	unsigned int locSrcRow			= locWidth * 8;

	const u8* ysrc = (u8*)(FImage);
	unsigned long * dst = locOutput;

	for(unsigned int blocky = 0; blocky < locHeightBlocks; ++blocky) 
	{
		const u8* xsrc = ysrc;

		for(unsigned int blockx = 0; blockx < locWidthBlocks; ++blockx) 
		{
			const unsigned long* src = (unsigned long*)xsrc;
			for (int i=0; i<8; ++i) 
			{
				*(dst++) = *(src++);
				*(dst++) = *(src++);
				*(dst++) = *(src++);
				*(dst++) = *(src++);
				src += locSrcPitch;
			}

			xsrc += 16;
		}

		ysrc += locSrcRow;
	}

	// Delete previously allocated texture
	delete FImage;

	FImage=(s16*)locOutput;
	FIsSwizzled = true;
}

void TTextureItem::Free()
{
	if(FImage != NULL)
		delete FImage;

	FIsSwizzled = false;
	FImage = NULL;
}

} // namespace video
} // namespace engine
} // namespace psp

#ifndef COLOR_H
#define COLOR_H

#include "config.h"

namespace psp { namespace engine { namespace video {

//----------------------------//
// Standard convert functions //
//----------------------------//

//! Creates a 16 bit A1R5G5B5 color 
/*
inline s16 RGB16(s32 R, s32 G, s32 B)
{
	return	(( R & 0xF8) << 7) |
			(( G & 0xF8) << 2) |
			(( B & 0xF8) >> 3);
}
//*/

//! Creates a 16 bit A1R5G5B5 color 
inline s16 ARGB16(u8 A, u8 R, u8 G, u8 B)
{
	return  (((A>>7) & 0x1)<<15) |
			(((B>>3) & 0x1f)<<10)|
			(((G>>3) & 0x1f)<<5) |
			((R>>3) & 0x1f);
}

//! Converts a 32 bit (A8R8G8B8) color to a 16 A1R5G5B5 color
inline u16 A8R8G8B8toA1R5G5B5(u32 Color)
{
	return	( Color & 0x80000000) >> 16 |
			( Color & 0x00F80000) >> 9  |
			( Color & 0x0000F800) >> 6  |
			( Color & 0x000000F8) >> 3;
}

//! Returns A8R8G8B8 Color from A1R5G5B5 color
inline u32 A1R5G5B5toA8R8G8B8(u16 Color)
{
	return	( Color & 0x8000 ) << 16 |
			( Color & 0x7C00 ) << 9  |
			( Color & 0x03E0 ) << 6  |
			( Color & 0x001F ) << 3;
}

struct TColor
{
	inline TColor() {}

	inline TColor(const s32& parColor) : FColor(parColor)
	{}

	inline TColor(u8 A, u8 R, u8 G, u8 B) :	
	FColor( (A<<24) | (B<<16) | (G<<8) | R )
	{}

	inline void Set(const s32& parColor)
	{
		FColor = parColor;
	}

	inline void Set(u8 A, u8 R, u8 G, s32 B)
	{
		FColor = (A<<24) | (B<<16) | (G<<8) | R;
	}

	//! Returns R5G5B5A1 color value
	inline s16 ToR5G5B5A1() const 
	{ 
		return ARGB16(FColor>>24, FColor>>10 & 0x1f, FColor>>5 & 0x1f, FColor & 0x1f); 
	}

	inline u8 GetR() const {return (FColor & 0xff);}
	inline u8 GetG() const {return (FColor>>8 & 0xff);}
	inline u8 GetB() const {return (FColor>>16 & 0xff);}
	inline u8 GetA() const {return (FColor>>24 & 0xff);}

	bool operator ==(u32 parColor)
	{
		return	((FColor & 0xff) == (parColor & 0xff)) &&
				((FColor>>8 & 0xff) == (parColor>>8 & 0xff)) &&
				((FColor>>16 & 0xff) == (parColor>>16 & 0xff));
	}

	TColor& operator =(const TColor& parColor)
	{
		FColor = parColor.FColor;
		return *this;
	}

	//! Color in A8R8G8B8 format
	s32 FColor;
};

} // namespace video
} // namespace engine
} // namespace psp

#endif

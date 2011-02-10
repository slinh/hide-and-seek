#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "config.h"
#include "engineArray.h"

namespace psp {

// Declare namespace
namespace engine {	

	namespace video {
		struct TVertex3D;
		struct TMeshBuffer;
	}

	namespace io {
		class IReadBuffer;
		class IWriteBuffer;
		class IReadFile;
	}

}

// using rustines
using namespace engine::video;
using namespace engine::core;
using namespace engine::io;

//! Some functions to read text buffer content
c8* ReachAfter(c8* parBuffer, c8 parCar);
c8*	GetFirstWord(c8* parBuffer);
void CopyWord(c8* parBuffer, s32 parBufferLength, c8* parWord);
void CopyWordLineEnd(c8* parBuffer, s32 parBufferLength, c8* parWord);
void CopyWordSpaceEnd(c8* parBuffer, s32 parBufferLength, c8* parWord);
c8*	GetNextWord(c8* parWord);
c8*	GetNextWordLineEnd(c8* parWord);

//! Some functions to read ReadBuffer content
void CopyWordFromFile(c8* parOutputBuffer, u32 parBufferLength, IReadFile* parInputBuffer);
c8 ReachFromFile(IReadFile* parBuffer, c8 parCar);
c8 ReachAfterFromFile(IReadFile* parBuffer, c8 parCar);
c8 GetFirstWord(IReadFile* parBuffer);
c8 GetNextWord(IReadFile* parWord);

//! Load picture in format PPM, PGM (later we'll implement PBM format)

enum READ_PXM_STATE
{ 
	PXM_COMMENT			= 1,
	PXM_HEADER			= 2,
	PXM_WIDTH			= 4,
	PXM_HEIGHT			= 8,
	PXM_DEPTH			= 16,
	PXM_DATAS_NORMAL	= 32,
	PXM_DATAS_REVERSE	= 64,
	PXM_END				= 128,
	PXM_FAIL			= 256
};

#define PXM_NORMAL	1
#define PXM_REVERSE 2

c8* LoadPXM(const c8* parFile, s32& parWidth, s32& parHeight, s32 parMode = PXM_REVERSE);
c8* LoadPXMDirectlyFromFile(const c8* parFile, s32& parWidth, s32& parHeight, s32 parMode = PXM_REVERSE);

} // psp namespace

#endif

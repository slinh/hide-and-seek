#ifndef WRITE_BUFFER_H
#define WRITE_BUFFER_H

#include "config.h"

namespace psp { namespace engine { namespace io {

class IWriteBuffer
{
public:
	VIRTUAL_DESTRUCTOR(IWriteBuffer);

	//! Writes an amount of bytes in the buffer
	virtual s32 Write(const void* parBuffer, s32 parSizeToWrite) = 0;

	//! Write a car in the current position in buffer
	virtual s32 Write(c8 parCar) = 0;

	//! Changes position in buffer, returns true if successful.
	//! \param finalPos: Destination position in the buffer.
	//! \param relativeMovement: If set to true, the position in the buffer is
	//! changed relative to current position. Otherwise the position is changed 
	//! from begin of buffer.		
	//! \return Returns true if successful, otherwise false.
	virtual bool Seek(s32 parFinalPos, bool parRelativeMovement = false) = 0;

	//! Returns size of buffer.
	virtual s32 GetSize() = 0;

	//! Returns the current position in the buffer.
	virtual s32 GetPos() = 0;
};

} // io namespace
} // engine namespace
} // psp namespace

#endif

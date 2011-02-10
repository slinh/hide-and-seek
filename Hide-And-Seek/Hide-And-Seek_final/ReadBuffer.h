#ifndef READ_BUFFER_H
#define READ_BUFFER_H

#include "config.h"

namespace psp { namespace engine { namespace io {

class IReadBuffer
{
public:
	VIRTUAL_DESTRUCTOR(IReadBuffer);

	//! Reads an amount of bytes from the buffer
	virtual s32 Read(void* parBuffer, s32 parSizeToRead) = 0;
	
	//! Read 1 bytes and return it
	virtual c8 Read() = 0;	

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

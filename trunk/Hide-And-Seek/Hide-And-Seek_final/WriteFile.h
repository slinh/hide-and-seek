#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include "WriteBuffer.h"
#include "engineString.h"
#include "IOEnum.h"

namespace psp { namespace engine { namespace io {

class IWriteFile
{
public:
	VIRTUAL_DESTRUCTOR(IWriteFile);

	//! Reads an amount of bytes from the buffer
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

  //////////////////
 //  TWriteFile  //
//////////////////

class TWriteFile : public IWriteFile
{
public :
	TWriteFile(const c8* parFilename, bool parAppend = true, DATA_TYPE parDataType = TEXT);
	virtual ~TWriteFile();

	//! Reads an amount of bytes from the file
	virtual s32 Write(const void* parBuffer, s32 parSizeToWrite);
	virtual s32 Write(c8 parChar);

	//! Changes position in file, returns true if successful
	virtual bool Seek(s32 parFinalPos, bool parRelativeMovement = false);

	//! Returns size of file
	virtual s32 GetSize();

	//! Returns the current position in the file
	virtual s32 GetPos();

	//! Returns name of file
	virtual const c8* GetFileName();

	//! Returns if file is open
	bool IsOpen();

	//! Close the file
	void Close();

private :
	void OpenFile(bool parAppend);

	core::stringc	FFileName;
	s32				FFileSize;
	DATA_TYPE		FDataType;
#if defined(COMPILE_PSP)
	s32					FFile;
#elif defined(COMPILE_PC)
	FILE*				FFile;
#endif
};

} // io namespace
} // engine namespace
} // psp namespace

#endif

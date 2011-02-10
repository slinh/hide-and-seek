#ifndef READ_FILE_H
#define READ_FILE_H

#include "ReadBuffer.h"
#include "engineString.h"
#include "IOEnum.h"

namespace psp { namespace engine { namespace io {

class IReadFile : public IReadBuffer
{
public :
	VIRTUAL_DESTRUCTOR(IReadFile);

	//! Reads an amount of bytes from the file
	virtual s32 Read(void* parBuffer, s32 parSizeToRead) = 0;

	//! Read 1 byte and return its value
	virtual c8 Read() = 0;

	virtual void Close() = 0;

	//! Returns last Red car
	virtual c8 GetLastCarRead() = 0;

	//! Changes position in file, returns true if successful
	//! \param finalPos: Destination position in the file
	//! \param relativeMovement: If set to true, the position in the file is
	//! changed relative to current position. Otherwise the position is changed 
	//! from begin of file
	//! \return Returns true if successful, otherwise false
	virtual bool Seek(s32 parFinalPos, bool parRelativeMovement = false) = 0;

	//! Returns size of file
	virtual s32 GetSize() = 0;

	//! Returns the current position in the file
	virtual s32 GetPos() = 0;

	//! Returns name of file
	virtual const c8* GetFileName() = 0;
};

  //////////////////
 //   TReadFile  //
//////////////////

class TReadFile : public IReadFile
{
public :
	TReadFile(const c8* parFilename, DATA_TYPE parDataType = TEXT);
	virtual ~TReadFile();

	//! Reads an amount of bytes from the file
	virtual s32 Read(void* parBuffer, s32 parSizeToRead);
	virtual c8 Read();
	virtual void Close();

	virtual inline c8 GetLastCarRead() {return FLastCarRead;}

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

private :
	void OpenFile();

	core::stringc	FFileName;
	s32				FFileSize;
	c8				FLastCarRead;
	DATA_TYPE		FDataType;
#if defined(COMPILE_PSP)
	s32				FFile;
#elif defined(COMPILE_PC)
	FILE*			FFile;
#endif
};

} // io namespace
} // engine namespace
} // psp namespace

#endif

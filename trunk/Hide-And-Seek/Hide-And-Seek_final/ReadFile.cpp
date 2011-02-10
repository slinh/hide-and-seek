#include "Common.h"
#include "ReadFile.h"

#if defined(COMPILE_PSP)
#include <pspiofilemgr.h>
#include <sys/unistd.h>
#elif defined(COMPILE_PC)
#include <cstdio>
#include <direct.h>
#endif

namespace psp { namespace engine { namespace io {

TReadFile::TReadFile(const c8* parFileName, DATA_TYPE parDataType) : FFileSize(0), FLastCarRead('\0'), FDataType(parDataType),
#ifdef COMPILE_PC
FFile(NULL)
#elif defined(COMPILE_PSP)
FFile(-1)
#endif
{
	FFileName = parFileName;
	OpenFile();
}

TReadFile::~TReadFile()
{
#if defined(COMPILE_PSP)
	if (FFile > -1)
#elif defined(COMPILE_PC)
	if (FFile != NULL)
#endif
	{
#if defined(COMPILE_PSP)
		sceIoClose(FFile);
#elif defined(COMPILE_PC)
		fclose(FFile);
#endif
	}
}

bool TReadFile::IsOpen()
{
#if defined(COMPILE_PSP)
	return FFile > -1;
#elif defined(COMPILE_PC)
	return FFile != NULL;
#endif
}

s32 TReadFile::Read(void* parBuffer, s32 parSizeToRead)
{
	LAssert(parBuffer != NULL);
	LAssert(IsOpen());

#ifdef COMPILE_PSP
	s32 locRead = sceIoRead(FFile, parBuffer, parSizeToRead);
#elif defined(COMPILE_PC)
	s32 locRead = fread(parBuffer, 1, parSizeToRead, FFile);
#endif

	if(locRead > 0) FLastCarRead = ((char*)parBuffer)[locRead-1];

	return locRead;
}

c8 TReadFile::Read()
{
	LAssert(IsOpen());

#ifdef COMPILE_PSP
	sceIoRead(FFile, &FLastCarRead, 1);
#elif defined(COMPILE_PC)
	fread(&FLastCarRead, 1, 1, FFile);
#endif

	return FLastCarRead;
}

bool TReadFile::Seek(s32 parFinalPos, bool parRelativeMovement)
{
	LAssert(IsOpen());

#ifdef COMPILE_PSP
	return sceIoLseek(FFile, parFinalPos, parRelativeMovement ? PSP_SEEK_CUR : PSP_SEEK_SET) == 0;
#elif defined(COMPILE_PC)
	return fseek(FFile, parFinalPos, parRelativeMovement? SEEK_CUR : SEEK_SET) == 0;
#endif
}

s32 TReadFile::GetSize()
{
	return FFileSize;
}

s32 TReadFile::GetPos()
{
	LAssert(IsOpen());

#ifdef COMPILE_PSP
	return sceIoLseek(FFile, 0, PSP_SEEK_CUR);
#elif defined(COMPILE_PC)
	return ftell(FFile);
#endif
}

const c8* TReadFile::GetFileName()
{
	return FFileName.c_str();
}

void TReadFile::OpenFile()
{
	if (FFileName.size() == 0) // bugfix posted by rt
	{
#if defined(COMPILE_PSP)
		FFile = -1;
#elif defined(COMPILE_PC)
		FFile = NULL;
#endif
		return;
	}

	c8 *locFilePath;
	c8 *locRealPath;
	core::stringc locFilename;


	locFilePath = (c8*)FFileName.c_str();

#if defined(COMPILE_PSP)
	if (locFilePath[0] == '/')
	{
		locFilename = "ms0:/";
		locFilename += locFilePath;
		locRealPath = (c8*)locFilename.c_str();

	}
	else
	{
#endif
		if ( (strstr(locFilePath, ":/") == 0)
#if defined(WIN32) || defined(WIN64) 
			&& (strstr(locFilePath, ":\\") == 0)
#endif
			)
		{
			c8 locWorkingDirectory[LONG_BUFFER_SIZE];
#if defined(COMPILE_PSP)
			getcwd(locWorkingDirectory, LONG_BUFFER_SIZE);
#elif defined(COMPILE_PC)
			_getcwd(locWorkingDirectory, LONG_BUFFER_SIZE);
#endif

			if (locWorkingDirectory[ strlen(locWorkingDirectory) - 1 ] != '\\' &&
			    locWorkingDirectory[ strlen(locWorkingDirectory) - 1 ] != '/')
			{

				locWorkingDirectory[ strlen(locWorkingDirectory) + 1 ] = 0;
				locWorkingDirectory[ strlen(locWorkingDirectory) ] = '/';

			}


			locFilename = locWorkingDirectory;
			locFilename += locFilePath;
			locRealPath = (c8*)locFilename.c_str();
		}
		else
		{
			locRealPath = locFilePath;
		}
#if defined(COMPILE_PSP)
	}
#endif

#if defined(COMPILE_PSP)
	FFile = sceIoOpen(locRealPath, PSP_O_RDONLY, 0777);
#elif defined(COMPILE_PC)
	if (FDataType == BINARY) fopen_s(&FFile, locRealPath, "rb");
	else if (FDataType == TEXT) fopen_s(&FFile, locRealPath, "rt");
	else FFile = NULL;
#endif

#if defined(COMPILE_PSP)
	if (FFile > -1)
#elif defined(COMPILE_PC)
 	if (FFile != NULL)
#endif
	{
		// get FileSize
#if defined(COMPILE_PSP)
		FFileSize = sceIoLseek(FFile, 0, PSP_SEEK_END);
		sceIoLseek(FFile, 0, PSP_SEEK_SET);
#elif defined(COMPILE_PC)
		fseek(FFile, 0, SEEK_END);
		FFileSize = ftell(FFile);
		fseek(FFile, 0, SEEK_SET);
#endif
	}
}

void TReadFile::Close()
{
#if defined(COMPILE_PSP)
	if (FFile > -1)
#elif defined(COMPILE_PC)
	if (FFile != NULL)
#endif
	{
#if defined(COMPILE_PSP)
		sceIoClose(FFile);
		FFile = -1;
#elif defined(COMPILE_PC)
		fclose(FFile);
		FFile = NULL;
#endif
	}
}

} // io namespace
} // engine namespace
} // psp namespace

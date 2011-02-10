#include "Common.h"

#include "WriteFile.h"

#if defined(COMPILE_PSP)
#include <pspiofilemgr.h>
#include <sys/unistd.h>
#elif defined(COMPILE_PC)
#include <cstdio>
#include <direct.h>
#endif

namespace psp { namespace engine { namespace io {

TWriteFile::TWriteFile(const c8* parFileName, bool parAppend, DATA_TYPE parDataType) : FFileSize(0), FDataType(parDataType),
#ifdef COMPILE_PC
FFile(NULL)
#elif defined(COMPILE_PSP)
FFile(-1)
#endif
{
	FFileName = parFileName;
	OpenFile(parAppend);
}



TWriteFile::~TWriteFile()
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

bool TWriteFile::IsOpen()
{
#if defined(COMPILE_PSP)
	return FFile > -1;
#elif defined(COMPILE_PC)
	return FFile != NULL;
#endif
}

s32 TWriteFile::Write(const void* parBuffer, s32 parSizeToWrite)
{
	LAssert(parBuffer != NULL);
	LAssert(IsOpen());
	
#if defined(COMPILE_PSP)
	return sceIoWrite(FFile, parBuffer, parSizeToWrite);
#elif defined(COMPILE_PC)
	return fwrite(parBuffer, 1, parSizeToWrite, FFile);
#endif
}

s32 TWriteFile::Write(c8 parChar)
{
	LAssert(IsOpen());

#if defined(COMPILE_PSP)
	return sceIoWrite(FFile, &parChar, 1);
#elif defined(COMPILE_PC)
	return fwrite(&parChar, 1, 1, FFile);
#endif
}

bool TWriteFile::Seek(s32 parFinalPos, bool parRelativeMovement)
{
	LAssert(IsOpen());

#ifdef COMPILE_PSP
	return sceIoLseek(FFile, parFinalPos, parRelativeMovement ? PSP_SEEK_CUR : PSP_SEEK_SET) == 0;
#elif defined(COMPILE_PC)
	return fseek(FFile, parFinalPos, parRelativeMovement? SEEK_CUR : SEEK_SET) == 0;
#endif
}

s32 TWriteFile::GetSize()
{
	return FFileSize;
}

s32 TWriteFile::GetPos()
{
	LAssert(IsOpen());

#ifdef COMPILE_PSP
	return sceIoLseek(FFile, 0, PSP_SEEK_CUR);
#elif defined(COMPILE_PC)
	return ftell(FFile);
#endif
}

const c8* TWriteFile::GetFileName()
{
	return FFileName.c_str();
}

void TWriteFile::OpenFile(bool parAppend)
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
		locFilename = "ms0:";
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
	FFile = sceIoOpen(locRealPath, parAppend ? PSP_O_APPEND|PSP_O_WRONLY|PSP_O_CREAT :  PSP_O_WRONLY|PSP_O_CREAT, 0777);
#elif defined(COMPILE_PC)
	if (FDataType == BINARY) fopen_s(&FFile, locRealPath, parAppend ? "ab" : "wb");
	else if (FDataType == TEXT) fopen_s(&FFile, locRealPath, parAppend ? "at" : "wt");
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

void TWriteFile::Close()
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

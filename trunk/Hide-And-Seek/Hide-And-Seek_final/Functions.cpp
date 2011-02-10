#include "Common.h"
#include "Functions.h"
#include "ReadFile.h"
#include "LoggerTypes.h"
#include "GameConstantes.h"
#include "Alloc.h"
#include "Vertex3D.h"
#include "MeshBuffer.h"
#include "StaticMeshOBJ.h"

namespace psp {

// -----------------------------------
// Functions for text buffer reading
// -----------------------------------

c8* ReachAfter(c8* parBuffer, c8 parCar)
{
	u32 i = 0;
	while(parBuffer[i] && (parBuffer[i] != parCar))
		++i;
	//print("Reach After read %d\n", parBuffer[i] == parCar? i+1: 0);
	return parBuffer[i] == parCar? &(parBuffer[i]) : parBuffer;
}

c8*	GetFirstWord(c8* parBuffer)
{
	s32 i = 0;
	while(parBuffer[i] && (parBuffer[i]==' ' || parBuffer[i]=='\n' || parBuffer[i]=='\r' || parBuffer[i]=='\t'))
		++i;

	//print("GetFirstWord has red %d\n", i);

	return &parBuffer[i];
}

void CopyWord(c8* parBuffer, s32 parBufferLength, c8* parWord)
{
	if(!parWord)
		return;

	s32 i = 0;
	while((i<parBufferLength) && parWord[i] && (parWord[i]!=' ') && (parWord[i]!='\n') && (parWord[i]!='\r') && (parWord[i]!='\t'))
		++i;

	for(s32 j=0; j<i; ++j)
		parBuffer[j] = parWord[j];

	parBuffer[i] = '\0';
}

void CopyWordLineEnd(c8* parBuffer, s32 parBufferLength, c8* parWord)
{
	if(!parWord)
		return;

	s32 i = 0;
	while((i<parBufferLength) && parWord[i] && (parWord[i]!='\n'))
		++i;

	for(s32 j=0; j<i; ++j)
		parBuffer[j] = parWord[j];

	parBuffer[i] = '\0';
}

void CopyWordSpaceEnd(c8* parBuffer, s32 parBufferLength, c8* parWord)
{
	if(!parWord)
		return;

	s32 i = 0;
	while((i<parBufferLength) && parWord[i] && (parWord[i]!=' '))
		++i;

	for(s32 j=0; j<i; ++j)
		parBuffer[j] = parWord[j];

	parBuffer[i] = '\0';
}

c8*	GetNextWord(c8* parWord)
{
	if (!parWord)
		return NULL;

	s32 i = 0;
	while(parWord[i] && (parWord[i]!=' ') && (parWord[i]!='\n') && (parWord[i]!='\r') && (parWord[i]!='\t'))
		++i;

	//print("GetNextWord has red %d\n", i);

	c8* locNextWord = GetFirstWord(&parWord[i]);
	return locNextWord == parWord ? NULL : locNextWord;

}

c8*	GetNextWordLineEnd(c8* parWord)
{
	if (!parWord)
		return NULL;

	s32 i = 0;
	while(parWord[i] && (parWord[i]!='\n'))
		++i;

	//print("GetNextWordLineEnd has red %d\n", i);

	c8* locNextWord = GetFirstWord(&parWord[i]);
	return locNextWord == parWord ? NULL : locNextWord;

}

// -----------------------------------
// Functions for ReadBuffer reading
// -----------------------------------

void CopyWordFromFile(c8* parOutputBuffer, u32 parBufferLength, IReadFile* parInputBuffer)
{
	LAssert(parBufferLength > 0);

	if(!parInputBuffer) return;

	u32 i = 0;
	c8 car = parInputBuffer->GetLastCarRead();
	while((i<parBufferLength) && car && (car!=' ') && (car!='\n') && (car!='\r') && (car!='\t'))
	{
		parOutputBuffer[i] = car;
		car = parInputBuffer->Read();
		++i;
	}

	parOutputBuffer[i] = '\0';
}

c8 ReachFromFile(IReadFile* parBuffer, c8 parCar)
{
	if(!parBuffer) return NULL;

	u32 i=0;
	c8 car = parBuffer->GetLastCarRead();
	while(car && (car != parCar))
	{
		++i;
		car = parBuffer->Read();
	}

	//print("Reach 2 read %d and finish (%c)\n", i, car);

	return car;
}

c8 ReachAfterFromFile(IReadFile* parBuffer, c8 parCar)
{
	if(!parBuffer) return NULL;

	u32 i=0;
	c8 car = parBuffer->GetLastCarRead();
	while(car && (car != parCar))
	{
		++i;
		car = parBuffer->Read();
	}

	//print("Reach After2 read %d\n", car == parCar? i+1: 0);

	return car == parCar? parBuffer->Read() : car;
}

c8 GetFirstWord(IReadFile* parBuffer)
{
	if(!parBuffer) return '\0';

	u32 i=0;
	c8 car = parBuffer->GetLastCarRead();
	//print("GetFirstWord2 last (%c) ", car);
	while(car && (car==' ' || car=='\n' || car=='\r' || car=='\t'))
	{
		++i;
		car = parBuffer->Read();
	}

	//print(" has red %d and finish (%c)\n", i, car);

	return i==0? '\0' : car;
}

c8 GetNextWord(IReadFile* parBuffer)
{
	if(!parBuffer) return NULL;

	s32 i = 0;
	c8 car = parBuffer->GetLastCarRead();
	while(car && (car!=' ') && (car!='\n') && (car!='\r') && (car!='\t'))
	{
		++i;
		car = parBuffer->Read();
	}

	//print("GetNextWord2 has red %d\n", i);

	return GetFirstWord(parBuffer);
}

// -----------------------------------
// Functions for load PPM, PGM files
// -----------------------------------

c8* LoadPXM(const c8* parFile, s32& parWidth, s32& parHeight, s32 parMode)
{
	engine::io::TReadFile locFile(parFile);
	//LOGC("Load picture %s\n", parFile);

	LAssert(locFile.IsOpen());

	// Parameters for picture settings
	c8* parOutput = NULL;
	s32 locDepth = 0;
	bool IsGreyScale = false;
	u32 locSizeInBytes = 0;
	u32 locState = PXM_HEADER;

	// Parameters to load texture in mirror mode
	s32 locColumn = 0;
	s32 locRow = 0;
	s32 locCurrPix = 0;

	// Parameters for read in file
	c8 locWordBuffer[LONG_BUFFER_SIZE];

	c8* locBuffer = NEW_ c8[locFile.GetSize()];
	locFile.Read(locBuffer, locFile.GetSize());

	c8* locLine = locBuffer;

	while(locLine && (locState != PXM_END) && (locState != PXM_FAIL))
	{
		c8* locWord = locLine;
		// At this state datas is in binary format
		if(!(locState & PXM_DATAS_REVERSE) && !(locState & PXM_DATAS_NORMAL))
			CopyWord(locWordBuffer, LONG_BUFFER_SIZE, locWord);

		if(!(locState & PXM_DATAS_REVERSE) && !(locState & PXM_DATAS_NORMAL) && (locWordBuffer[0] == '#')) // find end of line because
		{
			s32 i=0;
			while((locLine[i] != '\n') && (locLine[i] != '\r'))
				++i;

			locLine = &locLine[i];
			locState = locState | PXM_COMMENT;
		}
		else
		{
			switch(locState)
			{
			case PXM_HEADER: // Read picture id
				if((locWordBuffer[0] != 'P') || ((locWordBuffer[1] != '5') && (locWordBuffer[1] != '6')))
				{
					locState = PXM_FAIL;
					break;
				}

				IsGreyScale = locWordBuffer[1] == '5';// LOGC("Header : %s - IsGreyScale %d\n", locWordBuffer, IsGreyScale? 1:0);

				locState = PXM_WIDTH;
			break;

			case PXM_WIDTH: // Read picture width
				parWidth = atoi(locWordBuffer); //LOGC("Width : %d\n", parWidth);

				locState = PXM_HEIGHT;
			break;

			case PXM_HEIGHT: // Read picture height
				parHeight = atoi(locWordBuffer); //LOGC("Height : %d\n", parWidth);

				locState = PXM_DEPTH;
			break;

			case PXM_DEPTH: // Read picture pixels depth
				locDepth = atoi(locWordBuffer);
				locSizeInBytes = IsGreyScale? parWidth*parHeight : parWidth*parHeight*3; //LOGC("Depth : %d - SizeInBytes %d\n", locDepth, locSizeInBytes);

				// Allocate memory to store pictures datas
				parOutput = NEW_IN_DOMAIN(Video) c8[locSizeInBytes];

				/*locColumn = 0;
				locRow = parWidth-1;
				locCurrPix = locRow*parWidth*3 + locColumn;*/

				if(parMode == PXM_NORMAL)
					locState = PXM_DATAS_NORMAL;
				else if(parMode == PXM_REVERSE)
					locState = PXM_DATAS_REVERSE;
				else
					locState = PXM_FAIL;
			break;

			case PXM_DATAS_NORMAL:
				for(u32 i=0; i<locSizeInBytes; ++i)
				{
					parOutput[i] = locWord[i];
				}
			//*/
				locState = PXM_END;
			break;

			case PXM_DATAS_REVERSE: // Read picture pixels values
			//*
				locColumn = 0;
				locRow = parHeight-1;
				locCurrPix = locRow*parWidth*3;

				for(u32 i=0; i<locSizeInBytes; i+=3)
				{
					parOutput[locCurrPix++] = locWord[i];
					parOutput[locCurrPix++] = locWord[i+1];
					parOutput[locCurrPix++] = locWord[i+2];
					
					if(locColumn == (parWidth-1)*3)
					{
						locColumn = 0;
						--locRow;
					}
					else
						locColumn += 3;

					locCurrPix = locRow*parWidth*3 + locColumn;
				}
			//*/
				locState = PXM_END;
			break;

			case PXM_FAIL:
			case PXM_END:
			break;
			}
		}

		if(!(locState & PXM_FAIL) && !(locState & PXM_END))
		{
			if(!(locState & PXM_DATAS_NORMAL) && !(locState & PXM_DATAS_REVERSE) && !(locState & PXM_COMMENT))
				locLine = GetNextWord(locLine);
			else
			{
				locLine = &(locLine[4]);

				// Remove comment bite
				locState = ((locState>>1)<<1);
			}
		}
	}

	delete locBuffer;

	return parOutput;
}

c8* LoadPXMDirectlyFromFile(const c8* parFile, s32& parWidth, s32& parHeight, s32 parMode)
{
	engine::io::TReadFile locFile(parFile); //LOGC("Load picture %s\n", parFile);

	LAssert(locFile.IsOpen());

	// Parameters for picture settings
	c8* parOutput = NULL;
	s32 locDepth = 0;
	bool IsGreyScale = false;
	u32 locSizeInBytes = 0;
	u32 locState = PXM_HEADER;

	// Parameters to load texture in mirror mode
	s32 locColumn = 0;
	s32 locRow = 0;
	s32 locCurrPix = 0;

	// Parameters for file reading
	c8 locWordBuffer[SMALL_BUFFER_SIZE];
	c8 car = '\0';

	// Read the first car
	locFile.Read();

	while((locFile.GetPos() < locFile.GetSize()) && (locState != PXM_END) && (locState != PXM_FAIL))
	{
		// At this state datas is in binary format
		if(!(locState & PXM_DATAS_REVERSE) && !(locState & PXM_DATAS_NORMAL))
			CopyWordFromFile(locWordBuffer, SMALL_BUFFER_SIZE, &locFile);

		if(!(locState & PXM_DATAS_REVERSE) && !(locState & PXM_DATAS_NORMAL) && (locWordBuffer[0] == '#')) // find end of line because of comments
		{
			while((car != '\n') && (car != '\r'))
				car = locFile.Read();

			locState = locState | PXM_COMMENT;
		}
		else
		{
			switch(locState)
			{
			case PXM_HEADER: // Read picture id
				if((locWordBuffer[0] != 'P') || ((locWordBuffer[1] != '5') && (locWordBuffer[1] != '6')))
				{
					locState = PXM_FAIL;
					break;
				}

				IsGreyScale = locWordBuffer[1] == '5'; print("Header : %s - IsGreyScale %d\n", locWordBuffer, IsGreyScale? 1:0);

				locState = PXM_WIDTH;
			break;

			case PXM_WIDTH: // Read picture width
				parWidth = atoi(locWordBuffer); print("Width : %d\n", parWidth);

				locState = PXM_HEIGHT;
			break;

			case PXM_HEIGHT: // Read picture height
				parHeight = atoi(locWordBuffer); print("Height : %d\n", parWidth);

				locState = PXM_DEPTH;
			break;

			case PXM_DEPTH: // Read picture pixels depth
				locDepth = atoi(locWordBuffer);
				locSizeInBytes = IsGreyScale? parWidth*parHeight : parWidth*parHeight*3; print("Depth : %d - SizeInBytes %d\n", locDepth, locSizeInBytes);

				// Allocate memory to store pictures datas
				parOutput = NEW_IN_DOMAIN(Video) c8[locSizeInBytes];

				if(parMode == PXM_NORMAL)
					locState = PXM_DATAS_NORMAL;
				else if(parMode == PXM_REVERSE)
					locState = PXM_DATAS_REVERSE;
				else
					locState = PXM_FAIL;
			break;

			case PXM_DATAS_NORMAL:
				for(u32 i=0; i<locSizeInBytes; ++i)
				{
					parOutput[i] = locFile.Read();
				}

				locState = PXM_END;
			break;

			case PXM_DATAS_REVERSE: // Read picture pixels values
			
				locColumn = 0;
				locRow = parHeight-1;
				locCurrPix = locRow*parWidth*3;

				for(u32 i=0; i<locSizeInBytes; i+=3)
				{
					parOutput[locCurrPix++] = locFile.Read();
					parOutput[locCurrPix++] = locFile.Read();
					parOutput[locCurrPix++] = locFile.Read();
					
					if(locColumn == (parWidth-1)*3)
					{
						locColumn = 0;
						--locRow;
					}
					else
						locColumn += 3;

					locCurrPix = locRow*parWidth*3 + locColumn;
				}

				locState = PXM_END;
			break;

			case PXM_FAIL:
			case PXM_END:
			break;
			}
		}

		if((locState != PXM_FAIL) && (locState != PXM_END))
		{
			if(!(locState & PXM_DATAS_NORMAL) && !(locState & PXM_DATAS_REVERSE) && !(locState & PXM_COMMENT))
				car = GetNextWord(&locFile);
			else
			{
				// TODO : test tis call because it dont work on loading with buffer
				car = ReachFromFile(&locFile, '\n');				
				locState = ((locState>>1)<<1);
			}
		}
	}

	return parOutput;
}

} // namespace psp

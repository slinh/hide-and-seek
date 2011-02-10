// Texture_Converter.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "config.h"
#include "Functions.h"
#include "Alloc.h"
#include "LoggerTypes.h"
#include "TextureItem.h"

int _tmain(int argc, _TCHAR* argv[])
{
	INITDOMAINMEMORYMANAGER
	LOGINSTANCE(TLoggerDebug)

	psp::engine::video::TTextureItem locTexture("Data/bureau.ppm", psp::engine::video::CF_A1R5G5B5);
	
	REPORTLEAKS
	LOGCLOSE

	system("pause");

	return 0;
}


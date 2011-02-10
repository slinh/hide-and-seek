#include "stdafx.h"

#include "engineMath.h"
#include "Alloc.h"
#include "LoggerTypes.h"

using namespace psp::engine::core;

int _tmain(int argc, _TCHAR* argv[])
{
	// Init rustines
	INITDOMAINMEMORYMANAGER
	LOGINSTANCE(TLoggerDebug)

	// End rustines
	REPORTLEAKS
	LOGCLOSE

	system("PAUSE");
	return 0;
}

#ifndef LAssert_H
#define LAssert_H

#include "config.h"

#ifdef COMPILE_PSP
#include <pspgu.h>
#endif

#ifdef DEBUG
	#if defined(COMPILE_PSP)
		#define LAssert(CONDITION) if(!(CONDITION))                                                         \
									{                                                                       \
									  sceGuTerm();                                                          \
									  pspDebugScreenInit();                                                 \
									  print("LAssert FAILED %s(%d): %s\n", __FILE__, __LINE__, #CONDITION); \
									  asm("break\r\n");                                                     \
									  sceKernelExitGame();													\
									}
	#elif defined(COMPILE_PC)||defined(COMPILE_TOOLS)

		#define LAssert(CONDITION) _engine_DEBUG_BREAK_IF(!(CONDITION))
	#endif

	#define LAssertIsCalled() LAssert(false)
	#define LAssertNotImplemented() LAssert(false)
#else
	#define LAssert(CONDITION) DoNothing(!(CONDITION))
	#define LAssertIsCalled() DoNothing(true)
	#define LAssertNotImplemented() DoNothing(true)
#endif 

#endif
	
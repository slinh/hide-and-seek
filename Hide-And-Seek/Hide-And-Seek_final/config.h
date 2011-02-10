#ifndef CONFIG_H
#define CONFIG_H

#define ANTISLASH 92

//#define COMPILE_PC
#define COMPILE_PSP
//#define CAMERA_DEBUG
#define WIREFRAME_MODE
#define WITH_SWIZZLE_TEXTURE
//#define COMPILE_FINAL
#define WITH_LIGHTS
//#define WITH_BLEND

#if defined(COMPILE_PC) || defined(COMPILE_TOOLS)
#undef COMPILE_PSP
#endif

#ifdef COMPILE_TOOLS
#define COMPILE_PC
#endif

#define DEBUG
//#define IA_LOG
#define MEM_LOG
//#define _3D_LOG
//#define LOAD_LOG
//#define CORE_LOG
//#define SOUND_LOG
#define WITH_SOUNDS

#if defined(COMPILE_PSP)
	#include <pspkernel.h>
	#include <pspdebug.h>
	#define print pspDebugScreenPrintf
	#define SMALL_BUFFER_SIZE 32
	#define LONG_BUFFER_SIZE 256
#elif defined(COMPILE_PC)
	#define print printf
	#define SMALL_BUFFER_SIZE 128
	#define LONG_BUFFER_SIZE 1024

	#include <cassert>
#endif

// core includes
#include "engineTypes.h"

// others
#include "macro.h"

// Use this directive when you wannot forget something : it is an exemple - NO UNCOMMENT on this one
//#pragma message ("WARNING!!! " __FILE__" : DONT FORGET TO RESOLVE THIS LAssert PROBLEM!!! ")

inline void DoNothing(bool) {}
inline void DoNothingLog(const c8* pattern, ...) {}

#endif

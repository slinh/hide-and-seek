/*
 * PSP Software Development Kit - http://www.pspdev.org
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * Copyright (c) 2005 Jesper Svennevid
 */
#include "callbacks.h"

#ifdef COMPILE_PSP

#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include <oslib/oslib.h>

int exitCallback(int arg1, int arg2, void *common)
{
	// Test to quit the game properly
	sceGuTerm();
	oslEndGfx();
	oslQuit();

	// TODO : instead quit - turn TGame in quit mode to free allocated memory
	sceKernelExitGame();

	return 0;
}

int callbackThread(SceSize args, void *argp)
{
	int cbid;

	cbid = sceKernelCreateCallback("Exit Callback", exitCallback, NULL);
	sceKernelRegisterExitCallback(cbid);

	sceKernelSleepThreadCB();

	return 0;
}

int setupCallbacks()
{
	int thid = 0;

	thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, 0);

	if(thid >= 0)
	{
		sceKernelStartThread(thid, 0, 0);
	}

	return thid;
}

#endif

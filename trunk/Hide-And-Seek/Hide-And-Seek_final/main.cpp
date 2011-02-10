#include "Common.h"
#include "Game.h"

#ifdef COMPILE_PSP

PSP_MODULE_INFO("Hide-And-Seek", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

#endif

int main()
{
#ifdef COMPILE_PSP
	//scePowerSetClockFrequency(333, 333, 166); // Overclock psp system
#endif

	// Init singletons
	if(!psp::engine::input::TUserInputStateBuffer::HasInstance())
		psp::engine::input::TUserInputStateBuffer::CreateInstance();

	if(!psp::game::TGame::HasInstance())
		psp::game::TGame::CreateInstance();

	psp::game::TGame::Instance().Start();

	psp::game::TGame::Instance().OnLaunch();

	psp::game::TGame::Instance().Stop();

#ifdef COMPILE_PSP 
	sceKernelExitGame();
#else
	system("PAUSE\n");
#endif

    return 0;
}

//int main( void)
//{
//	//System initilization
//	setupCallbacks();
//	pspDebugScreenInit();  //init the screen in a special mode that allow us to print on it easily
//	//reset the screen
//	pspDebugScreenClear();
//
//    pspDebugScreenSetXY(0, 1);
//    pspDebugScreenPrintf("Credits: \n");
//    pspDebugScreenPrintf("I was able to write this code thanks to all ps2dev guys \n");
//    pspDebugScreenPrintf("and specially from PspPet's posts  \n \n");
//    pspDebugScreenPrintf("                                       www.pspzorba.com  \n \n");
//
//    sceKernelDelayThread(5000 * 1000); // 5  Sec
//
//	pspDebugScreenClear();
//
//    psp::engine::net::AdhocNetwork* locAdhoc = psp::engine::net::AdhocNetwork::CreateInstance();
//	locAdhoc->Init();
//
//
//    SceCtrlData pad;
//    int ret ;
//    int encore=1;
//	pspDebugScreenClear();
//    while(encore)
//    {
//        pspDebugScreenSetXY(0, 1);
//        pspDebugScreenPrintf("If you want to initiate the comm press [] \n");
//        pspDebugScreenPrintf("If you want to wait for being contacted press /\\ \n");
//        pspDebugScreenPrintf("If you want to give up press O");
//
//        //what button is pressed
//	    sceDisplayWaitVblankStart();
//		sceCtrlReadBufferPositive(&pad, 1);
//
//        // adhoc network
//		locAdhoc->Update(pad);
//
//        if(pad.Buttons & PSP_CTRL_CIRCLE)
//        {
//            encore =0;
//        }
//
//    }//end of main while
//	pspDebugScreenClear();
//    pspDebugScreenPrintf("Fini !");
//
//	sceKernelDelayThread(5000 * 1000); // 5  Sec
//	sceKernelExitGame();
//
//return 0;
//}
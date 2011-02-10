#include "AdhocNetwork.h"
#include "LoggerTypes.h"
#ifdef COMPILE_PSP
#include "ZBadhoc.h"

#include <pspctrl.h>
#include <pspsdk.h>
#endif

namespace psp { namespace engine { namespace net {

	AdhocNetwork::AdhocNetwork()
	{
		SINGLETONREGINSTANCE
	}

	AdhocNetwork::~AdhocNetwork()
	{
		Free();
	}

	void AdhocNetwork::Init()
	{
#ifdef COMPILE_PSP
		ZBadhoc::getSingleton();
#endif
	}

	void AdhocNetwork::Free()
	{
		
	}

#ifdef COMPILE_PSP
	void AdhocNetwork::Update(SceCtrlData parPad)
	{
		pspDebugScreenSetXY(0, 1);
        print("If you want to initiate the comm press [] \n");
        print("If you want to wait for being contacted press /\\ \n");

        if(parPad.Buttons & PSP_CTRL_SQUARE)
        {
            RequestConnection();
        }

        if(parPad.Buttons & PSP_CTRL_TRIANGLE)
        {
            WaitForConnection();
        }
	}
#endif

	void AdhocNetwork::RequestConnection()
	{
#ifdef COMPILE_PSP
		s32 ret ;

		//I will request a connection
		ZBremotePsp * pPsp= ZBadhoc::getSingleton().selectAPsp();
		if( pPsp==NULL)
		{
			return;
		}
		pspDebugScreenSetXY(0, 18);
		print("request a connection \n");
		//we have selected a PSP, we request a connection
		ret = ZBadhoc::getSingleton().requestConnection(pPsp);
		if(ret <0)
		{
			return;
		}

		//when we are there, it means that my request has been accepted
		//I've read that at this point lumines close the connection and reopens it.
		//I guess it's for an exclusive comminication, but I think it's not mandatory

		// I just send an hello distant world to check that I can communicate
		// At this point you can implement whatever you want ......

		c8 mess[SMALL_BUFFER_SIZE];
		strncpy(mess, "Hello distant World !!!", SMALL_BUFFER_SIZE);
		ret = ZBadhoc::getSingleton().sendData( pPsp, mess, strlen( mess)); //send a messge to the other PSP
#endif
	}

	void AdhocNetwork::WaitForConnection()
	{
#ifdef COMPILE_PSP
		s32 ret ;

		//I will wait for a connection
		ZBremotePsp *pPsp = ZBadhoc::getSingleton().waitForConnection();
		if (pPsp == NULL)
		{ //I give up or I cancelled the request
			return;
		}

		//the connection has been accepted
		//when we are there, it means that my request has been accepted
		//I've read that at this point lumines close the connection and reopens it.
		//I guess it's for an exclusive comminication, but I think it's not mandatory
		char buffer[42+1];
		ret = ZBadhoc::getSingleton().receiveData( pPsp, buffer, 42);  //wait for a message

		if ( ret>0)
		{
			buffer[ret]=0;
			pspDebugScreenSetXY(0, 10);
			print("%s", buffer);
			sceKernelDelayThread(5000 * 1000); // 5 Sec
		}
#endif
	}

} // network namespace
} // engine namespace
} // psp namespace
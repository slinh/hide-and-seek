/**********************************************************************************************************
 * This file is part of PSPlorer.
 *
 *   PSPlorer is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   PSPlorer is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with PSPlorer.  If not, see <http://www.gnu.org/licenses/>.
 *
 * *******************************************************************************************************
 * Author :  pspZorba
 * Website:  www.pspZorba.com
 * changelog:
 * 		2008-04-08: creation
 * *******************************************************************************************************/


#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspsdk.h>
#include <pspdisplay.h>

#include <pspwlan.h>
#include <pspnet.h>
#include <pspnet_inet.h>
#include <pspnet_adhoc.h>
#include <pspnet_adhocctl.h>
#include <pspnet_adhocmatching.h>
#include <psputility_sysparam.h>

#include <string.h>

#include "ZBadhoc.h"


struct productStruct product;


/***************************************************************
 * @function: ZBloadStartModule
 * start a prx
 * @param1 : const char *prx
 * prx name
 * @param2 : int mode
 * mode (PSP_MEMORY_PARTITION_KERNEL or PSP_MEMORY_PARTITION_USER)
 * @param3 : int line
 * line of the display
 * @return: int
 * the module uid
 * *************************************************************/
int ZBloadStartModule( const char *prx, int mode, int line)
{
	SceUID mod = pspSdkLoadStartModule(prx, mode);
    if( mod <0)
    {
        pspDebugScreenSetXY(0, line);
    	pspDebugScreenPrintf("Module %s err = 0x%08X ", prx, mod);
    }
    else
    {
    	pspDebugScreenSetXY(0, line);
        pspDebugScreenPrintf("Module %s started", prx);
    }

    return mod;
}



/***************************************************************
 * @function: matchingCB
 * manage the reception of events sent by other PSP. I didn't test all the event
 * @param1 : int unk1
 *
 * @param2 : int event
 * the event
 * @param3 : char *macSource
 * the mac address of the sender
 * @param4 : int size
 * size of the data that were sent
 * @param5 : char *data
 * the datas
 * @return: void
 *
 * *************************************************************/
void matchingCB(int unk1, int event, unsigned char *macSource, int size, void *data)
{
    //we lookup the pPsp by its Mac Address
    ZBremotePsp *pPsp=ZBavaillableRemotePsp::getSingleton().findByMacAddress( (u8*) macSource);

    switch(event)
    {
        case PSP_ADHOC_MATCHING_EVENT_HELLO: //A psp has joined
            if( pPsp == NULL)
            { //it's a new PSP, we add it to the list
                char buffer[42];
                memcpy(buffer,data,42);
                buffer[41]=0;

                pPsp = new ZBremotePsp( (u8*) macSource, buffer);
                pPsp->setState( ZB_JOINED);
                ZBavaillableRemotePsp::getSingleton().addPSP( pPsp);
            }

        break;
        case PSP_ADHOC_MATCHING_EVENT_DISCONNECT: //A psp has given up
            if(  pPsp!= NULL)
            {
              ZBavaillableRemotePsp::getSingleton().removePSP(pPsp);
            }

        break;

        case PSP_ADHOC_MATCHING_EVENT_JOIN: // A PSP has selected me
            if(  pPsp!= NULL)
            {
                pPsp->setState( ZB_SELECTED);
            }
        break;

        case PSP_ADHOC_MATCHING_EVENT_REJECT:
            if(  pPsp!= NULL)
            {
                pPsp->setState( ZB_REJECTED);
            }
        break;
        case PSP_ADHOC_MATCHING_EVENT_CANCEL:
            if(  pPsp != NULL)
            {
                pPsp->setState( ZB_CANCELED);
            }
        break;
        case PSP_ADHOC_MATCHING_EVENT_COMPLETE:
            if(  pPsp!= NULL)
            {
                pPsp->setState( ZB_ESTABLISHED);
            }
        break;

        case 6:  //connection accepted ?
            if(  pPsp!= NULL)
            {
                pPsp->setState( ZB_ACCEPTED);
            }
        break;


        default:
            pspDebugScreenSetXY(12, 15);
            pspDebugScreenPrintf("DEFAULT %d", event);
        break;
    }


}

/***************************************************************
******   ZBremote mthods   *************************************
***************************************************************/


/***************************************************************
 * @classe: ZBremotePsp
 * @methode: display
 * display a PSPs
 * @param1 : int X
 * X-coordonate
 * @param2 : int Y
 * Y-coordonate
 * @return: void
 *
 * *************************************************************/
void ZBremotePsp::display( int X, int Y)
{
    pspDebugScreenSetXY(X, Y);
    for( int j =0; j< 6; j++)
        pspDebugScreenPrintf("%X:",myMacAddress[j]);
    pspDebugScreenPrintf(", %s , status: %d",name.c_str(), connectionState);
}










/***************************************************************
******    ZBavaillableRemotePsp   ******************************
***************************************************************/



/***************************************************************
 * @classe: ZBavaillableRemotePsp
 * @methode: emptylist
 * clean the list of availlable PSP
 * @param1 : void
 * void
 * @return: void
 * void
 * *************************************************************/
void ZBavaillableRemotePsp::emptylist( void)
{
    list<ZBremotePsp *>::iterator it;
	for( it= myList.begin(); it != myList.end(); it++)
	{
	    delete (*it);

	}

    myList.clear();
}




/***************************************************************
 * @classe: ZBavaillableRemotePsp
 * @methode: getElt
 * look up a PSP by it's number
 * @param1 : int num
 * number
 * @return: ZBremotePsp *
 * NULL or the address of a remote PSP
 * *************************************************************/
ZBremotePsp * ZBavaillableRemotePsp::getElt( int num)
{
    list<ZBremotePsp *>::iterator it;
    int j;
	for( j=0, it= myList.begin(); it != myList.end(); it++, j++)
	{
	    if( j==num)
            return (*it);
	}

    return NULL;
}



/***************************************************************
 * @classe: ZBavaillableRemotePsp
 * @methode: findByMacAddress
 * look up a PSP by it's Mac Address
 * @param1 : const u8 aMacAddress[6]
 * the Mac Address
 * @return: ZBremotePsp *
 * NULL or the address of a remote PSP
 * *************************************************************/
ZBremotePsp * ZBavaillableRemotePsp::findByMacAddress( const u8 aMacAddress[6])
{
    list<ZBremotePsp *>::iterator it;
	for( it= myList.begin(); it != myList.end(); it++)
	{
	    if( memcmp( aMacAddress, (*it)->getMacAddress() ,6 *sizeof(u8))==0)
            return (*it);
	}

    return NULL;
}


/***************************************************************
 * @classe: ZBavaillableRemotePsp
 * @methode: findByState
 * find the find PSP which state is aSatre
 * @param1 : ZBremotePspState aState
 * the state
 * @return: ZBremotePsp *
 * NULL or the address of a remote PSP
 * *************************************************************/
ZBremotePsp * ZBavaillableRemotePsp::findByState(ZBremotePspState aState )
{
    list<ZBremotePsp *>::iterator it;
	for( it= myList.begin(); it != myList.end(); it++)
	{
	    if( aState == (*it)->getState() )        return (*it);
	}

    return NULL;
}



/***************************************************************
 * @classe: ZBavaillableRemotePsp
 * @methode: display
 * display the list of availlable PSPs
 * @param1 : int X
 * X-coordonate
 * @param2 : int Y
 * Y-coordonate
 * @param3 : int curr
 * selected line
 * @return: void
 *
 * *************************************************************/
void ZBavaillableRemotePsp::display( int X, int Y, int curr)
{
    list<ZBremotePsp *>::iterator it;
    int j;
	for( j=0, it= myList.begin(); it != myList.end(); it++, j++)
	{
	    if( j==curr)
            {	pspDebugScreenSetTextColor(0x0000FFFF);}
        else
            {	pspDebugScreenSetTextColor(0xFFFFFFFF);}

		(*it)->display(X, Y+j);
	}
    pspDebugScreenSetTextColor(0xFFFFFFFF);
}










/***************************************************************
******   ZBadhoc mthods   **************************************
***************************************************************/



/***************************************************************
 * @classe: ZBadhoc
 * @methode: requestConnection
 * request a connection
 * @param1 : ZBremotePsp * aPsp
 * the PSP we want to connect to
 * @return: int
 *  -1 give up or rejected, <0 error 0 success
 * *************************************************************/
int ZBadhoc::requestConnection(ZBremotePsp * aPsp)
{
    int ret = sceNetAdhocMatchingSelectTarget(matchingHD, (unsigned char *) aPsp->getMacAddress(), 0, 0); //we could add a message
    if( ret <0) return ret;

	SceCtrlData pad;
    pspDebugScreenClear();
    pspDebugScreenPrintf("request done, Wait for an answer. O to give up \n");
    int encore=1;
    while(encore)
    {
	    sceDisplayWaitVblankStart();
		sceCtrlReadBufferPositive(&pad, 1);
        if(pad.Buttons & PSP_CTRL_CIRCLE)
        {   //give up
            return -1;
        }

        //connection accepted
        if( (aPsp->getState() == ZB_ACCEPTED)||(aPsp->getState() == ZB_ESTABLISHED))  return 0;

        //connection not accepted
        if( aPsp->getState() == ZB_REJECTED)
        {
               aPsp->setState( ZB_JOINED); //reset the state flag
               pspDebugScreenPrintf("request rejected");
               sceKernelDelayThread(1000 * 1000); // 1 sec
               return -1;
        }
    }
    return -1;
}




/***************************************************************
 * @classe: ZBadhoc
 * @methode: checkWlanPower
 * check if the wlan button is on
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::checkWlanPower(void)
{
    int ret, encore;
        //1) check if Wlan Power On
    encore =1;
    while( encore)
    {
        ret = sceWlanDevIsPowerOn();
        if(  ret == 1)
        {
            encore =0;
            pspDebugScreenSetXY(0, line++);
            pspDebugScreenPrintf("Wlan power is on                       ");
        }
        else
        {
            sceDisplayWaitVblankStart();
            pspDebugScreenSetXY(0, line++);
            pspDebugScreenPrintf("Wlan power is off, is the switch is on?");
            state = POWER;
        }
    }

}

/***************************************************************
 * @classe: ZBadhoc
 * @methode: getMacAddress
 * get the MAC address
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::getMacAddress(void)
{
    int ret = sceWlanGetEtherAddr(myMacAddress);
    if (ret == 0)
    {
        pspDebugScreenSetXY(0, line++);
        pspDebugScreenPrintf("Wlan Ethernet Addr: ");
    	for(int i=0; i<6;i++)
            pspDebugScreenPrintf("%02X:", myMacAddress[i]);
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("Error getting Wlan Ethernet Address (0x%08X)", ret);
    	state= MAC_ADDRESS;
    }

}



/***************************************************************
 * @classe: ZBadhoc
 * @methode: loadModules
 * loads the modules used for the communication
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::loadModules( void)
{
    int ret;
    ret = ZBloadStartModule("flash0:/kd/ifhandle.prx", PSP_MEMORY_PARTITION_KERNEL, line++);
    if( ret<0) state = ZB_COMM_MODULE;
    ret = ZBloadStartModule("flash0:/kd/memab.prx", PSP_MEMORY_PARTITION_KERNEL, line++);
    if( ret<0) state = ZB_COMM_MODULE;
    ret = ZBloadStartModule("flash0:/kd/pspnet_adhoc_auth.prx", PSP_MEMORY_PARTITION_KERNEL, line++);
    if( ret<0) state = ZB_COMM_MODULE;
    ret = ZBloadStartModule("flash0:/kd/pspnet.prx", PSP_MEMORY_PARTITION_USER, line++);
    if( ret<0) state = ZB_COMM_MODULE;
    ret = ZBloadStartModule("flash0:/kd/pspnet_adhoc.prx", PSP_MEMORY_PARTITION_USER, line++);
    if( ret<0) state = ZB_COMM_MODULE;
    ret = ZBloadStartModule("flash0:/kd/pspnet_adhocctl.prx", PSP_MEMORY_PARTITION_USER, line++);
    if( ret<0) state = ZB_COMM_MODULE;
    ret = ZBloadStartModule("flash0:/kd/pspnet_adhoc_matching.prx", PSP_MEMORY_PARTITION_USER, line++);
    if( ret<0) state = ZB_COMM_MODULE;

}


/***************************************************************
 * @classe: ZBadhoc
 * @methode: libNetInit
 * init the net lib
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::libNetInit( void)
{
    int ret = sceNetInit(0x20000, 0x20 , 0x1000, 0x20, 0x1000);
    if(  ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("Init Libs err = 0x%08X ", ret);
        state = ZB_LIB_NET;
    }
    else
    {
    	pspDebugScreenSetXY(0, line++);
        pspDebugScreenPrintf("Init Libs ..done");
    }
}



/***************************************************************
 * @classe: ZBadhoc
 * @methode: libAdhocInit
 * init the adhoc lib
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::libAdhocInit( void)
{
    int ret = sceNetAdhocInit();
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("Init Adhoc err = 0x%08X ", ret);
        state = ZB_LIB_ADHOC;
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("Init Adhoc ..done");
    }

}



/***************************************************************
 * @classe: ZBadhoc
 * @methode: libAdhocctlInit
 * init the adhocctl lib
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::libAdhocctlInit( void)
{
           //adhocctl lib
    int ret = sceNetAdhocctlInit(0x2000, 0x20, &product);
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("Init AdhocctInit err = 0x%08X ", ret);
        state = ZB_LIB_ADHOCCTL;

    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("Init AdhocctInit ..done");
    }



}




/***************************************************************
 * @classe: ZBadhoc
 * @methode: adhocctlConnect
 * Connect to the Adhoc control
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::adhocctlConnect( void)
{

    int ret = sceNetAdhocctlConnect(NULL);
    if( ret !=0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocctlConnect err = 0x%08X ", ret);
        state = ZB_ADHOCCTL_CONNECT;
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocctlConnect ..done");
    }



}


/***************************************************************
 * @classe: ZBadhoc
 * @methode: adhocctlState
 *  wait for the state of the Adhoc control to be 1
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::adhocctlState( void)
{
    int encore =1, ret;
    int s;
    while( encore)
    {
        ret = sceNetAdhocctlGetState(&s);

        pspDebugScreenSetXY(0, line);
    	pspDebugScreenPrintf("State:%d  Ret:%x", s, ret);

        if (s == 1)
        {
            encore=0; /* connected */
        }
        else
        {
            /* wait a little before polling again */
            sceKernelDelayThread(50 * 1000); // 50ms
        }
    }
    line++;
}


/***************************************************************
 * @classe: ZBadhoc
 * @methode: pdpCreate
 *
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::pdpCreate( void)
{
    //open a connection
    pdpHD = sceNetAdhocPdpCreate( myMacAddress , port, 0x400, 0);
    if( pdpHD<0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("PDP creation err = 0x%08X ", pdpHD);
        state = ZB_PDP_CREATE;
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("PDP creation..done");
    }

}


/***************************************************************
 * @classe: ZBadhoc
 * @methode: matchingInit
 * init the marching process
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::matchingInit( void)
{
    int ret = sceNetAdhocMatchingInit( 0x20000);
    if( ret !=0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingInit err = 0x%08X ", ret);
        state = ZB_MATCHING_INIT;
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingInit ..done");
    }

}




/***************************************************************
 * @classe: ZBadhoc
 * @methode: createMatching
 * setups the matching callback
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::createMatching( void)
{
    matchingHD = sceNetAdhocMatchingCreate( 3,0xa,0x22b,0x800, 0x2dc6c0, 0x5b8d80,3,0x7a120, matchingCB);
    if( matchingHD<0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("Matching creation err = 0x%08X ", matchingHD);
        state = ZB_CREATE_MATCHING;
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("Matching creation..done");
    }



}


/***************************************************************
 * @classe: ZBadhoc
 * @methode: startMatching
 * In the matching wee send PSP's nickname
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::startMatching( void)
{
    char name[50];
    sceUtilityGetSystemParamString(PSP_SYSTEMPARAM_ID_STRING_NICKNAME, name, 50);

    int ret = sceNetAdhocMatchingStart( matchingHD, 0x10,0x2000,0x10,0x2000,strlen(name),name);
    if( ret !=0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingStart err = 0x%08X ", ret);
        state = ZB_START_MATCHING;
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingStart ..done");
    }

}



/***************************************************************
 * @classe: ZBadhoc
 * @methode: init
 * init libs for an adhoc communication
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::init( void)
{
    if( state != ADHOC_UNINIT) return;
    line=0;

    memset(myMacAddress, 0, 6*sizeof(u8) );
    strcpy(product.product, "ULUS99999");
    product.unknown = 0;
    matchingHD=-1;
    pdpHD=-1;
    port = 0x309;

    state = ADHOC_INIT;
    //power check
    checkWlanPower();
    if( state!=ADHOC_INIT) return;

    //get the MacAddress
    getMacAddress();
    if( state!=ADHOC_INIT) return;

    //starts the prx needed for adhoc communication
    loadModules();
    if( state!=ADHOC_INIT) return;


    //init the libs
    libNetInit();
    if( state!=ADHOC_INIT) return;

    libAdhocInit();
    if( state!=ADHOC_INIT) return;

    libAdhocctlInit();
    if( state!=ADHOC_INIT) return;

    adhocctlConnect();
    if( state!=ADHOC_INIT) return;

    adhocctlState();
    if( state!=ADHOC_INIT) return;

    pdpCreate();
    if( state!=ADHOC_INIT) return;

    matchingInit();
    if( state!=ADHOC_INIT) return;

    createMatching();
    if( state!=ADHOC_INIT) return;

    startMatching();
    if( state!=ADHOC_INIT) return;

}




/***************************************************************
 * @classe: ZBadhoc
 * @methode: unInit
 * unInit libs for an adhoc communication
 * @param1 : void
 * void
 * @return: void
 *
 * *************************************************************/
void ZBadhoc::unInit( void)
{
    int ret;

    if( state!=ADHOC_INIT) return;

        //close the connection
    ret = sceNetAdhocctlDisconnect();
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocctlDisconnect err = 0x%08X ", ret);
        sceKernelSleepThread();
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocctlDisconnect..done");
    }



    ret = sceNetAdhocPdpDelete(pdpHD, 0);
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("PDP close err = 0x%08X ", ret);
        sceKernelSleepThread();
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("PDP close..done");
    }


    ret = sceNetAdhocMatchingStop( matchingHD);
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingStop err = 0x%08X ", ret);
        sceKernelSleepThread();
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingStop..done");
    }


    ret = sceNetAdhocMatchingDelete( matchingHD);
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingDelete err = 0x%08X ", ret);
        sceKernelSleepThread();
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingDelete..done");
    }



    ret = sceNetAdhocMatchingTerm();
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingTerm err = 0x%08X ", ret);
    	sceKernelSleepThread();
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocMatchingTerm..done");
    }


    ret = sceNetAdhocctlTerm();
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocctlTerm err = 0x%08X ", ret);
    	sceKernelSleepThread();
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocctlTerm..done");
    }



    ret = sceNetAdhocTerm();
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocTerm err = 0x%08X ", ret);
    	sceKernelSleepThread();
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetAdhocTerm..done");
    }

    ret = sceNetTerm();
    if( ret <0)
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetTerm err = 0x%08X ", ret);
    	sceKernelSleepThread();
    }
    else
    {
        pspDebugScreenSetXY(0, line++);
    	pspDebugScreenPrintf("sceNetTerm..done");
    }

    state = ADHOC_UNINIT;
}




/***************************************************************
 * @classe: ZBadhoc
 * @methode: waitForConnection
 * wait for a PSPs to try to connect to me
 * @param1 : void
 * void
 * @return: ZBremotePsp *
 * NULL => give up, the PSP that has contacted me
 * *************************************************************/
ZBremotePsp * ZBadhoc::waitForConnection( void)
{
	SceCtrlData pad;
    pspDebugScreenClear();


    int encore=1;
	while( encore)
	{
	    sceDisplayWaitVblankStart();
		sceCtrlReadBufferPositive(&pad, 1);

        pspDebugScreenSetXY(0, 1);
        pspDebugScreenPrintf("Waiting for a connection request, O to give up");
		ZBavaillableRemotePsp::getSingleton().display(0,2,0);
            //look up in the list if a PSP is trying to reach me
        ZBremotePsp *pElt = ZBavaillableRemotePsp::getSingleton().findByState( ZB_SELECTED);
        if(pElt==NULL)
        {//until now, nobody tried to reach me
            if(pad.Buttons & PSP_CTRL_CIRCLE)
            { //we want to give up
                encore =0;
			}

            continue;
        }

        //we have been contacted for a connection !!!
        pspDebugScreenClear();
        pspDebugScreenSetXY(0, 1);
        for(int i=0;i<6;i++)
                pspDebugScreenPrintf("%X:", pElt->getMacAddress()[i]);
        pspDebugScreenPrintf("%s has requested a connection\nTo accept the connection press X, to cancel press O\n", pElt->getName().c_str());

        int encore2=1;
        while(encore2)
        {
            sceDisplayWaitVblankStart();
            sceCtrlReadBufferPositive(&pad, 1);

			if(pad.Buttons & PSP_CTRL_CIRCLE)
            {//I don't acept the connection
                sceNetAdhocMatchingCancelTarget(matchingHD, (unsigned char *) pElt->getMacAddress());
                pElt->setState( ZB_JOINED); //I reset the state (in order to not re-select the line cf some lines above)
                encore2=0;
                continue;
            }
            if(pad.Buttons & PSP_CTRL_CROSS)
            {
                //Connection accepted !!!
                sceNetAdhocMatchingSelectTarget(matchingHD, (unsigned char *) pElt->getMacAddress(), 0, 0);
                return pElt;
            }

        }//end of the second while (accept or not the connection
	}//end of the main while

    return NULL;
}




/***************************************************************
 * @classe: ZBadhoc
 * @methode: selectAPsp
 * select a PSP to connect to
 * @param1 : void
 * void
 * @return: ZBremotePsp *
 * NULL or the PSP which is selected
 * *************************************************************/
ZBremotePsp * ZBadhoc::selectAPsp( void)
{
    if( state!=ADHOC_INIT) return NULL;


	SceCtrlData pad;
    unsigned int pspCurrent=0;


    pspDebugScreenClear();
    int encore=1;
    while(encore)
    {
        //what button is pressed
	    sceDisplayWaitVblankStart();
		sceCtrlReadBufferPositive(&pad, 1);

		//display list and information
		pspDebugScreenSetXY(0, 1);
		pspDebugScreenPrintf("You are the initiator:  Select a PSP (up and down and X to validate), O to quit");
		ZBavaillableRemotePsp::getSingleton().display(0,2,pspCurrent);


        if(pad.Buttons & PSP_CTRL_UP)
        { //previous PSPS
            pspCurrent--;
            if( pspCurrent<0) pspCurrent=ZBavaillableRemotePsp::getSingleton().getList().size();
        }

        if(pad.Buttons & PSP_CTRL_DOWN)
        { //next PSPS
            pspCurrent++;
            if( pspCurrent>ZBavaillableRemotePsp::getSingleton().getList().size() ) pspCurrent=0;
        }

        if(pad.Buttons & PSP_CTRL_CROSS)
        {   //we have chosen the target
            list<ZBremotePsp *>::iterator it;
            it= ZBavaillableRemotePsp::getSingleton().getList().begin();

            return ZBavaillableRemotePsp::getSingleton().getElt(pspCurrent);
        }

        if(pad.Buttons & PSP_CTRL_CIRCLE)   encore=0;

    }//end while


    return NULL;
}



/***************************************************************
 * @classe: ZBadhoc
 * @methode: selectAPsp
 * send data to pPsp
 * @param1 : ZBremotePsp *pPsp
 * the target
 * @param1 : void *data
 * data to be sent
 * @param1 : int lenData
 * lenght
 * @return: int
 * 0< if error
 * *************************************************************/
int ZBadhoc::sendData( ZBremotePsp *pPsp, void *data, int lenData)
{
    return sceNetAdhocPdpSend( pdpHD, pPsp->getMacAddress(),  port, data, lenData, 0, 0);
}




/***************************************************************
 * @classe: ZBadhoc
 * @methode: receiveData
 * receive data from pPsp. It's a blocking call
 * @param1 : ZBremotePsp *pPsp
 * the target
 * @param1 : void *data
 * data to be sent
 * @param1 : int maxLen
 * max size of data to rettreive, IT SEEMS THAT it has to be big enough to read all datas in once
 * so this method has to be rewritten.
 * @return: int
 * 0< if error, otherwise the number of bytes that were read
 * *************************************************************/
int ZBadhoc::receiveData( ZBremotePsp *pPsp, void *data, int maxLen)
{
    pdpStatStruct aStat;
    aStat.next=NULL;
    int sizeStat = sizeof( pdpStatStruct);
    int ret;
    unsigned int sizeData;

    //we check that tjere are datas to be read
    int encore=1;
    while( encore)  //if you don't want this call to be blocking, remove the while
    {
        //read the stat in order to have the size of data that was sent to us
        int ret = sceNetAdhocGetPdpStat(&sizeStat, &aStat);
        if( ret <0) return ret;

        if( aStat.rcvdData > 0) encore=0;
        else sceKernelDelayThread(50 * 1000); // 50  mSec
    }



    //there are data to be read
	//sizeData = ( maxLen<aStat.rcvdData)?maxLen:aStat.rcvdData; //MIN
	//if the size isn't big enough there is an error ....
	sizeData = maxLen;
 	ret = sceNetAdhocPdpRecv(pdpHD, pPsp->getMacAddress(), &(aStat.port), data, &sizeData, 0,	0);
    if(ret<0)
    {   //there is an error
        return ret;
    }

    return sizeData;
}


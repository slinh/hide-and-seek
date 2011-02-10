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
 * Credits:	I just reorganized the code provided by   blondin and J.F. on ps2dev.org
 * 			and add my own stuff (such as the languages and the keyboards)
 * Website:  www.pspZorba.com
 * changelog:
 * 		2008-02-08: creation
 * *******************************************************************************************************/

#ifndef ZBADHOC_H_
#define ZBADHOC_H_

#include "config.h"

#include <stdio.h>
#include <string>
#include <string.h>
#include <list>

using namespace std;

/***************************************************************
 * @classe: ZBremotePsp
 * ZBremotePsp "describes" a remote PSP (i.e, a Mac address)
 *
 * *************************************************************/
enum ZBremotePspState { ZB_DISCONNECTED=0, ZB_JOINED, ZB_SELECTED, ZB_REJECTED, ZB_CANCELED, ZB_ACCEPTED, ZB_ESTABLISHED };

class ZBremotePsp
{
protected:

    u8 myMacAddress[6]; //the mac address of the PSP
    string name;        //nickname of the PSP
    ZBremotePspState connectionState;

public:

    //Ctor and Dtor
    ZBremotePsp(const u8 aMacAddress[6], const string aName) { memcpy(myMacAddress,aMacAddress, 6*sizeof(u8)); name = aName;connectionState=ZB_DISCONNECTED;};
    virtual ~ZBremotePsp() {};

    //Accessors
    u8* getMacAddress( void)  {return myMacAddress;};
    const string & getName( void)   {return name;};
    ZBremotePspState getState(void)      {return connectionState;}
    void setState( ZBremotePspState aState)      {connectionState=aState;}


    //methods
    void display( int X, int Y);//display the list of availlable PSPs
};


/***************************************************************
 * @classe: ZBavaillableRemotePsp
 * ZBavaillableRemotePsp is the class in charge of managing the list of availlable PSP for an Adhoc connection
 *
 * *************************************************************/
class ZBavaillableRemotePsp
{
protected:

    list<ZBremotePsp *> myList; //list of all the files and directories contained in the directory

    ZBavaillableRemotePsp() {}; //forbid the creation of instance (it's a singleton !)

public:
        //Ctor and Dtor
    virtual ~ZBavaillableRemotePsp() {emptylist();};


    //accessors
    static ZBavaillableRemotePsp & getSingleton(void) {static ZBavaillableRemotePsp theSingleton; return theSingleton;};

	list<ZBremotePsp *> & getList(void)  {return myList;}
	void addPSP( ZBremotePsp *pElt)      { myList.push_back( pElt);};//add an elt in the list

	void removePSP( ZBremotePsp *pElt)   { myList.remove( pElt); delete pElt;};//add an elt in the list
	void removePSP( const u8 aMacAddress[6])   //add an elt in the list
				{ ZBremotePsp *pElt; pElt =findByMacAddress(aMacAddress); if( pElt!=NULL) removePSP( pElt); };

    ZBremotePsp * findByMacAddress( const u8 aMacAddress[6]); //look up a PSP by it's mac Address
    ZBremotePsp * getElt( int num); //look up a PSP by it's number
    ZBremotePsp * findByState(ZBremotePspState aState ); //find the find PSP which state is aSatre



    //methods
	void emptylist( void); 	// delete all PSP from the list
    void display( int X, int Y, int curr);//display the list of availlable PSPs

};




/***************************************************************
 * @classe: ZBadhoc
 * ZBadhoc is the class in charge of managing adhoc communication
 *
 * *************************************************************/
enum ZBadhocState { ADHOC_INIT=0, POWER, UNINIT, MAC_ADDRESS, ZB_COMM_MODULE, ZB_LIB_NET, ZB_LIB_ADHOC, ZB_LIB_ADHOCCTL, ZB_ADHOCCTL_CONNECT,
                    ZB_PDP_CREATE, ZB_MATCHING_INIT, ZB_CREATE_MATCHING, ZB_START_MATCHING, ADHOC_UNINIT };
class ZBadhoc
{
protected:

    u8 myMacAddress[6]; //the mac address of the PSP
    //struct productStruct product;
    int matchingHD;
    ZBadhocState state;
    int pdpHD;
    int port;
    int line;


    void checkWlanPower(void); //check if the wlan power is on
    void getMacAddress(void); //get the MAC Address
    void loadModules(void); //loads the modules used for the communication
    void libNetInit( void);
    void libAdhocInit( void);
    void libAdhocctlInit( void);
    void adhocctlConnect( void);
    void adhocctlState( void);
    void pdpCreate( void);
    void matchingInit( void);
    void createMatching( void);
    void startMatching( void);

    void init(void); //init the libs
    void unInit(void); //init the libs

    ZBadhoc() { state = ADHOC_UNINIT; init();}; //forbid the creation of instance (it's a singlton!)

public:
        //Ctor and Dtor
    virtual ~ZBadhoc() {};


        //accessors
    static ZBadhoc & getSingleton(void) {static ZBadhoc theSingleton; return theSingleton;};


        //methods
    ZBremotePsp * selectAPsp( void); //returns the Mac address of the selected PSP
    ZBremotePsp * waitForConnection( void);//wait for a connection, return NULL if abort otherwise returns the PSP
    int requestConnection( ZBremotePsp *pPsp);//
    void waitForPsp( void);


    int sendData( ZBremotePsp *pPsp, void *data, int lenData);// send data to pPsp
    int receiveData( ZBremotePsp *pPsp, void *data, int maxLen);// receive data from pPsp
};



#endif /**ZBADHOC_H_*/



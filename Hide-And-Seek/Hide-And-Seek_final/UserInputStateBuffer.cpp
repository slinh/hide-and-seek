#include "Common.h"
#include "UserInputStateBuffer.h"
#include "engineMath.h"
#ifdef COMPILE_PSP
#include <oslib/oslib.h>
#include <pspctrl.h>
#endif

namespace psp { namespace engine { namespace input {

TUserInputStateBuffer::TUserInputStateBuffer()
{
	SINGLETONREGINSTANCE
	FUpPressedPreviously = false;
	FDownPressedPreviously = false;
	FLeftPressedPreviously = false;
	FRightPressedPreviously = false;
	FCrossPressedPreviously = false;
	FSquarePressedPreviously = false;
	FTrianglePressedPreviously = false;
	FCirclePressedPreviously = false;
	FL1PressedPreviously = false;
	FR1PressedPreviously = false;
	FHomePressedPreviously = false;
	FNotePressedPreviously = false;
	FSelectPressedPreviously = false;
	FStartPressedPreviously = false;
	FHoldPressedPreviously = false;
}


TUserInputStateBuffer::~TUserInputStateBuffer()
{
	Free();
}

void TUserInputStateBuffer::AddEventListener(TEventListener* parEventListener)
{
	LAssert(parEventListener != NULL);
	
	// Listener must not be in the list
	s32 locPos = FEventListenerList.binary_search(parEventListener);
	LAssert(locPos == -1);

	FEventListenerList.push_back(parEventListener);
}

void TUserInputStateBuffer::RemoveEventListener(TEventListener* parEventListener)
{
	LAssert(parEventListener != NULL);

	s32 locPos = FEventListenerList.binary_search(parEventListener);

	//LAssert(locPos != -1);
	if(locPos != -1)
		FEventListenerList.erase(locPos);
}

void TUserInputStateBuffer::UpdateAllState()
{
	// 1. update padevent
	UpdatePadEvent();
	
	// 2. forall event listener, call on pad event
	for(u32 i=0; i < FEventListenerList.size(); ++i)
	{
		FEventListenerList[i]->OnTimer();	
	}
}

void TUserInputStateBuffer::UpdatePadEvent()
{
#ifdef COMPILE_PSP	
	// read keys
	oslReadKeys();

	// ANALOG STICK
	if( (osl_keys->analogX*osl_keys->analogX > 25) || (osl_keys->analogY*osl_keys->analogY > 25) )
	{	
		FPadEventList.push_back(TPadEvent(true, PSP_CTRL_UP, true, false, false, osl_keys->analogX, osl_keys->analogY));
	}

	// UP
	if(osl_keys->pressed.up)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_UP, true, false, false));
		FUpPressedPreviously = true;
	}
	else if(osl_keys->held.up)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_UP, false, true, false));
		FUpPressedPreviously = true;
	}
	else if(FUpPressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_UP, false, false, true));
		FUpPressedPreviously = false;
	}

	// DOWN
	if(osl_keys->pressed.down)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_DOWN, true, false, false));
		FDownPressedPreviously = true;
	}
	else if(osl_keys->held.down)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_DOWN, false, true, false));
		FDownPressedPreviously = true;
	}
	else if(FDownPressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_DOWN, false, false, true));
		FDownPressedPreviously = false;
	}

	// LEFT
	if(osl_keys->pressed.left)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_LEFT, true, false, false));
		FLeftPressedPreviously = true;
	}
	else if(osl_keys->held.left)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_LEFT, false, true, false));
		FLeftPressedPreviously = true;
	}
	else if(FLeftPressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_LEFT, false, false, true));
		FLeftPressedPreviously = false;
	}

	// RIGHT
	if(osl_keys->pressed.right)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_RIGHT, true, false, false));
		FRightPressedPreviously = true;
	}
	else if(osl_keys->held.right)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_RIGHT, false, true, false));
		FRightPressedPreviously = true;
	}
	else if(FRightPressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_RIGHT, false, false, true));
		FRightPressedPreviously = false;
	}

	// CROSS
	if(osl_keys->pressed.cross)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_CROSS, true, false, false));
		FCrossPressedPreviously = true;
	}
	else if(osl_keys->held.cross)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_CROSS, false, true, false));
		FCrossPressedPreviously = true;
	}
	else if(FCrossPressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_CROSS, false, false, true));
		FCrossPressedPreviously = false;
	}

	// SQUARE
	if(osl_keys->pressed.square)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_SQUARE, true, false, false));
		FSquarePressedPreviously = true;
	}
	else if(osl_keys->held.square)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_SQUARE, false, true, false));
		FSquarePressedPreviously = true;
	}
	else if(FSquarePressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_SQUARE, false, false, true));
		FSquarePressedPreviously = false;
	}

	// TRIANGLE
	if(osl_keys->pressed.triangle)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_TRIANGLE, true, false, false));
		FTrianglePressedPreviously = true;
	}
	else if(osl_keys->held.triangle)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_TRIANGLE, false, true, false));
		FTrianglePressedPreviously = true;
	}
	else if(FTrianglePressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_TRIANGLE, false, false, true));
		FTrianglePressedPreviously = false;
	}

	// CIRCLE
	if(osl_keys->pressed.circle)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_CIRCLE, true, false, false));
		FCirclePressedPreviously = true;
	}
	else if(osl_keys->held.circle)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_CIRCLE, false, true, false));
		FCirclePressedPreviously = true;
	}
	else if(FCirclePressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_CIRCLE, false, false, true));
		FCirclePressedPreviously = false;
	}
	
	// LEFT TRIGGER
	if(osl_keys->pressed.L)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_LTRIGGER, true, false, false));
		FL1PressedPreviously = true;
	}
	else if(osl_keys->held.L)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_LTRIGGER, false, true, false));
		FL1PressedPreviously = true;
	}
	else if(FL1PressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_LTRIGGER, false, false, true));
		FL1PressedPreviously = false;
	}

	// RIGHT TRIGGER
	if(osl_keys->pressed.R)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_RTRIGGER, true, false, false));
		FR1PressedPreviously = true;
	}
	else if(osl_keys->held.R)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_RTRIGGER, false, true, false));
		FR1PressedPreviously = true;
	}
	else if(FR1PressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_RTRIGGER, false, false, true));
		FR1PressedPreviously = false;
	}
	
	// SELECT
	if(osl_keys->pressed.select)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_SELECT, true, false, false));
		FSelectPressedPreviously = true;
	}
	else if(osl_keys->held.select)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_SELECT, false, true, false));
		FSelectPressedPreviously = true;
	}
	else if(FSelectPressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_SELECT, false, false, true));
		FSelectPressedPreviously = false;
	}
	
	// START
	if(osl_keys->pressed.start)
	{		
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_START, true, false, false));
		FStartPressedPreviously = true;
	}
	else if(osl_keys->held.start)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_START, false, true, false));
		FStartPressedPreviously = true;
	}
	else if(FStartPressedPreviously)
	{
		FPadEventList.push_back(TPadEvent(false, PSP_CTRL_START, false, false, true));
		FStartPressedPreviously = false;
	}

#endif

	for(u32 i=0; i<FPadEventList.size(); ++i)
	{
		for(u32 j=0; j < FEventListenerList.size(); ++j)
		{
			FEventListenerList[j]->OnPadEvent(FPadEventList[i]);
		}
	}

	FPadEventList.reset();
}

void TUserInputStateBuffer::Free()
{
	for(unsigned int i = 0; i < FEventListenerList.size(); ++i)
	{
		delete FEventListenerList[i];
	}
}

} // input namespace
} // engine namespace
} // psp namespace

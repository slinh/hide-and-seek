#ifndef TPADEVENT_H
#define TPADEVENT_H

#include "config.h"
#ifdef COMPILE_PSP
#include <pspctrl.h>
#endif

namespace psp { namespace engine { namespace input {

class TPadEvent
{
public:
	TPadEvent();
	TPadEvent(bool parIsJoystickEvent, u32 parKey, bool parIsPressed, bool parIsHeld, bool parIsReleased, s8 parAnalogX = 0, s8 parAnalogY = 0);
	 ~TPadEvent();
	GETTER(u32, Key);
	GETTER(bool , IsPressed);
	GETTER(bool , IsHeld);
	GETTER(bool , IsReleased);

	GETTER_SETTER(s8 , AnalogX);
	GETTER_SETTER(s8 , AnalogY);

	GETTER_SETTER(bool , IsJoystickEvent);

private:
	u32		FKey;
	bool	FIsPressed;
	bool	FIsHeld;
	bool	FIsReleased;
	
	s8		FAnalogX;
	s8		FAnalogY;

	bool FIsJoystickEvent;

};

} // input namespace
} // engine namespace
} // psp namespace

#endif 
#include "Common.h"
#include "PadEvent.h"

namespace psp { namespace engine { namespace input {


TPadEvent::TPadEvent()
:FIsPressed(false), FIsHeld(false), FIsReleased(false)
{}

TPadEvent::TPadEvent(bool parIsJoystickEvent, u32 parKey, bool parIsPressed, bool parIsHeld, bool parIsReleased, s8 parAnalogX, s8 parAnalogY)
:FKey(parKey), FIsPressed(parIsPressed), FIsHeld(parIsHeld), FIsReleased(parIsReleased), FAnalogX(parAnalogX), FAnalogY(parAnalogY), FIsJoystickEvent(parIsJoystickEvent)
{}


TPadEvent::~TPadEvent()
{}


} // input namespace
} // engine namespace
} // psp namespace

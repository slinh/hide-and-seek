#ifndef IINPUTMANAGER_H
#define IINPUTMANAGER_H

#include "config.h"
#include "PadEvent.h"
#ifdef COMPILE_PSP
#include <pspctrl.h>
#endif

namespace psp { namespace engine { namespace input{

class IInputManager
{
public:
	VIRTUAL_DESTRUCTOR(IInputManager);

	virtual void OnPadEvent(const TPadEvent& parPadEvent) = 0;
	virtual void OnTimer() = 0;

private:

};

} // gui namespace
} // engine namespace
} // psp namespace

#endif 
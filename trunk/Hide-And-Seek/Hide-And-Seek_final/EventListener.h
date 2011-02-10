#ifndef TEVENTLISTENER_H
#define TEVENTLISTENER_H

#include "config.h"
#include "InputManager.h"
#include "PadEvent.h"

namespace psp { namespace engine { namespace input{

class TEventListener
{
public:
	TEventListener(IInputManager * parInputManager);
	~TEventListener();

	void OnPadEvent(const TPadEvent& parPadEvent);
	void OnTimer();

	GETTER_SETTER_PTR(IInputManager, InputManager)

private:
	IInputManager * FInputManager;
};

} // gui namespace
} // engine namespace
} // psp namespace

#endif 
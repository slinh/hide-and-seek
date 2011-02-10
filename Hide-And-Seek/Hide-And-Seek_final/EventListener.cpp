#include "Common.h"
#include "EventListener.h"

namespace psp { namespace engine { namespace input {

TEventListener::TEventListener(IInputManager * parInputManager)
	:FInputManager(parInputManager)
{
}

TEventListener::~TEventListener()
{
}

void TEventListener::OnPadEvent(const TPadEvent& parPadEvent)
{
	FInputManager->OnPadEvent(parPadEvent);
}

void TEventListener::OnTimer()
{
	FInputManager->OnTimer();
}

} // input namespace
} // engine namespace
} // psp namespace

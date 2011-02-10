
#include "Common.h"
#include "Event.h"

namespace psp { namespace engine { namespace gui {

TEvent::TEvent()
{}

TEvent::TEvent(u8 parId, u8 parValue, const core::stringc& parEventName)
	:FId(parId), 
	FValue(parValue),
	FMinValue(0),
	FMaxValue(0),
	FCursorType(0),
	FSelected(false),
	FName(parEventName),
	FLocation(TLocation())
{}

TEvent::~TEvent()
{}

} // gui namespace
} // engine namespace
} // psp namespace

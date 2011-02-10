#ifndef TEVENT_H
#define TEVENT_H

#include "config.h"
#include "Location.h"

typedef enum TypeEvent_
{
	LINK	= 0,
	OPTION	= 1,
	SLIDER	= 2
} TypeEvent;

typedef enum TypeCursor_
{
	BLOOD	= 0,
	TRIGGER = 1,
	GLOW	= 2,
	NONE	= 3,
} TypeCursor;

namespace psp { namespace engine { namespace gui {

class TEvent
{
public:
	TEvent();
	TEvent(u8 parId, u8 parValue, const core::string<c8>& parEventName);
	~TEvent();
	
	GETTER_SETTER(u8, Id)
	GETTER_SETTER(u8, Value)
	GETTER_SETTER(u8, MinValue)
	GETTER_SETTER(u8, MaxValue)
	GETTER_SETTER(u8, CursorType)
	GETTER_SETTER(bool, Selected)
	GETTER_SETTER(core::string<c8>, Name)
	GETTER_SETTER(TLocation, Location)
	GETTER_SETTER(TypeEvent, Type)

private:
	u8 FId;
	u8 FValue;
	u8 FMinValue;
	u8 FMaxValue;
	u8 FCursorType;
	bool FSelected;
	core::string<c8> FName;
	TypeEvent FType;
	TLocation FLocation;
};

} // gui namespace
} // engine namespace
} // psp namespace

#endif 

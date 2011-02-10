#ifndef TUSERINPUTBUFFER_H
#define TUSERINPUTBUFFER_H

#include "config.h"
#include "Singleton.h"
#include "EventListener.h"
#include "PadEvent.h"

namespace psp { namespace engine { namespace input {

class TUserInputStateBuffer : public TSingleton<TUserInputStateBuffer>
{
public:
	TUserInputStateBuffer();
	~TUserInputStateBuffer();

	void UpdateAllState();
	void UpdatePadEvent();

	void AddEventListener(TEventListener* parEventListener);
	void RemoveEventListener(TEventListener* parEventListener);

	void Free();

	GETTER_SETTER(core::array<TEventListener*>, EventListenerList)
	GETTER_SETTER(core::array<TPadEvent>, PadEventList)
	GETTER_SETTER(TPadEvent, PadEvent)

private:
	core::array<TEventListener*>	FEventListenerList;
	core::array<TPadEvent>			FPadEventList;

	TPadEvent FPadEvent;

	bool FUpPressedPreviously;
	bool FDownPressedPreviously;
	bool FLeftPressedPreviously;
	bool FRightPressedPreviously;
	bool FCrossPressedPreviously;
	bool FSquarePressedPreviously;
	bool FTrianglePressedPreviously;
	bool FCirclePressedPreviously;
	bool FL1PressedPreviously;
	bool FR1PressedPreviously;
	bool FHomePressedPreviously;
	bool FNotePressedPreviously;
	bool FSelectPressedPreviously;
	bool FStartPressedPreviously;
	bool FHoldPressedPreviously;
};

} // input namespace
} // engine namespace
} // psp namespace

#endif 
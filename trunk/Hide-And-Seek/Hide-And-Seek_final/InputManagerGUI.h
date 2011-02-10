#ifndef TINPUTMANAGERGUI_H
#define TINPUTMANAGERGUI_H

#include "config.h"
#include "InputManager.h"
#include "Page.h"
#include "GenericVirtualCallback.h"

typedef enum FadeState_
{
	FADE_IN		= 1,
	FADE_OUT	= 2
}FadeState;

namespace psp { namespace engine { namespace input{

class TInputManagerGUI : public IInputManager
{
public:
	TInputManagerGUI(engine::core::array<gui::TPage> * parPageList);
	virtual ~TInputManagerGUI();

	virtual void OnPadEvent(const TPadEvent& parPadEvent);
	virtual void OnTimer();

	void LoadCallbacks();

	GETTER_SETTER_PTR(engine::core::array<gui::TPage>, PageList)
	GETTER_SETTER(u8, IndexCurrentPage)
	GETTER_SETTER(u8, IndexCurrentEvent)
	GETTER_SETTER(bool, ChangeEvent)
	GETTER_SETTER(s16, AlphaScreen)
	GETTER_SETTER(FadeState, FadeState)

private:
	// states variable
	u8			FIndexCurrentPage;					// current page	
	u8			FIndexCurrentEvent;					// current event
	bool		FChangeEvent;						// change event

	u32			FDeltaTime;							// Delta time between frame alpha changing
	u32			FLastTime;							// time of last alpha changing
	s16			FAlphaScreen;						// alpha for fade in function
	FadeState	FFadeState;							// fade in / out state
	engine::core::array<gui::TPage> * FPageList; // list of pages pointing to gui
	
};

} // gui namespace
} // engine namespace
} // psp namespace

#endif 
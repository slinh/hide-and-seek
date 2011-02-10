#ifndef INPUT_MANAGER_GAME_H
#define INPUT_MANAGER_GAME_H

#include "config.h"
#include "InputManager.h"
#include "EventListener.h"

#define JOYSTICK_DISTANCE_MIN 0.1f

namespace psp { namespace engine { namespace input{

class TInputManagerGame : public engine::input::IInputManager
{
public:
	TInputManagerGame();
	virtual ~TInputManagerGame();

	void Plug();
	void UnPlug();

	virtual void OnTimer();

	virtual void OnPadEvent(const engine::input::TPadEvent& parPadEvent);

private:
	engine::input::TEventListener* FEventListener;
};

}
}
} // psp namespace

#endif

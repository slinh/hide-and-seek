#include "config.h"
#include "Common.h"
#include "InputManagerGame.h"
#include "Game.h"
#ifdef COMPILE_PSP
#include <pspctrl.h>
#endif
#include "UserInputStateBuffer.h"

// TODO : put this value in an other file
#define CAMERA_MOVEMENT_SPEED 0.10f

namespace psp { namespace engine { namespace input{

TInputManagerGame::TInputManagerGame()
{
	FEventListener = NEW_IN_DOMAIN(Game) TEventListener(this);
}

TInputManagerGame::~TInputManagerGame()
{
	delete FEventListener;
}

void TInputManagerGame::Plug()
{
	engine::input::TUserInputStateBuffer::Instance().AddEventListener(FEventListener);
}

void TInputManagerGame::UnPlug()
{
	engine::input::TUserInputStateBuffer::Instance().RemoveEventListener(FEventListener);
}

void TInputManagerGame::OnTimer()
{

}

void TInputManagerGame::OnPadEvent(const engine::input::TPadEvent& parPadEvent)
{
	TCamera* locCamera = game::TGame::Instance().GetCamera();

	core::vector3df locDir = locCamera->GetDirection();
	core::vector3df locRight = locCamera->GetRightInView();
	game::ICharacter* locChar = const_cast<game::ICharacter*>(&game::TGame::Instance().GetCharacterList()[0]);

	// joystick event	
	if (parPadEvent.GetIsJoystickEvent())
	{
#ifdef WITH_SOUNDS
		// TODO : that completely don't work - fix it
		if(!game::TGame::Instance().GetSoundManager()->IsSoundPlaying(game::TGame::Instance().GetSoundManager()->GetIndexLFMan()))
			game::TGame::Instance().GetSoundManager()->PlaySound(game::TGame::Instance().GetSoundManager()->GetIndexLFMan());
		else if (!game::TGame::Instance().GetSoundManager()->IsSoundPlaying(game::TGame::Instance().GetSoundManager()->GetIndexRFMan()))
			game::TGame::Instance().GetSoundManager()->PlaySound(game::TGame::Instance().GetSoundManager()->GetIndexRFMan());
#endif

		core::vector3df locDirectionToGo = locCamera->ConvertDirectionFromJoystick(parPadEvent.GetAnalogX(), parPadEvent.GetAnalogY());
		if (locDirectionToGo.getLengthSQ() > JOYSTICK_DISTANCE_MIN)
		{	
			locChar->AddOrder(CO_RUN);
			locChar->SetDirectionToGo() = locDirectionToGo;
		}
		else
		{
			locChar->RemoveOrder(CO_RUN);
			locChar->SetDirectionToGo() = core::vector3df(0.f, 0.f, 0.f);
		}
		/*
		// if not in inactive zone
		if((parPadEvent.GetAnalogX()*parPadEvent.GetAnalogX()  +  parPadEvent.GetAnalogY()*parPadEvent.GetAnalogY()) >= JOYSTICK_DISTANCE_MIN)
		{
			// set direction of character
			// WARNING : direction must be not directly change : we should have a directionToGo 
			// and for each update of character we turn its direction to reach directionToGo
			// its very useful to have a good gameplay and smooth movements
			// Add a function GetPlayerCharacter in TGame class its better than Read directly in players tabs - Please
			game::TGame::Instance().SetCharacterList()[0].SetDirection().X = parPadEvent.GetAnalogX();
			game::TGame::Instance().SetCharacterList()[0].SetDirection().Y = parPadEvent.GetAnalogY();
			game::TGame::Instance().SetCharacterList()[0].SetDirection().normalize();

			// WARNING : its very bad to go and read in the userInputStateBuffer directly
			// you can simply store when you receive PadEvent see if the last order of character was WALK or DASH or DO_NOTHING and act rightly
			// May be it should be useful to store Current and Previous order of character
			// If you have time - do a function that do the order changing in TGame class - but its not really really necessary
			// its just to make the code cleaner

			// look at the other input see if we walk
			for(u32 i = 0; i < input::TUserInputStateBuffer::Instance().GetPadEventList().size(); ++i)
			{
				// triangle button
				if(
					input::TUserInputStateBuffer::Instance().GetPadEventList()[i].GetIsPressed() && 
					(input::TUserInputStateBuffer::Instance().GetPadEventList()[i].GetKey() & PSP_CTRL_TRIANGLE)
				  )
				{
					// dash
					locCharacterOrder = game::CO_DASH;
					break;
				}
				// left trigger pressed
				else if(
						input::TUserInputStateBuffer::Instance().GetPadEventList()[i].GetIsPressed() && 
						input::TUserInputStateBuffer::Instance().GetPadEventList()[i].GetKey() & PSP_CTRL_RTRIGGER
				       )
				{
					// walk before dash
					if(locCharacterOrder != game::CO_DASH)
						locCharacterOrder = game::CO_WALK;
				}
			}

			// run if not
			if(locCharacterOrder !=  game::CO_RUN)
			{
				locCharacterOrder = game::CO_RUN;
			}
			//print("X : %d, Y: %d\n", parPadEvent.GetAnalogX(), parPadEvent.GetAnalogY());
			
		}
		else
		{
			locCharacterOrder = game::CO_NOTHING;
		}
		*/
	// key pad event
	}
	else if(parPadEvent.GetIsPressed() || parPadEvent.GetIsHeld())
	{
		// PAUSE menu
		if(parPadEvent.GetKey() & PSP_CTRL_START)
		{
			// TODO
			// high priority towards other actions
			// Its absolutely forbiden to delete all eventListener (because we need to plug them when start is quit)
			// its really really better to have a variable in usrInputStateBuffer which tell him to call or not call eventListener
			// We have done a so good architecture for input so use it properly
			// Do input::TUserInputStateBuffer::Instance().StopAllMessageAndKeepOnly(FInputManagerPause.GetEventListener()) that skip iteration on eventListener
			// We give an input manager PAUSE to manage events on pause message - and this one is the only whih can be called when stopMessage is activated
			// So add a second tab in UserInputStateBuffer to store eventListener which are not concerned with StopMessage - ask me if you dont understand what i told you

			if(game::TGame::Instance().GetCurrentState() & GS_LAUNCH_GAME)
				game::TGame::Instance().SetCurrentState() = GS_RETURN_TO_MENU;
		}
		// Player action : use interactive item
		else if(parPadEvent.GetKey() & PSP_CTRL_CROSS)
		{
			if((game::TGame::Instance().GetCurrentState() & GS_LOSE_GAME) || (game::TGame::Instance().GetCurrentState() & GS_WIN_GAME))
				game::TGame::Instance().SetCurrentState() = GS_RETURN_TO_MENU;

#ifdef CAMERA_DEBUG
			locCamera->MoveUp(-CAMERA_MOVEMENT_SPEED);
#else
			locChar->AddOrder(CO_ACTIVATE);
#endif
		}
		else if(parPadEvent.GetKey() & PSP_CTRL_TRIANGLE)
		{
			//LOGC("Add order Event : CO_DASH\n \n");
#ifdef CAMERA_DEBUG
			locCamera->MoveUp(CAMERA_MOVEMENT_SPEED);
#else
			//[DASH]
			locChar->AddOrder(CO_DASH);
#endif
		}
		else if(parPadEvent.GetKey() & PSP_CTRL_SQUARE)
		{			
#ifdef CAMERA_DEBUG
			locCamera->RotatePhi(0.1f);
#endif
		}
		else if(parPadEvent.GetKey() & PSP_CTRL_CIRCLE)
		{			
#ifdef CAMERA_DEBUG
			locCamera->RotatePhi(-0.1f);
#endif
		}
		// Camera movements : change vertical view angle up
		else if(parPadEvent.GetKey() & PSP_CTRL_UP)
		{
#ifdef CAMERA_DEBUG
			locCamera->MoveForward(CAMERA_MOVEMENT_SPEED);
#endif
		}
		// Camera movements : change vertical view angle down
		else if(parPadEvent.GetKey() & PSP_CTRL_DOWN)
		{
#ifdef CAMERA_DEBUG
			locCamera->MoveForward(-CAMERA_MOVEMENT_SPEED);
#else
#endif
		}		
		// Camera movements : turn around the target left->right
		else if(parPadEvent.GetKey() & PSP_CTRL_RIGHT)
		{
#ifdef CAMERA_DEBUG
			locCamera->MoveTrans(-CAMERA_MOVEMENT_SPEED);
#else
			locCamera->RotateTheta(5);
#endif
		}
		// Camera movements : turn around the target right->left
		else if(parPadEvent.GetKey() & PSP_CTRL_LEFT)
		{
#ifdef CAMERA_DEBUG
			locCamera->MoveTrans(CAMERA_MOVEMENT_SPEED);
#else
			locCamera->RotateTheta(-5);
#endif
		}
		else if(parPadEvent.GetKey() & PSP_CTRL_LTRIGGER)
		{
#ifdef CAMERA_DEBUG
			locCamera->RotateTheta(-5.f);
#else
			if(parPadEvent.GetIsPressed())
				locCamera->SetBehindTarget();
#endif
		}
		else if(parPadEvent.GetKey() & PSP_CTRL_RTRIGGER)
		{
#ifdef CAMERA_DEBUG
			locCamera->RotateTheta(5.f);
#else
			if(parPadEvent.GetIsPressed() && (locChar->GetOrder() & CO_RUN))
				locChar->AddOrder(CO_WALK);
#endif
		}
	}

	else if(parPadEvent.GetIsReleased())
	{
		if(parPadEvent.GetKey() & PSP_CTRL_RTRIGGER)
		{
#ifndef CAMERA_DEBUG
			locChar->RemoveOrder(CO_WALK);
#endif
		}
	}
}

} // input namespace
} // engine namespace
} // psp namespace

#include "Common.h"
#include "InputManagerGUI.h"
#include "Event.h"
#include "Game.h"
#include "Globals.h"

#ifdef COMPILE_PSP
	#include <pspctrl.h>
	#include <pspaudio.h>
	#include <pmp.h>	
#endif

namespace psp { namespace engine { namespace input {

TInputManagerGUI::TInputManagerGUI(engine::core::array<gui::TPage> * parPageList)
	:FIndexCurrentPage(0), 
	FIndexCurrentEvent(0), 
	FChangeEvent(false), 
	FDeltaTime(0), 
	FAlphaScreen(0),
	FFadeState(FADE_IN)
{
	LAssert(parPageList != NULL);

	// get page list
	FPageList = parPageList;
}


TInputManagerGUI::~TInputManagerGUI()
{
}

void TInputManagerGUI::OnTimer()
{
	LAssert(game::TGame::HasInstance());

	if(	!game::TGame::Instance().GetGameConfig().GetGUILoaded() ||
		game::TGame::Instance().GetCurrentState() & GS_START_CINEMATIC)
		return;

	if(game::TGame::Instance().GetCurrentState() & GS_START_SPLASH_SCREEN)
	{
		FDeltaTime = SPEED_FADE_SPLASH_SCREEN; // ms
		u32 locElapsedTime = game::TGame::Instance().GetTimeInteger32() - FLastTime;

		if(locElapsedTime >= FDeltaTime)
		{
			if(FFadeState & FADE_IN)
			{
				if(FAlphaScreen >= 255)
				{
					FFadeState = FADE_OUT;
				}
				else
					FAlphaScreen = (FAlphaScreen + locElapsedTime/FDeltaTime) <= 255? (FAlphaScreen + locElapsedTime/FDeltaTime) : 255;
			}
			else if(FFadeState & FADE_OUT)
			{
				if(FAlphaScreen <= 0)
					game::TGame::Instance().SetCurrentState() = GS_START_MENU;
				else
					FAlphaScreen = (FAlphaScreen - locElapsedTime/FDeltaTime) >= 0? (FAlphaScreen - locElapsedTime/FDeltaTime) : 0;
			}

			FLastTime += locElapsedTime;
		}
	}		
	// Idle for credit page
	else if((*FPageList)[FIndexCurrentPage].GetIdPage() == PAGE_CREDITS)
	{
		FDeltaTime = SPEED_CREDITS; // ms

		u32 locElapsedTime = game::TGame::Instance().GetTimeInteger32() - FLastTime;

		if(locElapsedTime >= FDeltaTime)
		{
			(*FPageList)[FIndexCurrentPage].SetLabelList()[0].SetPosY() += locElapsedTime/FDeltaTime;
		
			FLastTime += locElapsedTime;
		}
	}
}

void TInputManagerGUI::OnPadEvent(const TPadEvent& parPadEvent)
{
	LAssert(game::TGame::HasInstance());

// TODO : fix compile problem on PC wit PSP_CTRL.. variables
#ifdef COMPILE_PSP
	if(parPadEvent.GetIsJoystickEvent())
		return;

#ifdef WITH_SOUNDS
	// play sounds
	if(	parPadEvent.GetIsPressed() && 
		(
		 game::TGame::Instance().GetCurrentState() & GS_CHOOSE_LANGUAGE ||
		 game::TGame::Instance().GetCurrentState() & GS_START_CINEMATIC ||
		 game::TGame::Instance().GetCurrentState() & GS_START_MENU
		)
	  )
	{
		if(parPadEvent.GetKey() & PSP_CTRL_CROSS || parPadEvent.GetKey() & PSP_CTRL_START)
			game::TGame::Instance().GetSoundManager()->PlaySound(game::TGame::Instance().GetSoundManager()->GetIndexSelect());
		else
			game::TGame::Instance().GetSoundManager()->PlaySound(game::TGame::Instance().GetSoundManager()->GetIndexCursor());
	}
#endif

	// Handle input in choose language menu
	if(
		game::TGame::Instance().GetCurrentState() & GS_CHOOSE_LANGUAGE &&
		!game::TGame::Instance().GetGameConfig().GetGUILoaded()
	  )
	{
		if(parPadEvent.GetIsPressed())
		{
			if(parPadEvent.GetKey() & PSP_CTRL_CROSS || parPadEvent.GetKey() & PSP_CTRL_START)
			{
				// Print loading screen
				FAlphaScreen = 255;				

				// Load xml with langage
				game::TGame::Instance().GetGameConfig().GetLanguage() & L_EN ?
					game::TGame::Instance().GetGUI()->LoadGUI(XML_EN):
					game::TGame::Instance().GetGUI()->LoadGUI(XML_FR);

					game::TGame::Instance().SetGameConfig().SetGUILoaded() = true;
					
					game::TGame::Instance().SetCurrentState() = GS_START_CINEMATIC;
			}

			else if (parPadEvent.GetKey() & PSP_CTRL_LEFT || parPadEvent.GetKey() & PSP_CTRL_RIGHT)
			{
				game::TGame::Instance().GetGameConfig().GetLanguage() & L_EN ?
					game::TGame::Instance().SetGameConfig().SetLanguage() = L_FR :
					game::TGame::Instance().SetGameConfig().SetLanguage() = L_EN;
			}
		}
		return;
	}
	// hanlde input in cinematic mode
	else if(game::TGame::Instance().GetCurrentState() & GS_START_CINEMATIC)
	{
		if((parPadEvent.GetKey() & PSP_CTRL_START || parPadEvent.GetKey() & PSP_CTRL_CROSS) &&
			parPadEvent.GetIsPressed() &&
			game::TGame::Instance().GetVideoManager()->IsVideoPlaying() &&
			game::TGame::Instance().GetVideoManager()->GetVideoInitialized()
			)
		{
			game::TGame::Instance().GetVideoManager()->StopVideo();
			
			// cinematic 1 then menu, cinematic 2 then game 
			if(game::TGame::Instance().GetCurrentCinematicVideo() & CINEMATIC_1)
				game::TGame::Instance().SetCurrentState() = GS_START_MENU;
			else
				game::TGame::Instance().SetCurrentState() = GS_LOADING_GAME;

			return;
		}
	}
	// handle input in menu selection
	else if(game::TGame::Instance().GetCurrentState() & GS_START_MENU)
	{
		// current event name
		gui::TEvent & locEvent					= (*FPageList)[FIndexCurrentPage].SetEventList()[FIndexCurrentEvent];
		gui::TEvent & locNextEvent				= (*FPageList)[FIndexCurrentPage].SetEventList()[FIndexCurrentEvent + 1];
		gui::TEvent & locPreviousEvent			= (*FPageList)[FIndexCurrentPage].SetEventList()[FIndexCurrentEvent - 1];
		const core::stringc & locEventName		= locEvent.GetName();
		u8 locMaxIndexEvent						= (*FPageList)[FIndexCurrentPage].GetEventList().size() - 1;
		u8 locIndexPreviousEvent				= FIndexCurrentEvent;

		// if multiplayer home page
		if((*FPageList)[FIndexCurrentPage].GetIdPage() == PAGE_MULTIPLAYER_MAIN)
		{
			// change page following current input
			if(parPadEvent.GetIsPressed())
			{
				// join
				if(parPadEvent.GetKey() & PSP_CTRL_SQUARE)
					FIndexCurrentPage = (*FPageList)[FIndexCurrentPage].GetEventList()[0].GetValue();

				//host
				else if (parPadEvent.GetKey() & PSP_CTRL_TRIANGLE)
					FIndexCurrentPage = (*FPageList)[FIndexCurrentPage].GetEventList()[1].GetValue();
				
				// back
				else if (parPadEvent.GetKey() & PSP_CTRL_CIRCLE)
					FIndexCurrentPage = (*FPageList)[FIndexCurrentPage].GetEventList()[2].GetValue();
				
				// skip other instructions
				return;
			} 
			
		}
		// if multiplayer join page
		else if((*FPageList)[FIndexCurrentPage].GetIdPage() == PAGE_MULTIPLAYER_JOIN || (*FPageList)[FIndexCurrentPage].GetIdPage() == PAGE_MULTIPLAYER_HOST)
		{
			// back
			if(parPadEvent.GetIsPressed())
			{
				if (parPadEvent.GetKey() & PSP_CTRL_CIRCLE)
				{
					FIndexCurrentPage = (*FPageList)[FIndexCurrentPage].GetEventList()[1].GetValue();
					
				}
				
				// join or host
				else if(parPadEvent.GetKey() & PSP_CTRL_CROSS)
				{
					
					if((*FPageList)[FIndexCurrentPage].GetEventList()[0].GetName().equals_ignore_case("HostGame"))
					{
						//LOGC_IA("host game\n");
					}
					else if((*FPageList)[FIndexCurrentPage].GetEventList()[0].GetName().equals_ignore_case("JoinGame"))
					{
						//LOGC_IA("join game\n");
					}
				}
			}
			
			// skip all other commands
			return;
		}
		// if pressing button in menu
		if(parPadEvent.GetIsPressed())
		{
			// down pressed
			if(parPadEvent.GetKey() & PSP_CTRL_DOWN)
			{
		
				//skip option to go to next event
				if(locNextEvent.GetType() == OPTION)
				{
					if(locNextEvent.GetType() == locEvent.GetType() && FIndexCurrentEvent < locMaxIndexEvent - 1)
					{
						++FIndexCurrentEvent;
					}
			
					// go to selected event
					if(locNextEvent.GetType() != locEvent.GetType() && FIndexCurrentEvent < locMaxIndexEvent - 1)
					{
						if(!locNextEvent.GetSelected())
						{
							++FIndexCurrentEvent;
						}
					}
				}

				// if last event isn't reached
				if(FIndexCurrentEvent < locMaxIndexEvent)
				{	
					++FIndexCurrentEvent;
				}
			}	
			// up pressed
			else if(parPadEvent.GetKey() & PSP_CTRL_UP)
			{
		
				if(locPreviousEvent.GetType() == OPTION )
				{
					// skip option to go to previous event
					if(locPreviousEvent.GetType() == locEvent.GetType() && FIndexCurrentEvent > 0)
					{
						--FIndexCurrentEvent;
					}

					// go to selected event
					if(locPreviousEvent.GetType() != locEvent.GetType())
					{
						if(!locPreviousEvent.GetSelected()  && FIndexCurrentEvent > 0)
						{
							--FIndexCurrentEvent;
						}
					}
				}

				if(FIndexCurrentEvent > 0)
				{
					--FIndexCurrentEvent;
				}
		
			}
			// right pressed
			else if(parPadEvent.GetKey() & PSP_CTRL_RIGHT)
			{
				if(locEvent.GetType() == OPTION
					&& (locNextEvent.GetType() == locEvent.GetType())
					&& (locNextEvent.GetName() == locEvent.GetName())
					&& (FIndexCurrentEvent < locMaxIndexEvent - 1)
					)
				{
					++FIndexCurrentEvent;
				}
				else if(locEvent.GetType() == SLIDER)
				{
					if(locEvent.GetValue() < 100)
					{
						locEvent.SetValue() += NUDGE_TRIGGER;
					}
				}
			}	
			// left pressed
			else if(parPadEvent.GetKey() & PSP_CTRL_LEFT)
			{
				if(locEvent.GetType() == OPTION
					&& (locPreviousEvent.GetType() == locEvent.GetType())
					&& (locPreviousEvent.GetName() == locEvent.GetName())
					&& (FIndexCurrentEvent > 0)
					)
				{
					--FIndexCurrentEvent;
				}
				else if(locEvent.GetType() == SLIDER)
				{
					if(locEvent.GetValue() > 0)
					{
						locEvent.SetValue() -= NUDGE_TRIGGER;
						sceAudioChangeChannelVolume(0, 0, 0);
						sceAudioChangeChannelVolume(1, 0, 0);
						sceAudioChangeChannelVolume(2, 0, 0);
						sceAudioChangeChannelVolume(3, 0, 0);
						sceAudioChangeChannelVolume(4, 0, 0);
						sceAudioChangeChannelVolume(5, 0, 0);
						sceAudioChangeChannelVolume(6, 0, 0);
						sceAudioChangeChannelVolume(7, 0, 0);
					}
				}
			}
			// start pressed 
			else if(parPadEvent.GetKey() & PSP_CTRL_START || parPadEvent.GetKey() & PSP_CTRL_CROSS)
			{
				//LOGC_IA("locEventName pressed: %s\n", locEventName.c_str());

				// change page
				if(locEventName.equals_ignore_case("ChangePage"))
				{
					const u8 & locIndexPageSelected = locEvent.GetValue();
					if(locIndexPageSelected >= 0 && locIndexPageSelected < (*FPageList).size())
					{
						// change page
						FIndexCurrentPage = (*FPageList)[FIndexCurrentPage].GetEventList()[FIndexCurrentEvent].GetValue();

						// reset to first event in current page
						// if option, set to saved event
						FIndexCurrentEvent = 0;
						if((*FPageList)[FIndexCurrentPage].SetEventList()[0].GetType() == OPTION
							&& !(*FPageList)[FIndexCurrentPage].SetEventList()[0].GetSelected())
						{
							++FIndexCurrentEvent;
						}
					}
				}
				else if (locEventName.equals_ignore_case("LaunchGame"))
				{
					game::TGame::Instance().SetCurrentCinematicVideo() = CINEMATIC_2;
					game::TGame::Instance().SetCurrentState() = GS_START_CINEMATIC;
				}
				
				else if (locEventName.equals_ignore_case("ChangeLanguage"))
				{
					((*FPageList)[FIndexCurrentPage].SetEventList()[FIndexCurrentEvent].GetValue() & L_EN) ?
						game::TGame::Instance().GetGUI()->LoadGUI(XML_EN):
						game::TGame::Instance().GetGUI()->LoadGUI(XML_FR);
				}
				else if (locEventName.equals_ignore_case("WatchCinematic"))
				{
					game::TGame::Instance().SetCurrentCinematicVideo() = CINEMATIC_1;
					game::TGame::Instance().SetCurrentState() = GS_START_CINEMATIC;

				}

				else if (locEventName.equals_ignore_case("Quit"))
				{
					// Switch menu to game
					game::TGame::Instance().SetCurrentState() = GS_END_GAME;
				}
		//		print("current page : %d\n", FIndexCurrentPage);
			}
		}
	
		// update state to load dynamic cursor
		FChangeEvent = (locIndexPreviousEvent != FIndexCurrentEvent);

		gui::TEvent & locPreviousSelected = (*FPageList)[FIndexCurrentPage].SetEventList()[locIndexPreviousEvent];
		gui::TEvent & locCurrentSelected = (*FPageList)[FIndexCurrentPage].SetEventList()[FIndexCurrentEvent];

		if(FChangeEvent && locCurrentSelected.GetType() == OPTION && locPreviousSelected.GetType() == OPTION )
		{
			locPreviousSelected.SetSelected() = false;
			locCurrentSelected.SetSelected() = true;
			//LOGC_IA("locIndexPreviousEvent : %d\n", locIndexPreviousEvent);
			//LOGC_IA("FIndexCurrentEvent : %d\n", FIndexCurrentEvent);
		}
	}
#endif
}

void TInputManagerGUI::LoadCallbacks()
{
//	FNamedCallback = TNamedCallbackItem<input::TInputManagerGUI, &input::TInputManagerGUI::ChangePage>::Make("ChangePage", this);
}

} // input namespace
} // engine namespace
} // psp namespace

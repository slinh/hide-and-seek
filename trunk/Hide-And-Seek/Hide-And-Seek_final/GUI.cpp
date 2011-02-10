
#include "Common.h"
#include "GUI.h"
#include "engineXML.h"
#include "UserInputStateBuffer.h"
#include "InputManagerGUI.h"
#include "EventListener.h"
#include "Game.h"

namespace psp { namespace engine { namespace gui {

TGUI::TGUI():
FIsLoaded(false)
{
	FInputManager = NEW_IN_DOMAIN(GUI) input::TInputManagerGUI(&FPageList);
}


TGUI::~TGUI()
{
	UnloadGUI();
	delete FInputManager;
}

void TGUI::LoadChooseLanguageSprites()
{
	TEvent locEventEN, locEventFR;

	// load win - loose
	FLooseScreen.SetWidth() = DEFAULT_WIDTH;
	FLooseScreen.SetHeight() = DEFAULT_HEIGHT;
#ifdef COMPILE_PSP
	FLooseScreen.SetSprite(oslLoadImageFile(const_cast<char*>(SPRITE_LOOSE), OSL_IN_RAM, OSL_PF_5551));
#endif

	FWinScreen.SetWidth() = DEFAULT_WIDTH;
	FWinScreen.SetHeight() = DEFAULT_HEIGHT;
#ifdef COMPILE_PSP
	FWinScreen.SetSprite(oslLoadImageFile(const_cast<char*>(SPRITE_WIN), OSL_IN_RAM, OSL_PF_5551));
#endif

	// load loading sprite
	FLoading.SetWidth() = DEFAULT_WIDTH;
	FLoading.SetHeight() = DEFAULT_HEIGHT;
#ifdef COMPILE_PSP
	FLoading.SetSprite(oslLoadImageFile(const_cast<char*>(SPRITE_LOADING), OSL_IN_RAM, OSL_PF_5551));
#endif
	
	// create sprite objects to choose language
	FPageLanguage.SetBackground().SetWidth() = DEFAULT_WIDTH;
	FPageLanguage.SetBackground().SetHeight() = DEFAULT_HEIGHT;
#ifdef COMPILE_PSP
	FPageLanguage.SetBackground().SetSprite(oslLoadImageFile(const_cast<char*>(SPRITE_BACKGROUND), OSL_IN_RAM, OSL_PF_5551));
#endif

	// EN
	locEventEN = TEvent(0, L_EN, "ChooseLanguage");
	locEventEN.SetCursorType() = BLOOD;
	locEventEN.SetLocation().SetWidth() = FLAG_WITH;
	locEventEN.SetLocation().SetHeight() = FLAG_HEIGHT;
#ifdef COMPILE_PSP
	locEventEN.SetLocation().SetSprite(oslLoadImageFile(const_cast<char*>(SPRITE_FLAG_EN), OSL_IN_RAM, OSL_PF_5551));
#endif

	// FR
	locEventFR = TEvent(0, L_FR, "ChooseLanguage");
	locEventFR.SetCursorType() = BLOOD;
	locEventFR.SetLocation().SetWidth() = FLAG_WITH;
	locEventFR.SetLocation().SetHeight() = FLAG_HEIGHT;
#ifdef COMPILE_PSP
	locEventFR.SetLocation().SetSprite(oslLoadImageFile(const_cast<char*>(SPRITE_FLAG_FR), OSL_IN_RAM, OSL_PF_5551));
#endif

	FPageLanguage.SetEventList().push_back(locEventEN);
	FPageLanguage.SetEventList().push_back(locEventFR);

	// load cursors
#ifdef COMPILE_PSP
	FCursorList[0] = *(oslLoadImageFile(const_cast<char*>(CURSOR_BLOOD), OSL_IN_RAM, OSL_PF_5551));
	FCursorList[1] = *(oslLoadImageFile(const_cast<char*>(CURSOR_SLIDER), OSL_IN_RAM, OSL_PF_5551));
	FCursorList[2] = *(oslLoadImageFile(const_cast<char*>(CURSOR_DEFAULT_HOVER), OSL_IN_RAM, OSL_PF_5551));
	FCursorList[3] = *(oslLoadImageFile(const_cast<char*>(CURSOR_SLIDER_OFF), OSL_IN_RAM, OSL_PF_5551));
#endif
}

void TGUI::PrintChooseLanguage()
{
#ifdef COMPILE_PSP
	oslStartDrawing();
	
	// clears the screen
    oslCls();
#endif

	// background
	DrawSprite(const_cast<image_type*>(FPageLanguage.GetBackground().GetSprite()),
			DEFAULT_WIDTH,
			DEFAULT_HEIGHT);

	// cursor
	if(game::TGame::Instance().GetGameConfig().GetLanguage() & L_EN)
	{
		DrawSprite(&(FCursorList[0]),
			BLOOD_WIDTH,
			BLOOD_HEIGHT,
			0,
			0,
			175 + FLAG_WITH/2 - BLOOD_WIDTH/2,
			127 + FLAG_HEIGHT/2 - BLOOD_HEIGHT/2);
	}
	else
	{
		DrawSprite(&(FCursorList[0]),
			BLOOD_WIDTH,
			BLOOD_HEIGHT,
			0,
			0,
			275 + FLAG_WITH/2 - BLOOD_WIDTH/2,
			127 + FLAG_HEIGHT/2 - BLOOD_HEIGHT/2);
	}

	//EN
	DrawSprite(const_cast<image_type*>(FPageLanguage.GetEventList()[0].GetLocation().GetSprite()),
		FLAG_WITH,
		FLAG_HEIGHT,
		0,
		0,
		175,
		127);

	//FR
	DrawSprite(const_cast<image_type*>(FPageLanguage.GetEventList()[1].GetLocation().GetSprite()),
		FLAG_WITH,
		FLAG_HEIGHT,
		0,
		0,
		275,
		127);

#ifdef COMPILE_PSP
	// ends drawing mode
	oslEndDrawing();

	// synchronizes the screen
	oslSyncFrame();
#endif
}

void TGUI::LoadGUI(const c8 * parXmlfileName)
{
	PrintImageScreen(FLoading.GetSprite(), true);

	if(game::TGame::Instance().GetGameConfig().GetGUILoaded())
	{
//		UnloadGUI();	-> bug cause cursors are unloaded too
		FPageList.clear();
		FDynamicCursorList.clear();
	}

	// load xml file to get info on pages and categories
	LoadXml(parXmlfileName);

	// load sprite
	LoadSprite();
		
	FIsLoaded = true;
}

void TGUI::LoadXml(const c8 * parXmlFile)
{
	core::stringc node;

	// create the reader using one of the factory functions
    io::engineXMLReader* xml = io::createengineXMLReader(parXmlFile);

//	print("check if not null\n");
    if (xml == 0)
            return; // file could not be opened
//	print("reading xml\n");
    // parse the file until end reached
    while(xml->read())
    {
            // not and ending tag
			if(xml->getNodeType() != engine::io::EXN_ELEMENT_END)
			{
				
				// get not name into string
				node = xml->getNodeName(); 

				// menu
				if(node.equals_ignore_case("menu"))
				{
//					print("menu found\n");
				}

				// page
				if(node.equals_ignore_case("page"))
				{
					createPage(xml);
				}
					
				// background
				if(node.equals_ignore_case("background"))
				{
//					print("background found");
					createBackground(xml);
				}

				// label
				if(node.equals_ignore_case("label"))
				{
//					print("label found\n");
					createLabel(xml);
				}
				
				// event
				if(node.equals_ignore_case("event") 
					|| node.equals_ignore_case("option")
					|| node.equals_ignore_case("slider"))
				{
//					print("event found\n");
					createEvent(xml);
				}
			}

    }

	// print page
//	print("page size : %d", FPageList.size());

    // delete the xml parser after usage
    delete xml;
}

void TGUI::createPage(io::engineXMLReader * parXML)
{	
	// variables used to construct objects
	u8			locIdPage;

	// get attribute from XML
	locIdPage = parXML->getAttributeValueAsInt("id");

	// add page to list
	FPageList.push_back(TPage(locIdPage));
}

void TGUI::createBackground(io::engineXMLReader * parXML)
{	
	// create new location
	TLocation locBackgroundLocation = createLocation(parXML);
	
	// set background on last page selected
	FPageList.getLast().SetBackground() = locBackgroundLocation;
}

TLocation TGUI::createLocation(io::engineXMLReader * parXML)
{
	// variables used to construct objects
	core::stringc locImageFile;
	
	u8	locPosX;
	u8	locPosY;
	u16	locWidth;
	u16	locHeight;
	u16	locPosU;
	u16	locPosV;

	// get attribute from XML
	locImageFile = parXML->getAttributeValue("urlImage");
	locPosX = parXML->getAttributeValueAsInt("x");
	locPosY = parXML->getAttributeValueAsInt("y");
	locWidth = parXML->getAttributeValueAsInt("width");
	locHeight = parXML->getAttributeValueAsInt("height");
	locPosU = parXML->getAttributeValueAsInt("u");
	locPosV = parXML->getAttributeValueAsInt("v");

	//print("locImageFile : %s\n", locImageFile.c_str());
	//print("locPosX : %d\n", locPosX);
	//print("locPosY : %d\n", locPosY);
	//print("locWidth : %d\n", locWidth);
	//print("locHeight : %d\n", locHeight);
	//print("locPosU : %d\n", locPosU);
	//print("locPosV : %d\n", locPosV);
	
		// create a background location
	return(TLocation(locImageFile, locPosX, locPosY, locWidth, locHeight, locPosU, locPosV));
}

void TGUI::createLabel(io::engineXMLReader * parXML)
{
	// create a label
	TLocation locLabel = createLocation(parXML);
	
	// add to label list
	FPageList.getLast().SetLabelList().push_back(locLabel);
}

void TGUI::createEvent(io::engineXMLReader * parXML)
{
	u8 locId;
	u8 locValue;
	u8 locCursorType;
	core::stringc locEventName; 
	TEvent locEvent;

	// get info from xml
	locId = parXML->getAttributeValueAsInt("id");
	locValue = parXML->getAttributeValueAsInt("value");
	locCursorType = parXML->getAttributeValueAsInt("cursor");

	// create an event
	locEvent = TEvent(locId, locValue, locEventName);
	locEvent.SetCursorType() = locCursorType;

	// set event location

	locEvent.SetLocation() = createLocation(parXML);
	
	// slider type
	if(core::stringc(parXML->getNodeName()).equals_ignore_case("option"))
	{
		locEvent.SetType() = OPTION;
	}
	else if(core::stringc(parXML->getNodeName()).equals_ignore_case("slider"))
	{
		locEvent.SetType() = SLIDER;
		locEvent.SetMinValue() = parXML->getAttributeValueAsInt("min");
		locEvent.SetMaxValue() = parXML->getAttributeValueAsInt("max");
	}
	else
	{
		locEvent.SetType() = LINK;
	}

	// read data node
	parXML->read();
	locEventName = parXML->getNodeData();
	//LOGC("locEventName : %s\n", locEventName.c_str());
	
	// define name
	locEvent.SetName() = locEventName;

	// search selected option by default
	if(locEvent.GetType() == OPTION)
	{
		if (locEvent.GetName().equals_ignore_case("ChangeLanguage")
			&& (locEvent.GetValue() & game::TGame::Instance().GetGameConfig().GetLanguage()))
		{
			locEvent.SetSelected() = true;
		}
		else if (locEvent.GetName().equals_ignore_case("ChangeLevelDifficulty") 
			&& (locEvent.GetValue() &  game::TGame::Instance().GetGameConfig().GetLevelDifficulty()))
		{
			locEvent.SetSelected() = true;
		}
		else
		{
			locEvent.SetSelected() = false;
		}
	}

	// add to event list
	FPageList.getLast().SetEventList().push_back(locEvent);
}

void TGUI::LoadSprite()
{
#ifdef COMPILE_PSP

	// -- loads our images into memory

	// load pages
	for(unsigned int i = 0; i < FPageList.size(); ++i)
	{
		// load backgrounds
#ifdef COMPILE_PSP
		FPageList[i].SetBackground().SetSprite(oslLoadImageFile(const_cast<char*>(FPageList[i].GetBackground().GetImageFile().c_str()), OSL_IN_RAM, OSL_PF_5551));
#endif
		// load labels
		for(unsigned int j = 0; j < FPageList[i].GetLabelList().size(); ++j)
		{
			FPageList[i].SetLabelList()[j].SetSprite(oslLoadImageFile(const_cast<char*>(FPageList[i].GetLabelList()[j].GetImageFile().c_str()), OSL_IN_RAM, OSL_PF_5551));
		}

		// load events
		for(unsigned int k = 0; k < FPageList[i].GetEventList().size(); ++k)
		{
			
			FPageList[i].SetEventList()[k].SetLocation().SetSprite(oslLoadImageFile(const_cast<char*>(FPageList[i].GetEventList()[k].GetLocation().GetImageFile().c_str()), OSL_IN_RAM, OSL_PF_5551));
			const TEvent & locCurrentEvent = FPageList[i].GetEventList()[k];

			// get all dynamic cursors
			if(locCurrentEvent.GetCursorType() == GLOW)
			{
				TLocation locCursor;
				locCursor.SetImageFile() = GetSpriteHoverName(locCurrentEvent.GetLocation().GetImageFile());
				locCursor.SetPosX() = 0;
				locCursor.SetPosY() = 0;
				locCursor.SetWidth() = locCurrentEvent.GetLocation().GetWidth();
				locCursor.SetHeight() = locCurrentEvent.GetLocation().GetHeight();
				locCursor.SetPosU() = locCurrentEvent.GetLocation().GetPosU();
				locCursor.SetPosV() = locCurrentEvent.GetLocation().GetPosV();

				locCursor.SetSprite(oslLoadImageFile(const_cast<char*>(locCursor.GetImageFile().c_str()), OSL_IN_RAM, OSL_PF_5551));
				FDynamicCursorList.push_back(locCursor);
			}
		}
	}

#endif
}

void TGUI::LoadListener()
{
	// create event listener
	if(FEventListener == NULL)
	{
		FEventListener = NEW_IN_DOMAIN(GUI) input::TEventListener(FInputManager);
	}

	input::TUserInputStateBuffer::Instance().AddEventListener(FEventListener);
}

void TGUI::UnloadListener()
{
	input::TUserInputStateBuffer::Instance().RemoveEventListener(FEventListener);
}

// asymeytrical code : need to unload in descending order
void TGUI::UnloadGUI()
{
	if(!FIsLoaded)
		return;

	UnloadListener();

#ifdef COMPILE_PSP

	// unload dynamic cursors
	for(int i = FDynamicCursorList.size() - 1; i >= 0; --i)
	{
		if(FDynamicCursorList[i].GetSprite())
			oslDeleteImage(FDynamicCursorList[i].GetSprite());
	}

	for(int i = FPageList.size() - 1; i >= 0 ; --i)
	{
		// unload events
		for(int k = FPageList[i].GetEventList().size() - 1; k >= 0; --k)
		{
			if(FPageList[i].GetEventList()[k].GetLocation().GetSprite())
				oslDeleteImage(FPageList[i].GetEventList()[k].GetLocation().GetSprite()); 
		}
		
		// unload labels
		for(int j = FPageList[i].GetLabelList().size() - 1; j >= 0; --j)
		{
			if(FPageList[i].GetLabelList()[j].GetSprite())
				oslDeleteImage(FPageList[i].GetLabelList()[j].GetSprite()); 
		}
		
		// unload backgrounds
		if(FPageList[i].SetBackground().GetSprite())
				oslDeleteImage(FPageList[i].GetBackground().GetSprite()); 
	}

	//TODO : unload on the end of the game
	//// unload cursors
	//for(int i = 3; i >= 0; --i)
	//{
	//	if(&(FCursorList[i]))
	//	{
	//		oslDeleteImage(&(FCursorList[i]));
	//	}
	//}
	//
	//// unload choose language page
	//if(FPageLanguage.GetEventList()[0].GetLocation().GetSprite()
	//	&& FPageLanguage.GetEventList()[1].GetLocation().GetSprite())
	//{
	//	oslDeleteImage(FPageLanguage.GetEventList()[1].GetLocation().GetSprite());		
	//	oslDeleteImage(FPageLanguage.GetEventList()[0].GetLocation().GetSprite());
	//}

	//if(FPageLanguage.GetBackground().GetSprite())
	//	oslDeleteImage(FPageLanguage.GetBackground().GetSprite());

#endif

	FIsLoaded = false;
}

void TGUI::PrintSprite()
{	
	// initialize current index page & event
	input::TInputManagerGUI* locInputManager = static_cast<input::TInputManagerGUI*>(FInputManager);

	const u8 locIndexCurrentPage = locInputManager->GetIndexCurrentPage();
	//const u8 locIndexCurrentEvent = locInputManager->GetIndexCurrentEvent();

	const TPage & locCurrentPage = FPageList[locIndexCurrentPage];
	//const TEvent & locCurrentEvent = locCurrentPage.GetEventList()[locIndexCurrentEvent];

	// initialize current lists
	const core::array<TLocation> & locCurrentLabelList = locCurrentPage.GetLabelList();  
	const core::array<TEvent> & locCurrentEventList = locCurrentPage.GetEventList();

	// print lists
	DrawSprite(const_cast<image_type*>(locCurrentPage.GetBackground().GetSprite()), 
		locCurrentPage.GetBackground().GetWidth(), 
		locCurrentPage.GetBackground().GetHeight());

	// print labels first
	PrintSpriteLabelList(locCurrentLabelList);
	PrintSpriteEventList(locCurrentEventList);
}

void TGUI::PrintGUI()
{
#ifdef COMPILE_PSP
	//To be able to draw on the screen
	oslStartDrawing();
	
	// clears the screen
    oslCls();
#endif

	PrintSprite();

#ifdef COMPILE_PSP
	// ends drawing mode
	oslEndDrawing();

	// synchronizes the screen
	oslSyncFrame();		
#endif
}

void TGUI::PrintImageScreen(image_type * img, bool parEnableSync)
{
#ifdef COMPILE_PSP
	if(parEnableSync)
		oslSyncDrawing();

	// to be able to draw on the screen
	oslStartDrawing();
	
	// clears the screen
    oslCls();
	oslSetAlpha(OSL_FX_ALPHA, 255);
#endif

	DrawSprite(img,
				DEFAULT_WIDTH,
				DEFAULT_HEIGHT);


#ifdef COMPILE_PSP
	oslSetAlpha(OSL_FX_RGBA, 255);

	// ends drawing mode
	oslEndDrawing();
	
	// synchronizes the screen
	if(parEnableSync)
	{
		oslSyncDrawing();
		oslSyncFrame();
	}

#endif
}

void TGUI::PrintSpriteLabelList(const core::array<TLocation> & parLocationList )
{
#ifdef COMPILE_PSP
	for(unsigned int i =0; i < parLocationList.size(); ++i)
	{
		DrawSprite(const_cast<image_type*>(parLocationList[i].GetSprite()),
						parLocationList[i].GetWidth(),
						parLocationList[i].GetHeight(),
						parLocationList[i].GetPosX(),
						parLocationList[i].GetPosY(),
						parLocationList[i].GetPosU(),
						parLocationList[i].GetPosV());
	}
#endif
}

void TGUI::PrintSpriteEventList(const core::array<TEvent> & parEventList)
{
#ifdef COMPILE_PSP
	// initialize current index page & event
	input::TInputManagerGUI* locInputManager = static_cast<input::TInputManagerGUI*>(FInputManager);
	const u8 locIndexCurrentEvent = locInputManager->GetIndexCurrentEvent();
	//u8 locAlpha = 100.0f;

	// print blood cursor
	if(parEventList[locIndexCurrentEvent].GetCursorType() == BLOOD)
	{
		PrintSpriteCursor(parEventList[locIndexCurrentEvent]);
	}
	
	// print sprite event
	for(unsigned int i =0; i < parEventList.size(); ++i)
	{
		// print selected item
		if(parEventList[i].GetType() == OPTION && parEventList[i].GetSelected() == true)
		{
			PrintSpriteSelectedEvent(parEventList[i]);
		}

		else
		{
			DrawSprite(const_cast<image_type*>(parEventList[i].GetLocation().GetSprite()),
				parEventList[i].GetLocation().GetWidth(),
				parEventList[i].GetLocation().GetHeight(),
				parEventList[i].GetLocation().GetPosX(),
				parEventList[i].GetLocation().GetPosY(),
				parEventList[i].GetLocation().GetPosU(),
				parEventList[i].GetLocation().GetPosV());
		}
		
		// print trigger 
		if(parEventList[i].GetCursorType() == TRIGGER)
		{
			DrawSprite(&(FCursorList[3]),
				TRIGGER_WIDTH,
				TRIGGER_HEIGHT,
				0,
				0,
				parEventList[i].GetLocation().GetPosU() + (parEventList[i].GetValue() / 100.0 * parEventList[i].GetLocation().GetWidth()) - TRIGGER_WIDTH / 2,
				parEventList[i].GetLocation().GetPosV() + parEventList[i].GetLocation().GetHeight()/2 - TRIGGER_HEIGHT/2);
		}
		
	}

	// print cursors that go to foreground
	if(parEventList[locIndexCurrentEvent].GetCursorType() == GLOW || parEventList[locIndexCurrentEvent].GetCursorType() == TRIGGER)
	{
		PrintSpriteCursor(parEventList[locIndexCurrentEvent]);
	}


#endif
}

void TGUI::PrintSpriteSelectedEvent(const TEvent & parEvent)
{
#ifdef COMPILE_PSP
	oslSetAlpha(OSL_FX_ALPHA, 180);
#endif
	image_type * locCursorSprite = NULL;

	// search in cursor list the one whose position is the same 
	for(u32 i = 0; i < FDynamicCursorList.size(); ++i)
	{
		if	(FDynamicCursorList[i].GetPosU() == parEvent.GetLocation().GetPosU()
				&& FDynamicCursorList[i].GetPosV() == parEvent.GetLocation().GetPosV()
			)
		{
			// update dynamic cursor in table
			locCursorSprite = FDynamicCursorList[i].GetSprite();
			break;
		}

	}

	//  dynamic cursor
	DrawSprite(locCursorSprite,
				parEvent.GetLocation().GetWidth(),
				parEvent.GetLocation().GetHeight(),
				0,
				0,
				parEvent.GetLocation().GetPosU(),
				parEvent.GetLocation().GetPosV());

#ifdef COMPILE_PSP
	oslSetAlpha(OSL_FX_RGBA, 255);
#endif
}

void TGUI::PrintSpriteCursor(const TEvent & parEvent )
{
#ifdef COMPILE_PSP
	image_type * locCursorSprite = &(FCursorList[parEvent.GetCursorType()]);

	// cursor for direct linkss
	if(parEvent.GetCursorType() == BLOOD)
	{
		DrawSprite(locCursorSprite,
			BLOOD_WIDTH,
			BLOOD_HEIGHT,
			0,
			0,
			parEvent.GetLocation().GetPosU() + parEvent.GetLocation().GetWidth()/2 - BLOOD_WIDTH/2,
			parEvent.GetLocation().GetPosV() + parEvent.GetLocation().GetHeight()/2 - BLOOD_HEIGHT/2);
	}
	else if(parEvent.GetCursorType() == GLOW)
	{
		input::TInputManagerGUI* locInputManager = static_cast<input::TInputManagerGUI*>(FInputManager);

		// check if event has changed since last frame
		if(locInputManager->GetChangeEvent() == true || !locCursorSprite)
		{
			// reaload cursor with glow 
			// search in cursor list the one whose position is the same 
			for(u32 i = 0; i < FDynamicCursorList.size(); ++i)
			{
				if	(FDynamicCursorList[i].GetPosU() == parEvent.GetLocation().GetPosU()
						&& FDynamicCursorList[i].GetPosV() == parEvent.GetLocation().GetPosV()
					)
				{
					// update dynamic cursor in table
					FCursorList[parEvent.GetCursorType()] = (*FDynamicCursorList[i].GetSprite());
					break;
				}
			}
		}

		//  dynamic cursor
		DrawSprite(locCursorSprite,
			parEvent.GetLocation().GetWidth(),
			parEvent.GetLocation().GetHeight(),
			0,
			0,
			parEvent.GetLocation().GetPosU(),
			parEvent.GetLocation().GetPosV());
	}
	else if(parEvent.GetCursorType() == TRIGGER)
	{
		// cursor for sliders
		DrawSprite(locCursorSprite,
			TRIGGER_WIDTH,
			TRIGGER_HEIGHT,
			0,
			0,
			parEvent.GetLocation().GetPosU() + (parEvent.GetValue() / 100.0 * parEvent.GetLocation().GetWidth()) - TRIGGER_WIDTH / 2,
			parEvent.GetLocation().GetPosV() + parEvent.GetLocation().GetHeight()/2 - TRIGGER_HEIGHT/2);
	}
#endif
}

core::stringc TGUI::GetSpriteHoverName(const core::stringc & parEventSpriteName)
{
	core::stringc locCursorName = parEventSpriteName.c_str();
	u8 locIndexExtention = locCursorName.findFirst('.');

	locCursorName = locCursorName.subString(0, locIndexExtention);
	locCursorName += "_ON.png";
	
//	delete(locCursorName);
	return locCursorName;
}

void TGUI::DrawSprite(image_type * img,
						u16 witdh,
						u16 height,
						u8 posX,
						u8 posY,
						u16 posU,
						u16 posV)
{
	if(img != NULL)
	{
#ifdef COMPILE_PSP
		oslSetImageTileSize(img, posX, posY, witdh, height);
		img->x = posU;
		img->y = posV;
		
		oslDrawImage(img);
#endif
	}
}

} // gui namespace
} // engine namespace
} // psp namespace

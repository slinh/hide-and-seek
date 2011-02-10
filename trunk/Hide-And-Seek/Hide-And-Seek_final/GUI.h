#ifndef TGUI_H
#define TGUI_H

#include "config.h"
#include "InputManager.h"
#include "EventListener.h"

#ifndef COMPILE_PSP
#include <iostream>
#endif

#ifdef COMPILE_PSP
#include <oslib/oslib.h>
#endif
#include "Page.h"
#include "engineXML.h"

#include "config.h"
#include "34LettresEngine.h"
#include "GenericVirtualCallback.h"
#include "Location.h"

#define DEFAULT_WIDTH	480
#define DEFAULT_HEIGHT	272

#define BLOOD_WIDTH		100
#define BLOOD_HEIGHT	63

#define TRIGGER_WIDTH	28
#define TRIGGER_HEIGHT	14

#define FLAG_WITH		33
#define	FLAG_HEIGHT		25

#define CURSOR_BLOOD			"ms0:/PSP/GAME/Hide-And-Seek/Data/tache_sang.png"
#define CURSOR_SLIDER			"ms0:/PSP/GAME/Hide-And-Seek/Data/curseur.png"
#define CURSOR_SLIDER_OFF		"ms0:/PSP/GAME/Hide-And-Seek/Data/curseur_OFF.png"
#define CURSOR_DEFAULT_HOVER	"ms0:/PSP/GAME/Hide-And-Seek/Data/easy_ON.png"

#define SPRITE_FLAG_EN			"ms0:/PSP/GAME/Hide-And-Seek/Data/drapeau_en.png"
#define SPRITE_FLAG_FR			"ms0:/PSP/GAME/Hide-And-Seek/Data/drapeau_fr.png"

#define SPRITE_BACKGROUND		"ms0:/PSP/GAME/Hide-And-Seek/Data/background.png"
#define SPRITE_WIN				"ms0:/PSP/GAME/Hide-And-Seek/Data/win.png"
#define SPRITE_LOOSE			"ms0:/PSP/GAME/Hide-And-Seek/Data/loose.png"
#define SPRITE_LOADING			"ms0:/PSP/GAME/Hide-And-Seek/Data/loading.png"

#ifdef COMPILE_PSP
typedef OSL_IMAGE image_type;
#else
typedef char* image_type;
#endif

namespace psp { namespace engine { namespace gui {

class TGUI
{

public:
	TGUI();
	~TGUI();	
	
	void LoadGUI(const c8 * parXmlfileName);
	void LoadXml(const c8 * parXmlFile);
	void LoadChooseLanguageSprites();

	void createPage(io::engineXMLReader * parXML);
	void createBackground(io::engineXMLReader * parXML);
	TLocation createLocation(io::engineXMLReader * parXML);
	void createLabel(io::engineXMLReader * parXML);
	void createEvent(io::engineXMLReader * parXML);

	void LoadSprite();

	void LoadListener();
	void UnloadListener();

	//! Free all allocated memory for 2D displaying
	void UnloadGUI();

	void PrintGUI();
	void PrintSprite();

	void PrintImageScreen(image_type * img, bool parEnableSync=true);

	void PrintChooseLanguage();
	void PrintSpriteLabelList(const core::array<TLocation> & locationList );
	void PrintSpriteEventList(const core::array<TEvent> & eventLst);
	void PrintSpriteSelectedEvent(const TEvent & parEvent);
	void PrintSpriteCursor(const TEvent & parEvent);

	void DrawSprite(image_type * img,
						u16 witdh = 0,
						u16 height = 0,
						u8 posX = 0,
						u8 posY = 0,
						u16 posU = 0,
						u16 posV = 0);

	core::stringc GetSpriteHoverName(const core::stringc & parEventSpriteName);

	GETTER_SETTER(engine::core::array<TPage>, PageList)
	GETTER_SETTER_PTR(input::IInputManager, InputManager)
	GETTER_SETTER(TLocation, WinScreen)
	GETTER_SETTER(TLocation, LooseScreen)
	GETTER_SETTER(TLocation, Loading)

private:
	core::array<TPage>		FPageList;					// list of pages
	TPage					FPageLanguage;				// first language page
	TLocation 				FWinScreen;
	TLocation 				FLooseScreen;
	TLocation				FLoading;

#ifdef COMPILE_PSP
	core::array<TLocation>	FDynamicCursorList;		// list of dynamic cursors
	image_type				FCursorList[4];			// list of static cursors
#endif

	bool					FIsLoaded;
	input::IInputManager*	FInputManager;				// input manager to handle input events
	input::TEventListener*	FEventListener;
};

} // gui namespace
} // engine namespace
} // psp namespace

#endif 

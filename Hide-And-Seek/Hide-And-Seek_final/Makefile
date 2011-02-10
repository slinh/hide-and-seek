TARGET				=	Hide-And-Seek

EXTERNALS_OBJ		=	#Data/logo.o

COMMON_OBJS			=	Alloc.o\
						callbacks.o \
						Common.o \
						GenericVirtualCallback.o \
						Globals.o \
						intraFont.o \
						libccc.o \
						Logger.o \
						vram.o

CONCEPT_OBJS		=	Plugin.o \
						Singleton.o

CORE_OBJS			=	fast_atof.o \
						Graph.o \
						Node.o
				
GAME_OBJS			=	BlockingItem.o \
						Character.o \
						CharacterIA.o \
						CharacterPlayer.o \
						Game.o \
						GameRulesApplicator.o \
						InteractiveItem.o \
						Item.o \
						ManagerItem.o \
						SimpleItem.o \
						TrailTagItem.o \
						WarpZoneItem.o

GAME_ENGINE_OBJS	=	GameEngine.o

GUI_OBJS			=	Event.o \
						GUI.o \
						GuiInGame.o \
						Location.o \
						Page.o 

IA_OBJS				=	ManagerIA.o \
						TaskIA.o \
						FSMMachine.o \
						FSMState.o

INPUT_OBJS			=	EventListener.o \
						InputManagerGame.o \
						InputManagerGUI.o \
						PadEvent.o \
						UserInputStateBuffer.o

IO_OBJS				=	engineXML.o \
						ReadFile.o \
						WriteFile.o
						 

NET_OBJS			=	AdhocNetwork.o \
						ZBadhoc.o \
						NetworkData.o

OBJECT_OBJS			=	AnimatedMeshMD2.o \
						Animation.o \
						InteractiveObject.o \
						Map.o \
						MeshBuffer.o \
						MeshResource.o \
						Object.o \
						ObjectManager.o \
						StaticMeshOBJ.o

SOUND_OBJS			=	SoundManager.o 

VIDEO_OBJS			=	Camera.o \
						FPSCounter.o \
						Geometry.o \
						Light.o \
						LightManager.o \
						Renderer.o \
						TextureItem.o \
						VideoManager.o \
						Transform.o

WORLD_OBJS			=	World.o
						

OBJS				=	$(EXTERNALS_OBJ) \
						$(COMMON_OBJS) \
						$(CONCEPT_OBJS) \
						$(CORE_OBJS) \
						$(GAME_OBJS) \
						$(GAME_ENGINE_OBJS) \
						$(GUI_OBJS) \
						$(INPUT_OBJS) \
						$(IA_OBJS) \
						$(IO_OBJS) \
						$(NET_OBJS) \
						$(OBJECT_OBJS) \
						$(SOUND_OBJS) \
						$(VIDEO_OBJS) \
						$(WORLD_OBJS) \
						Functions.o \
						main.o

CFLAGS				=  -O2 -G0 -Wall 

CXXFLAGS			=	$(CFLAGS) -fexceptions -D "TIXML_USE_STL" \
						-Wno-deprecated \
						#-fno-rtti 

ASFLAGS				=	$(CFLAGS)
		
STDLIBS				=	-losl -lmikmod -lpng -lz \
						-ltri -lpmp  -lpspaudiocodec -lpspaudio -lpspmpeg \
						-lpspsdk -lpspctrl -lpspumd -lpsprtc -lpsppower -lpspgum -lpspgu -lpspaudiolib -lpspaudio -lm \
						-lsupc++ -lstdc++ -lpspwlan -lpspnet -lpspnet_adhoc -lpspnet_adhocmatching -lpspnet_adhocctl -lpsplibc
						
LIBS				=	$(STDLIBS) $(YOURLIBS)

EXTRA_TARGETS		=	EBOOT.PBP
PSP_EBOOT_TITLE		=	Hide-And-Seek
PSP_EBOOT_ICON		=	Data/ICON0.png

PSPSDK				=	$(shell psp-config --pspsdk-path)

include $(PSPSDK)/lib/build.mak

Data/logo.o: Data/output.raw
	bin2o -i Data/output.raw Data/logo.o logo



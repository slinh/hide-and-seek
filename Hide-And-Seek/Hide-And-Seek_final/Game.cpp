#include "Common.h"
#include "Game.h"
#include "Renderer.h"
#include "LoggerTypes.h"
#include "Functions.h"
#include "CharacterPlayer.h"
#include "CharacterIA.h"
#include "InputManagerGame.h"
#include "ManagerIA.h"
#include "StaticMeshOBJ.h"
#include "AnimatedMeshMD2.h"
#include "MeshResource.h"
#include "ObjectManager.h"
#include "BoundingBox2D.h"
#include "GameConstantes.h"

#ifdef COMPILE_PSP
#include "callbacks.h"
#include <psprtc.h>
#endif

using namespace psp::engine::core;
using namespace psp::engine::object;
using namespace psp::engine::video;

//#define DEBUG_MAP TA_MEWWW
//#define ALL_BLOCKS DONT_ERASE_ME

namespace psp { namespace game {

f32 TGame::GFrameDuration = 40.0f; // ms

TGame::TGame():
FRunning(false),
//FCurrentState(GS_DEBUG),
FCurrentState(GS_INIT),
FCurrentCinematicVideo(CINEMATIC_1),
FlastTickCounter(0),
FCurrentTickCounter(0),
FTime(0),
FElapsedTime(0)
{
	SINGLETONREGINSTANCE
}
	
TGame::~TGame()
{}

void TGame::Start()
{
#ifdef COMPILE_PSP  
	// TODO : verify if it work with true, previously : oslInit(0)
	oslInit(1);
	//oslInitGfx(OSL_PF_8888, 1);

	// Its important to do this after all osl initializations
	setupCallbacks();
#endif

	INITDOMAINMEMORYMANAGER
#ifdef DEBUG
	//LOGINSTANCE(TLoggerDebug) // Logger is set to screen printing
	LOGINSTANCE(TLoggerFile) // Logger is set to output.log file writing
#endif

	FInputManager	= NEW_IN_DOMAIN(Game)			engine::input::TInputManagerGame();

	FVideoManager	= NEW_IN_DOMAIN(Video)			engine::video::TVideoManager();

	FSoundManager	= NEW_IN_DOMAIN(Sound)			engine::sound::TSoundManager();

	FGUI			= NEW_IN_DOMAIN(GUI)			engine::gui::TGUI();
	
	FGuiInGame		= NEW_IN_DOMAIN(GUI)			engine::gui::TGuiInGame();

	// Allocate 3D Renderer
	FCamera			= NEW_IN_DOMAIN(Video)			engine::video::TCamera();

	FRenderer		= engine::video::IRenderer::Make();

	FLightManager	= NEW_IN_DOMAIN(Video_Light)	engine::video::TLightManager();

	FManagerIA		= NEW_IN_DOMAIN(IA)			psp::ia::TManagerIA(this);

#ifndef DEBUG_MAP
	// New map - Change width/height to improve speed
	FMap			= NEW_IN_DOMAIN(Map)			engine::object::TMap(100, 100);
#endif

	//FCurrentTaskIA  = psp::ia::TTaskIA::Make< psp::ia::TManagerIA, &psp::ia::TManagerIA::FakeTestAppelFunctionTTaskIA >(FManagerIA, psp::ia::TASKIA_RECURRENT);

	// bbox object aroud character
	FBBoxAroundCharacter = psp::engine::core::array< engine::core::TBoundingBox2D<float> >(20);
	
	// bbox object around IA
	if( FGameConfig.GetNumberOfPlayers() == NP_SOLO )
	{
		FBBoxAroundIA = psp::engine::core::array< engine::core::TBoundingBox2D<float> >(20);
	}
}

void TGame::Stop()
{
	delete FInputManager;

	delete FVideoManager;

	delete FSoundManager;

	delete FGUI;

	delete FGuiInGame;

	delete FCamera;
	delete FRenderer;

	delete FLightManager;
	
	delete FManagerIA;

	delete FMap;

	//delete FCurrentTaskIA;

#ifdef DEBUG
	// Functions to call before quit
	REPORTLEAKS
	LOGCLOSE
#endif
}

void TGame::InitTime()
{
#ifdef COMPILE_PSP
	sceRtcGetCurrentTick(&FlastTickCounter);
	FCurrentTickCounter = FlastTickCounter;
#endif
}

void TGame::UpdateTime()
{
#ifdef COMPILE_PSP
	FTime += GetElapsedTime(); // ms
#endif
}

f64 TGame::GetElapsedTime()
{
#ifdef COMPILE_PSP
	sceRtcGetCurrentTick(&FCurrentTickCounter);
	FElapsedTime = ( ((f64)(FCurrentTickCounter - FlastTickCounter) / (f64)sceRtcGetTickResolution()) * 1000.0);
#endif
	FlastTickCounter = FCurrentTickCounter;
	FTime += FElapsedTime;
	return FElapsedTime;
}

void TGame::WaitForFrameEnd()
{
	f64 locTimeToSleep = GFrameDuration - GetElapsedTime();
	if(locTimeToSleep > 0)
		sceKernelDelayThread(locTimeToSleep * 1000);
}

void TGame::OnLaunch()
{
	FRunning = true;

	// TODO : delete later
	TGameLoopData locGameLoopData;

	InitTime();

	while(FRunning)
	{
		UpdateTime(); 

		bb2Df locBBox;
		array<int2> locCorner;

		// Manage new inputs
		engine::input::TUserInputStateBuffer::Instance().UpdateAllState();

		FFPSCounter.RegisterFrame(FTime);

		// For music sleep
		FSoundManager->Update();

		switch(FCurrentState)
		{
		case GS_INIT:
#ifdef COMPILE_PSP
			oslInitGfx(OSL_PF_8888, 1);
			oslInitAudio();
#endif
			FSoundManager->InitializeSoundGame();

			FGUI->LoadChooseLanguageSprites();
			FGUI->LoadListener();

			FCurrentState = GS_CHOOSE_LANGUAGE;
			//FCurrentState = GS_LOADING_GAME;
			//FCurrentState = GS_START_MENU;
		break;

		case GS_START_SPLASH_SCREEN:
			LAssert(FGUI != NULL);
		break;

		case GS_CHOOSE_LANGUAGE:
			LAssert(FGUI != NULL);

			FGUI->PrintChooseLanguage();
		break;

		case GS_START_CINEMATIC:
			LAssert(FVideoManager != NULL);

#ifdef WITH_SOUNDS
			if(FSoundManager->IsSoundPlaying(FSoundManager->GetIndexMenu()))
			{
				FSoundManager->StopSound(FSoundManager->GetIndexMenu());
			}
#endif
			if(!FVideoManager->GetVideoInitialized())
			{
				FVideoManager->InitializeVideo(FCurrentCinematicVideo);
			}

			FVideoManager->PlayVideo();

			if(!FVideoManager->IsVideoPlaying())
			{
				FVideoManager->StopVideo();
				
				if(FCurrentCinematicVideo & CINEMATIC_1)
				{
					FCurrentState = GS_START_MENU;
				}
				else if(FCurrentCinematicVideo & CINEMATIC_2)
				{
					FCurrentState = GS_LOADING_GAME;
				}
			}
		break;
	
		case GS_START_MENU:
			// Print menu
			if(FGameConfig.GetGUILoaded())
			{
				FGUI->PrintGUI();
			}
#ifdef WITH_SOUNDS
			if(!FSoundManager->IsSoundPlaying(FSoundManager->GetIndexMenu()) &&
			   !FVideoManager->IsVideoPlaying())
			{
				FSoundManager->PlaySound(FSoundManager->GetIndexMenu());
			}
#endif
		break;

		case GS_LOADING_GAME:
#ifdef WITH_SOUNDS
			if(FSoundManager->IsSoundPlaying(FSoundManager->GetIndexMenu()))
			{
				LOGC("Loading : stop sound with index  %d\n", FSoundManager->GetIndexMenu());
				FSoundManager->StopSound(FSoundManager->GetIndexMenu());
			}
#endif
			// print loading screen
			FGUI->PrintImageScreen(FGUI->GetLoading().GetSprite(), true);

			// TODO : do this into GUi class at the requested moment
			// its a temp debug to have a black screen on second buffer
#ifdef COMPILE_PSP
			oslClearScreen(0);
#endif

			FAKEmeshMD2.Load(	"ms0:/PSP/GAME/Hide-And-Seek/Mesh/character/victime.md2", "ms0:/PSP/GAME/Hide-And-Seek/Data/p_porte_anim.txt", 
					0.018f, engine::core::vector3df(0.f, 0.f, 0.f), engine::core::vector3df(-90.f, 0.f, 0.f),
					128.f/512.f, 384.f/512.f, 128.f/512.f, 128.f/512.f,
					std::pair<u32, u32>(45, 65), 1);
					
			FAKEmesh2MD2.Load(	"ms0:/PSP/GAME/Hide-And-Seek/Mesh/character/judith.md2", "ms0:/PSP/GAME/Hide-And-Seek/Data/p_porte_anim.txt", 
					0.11f, engine::core::vector3df(0.35f, -0.05f, -3.48f), engine::core::vector3df(-90.f, 0.f, 0.f),
					0.f, 384.f/512.f, 128.f/512.f, 128.f/512.f,
					std::pair<u32, u32>(130, 150), 85);
					
			locGameLoopData.meshMD2 = &FAKEmeshMD2;
			locGameLoopData.mesh2MD2 = &FAKEmesh2MD2;

			locGameLoopData.StartAnimation(1, 20, 35.f, 1, 20, 35.f);

			locGameLoopData.FMD2Frame = 0;
			locGameLoopData.FMD2Frame2 = 0;

			// Game init
			InitializeGame();

			FCurrentState = GS_LAUNCH_GAME;
		break;

		case GS_LAUNCH_GAME:
			LAssert(!FSoundManager->IsSoundPlaying(FSoundManager->GetIndexMenu()));

			// TO DO : put this call in Act method
			// because only act function can set the right music to play because its the one which know distance and interact between characters
			// jouer musique normale
#ifdef WITH_SOUNDS
			if(!FSoundManager->IsSoundPlaying(FSoundManager->GetIndexVictim()))
			{
				FSoundManager->PlaySound(FSoundManager->GetIndexVictim());
			}
#endif
			
			FCamera->Update();
			FLightManager->UpdateAllLights();

			// Reset list
			FBBoxAroundCharacter.reset();
			FLookedInteractiveItem.reset();

			// Prepare drawing
			FRenderer->Begin3DScene(*FCamera, *FLightManager);

			// Texture flushing
			FRenderer->FlushTexture();

			/*
			game::ICharacter* locChar = const_cast<game::ICharacter*>(&game::TGame::Instance().GetCharacterList()[0]);

			FRenderer->DrawLine(locChar->GetPosition(), locChar->GetPosition() + locChar->GetDirection(),
								TColor(255, 255, 255, 0));

			FRenderer->DrawLine(locChar->GetPosition(), locChar->GetPosition() + locChar->GetDirectionToGo(),
								TColor(255, 255, 0, 255));
			//*/

#if !defined(DEBUG_MAP) && !defined(ALL_BLOCKS)
			FCamera->XZProjectionBoundingBox(locBBox);
			locCorner = FMap->GetCornersForBoundingBox_WithClamp(locBBox);
#endif
		//*
			FRenderer->LoadIdentity();
			FMap->PrepareForDrawing();			
#if !defined(DEBUG_MAP) && defined(ALL_BLOCKS)
			FRenderer->Scale(engine::core::vector3df(10.f, 10.f, 10.f));
#endif

#if !defined(DEBUG_MAP) && !defined(ALL_BLOCKS)	

			for(s32 i=locCorner[0].X; i < locCorner[2].X; ++i)
			{
				for (int j=locCorner[0].Y; j < locCorner[1].Y; ++j)
				{
					// Read list of Mesh in this block
					for(u32 k=0; k < FMap->GetBlocksMeshIds()[i*FMap->GetWidth() + j].size(); ++k)
					{
						// Read the mesh id and transformation id
						// first : meshId
						// second : transformation id
						pair<u32, u32> locBlockInfo = FMap->GetBlocksMeshIds()[i*FMap->GetWidth() + j][k];
#else
			for(u32 i=0; i < FMap->GetBlocksMeshIds().size(); ++i)
			{
					// Read list of Mesh in this block
					for(u32 k=0; k < FMap->GetBlocksMeshIds()[i].size(); ++k)
					{
						// Read the mesh id and transformation id
						// first : meshId
						// second : transformation id
						pair<u32, u32> locBlockInfo = FMap->GetBlocksMeshIds()[i][k];
#endif
						LAssert(locBlockInfo.first <  FMap->GetMeshResources().size());

						engine::object::TMeshResource* locMeshData = FMap->GetMeshResources()[locBlockInfo.first];

						if(!(locMeshData->GetDrawingState( locBlockInfo.second ) & DRAWN))
						{
							// Set mesh as drawn
							locMeshData->AddDrawingState(locBlockInfo.second, DRAWN);

							// Mesh drawing
							FRenderer->LoadIdentity();			    	
								FRenderer->Translate(locMeshData->GetTransform(locBlockInfo.second).GetTranslation());	 
								FRenderer->Rotate(locMeshData->GetTransform(locBlockInfo.second).GetRotation());
							 
								// Draw Array list
//#ifndef WIREFRAME_MODE
								// Retrieve mesh buffer to draw
								// TODO : Watch mesh type to see if its necessary to update animation before
								const engine::video::TMeshBuffer* locMeshBuffer = &(locMeshData->GetMesh()->GetMeshBuffer());
								if(locMeshBuffer->GetIndexList().size() > 0)
									FRenderer->DrawArrayList(	locMeshBuffer->GetVertexList(), locMeshBuffer->GetIndexList().const_pointer(), locMeshBuffer->GetIndexList().size(), 
																GU_INDEX_16BIT|GU_TEXTURE_32BITF|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D);
								else
									FRenderer->DrawArrayList(	locMeshBuffer->GetVertexList(), locMeshBuffer->GetVertexCount(), 
																GU_TEXTURE_32BITF|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D);
//#endif
								// add the element in the bboxIA list
							if( ! (locMeshData->GetProperties() & O_PASS_ITEM) )
							{
								FBBoxAroundCharacter.push_back( locMeshData->GetBBox2Df(locBlockInfo.second) );

#ifdef WIREFRAME_MODE
								FRenderer->LoadIdentity();
									FRenderer->DrawRectangle(locMeshData->GetBBox2Df(locBlockInfo.second), psp::engine::video::TColor(255, 0, 255, 255));
#endif								
							}
							else
							{
#ifdef WIREFRAME_MODE
								//FRenderer->LoadIdentity();
								//FRenderer->DrawRectangle(locMeshData->GetBBox2Df(locBlockInfo.second), psp::engine::video::TColor(255, 255, 0, 255));
#endif			
							}
						}
#if !defined(DEBUG_MAP) && !defined(ALL_BLOCKS)
					}
				}
			}
#else
				}
			}

#endif

			FRenderer->Disable(GU_LIGHTING);
#ifdef WITH_BLEND
			FRenderer->Disable(GU_BLEND);
#endif
#ifdef COMPILE_PSP
			FRenderer->TextureMode(GU_TFX_REPLACE, GU_TCC_RGB);
#endif

			FRenderer->LoadIdentity();
				FRenderer->Translate(FCharacterList[0].GetPosition());
				FRenderer->Rotate(FAKEmeshMD2.GetRotate());
				FRenderer->RotateOnDirection(FCharacterList[0].GetDirection());
				
				
				FRenderer->DrawArrayList(	FAKEmeshMD2.GetMeshBuffer(locGameLoopData.FMD2Frame).GetVertexList(), FAKEmeshMD2.GetMeshBuffer(locGameLoopData.FMD2Frame).GetIndexList().const_pointer(), 
											FAKEmeshMD2.GetMeshBuffer(locGameLoopData.FMD2Frame).GetIndexList().size(), 
											GU_INDEX_16BIT|GU_TEXTURE_32BITF|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D);

				//locGameLoopData.FMD2Frame = locGameLoopData.FMD2Frame<meshMD2.GetNBFrame()-1? locGameLoopData.FMD2Frame+1 : 0;

			// Draw BBox md2 n1
			//FRenderer->LoadIdentity();
				//FRenderer->Translate(FCharacterList[0].GetPosition());
				//FRenderer->DrawRectangle(meshMD2.GetMeshBuffer(locGameLoopData.FMD2Frame).GetBBox2D(), engine::video::TColor(255, 255, 0, 255) );
			//*
			// SECOND MD2
			FRenderer->LoadIdentity();
				FRenderer->Translate(FCharacterList[1].GetPosition());
				FRenderer->Rotate(FAKEmesh2MD2.GetRotate());
				FRenderer->RotateOnDirection(FCharacterList[0].GetDirection());
				
				
				FRenderer->DrawArrayList(	FAKEmesh2MD2.GetMeshBuffer(locGameLoopData.FMD2Frame2).GetVertexList(), FAKEmesh2MD2.GetMeshBuffer(locGameLoopData.FMD2Frame2).GetIndexList().const_pointer(), 
											FAKEmesh2MD2.GetMeshBuffer(locGameLoopData.FMD2Frame2).GetIndexList().size(), 
											GU_INDEX_16BIT|GU_TEXTURE_32BITF|GU_NORMAL_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D);

				//locGameLoopData.FMD2Frame2 = locGameLoopData.FMD2Frame2<mesh2MD2.GetNBFrame()-1? locGameLoopData.FMD2Frame2+1 : 0;

			// Draw BBox md2 n2
			//FRenderer->LoadIdentity();
				//FRenderer->Translate(FCharacterList[1].GetPosition());
				//FRenderer->DrawRectangle(mesh2MD2.GetMeshBuffer(locGameLoopData.FMD2Frame2).GetBBox2D(), engine::video::TColor(255, 255, 0, 255) );
			//*/
#ifdef WITH_LIGHTS
				FRenderer->Enable(GU_LIGHTING);
#endif
#ifdef WITH_BLEND
				FRenderer->Enable(GU_BLEND);
#endif
			//*
			// Start 2D drawing
			FGuiInGame->InitGfxDraw();

			PrintDebugInfo(DI_FPS | DI_PLAYER_POSITION);

				// End 2D drawing
			FGuiInGame->EndGfxDraw();
			//*/
			// End drawing
			FRenderer->End3DScene();
			
			//FManagerIA->OnTimer();

			// Update world && resolve collisions
			FGameRulesApplicator.Act(locGameLoopData);
			locGameLoopData.UpdateAllAnimation();

			WaitForFrameEnd();

			//FCurrentState = GS_DEBUG;
			//FCurrentState = GS_END_GAME;
			//FCurrentState = GS_RETURN_TO_MENU;
		break;
		
		case GS_WIN_GAME:
			LAssert(FGUI != NULL);

			//FGUI->PrintImageScreen(FGUI->GetWinScreen().GetSprite(), true);
			
			FRenderer->Begin3DScene(*FCamera, *FLightManager);
			FGuiInGame->InitGfxDraw();

				FGuiInGame->SetStyle(1.5f, engine::video::TColor(255, 255, 255, 255), engine::video::TColor(0, 0, 0, 0));
				FGuiInGame->DrawMessage("You Win", SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.5f);

			FGuiInGame->EndGfxDraw();
			FRenderer->End3DScene();
			
			FCurrentState = GS_RETURN_TO_MENU;
		break;

		case GS_LOSE_GAME:
			LAssert(FGUI != NULL);

			//FGUI->PrintImageScreen(FGUI->GetLooseScreen().GetSprite(), true);
			
			FRenderer->Begin3DScene(*FCamera, *FLightManager);
			FGuiInGame->InitGfxDraw();

				FGuiInGame->SetStyle(1.5f, engine::video::TColor(255, 255, 255, 255), engine::video::TColor(0, 0, 0, 0));
				FGuiInGame->DrawMessage("You Lose", SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.5f);

			FGuiInGame->EndGfxDraw();
			FRenderer->End3DScene();
			
			FCurrentState = GS_RETURN_TO_MENU;
		break;

		case GS_RETURN_TO_MENU:

			// Unload Game
			UnloadGame();

#ifdef COMPILE_PSP
			oslInitGfx(OSL_PF_8888, 1);
#endif
			// Reset GUI
			(FGameConfig.GetLanguage() & L_EN) ? 
			FGUI->LoadGUI(XML_EN):
			FGUI->LoadGUI(XML_FR);

			FGUI->LoadListener();

			FCurrentState = GS_START_MENU;
		break;

		case GS_END_GAME:
			
			UnloadGame();

			// Memory leaks report
			REPORTLEAKS

			FRunning = false;
		break;

		case GS_DEBUG:
			/*
			static bool OSLInitialized = false;
			static OSL_IMAGE *locTestPicture = NULL;
			static OSL_IMAGE *locTestPicture2 = NULL;

			static bool Is2DMode = true;
			static int loc3DCount = 0;
			static int loc2DCount = 0;

			static u32 __attribute__((aligned(16))) FDisplayList[262144];
			
			if(Is2DMode)
			{
				///////////////////////////////// INITIALIZING
				if(!OSLInitialized)
				{
					oslSetTransparentColor(RGB(255,255,255));

					oslDisableTransparentColor();

					loc2DCount = 0;

					OSLInitialized = true;
				}

				////////////////////////////////// LOADING
				if(loc2DCount % 2 == 0)
				{
					if(locTestPicture2 != NULL)
						oslDeleteImage(locTestPicture2);
					if(locTestPicture != NULL)
						oslDeleteImage(locTestPicture);

					locTestPicture = locTestPicture2 = NULL;

					locTestPicture = oslLoadImageFile("ms0:/PSP/GAME/Hide-And-Seek/Data/loose.png", OSL_IN_RAM, OSL_PF_5551);
					locTestPicture2 = oslLoadImageFile("ms0:/PSP/GAME/Hide-And-Seek/Data/credits_fr.png", OSL_IN_RAM, OSL_PF_5551);
				}
				else
				{
					if(locTestPicture2 != NULL)
						oslDeleteImage(locTestPicture2);
					if(locTestPicture != NULL)
						oslDeleteImage(locTestPicture);

					locTestPicture = locTestPicture2 = NULL;

					locTestPicture = oslLoadImageFile("ms0:/PSP/GAME/Hide-And-Seek/Data/photo_groupe.png", OSL_IN_RAM, OSL_PF_5551);
					locTestPicture2 = oslLoadImageFile("ms0:/PSP/GAME/Hide-And-Seek/Data/tache_sang.png", OSL_IN_RAM, OSL_PF_5551);
				}

				LAssert(locTestPicture != NULL);
				LAssert(locTestPicture2 != NULL);

				//////////////////////////////////////// DRAWING
				oslStartDrawing();

				oslCls();

				oslDrawImage(locTestPicture);

				oslDrawImage(locTestPicture2);

				oslEndDrawing();

				oslSyncFrame();

				oslSyncDrawing();

				++loc2DCount;

				if(loc2DCount == 5)
					Is2DMode = false;
			}
			else
			{
				if(OSLInitialized)
				{
					if(locTestPicture2 != NULL)
						oslDeleteImage(locTestPicture2);
					if(locTestPicture != NULL)
						oslDeleteImage(locTestPicture);

					locTestPicture = locTestPicture2 = NULL;

					oslCls();

					loc3DCount = 0;

					/////////////////////////////// SETUP GU
					static void* FDrawBuffer		= getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_8888);
					static void* FDisplayBuffer	= getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_8888);
					static void* FDepthBuffer		= getStaticVramBuffer(BUFFER_WIDTH, SCREEN_HEIGHT, GU_PSM_4444);

					sceGuInit();

					sceGuStart(GU_DIRECT, FDisplayList);

					sceGuDrawBuffer(GU_PSM_8888, FDrawBuffer, BUFFER_WIDTH);
					sceGuDispBuffer(SCREEN_WIDTH, SCREEN_HEIGHT, FDisplayBuffer, BUFFER_WIDTH);
					sceGuDepthBuffer(FDepthBuffer, BUFFER_WIDTH);

					// Drawing settings
					sceGuOffset(2048 - (SCREEN_WIDTH/2), 2048 - (SCREEN_HEIGHT/2));
					sceGuViewport(2048, 2048, SCREEN_WIDTH, SCREEN_HEIGHT);
					sceGuDepthRange(65535, 0);
					//sceGuDepthRange(0xc350,0x2710);
					sceGuScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
					sceGuDepthFunc(GU_GEQUAL);
					sceGuShadeModel(GU_SMOOTH);

					// Enabling default states
					sceGuEnable(GU_SCISSOR_TEST);
					sceGuEnable(GU_DEPTH_TEST);
					sceGuEnable(GU_TEXTURE_2D);
					sceGuEnable(GU_CLIP_PLANES);
					//sceGuFrontFace(GU_CW);
					//sceGuEnable(GU_CULL_FACE);
					//sceGuEnable(GU_ALPHA_TEST);

					// Synchronise display list
					sceGuFinish();
					sceGuSync(0,0);

					sceDisplayWaitVblankStart();
					sceGuDisplay(GU_TRUE);

					OSLInitialized = false;
				}

				// Initialize display list
				sceGuStart(GU_DIRECT, FDisplayList);

				// Delete buffer for new rendering
				sceGuClearColor(0xffff00ff);
				//sceGuClearColor(0x0);
				sceGuClearDepth(0);
				sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

				// Treat display list
				sceGuFinish();
				sceGuSync(0, 0);

				// Swap buffers
				sceDisplayWaitVblankStart();
				sceGuSwapBuffers();

				++loc3DCount;

				if(loc3DCount == 5)
					Is2DMode = true;
			}
			//*/
			break;

		case GS_WAIT:

		break;
		}
	}	
}

// Init game
void TGame::InitializeGame()
{
	LAssert(FRenderer != NULL);
	FGUI->UnloadGUI();

	// Load game map
	LoadLevel();
//*
	// TODO : use a factory to create players
	// Victim :
	TCharacterPlayer	locPlayer;
	locPlayer.SetRole() = CR_VICTIM;
	FCharacterList.push_back(locPlayer);

	FCharacterList[0].SetSpeed() = 1.1f;
	FCharacterList[0].SetDashSpeed() = 1.45f;

	// If solo, 2nd = IA
	if( FGameConfig.GetNumberOfPlayers() == NP_SOLO )
	{
		FCharacterList.push_back( TCharacterIA() );
		FCharacterList[1].SetSpeed() = 1.20f;
		FCharacterList[1].SetDashSpeed() = 1.6f;
		
		// BBox around player for object around
		FBBoxZoneIA.AddPoint(FCharacterList[1].GetPosition().X - IA_BBOX_WIDTH, FCharacterList[1].GetPosition().Y - IA_BBOX_HEIGHT);
		FBBoxZoneIA.AddPoint(FCharacterList[1].GetPosition().X + IA_BBOX_WIDTH, FCharacterList[1].GetPosition().Y + IA_BBOX_HEIGHT);
	}
	else
	{
		// Hunter :
		TCharacterPlayer	locPlayerSecond;
		locPlayerSecond.SetRole() = CR_HUNTER;
		FCharacterList.push_back(locPlayerSecond);
	}

	FManagerIA->SetCurrentCharacterIA(static_cast< TCharacterIA* >(&FCharacterList[1]));
	//*/
	// Initialize listener for global game input management
	FInputManager->Plug();
	
	
	// Add first light
	FLightManager->AddLight(vector3df(-0.092f, 0.3f, -2.09f),  // position
							vector3df(0.f, -1.f, 0.f), // direction
							TColor(255, 237, 232, 206), // diffuse color
							TColor(255, 255, 255, 255), // specular color
							GU_DIFFUSE_AND_SPECULAR); // component

	FLightManager->GetLight(0).InitLight(&(FCharacterList[0]));

	// Set camera to follow character player
	FCamera->InitCamera(&(FCharacterList[0]));

	// New IA task - Here is an exemple 
	//FCurrentTaskIA->Wait(300);

	// Log start time
	FBeginingTime = GetTimeInteger64();

	FRenderer->Initialize3D();

	FGameState = G_RUNNING;
}

// load game : load level map and build graph 
void TGame::LoadLevel()
{
#ifdef DEBUG_MAP
#include "Data\Map\world_Last_light.inl"

	FMap->SetSubdivisionSize(1, 1);

#else

	FMap->LoadMap("ms0:/PSP/GAME/Hide-And-Seek/Map/map.map");
#endif
	//LOGC("Game Start !\n");

	// Set level light
	


	// Add second light
/*
	FLightManager->AddLight(vector3df(0.79f, 1.36f, 0.f), vector3df(0.f, 0.f, 0.f), 
							TColor(255, 0, 255, 0), TColor(255, 255, 255, 255),
							GU_DIFFUSE_AND_SPECULAR); 

	// Add second light
	FLightManager->AddLight(vector3df(0.9f, -1.3f, 0.f), vector3df(0.f, 0.f, 0.f), 
							TColor(255, 0, 0, 255), TColor(255, 255, 255, 255),
							GU_DIFFUSE_AND_SPECULAR);
*/
	// Add second light
	/*
	FLightManager->AddLight(vector3df(0.f, 0.f, -3.f), vector3df(0.f, 0.f, 0.f), 
							TColor(255, 255, 0, 255), TColor(255, 255, 255, 255),
							GU_DIFFUSE_AND_SPECULAR);
	*/
//*/
	/*TObjectManager::CreateInstance();
	TObjectManager::Instance().Init(FMap->GetMeshResources());
	
	psp::engine::core::array< psp::engine::core::array<u32> > locBlockIds;
	u32 locWidth = 0;
	u32 locHeight = 0;
	u32 locSpacing = 5;

	TGridGraph::CreateInstance();
	TGridGraph::Instance().Init(locWidth, locHeight, locSpacing, locBlockIds);
*/
//	// TEST NEAREST NODE
//	vector2di position(13,7);
//	u32 node = FGraph->GetNearestNode(position);
////	LOGC("Position (13,7) Nearest node : %d \n", node); 
//
//	// TEST A*
//	u32 start = 0;
//	u32 dest = 29;
//	u32 next = FGraph->GetNextNodeToGo(start, dest);

//	LOGC("Next node to go : %d \n", next);
//*/
}

void TGame::UnloadGame()
{
	FRenderer->FreeTextures();

	// Free all allocated memory in Map
	FMap->Clear();

	// Free MD2 models
	FAKEmeshMD2.Free();
	FAKEmesh2MD2.Free();

#ifdef WITH_SOUNDS
	// stop music
	if(FSoundManager->IsSoundPlaying(FSoundManager->GetIndexVictim()))
		FSoundManager->StopSound(FSoundManager->GetIndexVictim());

	if(FSoundManager->IsSoundPlaying(FSoundManager->GetIndexFear()))
		FSoundManager->StopSound(FSoundManager->GetIndexFear());

	if(FSoundManager->IsSoundPlaying(FSoundManager->GetIndexLFMan()))
		FSoundManager->StopSound( FSoundManager->GetIndexLFMan() );

	if(FSoundManager->IsSoundPlaying(FSoundManager->GetIndexRFMan()))
		FSoundManager->StopSound( FSoundManager->GetIndexRFMan() );
#endif

	FLightManager->RemoveAllLights();

#ifdef COMPILE_PSP
	sceGuTerm();
#endif
	
	LAssert(FInputManager != NULL);
	FInputManager->UnPlug();

	FCharacterList.clear();

	FAllInteractiveItems.clear();
	FLookedInteractiveItem.clear();

	FBBoxAroundIA.clear();
	FBBoxAroundCharacter.clear();
}

void TGame::PrintDebugInfo( const s32& parDebugList )
{
	c8 buffer[LONG_BUFFER_SIZE];
	u32 offset = 0;
	u32 nbRead = 0;
	u32 deltaX = 0;

	// ---------------------------------------------------------------------------------
	// Game fps
	// ---------------------------------------------------------------------------------

	if(parDebugList & DI_FPS)
#ifdef COMPILE_PSP
		nbRead = sprintf(buffer + offset, "%d fps\n", FFPSCounter.GetFps());
#else
		nbRead = sprintf_s(buffer + offset, LONG_BUFFER_SIZE, "%d fps\n", FFPSCounter.GetFps());
#endif

	offset += nbRead;
	deltaX = MAX(deltaX, nbRead);
	// ---------------------------------------------------------------------------------
	// Player position
	// ---------------------------------------------------------------------------------
	const vector3df& locPos = FCharacterList[0].GetPosition();

	if(parDebugList & DI_PLAYER_POSITION)
#ifdef COMPILE_PSP
		nbRead = sprintf(buffer + offset, "%3.2f %3.2f\n", locPos.X, locPos.Z);
#else
		nbRead = sprintf_s(buffer + offset, LONG_BUFFER_SIZE, "%3.2f %3.2f %3.2f\n", locPos.X, locPos.Y, locPos.Z);
#endif

	offset += nbRead;
	deltaX = MAX(deltaX, nbRead);

	// ---------------------------------------------------------------------------------
	// Info printing
	// ---------------------------------------------------------------------------------
	f32 fontSize = 0.7f;
	FGuiInGame->SetStyle(fontSize, engine::video::TColor(255, 255, 255, 255), engine::video::TColor(0, 0, 0, 0), INTRAFONT_ALIGN_LEFT);
	FGuiInGame->DrawMessage(buffer, (f32)deltaX * fontSize, 15.f);
}

} // namespace game
} // namespace psp
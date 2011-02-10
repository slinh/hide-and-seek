#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "GameConfig.h"
#include "GameConstantes.h"
#include "GameRulesApplicator.h"
#include "Renderer.h"
#include "Singleton.h"
#include "GUI.h"
#include "VideoManager.h"
#include "SoundManager.h"
#include "UserInputStateBuffer.h"
#include "FPSCounter.h"
#include "InputManagerGame.h"
#include "Character.h"
#include "Graph.h"
#include "ManagerIA.h"
#include "Camera.h"
#include "MeshBuffer.h"
#include "Map.h"
#include "MeshResource.h"
#include "vector2d.h"
#include "GuiInGame.h"
#include "BoundingBox2D.h"
#include "NetworkData.h"
#include "LightManager.h"

namespace psp { namespace game { 

class IRenderer;

class TGame : public TSingleton<TGame>
{
friend class TGameRulesApplicator;

public:
	static f32 GFrameDuration;

public:
	TGame();
	~TGame();
	//! Initialize all elements for game starting
	void Start();

	//! Stop all elements
	void Stop();

	//! Launch main loop for game
	void OnLaunch();

	//! Calculate and return the elapsed time (to use at the end of the game loop)
	f64 GetElapsedTime();

	//! Wait until the frame duration is reached
	void WaitForFrameEnd();

	//! Returns current frame tick
	u32 GetCurrentTime();

	// Getters for time
	GETTER(f64, Time)
	inline u64 GetTimeInteger64() const {return (u64)FTime;}
	inline u32 GetTimeInteger32() const {return (u32)FTime;}

	// getters
	GETTER_SETTER(GAME_STATE, CurrentState)
	GETTER_SETTER(TGameConfig, GameConfig)

	GETTER_SETTER(u64, BeginingTime)

	GETTER_SETTER(engine::video::TFPSCounter, FPSCounter)

	GETTER_PTR(engine::video::TCamera, Camera)

	GETTER_PTR(engine::input::TInputManagerGame, InputManager)
	GETTER_SETTER_PTR(engine::gui::TGUI, GUI)
	GETTER_SETTER_PTR(engine::sound::TSoundManager, SoundManager)
	GETTER_PTR(engine::video::TVideoManager, VideoManager)
	GETTER_SETTER(CinematicVideo, CurrentCinematicVideo)

	GETTER_SETTER(engine::core::array<game::ICharacter>, CharacterList)
	GETTER_PTR(ia::TManagerIA, ManagerIA)

	GETTER_SETTER(bb2Df, BBoxZoneIA)
	GETTER_PTR(engine::object::TMap, Map)

private:
	void InitTime();
	void UpdateTime();
	void InitializeGame();
	void LoadLevel();
	void UnloadGame();

	// Debug printing
	void PrintDebugInfo(const s32& parDebugList);


	// Game state variables
	bool									FRunning;
	GAME_STATE								FCurrentState;

	engine::gui::TGUI*						FGUI;			// GUI managing variable
	engine::gui::TGuiInGame*				FGuiInGame;		// GUI in game
	engine::video::TVideoManager*			FVideoManager;	// Video manager in game
	engine::sound::TSoundManager*			FSoundManager;	// sound manager in game
	engine::video::TCamera*					FCamera;		// Variables for 3D rendering management
	CinematicVideo							FCurrentCinematicVideo;
	engine::video::IRenderer*				FRenderer;
	engine::video::TLightManager*			FLightManager;
	engine::input::TInputManagerGame*		FInputManager;	// Manager of inputs in game
	TGameConfig								FGameConfig;
	TGameRulesApplicator					FGameRulesApplicator;
	engine::object::TMap*					FMap;			// Map containig datas and objects	
	psp::ia::TManagerIA*					FManagerIA;		// ManagerIA
    engine::core::array<game::ICharacter>	FCharacterList;	// Character playable vect

	// Game duration managing parameters
	u64 FBeginingTime;

	// Parameters for time counting
	u64										FlastTickCounter;
	u64										FCurrentTickCounter;
	f64 									FTime;
	f64										FElapsedTime;

	engine::video::TFPSCounter				FFPSCounter;

	// TTASKIA current
	ia::TTaskIA*							FCurrentTaskIA;
	// OBJECTS LIST
	// liste de tous les objets interractifs
	psp::engine::core::array<psp::engine::object::TMeshResource*> FAllInteractiveItems;
	
	// objets à portée
	psp::engine::core::array<psp::engine::object::TMeshResource*> FLookedInteractiveItem;
	
	// pointeurs sur liste d'objets interractifs (switche sur un tableau ou l'autre selon perso ou ia)
	psp::engine::core::array<psp::engine::object::TMeshResource*>* FObjectToLook;


	//
	// BBox which define where IA can intersect object
	bb2Df FBBoxZoneIA;

	// bbox list IA
	psp::engine::core::array< bb2Df > FBBoxAroundIA;

	// bbox list around character
	psp::engine::core::array< bb2Df > FBBoxAroundCharacter;
	// Game State
	u64 FGameState; // G_RUNNING / G_ENDED +  G_LOOSE / G_WIN

	// MD2 : TODO delete later
	psp::engine::object::TAnimatedMeshMD2 FAKEmeshMD2;
	psp::engine::object::TAnimatedMeshMD2 FAKEmesh2MD2;

	// TODO : put this in GameRulesApplicator
	// attack in current turn
	bool FAttackInThisRound;

	// Fake pour stocker pos arriver path secret i beoin
	vector2df FFakeEndSecretPath;

	friend void* ::psp::engine::net::NetworkPacketMaker::Serialize(const TNetworkPacketMetaData& parDiff);
	friend void ::psp::engine::net::NetworkPacketMaker::Deserialize(void* parData);
};

struct TGameLoopData
{
	TGameLoopData():
	FIsAnimated(false), FIsAnimated2(false),
	FMD2Frame(0), FMD2Frame2(0),
	FFPS(20.f), FFPS2(20.f),
	FInterFrameTime(0), FInterFrameTime2(0),
	meshMD2(NULL), mesh2MD2(NULL)
	{}

	// We managed on ly one animation type
	void StartAnimation(const u32& parFrameStart, const u32& parFrameEnd, const f32& parFPS,
						const u32& parFrameStart2, const u32& parFrameEnd2, const f32& parFPS2)
	{
		FIsAnimated = FIsAnimated2 = true;
		FFPS = parFPS; FFPS2 = parFPS2;
		FStartFrame = parFrameStart; FStartFrame2 = parFrameStart2;
		FEndFrame = parFrameEnd; FEndFrame2 = parFrameEnd2;
		FInterFrameTime = FInterFrameTime2 = TGame::Instance().GetTimeInteger32();
	}

	void UpdateAllAnimation()
	{
		LAssert(FFPS > 0.f);
		LAssert(FFPS2 > 0.f);

		u32 locTime = TGame::Instance().GetTimeInteger32();

		if(FIsAnimated)
		{				
			f32 locElapsedTime = (f32)(locTime - FInterFrameTime);
			f32 locFrameDelta = (1.f / FFPS) * 1000.f;

			u32 locCoeff = ROUND(locElapsedTime / locFrameDelta);
			FMD2Frame += locCoeff;

			FInterFrameTime = locTime;

			if(FMD2Frame > FEndFrame)
				FMD2Frame = FStartFrame;
		}
		else
			FMD2Frame = 0;

		if(FIsAnimated2)
		{
			f32 locElapsedTime = (f32)(locTime - FInterFrameTime2);
			f32 locFrameDelta = (1.f / FFPS2) * 1000.f;

			u32 locCoeff = ROUND(locElapsedTime / locFrameDelta);
			FMD2Frame2 += locCoeff;

			FInterFrameTime2 = locTime;

			if(FMD2Frame2 > FEndFrame2)
				FMD2Frame2 = FStartFrame2;
		}
		else
			FMD2Frame2 = 0;
	}

	// Management of 2 players MD2 models
	bool FIsAnimated;
	bool FIsAnimated2;

	u32 FMD2Frame;
	u32 FMD2Frame2;

	// Frame range management
	u32 FStartFrame;
	u32 FStartFrame2;

	u32 FEndFrame;
	u32 FEndFrame2;

	// Animation speed
	f32 FFPS;
	f32 FFPS2;

	u32 FInterFrameTime;
	u32 FInterFrameTime2;

	psp::engine::object::TAnimatedMeshMD2* meshMD2;
	psp::engine::object::TAnimatedMeshMD2* mesh2MD2;
};

} // game namespace
} // psp namespace

#endif

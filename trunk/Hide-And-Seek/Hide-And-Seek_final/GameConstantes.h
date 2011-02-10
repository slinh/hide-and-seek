#ifndef WORLD_CONSTANTES
#define WORLD_CONSTANTES

#define MAP_VERSION_ID "34L1"

// state game
#define G_RUNNING 1
#define G_ENDED 2
#define G_WIN 4
#define G_LOOSE 8

// object type
#define O_NORMAL 1
#define O_INTERACTIVE 2
#define O_PATH_MARKER 4
#define O_SECRET_PATH 8
#define O_VISUAL 16
#define O_SOUND 32
#define O_PASS_ITEM 64

// object status ( activate / desactivate ) 
#define OS_ACTIVATE 1
#define OS_DESACTIVATE 2

// epsilon pour detecter objet à proximité
#define EPSILON_NEAR 0.1
#define EPSILON_NEAR_CHARACTER 0.05


// value for bbox around ia (o find object near at each frame)
#define IA_BBOX_HEIGHT 1.2
#define IA_BBOX_WIDTH 1.5

enum GAME_STATE
{
	GS_START_SPLASH_SCREEN	= 1,
	GS_START_CINEMATIC		= 2,
	GS_CHOOSE_LANGUAGE		= 4,
	GS_START_MENU			= 8,
	GS_LOADING_GAME			= 16,
	GS_LAUNCH_GAME			= 32,
	GS_END_GAME				= 64,
	GS_WIN_GAME				= 128,
	GS_LOSE_GAME			= 256,	
	GS_RETURN_TO_MENU		= 512,
	GS_INIT					= 4096,
	GS_WAIT					= 8192,
	GS_DEBUG				= 16384,
};

enum NumPage
{
	/* MENU RELEASE */
	PAGE_HOME				= 0,
	PAGE_MAIN				= 1,
	PAGE_TUTORIAL			= 2,
	PAGE_OPTIONS			= 3,
	PAGE_CREDITS			= 4,

	PAGE_CONTINUE			,
	PAGE_MULTIPLAYER_MAIN	,
	PAGE_MULTIPLAYER_JOIN	,
	PAGE_MULTIPLAYER_HOST	,

};

enum DEBUG_INFO
{
	DI_FPS = 1,
	DI_PLAYER_POSITION = 2
};

#endif

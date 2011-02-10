#ifndef WORLD_CONSTANTES
#define WORLD_CONSTANTES

#define MAP_VERSION_ID "34L1"

namespace psp {

enum GAME_STATE
{
	GS_START_SPLASH_SCREEN	= 1,
	GS_START_MENU			= 2,
	GS_LOADING_GAME			= 4,
	GS_LAUNCH_GAME			= 8,
	GS_END_GAME				= 16,
	GS_RETURN_TO_MENU		= 32,
	GS_WAIT					= 4096
};

} // psp namespace

#endif

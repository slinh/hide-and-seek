#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "config.h"
#include "Singleton.h"

// Object include
#include "AnimatedMeshMD2.h"
#include "StaticMeshOBJ.h"

namespace psp { namespace engine {

class TGameEngine : public psp::TSingleton<TGameEngine, true>
{
public:
	TGameEngine();
    ~TGameEngine();
	void Free();
};

} // Engine namespace
} // psp namespace

#endif
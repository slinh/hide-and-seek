#include "Common.h"
#include "GameEngine.h"

namespace psp { namespace engine {

TGameEngine::TGameEngine()
{
	SINGLETONREGINSTANCE
}

// Destructor
TGameEngine::~TGameEngine()
{
	Free();
}

void TGameEngine::Free()
{
}

} // Engine namespace
} // psp namespace

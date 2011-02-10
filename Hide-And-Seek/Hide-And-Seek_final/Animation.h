#ifndef ANIMATION_H
#define ANIMATION_H

#include "engineArray.h"
#include "vector2d.h"

#include <algorithm>

namespace psp { namespace engine { namespace object {

class TAnimation
{
public :
	TAnimation();
	~TAnimation();

	void LoadAnim(const char* parFile);
	int Update();

	void SetAnimState(int parState);

private:
	int FAnimState;
	int FStartFrame;
	int FEndFrame;
	int FCurrentFrame;

	core::array<core::vector2di> FAnimFrames;
};

} // object namespace
} // engine namespace
} // psp namespace

#endif

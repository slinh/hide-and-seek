#ifndef GAMERULESAPPLICATOR_H
#define GAMERULESAPPLICATOR_H

#include "config.h"
#include "Character.h"
#include "BoundingBox2D.h"

namespace psp { namespace game {

struct TGameLoopData;

class TGameRulesApplicator
{
public:
	TGameRulesApplicator();
	~TGameRulesApplicator();

	void Act(TGameLoopData& parGameLoopData);

private:
	void CharacterAct(ICharacter* parCharacter);
	void CheckCollisonWithObject(ICharacter & parCharacter, psp::engine::core::array< engine::core::TBoundingBox2D<float> >& parBBoxList, TGameLoopData& parGameLoopData);
};

} // game namespace
} // psp namespace
#endif
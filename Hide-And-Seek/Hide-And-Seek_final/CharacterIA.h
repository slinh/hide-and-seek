#ifndef CHARACTER_IA_H
#define CHARACTER_IA_H

#include "config.h"
#include "Character.h"
#include "Object.h"
#include "TaskIA.h"
#include "vector3d.h"

#include "FSMState.h"

namespace psp { 
	
namespace ia
{
	class TFSMMachine;

	struct TFSMInSpotCondition : TFSMCondition
	{
	public:
		TFSMInSpotCondition(TFSMState* parFather) : TFSMCondition(parFather) {}

		bool operator()();
	};

	struct TFSMOutSpotCondition : TFSMCondition
	{
	public:
		TFSMOutSpotCondition(TFSMState* parFather) : TFSMCondition(parFather) {}

		bool operator()();
	};

	struct TFSMInAttackCondition : TFSMCondition
	{
	public:
		TFSMInAttackCondition(TFSMState* parFather) : TFSMCondition(parFather) {}

		bool operator()();
	};

	struct TFSMOutAttackCondition : TFSMCondition
	{
	public:
		TFSMOutAttackCondition(TFSMState* parFather) : TFSMCondition(parFather) {}

		bool operator()();
	};
}

namespace game {


class TCharacterIA : public ICharacter
{
public:
	TCharacterIA();
	TCharacterIA(engine::core::vector3df parPosition, engine::core::vector3df parDirection, float parSpeed);
	virtual ~TCharacterIA();

	void Start(void);
	void Act(void);

private:
	void ComputeNextNode();
	void ComputeNewDirection();
	void InitFSM();

	int FCount;
	::psp::ia::TTaskIA* FPtr;

	engine::object::TObject* FObjectToGo;
	u32 FNodeObjectToGo;
	u32 FNodeToGo;
	u32 FCurrentNode;
	u32 FLastPop;

	::psp::ia::TFSMMachine* FFSM;
};

} // namespace game
} // namespace psp

#endif


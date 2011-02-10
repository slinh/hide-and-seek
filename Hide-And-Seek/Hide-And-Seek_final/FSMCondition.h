#ifndef FSM_CONDITION_H
#define FSM_CONDITION_H

#include "FSMState.h"
#include "Logger.h"

namespace psp { namespace ia {

	struct TFSMDebugCondition : TFSMCondition
	{
	public:
		TFSMDebugCondition(TFSMState* parFather) : TFSMCondition(parFather) {}

		virtual bool operator()();
	};

	bool TFSMDebugCondition::operator()()
	{
		return true;
	}
}}

#endif
#ifndef FSM_MACHINE_H
#define FSM_MACHINE_H

#include "config.h"

#if defined(DEBUG) && defined(COMPILE_PC)
# include <string>
#endif

#include "engineArray.h"

namespace psp { namespace ia {

	// Forward declare
	class TFSMState;

	class TFSMMachine
	{
	public:
		TFSMMachine();
		~TFSMMachine();

		void Update();
		const TFSMState& GetCurrentState() const { return *FCurrentState; }
		void SetCurrentState(TFSMState* parState) { FCurrentState = parState; }

		void AddState(TFSMState* parState) { FStates.push_back(parState); }

#if defined(DEBUG) && defined(COMPILE_PC)
		std::string ToString() const;
#endif

	private:
		psp::engine::core::array< TFSMState* > FStates;
		TFSMState* FCurrentState;
	};

}}

#endif
#ifndef FSM_STATE_H
#define FSM_STATE_H

#include "config.h"
#include "engineArray.h"
#include <utility>

#if defined(DEBUG) && defined(COMPILE_PC)
# include <string>
#endif

namespace psp { namespace ia {

	class TFSMState;

	struct TFSMCondition
	{
	public:
		TFSMCondition(TFSMState* parFather) : FFather(parFather) {}
		virtual ~TFSMCondition(){}

		virtual bool operator()() = 0;

	protected:
		TFSMState* FFather;
	};

	class TFSMState
	{
	public:
		TFSMState(const u8& parCode);
		~TFSMState();

		TFSMState* GetNextState();
		const u8& GetCode() const { return FCode; }
		void LinkTo(TFSMCondition* parCondition, TFSMState* parState) { FForwardLinks.push_back(std::make_pair(parCondition, parState)); }

#if defined(DEBUG) && defined(COMPILE_PC)
		std::string ToString() const;
#endif

	private:
		psp::engine::core::array< std::pair< TFSMCondition*, TFSMState* > > FForwardLinks;
		u8 FCode;
	};

}}

#endif
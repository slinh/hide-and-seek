#include "FSMMachine.h"
#include "FSMState.h"

#if defined(DEBUG) && defined(COMPILE_PC)
# include <sstream>
#endif

namespace psp { namespace ia {

	TFSMMachine::TFSMMachine()
	{

	}

	TFSMMachine::~TFSMMachine()
	{
		for(u8 i = 0 ; i < FStates.size() ; i++)
		{
			delete FStates[i];
		}
	}

	void TFSMMachine::Update()
	{
		FCurrentState = FCurrentState->GetNextState();
	}

#if defined(DEBUG) && defined(COMPILE_PC)
	std::string TFSMMachine::ToString() const
	{
		std::ostringstream os;
		for(u8 i = 0 ; i < FStates.size() ; i++)
		{
			os << FStates[i]->ToString();
			os << std::endl << std::endl;
		}
		return os.str();
	}
#endif
}}
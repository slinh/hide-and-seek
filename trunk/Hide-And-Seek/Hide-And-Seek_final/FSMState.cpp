#include "FSMState.h"
#include "engineTypes.h"

#if defined(DEBUG) && defined(COMPILE_PC)
# include <sstream>
#endif

namespace psp { namespace ia {

	TFSMState::TFSMState(const u8& parCode) : FCode(parCode)
	{

	}

	TFSMState::~TFSMState()
	{
		for(u16 i = 0 ; i < FForwardLinks.size() ; i++)
		{
			delete FForwardLinks[i].first;
		}
	}

	TFSMState* TFSMState::GetNextState()
	{
		for(u16 i = 0 ; i < FForwardLinks.size() ; i++)
		{
			if((*FForwardLinks[i].first)())
				return FForwardLinks[i].second;
		}
		return this;
	}

#if defined(DEBUG) && defined(COMPILE_PC)
	std::string TFSMState::ToString() const
	{
		std::ostringstream os;

		os << "FSMState Dump" << std::endl << "Code : ";

		u8 flag = 1;
		for(u8 i = 0 ; i < sizeof(u8) * 8 ; i++)
		{
			os << ((flag & FCode) ? '1' : '0');
			flag *= 2;
		}

		os << std::endl << std::endl << "\tLinks :\n"; 

		for(u8 i = 0 ; i < FForwardLinks.size() ; i++)
		{
			flag = 1;
			for(u8 j = 0 ; j < sizeof(u8) * 8 ; j++)
			{
				os << ((flag & FForwardLinks[i].second->FCode) ? '1' : '0');
				flag *= 2;
			}
			os << std::endl;
		}

		return os.str();
	}
#endif
}}
#include "TaskIA.h"
#include "Game.h"
#include "Common.h"

#ifdef COMPILE_PSP
#ifdef COMPILE_PSP
	#include <psprtc.h>
#endif
#include "World.h"
#endif

namespace psp { namespace ia {


TTaskIA::~TTaskIA(void)
{
	Cancel_IFN(); 
}


void TTaskIA::Wait(const u32 & value)
{
	LAssert(value >= 0);

	u32 locCurrentTime = game::TGame::Instance().GetTimeInteger32()+value;

	if (locCurrentTime != FDateReveil || !Registered())
	{
		Cancel_IFN();
		Register();
		FDateReveil = locCurrentTime;
		// ajout de la tâche dans le managerIA
		//game::TGame::Instance().GetManagerIA()->InsertTaskIA(this);
	}
}

void TTaskIA::Cancel()
{
	LAssert(Registered());
	// on enlève la tâhce du ttaskIA
	//game::TGame::Instance().GetManagerIA()->RemoveTaskIA(this);
	UnRegister();
}

} // namespace ia
} // namespace psp
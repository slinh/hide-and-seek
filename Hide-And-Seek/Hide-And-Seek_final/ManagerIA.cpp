#include "ManagerIA.h"
#include "Game.h"

#ifdef COMPILE_PSP
	#include <psprtc.h>
#endif

namespace psp { namespace ia {

const u32 TManagerIA::G_AI_FRAME_DURATION = 200;

TManagerIA::TManagerIA(::psp::game::TGame* parGame):
FCurrentCharacterIA(NULL), FGame(parGame) 
{
	
}

TManagerIA::~TManagerIA(void)
{
}

void TManagerIA::Start()
{
//	FCurrentCharacterIA = NEW_IN_DOMAIN(IA) psp::game::TCharacterIA();
	FCurrentCharacterIA->SetRole() = game::CR_HUNTER; // poursuivant
	FLastTime = FGame->GetTimeInteger32();
}

void TManagerIA::Stop()
{
//	delete FCurrentCharacterIA;
}

// Fonction idle appellée tout le temps
void TManagerIA::OnTimer()
{
	//LOGC("### OnTimer ###\n");	
	u32 locCurrentTime = FGame->GetTimeInteger32();

	if((locCurrentTime - FLastTime) >= 20)
	{
		// Mise à jour des decisions IA
		UpdateIA();
		FLastTime = locCurrentTime;
	}
	//LOGC("### OnTimer End ###\n");
}

void TManagerIA::UpdateIA()
{
	// Mise à jour de l'ordre dans IA :
	//LOGC_IA("[TManagerIA::UpdateIA]\n");
	FCurrentCharacterIA->Act();
}


} // namespace ia
} // namespace psp
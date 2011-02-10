#ifndef MANAGER_IA_H
#define MANAGER_IA_H

#include "config.h"
#include "engineArray.h"
#include "TaskIA.h"
#include "CharacterIA.h"
#include "Singleton.h"

namespace psp { 
	
namespace game
{
	class TGame;
}

namespace ia {

class TManagerIA
{
public:
	static const u32 G_AI_FRAME_DURATION;

public:
	TManagerIA(::psp::game::TGame* parGame);
	~TManagerIA(void);

	void Start();
	void Stop();

	void OnTimer();

	GETTER_SETTER_PTR(game::TCharacterIA, CurrentCharacterIA)

private:
	::psp::game::TCharacterIA*			FCurrentCharacterIA;
	u32									FLastTime;
	::psp::game::TGame*					FGame;

	void UpdateIA();
};

} // namespace ia
} // namespace psp

#endif
#ifndef TPAGE_H
#define TPAGE_H

#include "Common.h"
#include "config.h"
#include "Location.h"
#include "Event.h"
#include "engineArray.h"

namespace psp { namespace engine { namespace gui{

class TPage
{
public:
	TPage();
	TPage(u8 parIdPage);
	~TPage();

	GETTER_SETTER(u8, IdPage)
	GETTER_SETTER(TLocation, Background)
	GETTER_SETTER(core::array<TLocation>, LabelList)
	GETTER_SETTER(core::array<TEvent>, EventList)

private:
	u8			FIdPage;
	TLocation	FBackground;
	core::array<TLocation> FLabelList;
	core::array<TEvent> FEventList;
};

} // gui namespace
} // engine namespace
} // psp namespace

#endif 
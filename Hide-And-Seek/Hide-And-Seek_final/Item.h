#ifndef ITEM_H
#define ITEM_H

#include "config.h"

namespace psp { namespace game {

typedef enum itemType {
	SimpleItem,
	InteractiveItem,
	BlockingItem,
	TrailTagItem,
	WarpZoneItem
} ItemType;

class IItem
{
public:

	VIRTUAL_DESTRUCTOR(IItem)
	GETTER_SETTER(u32, Id)

	virtual ItemType GetItemType(void) = 0;

private:
	u32 FId;
};

} // namespace game
} // namespace psp

#endif

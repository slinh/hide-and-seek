#ifndef WARP_ZONE_ITEM_H
#define WARP_ZONE_ITEM_H

#include "config.h"
#include "InteractiveItem.h"

namespace psp { namespace game {

class TWarpZoneItem : public TInteractiveItem
{
public:
	TWarpZoneItem(void);
	~TWarpZoneItem(void);

	ItemType GetItemType(void);
};

} // namespace game
} // namespace psp

#endif

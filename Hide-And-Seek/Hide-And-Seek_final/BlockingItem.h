#ifndef BLOCKING_ITEM_H
#define BLOCKING_ITEM_H

#include "config.h"
#include "InteractiveItem.h"
#include "Item.h"

namespace psp { namespace game {

class TBlockingItem : public TInteractiveItem
{
public:
	TBlockingItem(void);
	~TBlockingItem(void);

	ItemType GetItemType(void);
};

} // namespace game
} // namespace psp

#endif

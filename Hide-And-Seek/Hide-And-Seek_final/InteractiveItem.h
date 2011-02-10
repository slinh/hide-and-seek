#ifndef INTERACTIVE_ITEM_H
#define INTERACTIVE_ITEM_H

#include "Item.h"
#include "config.h"

namespace psp { namespace game {

class TInteractiveItem : public IItem
{
public:
	TInteractiveItem(void);
	~TInteractiveItem(void);

	ItemType GetItemType(void);
};

} // namespace game
} // namespace psp

#endif

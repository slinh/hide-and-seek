#include "BlockingItem.h"
#include "Item.h"

namespace psp { namespace game {

TBlockingItem::TBlockingItem(void)
{
}


TBlockingItem::~TBlockingItem(void)
{
}

ItemType TBlockingItem::GetItemType(void)
{
	return BlockingItem;
}

} // namespace game
} // namespace psp
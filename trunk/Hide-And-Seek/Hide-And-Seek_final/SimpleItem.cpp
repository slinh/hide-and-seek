#include "SimpleItem.h"
#include "Item.h"

namespace psp { namespace game {

TSimpleItem::TSimpleItem(void)
{
}


TSimpleItem::~TSimpleItem(void)
{
}

ItemType TSimpleItem::GetItemType(void)
{
	return SimpleItem;
}

} // namespace game
} // namespace psp
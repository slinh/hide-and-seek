#include "InteractiveItem.h"
#include "Item.h"

namespace psp { namespace game {

TInteractiveItem::TInteractiveItem(void)
{
}

TInteractiveItem::~TInteractiveItem(void)
{
}

ItemType TInteractiveItem::GetItemType(void)
{
	return InteractiveItem;
}

} // namespace game
} // namespace psp
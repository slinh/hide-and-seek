#ifndef TRAIL_TAG_ITEM_H
#define TRAIL_TAG_ITEM_H

#include "config.h"
#include "InteractiveItem.h"

namespace psp { namespace game {

class TTrailTagItem : public TInteractiveItem
{
public:
	TTrailTagItem(void);
	~TTrailTagItem(void);

	ItemType GetItemType(void);
};

} // namespace game
} // namespace psp

#endif
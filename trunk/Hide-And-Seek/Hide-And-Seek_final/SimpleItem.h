#ifndef SIMPLE_ITEM_H
#define SIMPLE_ITEM_H

#include "config.h"
#include "Item.h"

namespace psp { namespace game {

class TSimpleItem : public IItem
{
public:
	TSimpleItem(void);
	~TSimpleItem(void);

	ItemType GetItemType(void);

};

} // namespace game
} // namespace psp

#endif

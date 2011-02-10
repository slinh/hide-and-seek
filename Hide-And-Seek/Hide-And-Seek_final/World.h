#ifndef WORLD_H
#define WORLD_H

#include "config.h"

namespace psp {

class TWorld : public TSingleton<TWorld>
{
public:
	TWorld();
	~TWorld();
};

} // psp namespace

#endif

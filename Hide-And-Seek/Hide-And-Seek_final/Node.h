#ifndef NODE_H
#define NODE_H

#include "config.h"
#include "vector2d.h"

#ifdef COMPILE_PSP
	#include <pspctrl.h>
#endif

#ifdef COMPILE_PC
#include <iostream>
#endif

namespace psp { namespace engine { namespace core {

class Node
{
public :
    Node();
	~Node();

	GETTER_SETTER(engine::core::vector2di, Position)
	GETTER_SETTER(bool, Enabled)

private :
	vector2di FPosition;
	bool FEnabled;
};

} // core namespace
} // engine namespace
} // psp namespace

#endif // NODE_H

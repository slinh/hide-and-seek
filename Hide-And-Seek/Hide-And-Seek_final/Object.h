#ifndef OBJECT_H
#define OBJECT_H

#include "config.h"
#include "vector3d.h"

namespace psp { namespace engine { namespace object {

class TObject
{
public :
	TObject();
	~TObject();

	GETTER_SETTER(engine::core::vector3df, Position)

private:
	engine::core::vector3df FPosition;
};

} // namespace object
} // namespace engine
} // namespace psp

#endif

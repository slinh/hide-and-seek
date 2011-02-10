#ifndef INTERACTIVE_OBJECT_H
#define INTERACTIVE_OBJECT_H

#include "Object.h"

namespace psp { namespace engine { namespace object {

typedef enum EObjectState {
	Activated,
	Inactivated
} ObjectState;

class TInteractiveObject : public TObject
{
public :
	
	TInteractiveObject();
	~TInteractiveObject();

	GETTER_SETTER(ObjectState, State)

private :
	ObjectState FState;
};

} // namespace object
} // namespace engine
} // namespace psp

#endif

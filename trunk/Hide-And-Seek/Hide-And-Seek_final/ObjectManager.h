#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <vector>
#include <algorithm>

#include "Map.h"
#include "Singleton.h"
#include "InteractiveObject.h"

namespace psp { namespace engine { 

	using namespace core;
	
namespace object {

class TObjectManager : public TSingleton<TObjectManager, true>
{
public :
	TObjectManager();
	~TObjectManager();

	void Init(array<TMeshResource*> parMeshes);
	void Free();

	// Static objects

	void AddObject(TObject* parObject);
	void RemoveObject(TObject* parObject);

	TObject* GetNearestObject(engine::core::vector3df parPosition);

	// Interactive Objects

	void AddInteractiveObject(TInteractiveObject* parObject);
	void RemoveInteractiveObject(TInteractiveObject* parObject);

	TInteractiveObject* GetNearestInteractiveObject(engine::core::vector3df parPosition);
	TInteractiveObject* GetNearestInteractiveObjectWithState(engine::core::vector3df parPosition, ObjectState parState);

private :
	std::vector<TObject*> FObjects;
	std::vector<TInteractiveObject*> FInteractiveObjects;
};

} // namespace object
} // namespace engine
} // namespace psp

#endif

#include "ObjectManager.h"

#include "Alloc.h"
#include "Logger.h"
#include "engineArray.h"

namespace psp { namespace engine { namespace object {

	TObjectManager::TObjectManager()
	{
		SINGLETONREGINSTANCE
	}

	TObjectManager::~TObjectManager()
	{
		Free();
	}

	void TObjectManager::Init(array<TMeshResource*> parMeshes)
	{
		LOGC_IA("INIT Object manager : ");
		for(u32 i = 0; i < parMeshes.size(); ++i)
		{
			if(parMeshes[i]->GetProperties() == 1)
			{
				for(u32 j = 0; j < parMeshes[i]->GetNbBBox2Df(); ++j)
				{
					TInteractiveObject* locObject = NEW_IN_DOMAIN(Game) TInteractiveObject();
					locObject->SetPosition() = parMeshes[i]->GetTransform(j).GetTranslation();
					AddInteractiveObject(locObject);

					LOGC_IA("Adding Interactive object at : %f, %f, %f \n", locObject->GetPosition().X, locObject->GetPosition().Y, locObject->GetPosition().Z);
				}
			}
			else
			{
				for(u32 j = 0; j < parMeshes[i]->GetNbTransform(); ++j)
				{
					TObject* locObject = NEW_IN_DOMAIN(Game) TObject();
					locObject->SetPosition() = parMeshes[i]->GetTransform(j).GetTranslation();
					AddObject(locObject);

					LOGC_IA("Adding object at : %d, %d, %d \n", locObject->GetPosition().X, locObject->GetPosition().Y, locObject->GetPosition().Z);
				}
			}
		}
	}

	void TObjectManager::Free()
	{
	}

	void TObjectManager::AddObject(TObject* parObject)
	{
		std::vector<TObject*>::iterator it =  std::find(FObjects.begin(), FObjects.end(), parObject);
		if(it != FObjects.end())
			return;

		FObjects.push_back(parObject);
	}

	void TObjectManager::RemoveObject(TObject* parObject)
	{
		std::vector<TObject*>::iterator it =  std::find(FObjects.begin(), FObjects.end(), parObject);
		if(it != FObjects.end())
			FObjects.erase(it);
	}

	TObject* TObjectManager::GetNearestObject(engine::core::vector3df parPosition)
	{
		TObject* locNearest = NULL;
		TObject* locObject = NULL;
		float locNearestDistance = 10000.0f;
		float locDistance = 0.0f;

		for(std::vector<TObject*>::iterator it = FObjects.begin(); it != FObjects.end(); ++it)
		{
			locObject = *it;
			locDistance = parPosition.getDistanceFrom(locObject->GetPosition());
			if(locDistance < locNearestDistance)
			{
				locNearestDistance = locDistance;
				locNearest = locObject;
			}
		}
		return locNearest;
	}

	void TObjectManager::AddInteractiveObject(TInteractiveObject* parObject)
	{
		std::vector<TInteractiveObject*>::iterator it =  std::find(FInteractiveObjects.begin(), FInteractiveObjects.end(), parObject);
		if(it != FInteractiveObjects.end())
			return;

		FInteractiveObjects.push_back(parObject);
	}

	void TObjectManager::RemoveInteractiveObject(TInteractiveObject* parObject)
	{
		std::vector<TInteractiveObject*>::iterator it =  std::find(FInteractiveObjects.begin(), FInteractiveObjects.end(), parObject);
		if(it != FInteractiveObjects.end())
			FInteractiveObjects.erase(it);
	}

	TInteractiveObject* TObjectManager::GetNearestInteractiveObject(engine::core::vector3df parPosition)
	{
		TInteractiveObject* locNearest = NULL;
		TInteractiveObject* locObject = NULL;
		float locNearestDistance = 10000.0f;
		float locDistance = 0.0f;

		for(std::vector<TInteractiveObject*>::iterator it = FInteractiveObjects.begin(); it != FInteractiveObjects.end(); ++it)
		{
			locObject = *it;
			locDistance = parPosition.getDistanceFrom(locObject->GetPosition());
			if(locDistance < locNearestDistance)
			{
				locNearestDistance = locDistance;
				locNearest = locObject;
			}
		}
		return locNearest;
	}

	TInteractiveObject* TObjectManager::GetNearestInteractiveObjectWithState(engine::core::vector3df parPosition, ObjectState parState)
	{
		TInteractiveObject* locNearest = NULL;
		TInteractiveObject* locObject = NULL;
		float locNearestDistance = 10000.0f;
		float locDistance = 0.0f;

		for(std::vector<TInteractiveObject*>::iterator it = FInteractiveObjects.begin(); it != FInteractiveObjects.end(); ++it)
		{
			locObject = *it;
			if(locObject->GetState() == parState)
			{
				locDistance = parPosition.getDistanceFrom(locObject->GetPosition());
				if(locDistance < locNearestDistance)
				{
					locNearestDistance = locDistance;
					locNearest = locObject;
				}
			}
		}
		return locNearest;
	}

} // namespace object
} // namespace engine
} // namespace psp
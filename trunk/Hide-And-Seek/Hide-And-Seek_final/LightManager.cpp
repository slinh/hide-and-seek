#include "Common.h"
#include "LightManager.h"

namespace psp { namespace engine { namespace video {

TLightManager::TLightManager():
FLightCurrentID(0)
{}

TLightManager::~TLightManager()
{
	for(u32 i=0; i<FLightList.size(); ++i)
		delete FLightList[i];
}

void TLightManager::AddLight(
								const core::vector3df& parPosition, const core::vector3df& parDirection, 
								const TColor& parDiffuseColor, const TColor& parSpecularColor,
								u32 parComponents,
								LIGHT_TYPE parType, LIGHT_BEHAVIOR parBehavior
							)
{
	TLight* locLight = NEW_IN_DOMAIN(Video_Light) TLight(FLightCurrentID, parPosition, parDirection, parDiffuseColor, parSpecularColor, parComponents, parType, parBehavior);
	++FLightCurrentID;
	FLightList.push_back(locLight);
}


void TLightManager::FillPosition(const u8  &parId, ScePspFVector3 &parPos) const
{
	LAssert(parId < FLightList.size());
	FLightList[parId]->FillPosition(parPos);
}

void TLightManager::UpdateAllLights()
{
	for(u32 i=0; i<FLightList.size(); ++i)
	{
		FLightList[i]->Update();
	}

}

void TLightManager::RemoveAllLights()
{
	for(u32 i=0; i<FLightList.size(); ++i)
	{
		delete FLightList[i];;
	}

	FLightList.clear();
	FLightCurrentID = 0;
}

} // video namespace
} // engine namespace
} // psp namespacejj

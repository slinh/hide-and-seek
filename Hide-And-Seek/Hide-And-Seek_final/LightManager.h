#ifndef LIGHT_MANAGER_H
#define LIGHT_MANAGER_H

#include "Light.h"
#include "engineArray.h"

namespace psp { namespace engine { namespace video {

class TLightManager
{
public:
	TLightManager();
	~TLightManager();

	GETTER(core::array<TLight*>, LightList);
	const TLight& GetLight(u8 parId) const
	{
		LAssert(parId < FLightList.size());
		return *(FLightList[parId]);
	}
	TLight& GetLight(u8 parId)
	{
		LAssert(parId < FLightList.size());
		return *(FLightList[parId]);
	}

	void AddLight(
					const core::vector3df& parPosition, const core::vector3df& parDirection, 
					const TColor& parDiffuseColor, const TColor& parSpecularColor,
					u32 parComponents,
					LIGHT_TYPE parType = LT_POINT, LIGHT_BEHAVIOR parBehavior = LB_FIXED
				 );

	void UpdateAllLights();
	void FillPosition(const u8 &parId, ScePspFVector3 &parPos) const;

	void RemoveAllLights();

private:
	u8						FLightCurrentID;
	core::array<TLight*>	FLightList;

	NON_COPYABLE(TLightManager)
};

} // video namespace
} // engine namespace
} // psp namespace

#endif

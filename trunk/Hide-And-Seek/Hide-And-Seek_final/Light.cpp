#include "Common.h"
#include "Light.h"

namespace psp { namespace engine { namespace video {
	
TLight::TLight(u8 parId):
FId(parId),
FPosition(0.f, 1.f, -1.f), FDirection(0.f, -1.f, 0.f),
FType(LT_POINT), FBehavior(LB_FIXED)
{}

TLight::TLight(	
				u8 parId,
				const core::vector3df& parPosition, const core::vector3df& parDirection, 
				const TColor& parDiffuseColor, const TColor& parAuxComponentColor,
				u32 parComponents,
				LIGHT_TYPE parType, LIGHT_BEHAVIOR parBehavior
			  ):
FId(parId),
FPosition(parPosition), FDirection(parDirection),
FDiffuseColor(parDiffuseColor), FAuxComponentColor(parAuxComponentColor),
FComponents(parComponents),
FType(parType), FBehavior(parBehavior)
{}

void TLight::FillPosition(ScePspFVector3 &parPos) const
{
	parPos.x = FPosition.X;
	parPos.y = FPosition.Y;
	parPos.z = FPosition.Z;
}

void TLight::InitLight(const game::ICharacter* parTarget)
{
	LAssert(parTarget != NULL);
	FAim = parTarget;
	FPosition = parTarget->GetPosition();
	FPosition.Y += 0.15f;
}

void TLight::Update()
{
	if (FAim != NULL)
	{
		FPosition = FAim->GetPosition();
		FPosition.Y += 0.15f;
	}
}


} // video namespace
} // engine namespace
} // psp namespace

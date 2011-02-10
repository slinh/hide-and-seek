#ifndef LIGHT_H
#define LIGHT_H

#include "Color.h"
#include "vector3d.h"
#include "Light.h"
#include "Character.h"
#ifdef COMPILE_PSP
#include <pspgu.h>

enum LIGHT_TYPE
{
	LT_POINT		= GU_POINTLIGHT,
	LT_DIRECTIONAL	= GU_DIRECTIONAL,
	LT_SPOT			= GU_SPOTLIGHT
};
#else   // temporaire
enum LIGHT_TYPE
{
	LT_POINT		= 0,
	LT_DIRECTIONAL	= 1,
	LT_SPOT			= 2
};
#endif

enum LIGHT_BEHAVIOR
{
	// Light with a fixed position
	LB_FIXED = 1,

	// Light which have a target to follow
	LB_PURSUIT = 2
};

namespace psp { namespace engine { namespace video {

class TLight
{
public:
	TLight(u8 parId);
#ifdef COMPILE_PSP
	TLight(	
			u8 parId,
			const core::vector3df& parPosition, const core::vector3df& parDirection, 
			const TColor& parDiffuseColor, const TColor& parAuxComponentColor, 
			u32 parComponents = GU_DIFFUSE_AND_SPECULAR,
			LIGHT_TYPE parType = LT_POINT, LIGHT_BEHAVIOR parBehavior = LB_FIXED
		  );
#else	// temporaire
	TLight(	
		u8 parId,
		const core::vector3df& parPosition, const core::vector3df& parDirection, 
		const TColor& parDiffuseColor, const TColor& parAuxComponentColor, 
		u32 parComponents = 0,
		LIGHT_TYPE parType = LT_POINT, LIGHT_BEHAVIOR parBehavior = LB_FIXED
		);
#endif

	GETTER_SETTER(u8, Id)
	GETTER_SETTER(core::vector3df, Position)
	GETTER_SETTER(core::vector3df, Direction)
	GETTER_SETTER(TColor, DiffuseColor)
	GETTER_SETTER(TColor, AuxComponentColor)
	GETTER_SETTER(u32, Components)
	GETTER_SETTER(LIGHT_TYPE, Type)
	GETTER_SETTER(LIGHT_BEHAVIOR, Behavior)

	/* SERGE */
	void InitLight(const game::ICharacter* parTarget);
	void Update();
	void FillPosition(ScePspFVector3 &parPos) const;
	/* SERGE */

private:
	u8				FId;

	core::vector3df	FPosition;
	core::vector3df	FDirection;

	TColor			FDiffuseColor;
	TColor			FAuxComponentColor;
	
	u32				FComponents;
	
	LIGHT_TYPE		FType;
	LIGHT_BEHAVIOR	FBehavior;

	const game::ICharacter* FAim; // Light target
};

} // video namespace
} // engine namespace
} // psp namespace

#endif

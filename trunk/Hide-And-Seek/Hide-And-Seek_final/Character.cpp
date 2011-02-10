#include "Character.h"
#include "Game.h"

namespace psp { namespace game {

	ICharacter::ICharacter() : FLastDashStart(0), FLastDashEnd(0)
	{
	}

void ICharacter::Update()
{
	f32 locSpeedToGo = FDirectionToGo.getLength();

	if (locSpeedToGo >  WALKING_SENSIBILITY)
	{
		bool locWalk = false;

		// Cas pad poussé à fond : on avance directement vers la direction
		if (locSpeedToGo > 1 - 2 * WALKING_SENSIBILITY)
		{
			locWalk = true;
		}
		// Sinon on tourne
		else
		{	
			f32 locCross = FDirection.crossProduct(FDirectionToGo).Y;
			f32 locDot = FDirection.dotProduct(FDirectionToGo);

			f32 locRotAngle = locSpeedToGo*1000*FRAME_PER_UNIT;

			FDirection.rotateXZBy(locCross < 0 ? locRotAngle : -locRotAngle, engine::core::vector3df(0.f, 0.f, 0.f));

			if (FDirection.crossProduct(FDirectionToGo).Y*locCross < 0	// Après rotation, Direction dépasse direction to go
				|| (FastAbs(locCross/locSpeedToGo) < DIRECTION_SENSIBILITY && locDot > 0)) // Direction est dans le "cone"
				locWalk = true;
		}

		if (locWalk)
		{
			FDirection = FDirectionToGo.normalize();

			if((FCurrentState & CO_DASH && FLastDashStart != 0 && ::psp::game::TGame::Instance().GetTimeInteger32() - FLastDashStart > 200) || (FLastDashStart != 0 && !(FCurrentState & CO_DASH))) // dash max duration && dash out
			{
				FCurrentState = CO_WALK;
				FLastDashStart = 0;
				FLastDashEnd = ::psp::game::TGame::Instance().GetTimeInteger32();
			}
			if (FCurrentState & CO_DASH && (FLastDashEnd == 0 || ::psp::game::TGame::Instance().GetTimeInteger32() - FLastDashEnd > 1000)) // delay between dashes
			{
				if(FLastDashStart == 0)
					FLastDashStart = ::psp::game::TGame::Instance().GetTimeInteger32();
				FPosition += FDirection*locSpeedToGo*FDashSpeed*FRAME_PER_UNIT;
			}
			else if (FCurrentState & CO_RUN)
				FPosition += FDirection*locSpeedToGo*FSpeed*FRAME_PER_UNIT;
			else 
				FPosition += FDirection*locSpeedToGo*FRAME_PER_UNIT;
			
		}

		FDirectionToGo.X = 0.f;
		FDirectionToGo.Y = 0.f;
		FDirectionToGo.Z = 0.f;
	}
}

void ICharacter::SetPositionTo(float parX, float parY)
{
	engine::core::vector3df translation;

	translation.X = parX - FPosition.X;
	translation.Z = parY - FPosition.Z;

	// moving perso
	FPosition.X = parX;
	FPosition.Z = parY;

	// moving bbox
	FBBox.Translate(translation);
}

void ICharacter::SetOrderWalk()
{
	FOrder = CO_WALK | CO_RUN ;
}

void ICharacter::SetOrderRun()
{
	FOrder = CO_RUN ;
}

void ICharacter::SetOrderDash()
{
	FOrder = CO_DASH | CO_RUN ;
}

void ICharacter::SetOrderActivate()
{
	FOrder = CO_ACTIVATE;
}

void ICharacter::SetOrderNothing()
{
	FOrder = CO_NOTHING;
}

void ICharacter::AddOrder(const u32& parOrder)
{
	FOrder = FOrder | parOrder;
}

void ICharacter::RemoveOrder(const u32& parOrder)
{
	FOrder = FOrder & (FOrder ^ parOrder);
}


} //namesapce game
} // namespace ia

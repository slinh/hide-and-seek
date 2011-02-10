#include "Common.h"
#include "Camera.h"
#include "engineMath.h"
#include "fmathv.h"
#ifdef COMPILE_PSP
#include "psptypes.h"
#endif

namespace psp { namespace engine { namespace video {

TCamera::TCamera() :
FHeight(1.01f),
FDistance(0.5001f),
FFovy(28),
FAspect(16.0f/9.0f),
FNear(0.1f),
FFar(10.0f),
FAim(NULL)
{}

TCamera::~TCamera()
{}

void TCamera::InitCamera(const game::ICharacter* parTarget)
{
	LAssert(parTarget != NULL);

#ifdef CAMERA_DEBUG
	FPosition = core::vector3df(0.f, 4.f, -1.f);
	FDirection = core::vector3df(0.f, -1.f, 0.5f);
#else
	FAim = parTarget;
	FDirection = core::vector3df(0.f, -FHeight, FDistance);
	FPosition = parTarget->GetPosition() - FDirection;
#endif
	FUp.X = 0.f;
	FUp.Y = 1.f;
	FUp.Z = 0.f;

	NormalizeDirection();
	UpdateTheta();
}

void TCamera::Update()
{
	if (FAim != NULL)	FPosition = FAim->GetPosition() - FDirection;
}

void TCamera::NormalizeDirection()
{
	FDirection.normalize();
	FRightInView = -FDirection.crossProduct(FUp).normalize();
	FUpInView = FDirection.crossProduct(FRightInView);
}

void TCamera::UpdateTheta()
{
	// TODO : I don't know what this really do
	if (FastAbs(FDirection.X) < core::EPSILON)
	{
		if (FDirection.Z >= 0.f)
			FTheta = 90.f;
		else
			FTheta = 270.f;
	}
	else
	{
		FTheta = FastAtan(FDirection.Z/FDirection.X)*core::RAD_TO_DEG;

		if (FDirection.X < 0)
			FTheta += 180.f;
	}

	FTheta = core::CLAMP<f32>(FTheta, 0.f, 360.f);
}

void TCamera::CopyLookAt(ScePspFVector3& parEye, ScePspFVector3& parTarget, ScePspFVector3& parUp) const
{
	parEye.x = FPosition.X;
	parEye.y = FPosition.Y;
	parEye.z = FPosition.Z;

	parTarget.x = FPosition.X + FDirection.X;
	parTarget.y = FPosition.Y + FDirection.Y;
	parTarget.z = FPosition.Z + FDirection.Z;

	parUp.x = FUp.X;
	parUp.x = FUp.Y;
	parUp.x = FUp.Z;
}

void TCamera::RotateTheta(const f32& parAngle, bool parRelative)
{
	FTheta += parAngle;
	FTheta = core::CLAMP<f32>(FTheta, 0.f, 360.f);
	
	if (FAim != NULL)	FPosition.rotateXZBy(parAngle, FAim->GetPosition());
	FDirection.rotateXZBy(parAngle);

	NormalizeDirection();
}

void TCamera::RotatePhi(const f32& parAngle, bool parRelative)
{
	FDirection.Y = FDirection.Y + parAngle;
	NormalizeDirection();
}

void TCamera::MoveForward(const f32& parMovement)
{
	FPosition += FDirection*parMovement;
}

void TCamera::MoveTrans(const f32& parMovement)
{
	FPosition += FRightInView*parMovement;
}

void TCamera::MoveUp(const f32& parMovement)
{
	FPosition += FUpInView*parMovement;
}

core::vector3df TCamera::ConvertDirectionFromJoystick(const f32& parAnalogX, const f32& parAnalogY, bool parNormalize)
{
	core::vector3df locDir(
							parAnalogX < 0 ? parAnalogX / 128.f : parAnalogX / 127.f,
							0.f,
							parAnalogX < 0 ? parAnalogY / 128.f : parAnalogY / 127.f
						  );

	f32 locLength = locDir.getLength();
	locDir.normalize();
	locDir *= locLength > 1 ? 1 : locLength;

	locDir.rotateXZBy(FTheta + 90.f);

	return locDir;
}

void TCamera::SetBehindTarget()
{
	FPosition = FAim->GetPosition() - FAim->GetDirection()*FDistance;
	FPosition.Y += FHeight;

	FDirection = FAim->GetPosition() - FPosition;

	NormalizeDirection();
	UpdateTheta();
}

void TCamera::XZProjectionBoundingBox(bb2Df& parBBox)
{
	f32 locRadAngle = FFovy * core::DEG_TO_RAD * 0.5f;
	f32 locTanRatio = FastSin(locRadAngle) / FastCos(locRadAngle);

	core::vector3df locRightNormalizedRatio = FRightInView*locTanRatio*FAspect;
	core::vector3df locUpNormalizedRatio = FUpInView*locTanRatio;

	core::vector3df locTL = FDirection - locRightNormalizedRatio * 1.5f + locUpNormalizedRatio * 1.5f;
	core::vector3df locTR = FDirection + locRightNormalizedRatio * 1.5f + locUpNormalizedRatio * 1.5f;
	core::vector3df locBR = FDirection + locRightNormalizedRatio * 1.5f - locUpNormalizedRatio * 1.7f;
	core::vector3df locBL = FDirection - locRightNormalizedRatio * 1.5f - locUpNormalizedRatio * 1.7f;

	core::vector3df locTLProj(0.f, -1.f, 0.f);
	core::vector3df locTRProj(0.f, -1.f, 0.f);
	core::vector3df locBRProj(0.f, -1.f, 0.f);
	core::vector3df locBLProj(0.f, -1.f, 0.f);

	if (FastAbs(locTL.Y) > core::EPSILON) locTLProj = FPosition - locTL * (FPosition.Y) / locTL.Y;
	if (FastAbs(locTR.Y) > core::EPSILON) locTRProj = FPosition - locTR * (FPosition.Y) / locTR.Y;
	if (FastAbs(locBR.Y) > core::EPSILON) locBRProj = FPosition - locBR * (FPosition.Y) / locBR.Y;
	if (FastAbs(locBL.Y) > core::EPSILON) locBLProj = FPosition - locBL * (FPosition.Y) / locBL.Y;

	parBBox.AddPoint(locTLProj.X, locTLProj.Z);
	parBBox.AddPoint(locTRProj.X, locTRProj.Z);
	parBBox.AddPoint(locBRProj.X, locBRProj.Z);
	parBBox.AddPoint(locBLProj.X, locBLProj.Z);
}

} // namespace video
} // namespace engine
} // namespace psp


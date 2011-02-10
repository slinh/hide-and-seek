#ifndef CAMERA_H
#define CAMERA_H

#include "config.h"
#include "vector3d.h"
#include "Character.h"

using namespace std;

struct ScePspFVector3;

namespace psp { namespace engine { namespace video {

#define CAMERA_HEIGHT 0.9002f
#define CAMERA_DISTANCE 0.9001f

class TCamera
{
public:
	TCamera();
	~TCamera();

	void InitCamera(const game::ICharacter* parTarget);
	void Update();

#ifdef COMPILE_PSP
	void CopyLookAt(ScePspFVector3& parEye, ScePspFVector3& parTarget, ScePspFVector3& parUp) const;
#endif
	void RotateTheta(const f32& parAngle, bool parRelative = false);
	void RotatePhi(const f32& parAngle, bool parRelative = false);

	void MoveForward(const f32& parMovement);	
	void MoveTrans(const f32& parMovement);
	void MoveUp(const f32& parMovement);

	core::vector3df ConvertDirectionFromJoystick(const f32& parAnalogX, const f32& parAnalogY, bool parNormalize = true);
	void SetBehindTarget();

	void XZProjectionBoundingBox(bb2Df& parBBox);

	// Getter
	GETTER(core::vector3df, RightInView)
	GETTER_SETTER(core::vector3df, Position)
	GETTER_SETTER(core::vector3df, Direction)
	GETTER(f32, Fovy)
	GETTER(f32, Aspect)
	GETTER(f32, Near)
	GETTER(f32, Far)

	GETTER(f32, Theta)

private:	
	void NormalizeDirection();
	void UpdateTheta();

	core::vector3df FPosition;
	core::vector3df FDirection;
	f32 FHeight;
	f32 FDistance;

	core::vector3df FUp;
	core::vector3df FUpInView;
	core::vector3df FRightInView;
	core::vector3df FRotation;

	f32 FFovy;
	f32 FAspect;
	f32 FNear;
	f32 FFar;

	f32 FTheta;

	const game::ICharacter* FAim; // Camera target
};

} // namespace video
} // namespace engine
} // namespace psp

#endif

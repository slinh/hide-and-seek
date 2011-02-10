#include "Transform.h"

namespace psp { namespace engine { namespace video {

TTransform::TTransform() : FTranslation(), FRotation()
{}

TTransform::TTransform(c8** parBuffer) : FTranslation(), FRotation()
{
	Deserialize(parBuffer);
}

TTransform::TTransform(const vector3df &parTranslation, const vector3df &parRotation) : FTranslation(parTranslation), FRotation(parRotation)
{}

TTransform::TTransform(const TTransform& parTransform) : 
FTranslation(parTransform.GetTranslation()),
FRotation(parTransform.GetRotation())
{}

TTransform::~TTransform()
{}

bb2Df& TTransform::ApplyTransform(bb2Df &parBBox) const
{
	parBBox.Translate(FTranslation);

	// TODO : Do Y axis reverse in mesh export or use another method if it don't work but don't do it like that
	// its better to externalize axis rotation inversion
	vector3df locCenter(FTranslation.X, FTranslation.Y, FTranslation.Z);
	vector3df locRotation(FRotation.X, -FRotation.Y, FRotation.Z);
	parBBox.Rotate(locRotation, locCenter);

	return parBBox;
}

u32 TTransform::SerializedSize()
{
	return 6 * sizeof(f32);
}

void TTransform::Serialize(c8** parBuffer)
{
	SERIALIZE(*parBuffer, f32, FTranslation.X);
	SERIALIZE(*parBuffer, f32, FTranslation.Y);
	SERIALIZE(*parBuffer, f32, FTranslation.Z);
	SERIALIZE(*parBuffer, f32, FRotation.X);
	SERIALIZE(*parBuffer, f32, FRotation.Y);
	SERIALIZE(*parBuffer, f32, FRotation.Z);
}

void TTransform::Deserialize(c8** parBuffer)
{
	FTranslation.X = DESERIALIZE(*parBuffer, f32);
	FTranslation.Y = DESERIALIZE(*parBuffer, f32);
	FTranslation.Z = DESERIALIZE(*parBuffer, f32);
	FRotation.X = DESERIALIZE(*parBuffer, f32);
	FRotation.Y = DESERIALIZE(*parBuffer, f32);
	FRotation.Z = DESERIALIZE(*parBuffer, f32);
}

} // engine video
} // engine namespace
} // psp namespace

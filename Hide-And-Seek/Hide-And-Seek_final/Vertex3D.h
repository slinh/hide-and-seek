#ifndef VERTEX_3D_H
#define VERTEX_3D_H

#include "Color.h"
#include "WriteFile.h"
#include "ReadFile.h"
#include "Logger.h"

namespace psp { namespace engine { namespace video {

struct TVertex3DC
{
	f32 U, V;
	TColor Color;
	f32 NX, NY, NZ;
	f32 X, Y, Z;

	TVertex3DC():
	U(0.f), V(0.f),
	Color(255, 0, 0, 0),
	NX(0.f), NY(0.f), NZ(0.f),
	X(0.f), Y(0.f), Z(0.f)
	{}

	TVertex3DC(const TColor& parColor):
	U(0.f), V(0.f),
	Color(parColor),
	NX(0.f), NY(0.f), NZ(0.f),
	X(0.f), Y(0.f), Z(0.f)
	{}

	TVertex3DC(c8** parBuffer):
		U(0.f), V(0.f),
		Color(255, 0, 0, 0),
		NX(0.f), NY(0.f), NZ(0.f),
		X(0.f), Y(0.f), Z(0.f)
	{
		Deserialize(parBuffer);
	}

	TVertex3DC& operator =(const TVertex3DC& parVertex)
	{
		U = parVertex.U;
		V = parVertex.V;
		Color = parVertex.Color;
		NX = parVertex.NX;
		NY = parVertex.NY;
		NZ = parVertex.NZ;
		X = parVertex.X;
		Y = parVertex.Y;
		Z = parVertex.Z;

		return *this;
	}

	static u32 SerializedSize()
	{
		return 8 * sizeof(f32) + sizeof(s32);
	}

	void Serialize(c8** parBuffer)
	{
		SERIALIZE(*parBuffer, f32, U);
		SERIALIZE(*parBuffer, f32, V);
		SERIALIZE(*parBuffer, s32, Color.FColor);
		SERIALIZE(*parBuffer, f32, NX);
		SERIALIZE(*parBuffer, f32, NY);
		SERIALIZE(*parBuffer, f32, NZ);
		SERIALIZE(*parBuffer, f32, X);
		SERIALIZE(*parBuffer, f32, Y);
		SERIALIZE(*parBuffer, f32, Z);
	}

	void Deserialize(c8** parBuffer)
	{
		U = DESERIALIZE(*parBuffer, f32);
		V = DESERIALIZE(*parBuffer, f32);
		Color.FColor = DESERIALIZE(*parBuffer, s32);
		NX = DESERIALIZE(*parBuffer, f32);
		NY = DESERIALIZE(*parBuffer, f32);
		NZ = DESERIALIZE(*parBuffer, f32);
		X = DESERIALIZE(*parBuffer, f32);
		Y = DESERIALIZE(*parBuffer, f32);
		Z = DESERIALIZE(*parBuffer, f32);
	}
};

struct TVertex3D
{
	f32 U, V;
	f32 NX, NY, NZ;
	f32 X, Y, Z;

	TVertex3D():
	U(0.f), V(0.f),
	NX(0.f), NY(0.f), NZ(0.f),
	X(0.f), Y(0.f), Z(0.f)
	{}

	TVertex3D(c8** parBuffer):
		U(0.f), V(0.f),
		NX(0.f), NY(0.f), NZ(0.f),
		X(0.f), Y(0.f), Z(0.f)
	{
		Deserialize(parBuffer);
	}

	TVertex3D& operator =(const TVertex3D& parVertex)
	{
		U = parVertex.U;
		V = parVertex.V;
		NX = parVertex.NX;
		NY = parVertex.NY;
		NZ = parVertex.NZ;
		X = parVertex.X;
		Y = parVertex.Y;
		Z = parVertex.Z;

		return *this;
	}

	static u32 SerializedSize()
	{
		return 8 * sizeof(f32);
	}

	void Serialize(c8** parBuffer)
	{
		SERIALIZE(*parBuffer, f32, U);
		SERIALIZE(*parBuffer, f32, V);
		SERIALIZE(*parBuffer, f32, NX);
		SERIALIZE(*parBuffer, f32, NY);
		SERIALIZE(*parBuffer, f32, NZ);
		SERIALIZE(*parBuffer, f32, X);
		SERIALIZE(*parBuffer, f32, Y);
		SERIALIZE(*parBuffer, f32, Z);
	}

	void Deserialize(c8** parBuffer)
	{
		U = DESERIALIZE(*parBuffer, f32);
		V = DESERIALIZE(*parBuffer, f32);
		NX = DESERIALIZE(*parBuffer, f32);
		NY = DESERIALIZE(*parBuffer, f32);
		NZ = DESERIALIZE(*parBuffer, f32);
		X = DESERIALIZE(*parBuffer, f32);
		Y = DESERIALIZE(*parBuffer, f32);
		Z = DESERIALIZE(*parBuffer, f32);
	}
};

} // namespace video
} // namespace engine
} // namespace psp

#endif

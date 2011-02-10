#ifndef MESH_BUFFER_H
#define MESH_BUFFER_H

#include "config.h"
#include "engineArray.h"
#include "Vertex3D.h"
#include "Material.h"
#include "BoundingBox2D.h"
#include "WriteFile.h"

#define X_AXIS 1
#define Y_AXIS 2
#define Z_AXIS 4

namespace psp {namespace engine { 
	
	using namespace io;
	
	namespace video {

struct TMeshBuffer
{
	TMeshBuffer();
	TMeshBuffer(const TMeshBuffer& parMesh);
	TMeshBuffer(TVertex3D* parVertexList, const u32& parVertexCount, const core::array<u16>& parIndexList = core::array<u16>(), u8 parAxis = (X_AXIS|Z_AXIS));
	~TMeshBuffer();

	GETTER_SETTER(bb2Df, BBox2D)
	GETTER_PTR(TVertex3D, VertexList)
	GETTER(u32, VertexCount);
	GETTER(core::array<u16>, IndexList)

	//! Create TVertex3D array list
	TVertex3D* CreateArrayList(const core::array<TVertex3D>& parVertices, u8 parAxis = (X_AXIS|Z_AXIS));
	TVertex3D* CreateArrayList_WithBBox(const core::array<TVertex3D>& parVertices, const bb2Df& parBBox);
	TVertex3D* CreateArrayList_WithSamePointer(const core::array<TVertex3D>& parVertices, u8 parAxis = (X_AXIS|Z_AXIS));
	TVertex3D* CreateArrayList_WithBBoxAndSamePointer(const core::array<TVertex3D>& parVertices, const bb2Df& parBBox);

	void Load(const core::array<TVertex3D>& parVertexList, const core::array<u16>& parIndexList = core::array<u16>(), u8 parAxis = (X_AXIS|Z_AXIS));
	void Load_WithSamePointer(core::array<TVertex3D>& parVertexList, const core::array<u16>& parIndexList, u8 parAxis = (X_AXIS|Z_AXIS));

	TMaterial								FMaterial;
	bb2Df									FBBox2D;
#if defined(COMPILE_PSP)
	TVertex3D* __attribute__((aligned(16))) FVertexList;
#elif defined(COMPILE_PC)
	TVertex3D*	FVertexList;
#endif
	u32										FVertexCount;
	core::array<u16>						FIndexList;

	// Cannot copy a meshBuffer because a new must be necessary to create a copy of vertex
	//NON_COPYABLE(TMeshBuffer)
};

} // namespace video
} // namespace engine
} // namespace psp

#endif


#include "Common.h"
#include "MeshBuffer.h"

namespace psp {namespace engine { namespace video {

TMeshBuffer::TMeshBuffer():
FVertexList(NULL), FVertexCount(0)
{}

TMeshBuffer::TMeshBuffer(const TMeshBuffer& parMesh):
FMaterial(parMesh.FMaterial), FBBox2D(parMesh.FBBox2D),
FVertexList(parMesh.FVertexList), FVertexCount(parMesh.FVertexCount),
FIndexList(parMesh.FIndexList)
{}

// TO DO : define this function
TMeshBuffer::TMeshBuffer(TVertex3D* parVertexList, const u32& parVertexCount, const core::array<u16>& parIndexList, u8 parAxis):
	FVertexList(parVertexList), FVertexCount(parVertexCount), FIndexList(parIndexList)
{
	bb2Df locBBox;

	if(parIndexList.size() == 0)
		for(u32 i=0; i<parVertexCount; ++i)
			locBBox.AddPoint(parVertexList[i].X, parVertexList[i].Z);
	else
	{
		f32 locSecond = 0.f;

		for(u32 i=0; i<parIndexList.size(); ++i)
		{
			if(parAxis & Y_AXIS)
				locSecond = parVertexList[parIndexList[i]].Y;
			else if(parAxis & Z_AXIS)
				locSecond = parVertexList[parIndexList[i]].Z;

			locBBox.AddPoint(parVertexList[parIndexList[i]].X, locSecond);
		}
	}

	FBBox2D = locBBox;
}

TMeshBuffer::~TMeshBuffer()
{
#if defined(COMPILE_PSP) /*|| defined(COMPILE_TOOLS)*/
	if(FVertexList != NULL)
		delete FVertexList;

	FIndexList.clear();
#else
#pragma message ("WARNING!!! " __FILE__" : DONT FORGET TO RESOLVE THIS DELETE PROBLEM!!! ")
	FIndexList.clear();
#endif
}

TVertex3D* TMeshBuffer::CreateArrayList(const core::array<TVertex3D>& parVertices, u8 parAxis)
{
	// We suppose here that to fast up loading 
	// user fill itself indexList instead give it in param
	LAssert(parVertices.size() > 0);

	FVertexCount = parVertices.size();

	if(FVertexList == NULL)
		FVertexList = NEW_IN_DOMAIN(Video) TVertex3D[FVertexCount];
	else
	{
		delete FVertexList;
		FVertexList = NEW_IN_DOMAIN(Video) TVertex3D[FVertexCount];
	}

	f32 locSecond = 0.f;

	for(u32 i=0; i<FVertexCount; ++i)
	{
		FVertexList[i] = parVertices[i];

		if(parAxis & Y_AXIS)
		{
			locSecond = FVertexList[i].Y;
		}
		else if(parAxis & Z_AXIS)
		{
			locSecond = FVertexList[i].Z;
		}

		FBBox2D.AddPoint(FVertexList[i].X, locSecond);
	}

	return FVertexList;
}

TVertex3D* TMeshBuffer::CreateArrayList_WithBBox(const core::array<TVertex3D>& parVertices, const bb2Df& parBBox)
{
	// We suppose here that to fast up loading 
	// user fill itself indexList instead give it in param
	LAssert(parVertices.size() > 0);

	FVertexCount = parVertices.size();

	if(FVertexList == NULL)
		FVertexList = NEW_IN_DOMAIN(Video) TVertex3D[FVertexCount];
	else
	{
		delete FVertexList;
		FVertexList = NEW_IN_DOMAIN(Video) TVertex3D[FVertexCount];
	}

	FBBox2D = parBBox;

	return FVertexList;
}


TVertex3D* TMeshBuffer::CreateArrayList_WithSamePointer(const core::array<TVertex3D>& parVertices, u8 parAxis)
{
	// We suppose here that to fast up loading 
	// user fill itself indexList instead give it in param
	LAssert(parVertices.size() > 0);

	FVertexCount = parVertices.size();

	
	FVertexList = const_cast<TVertex3D*>(parVertices.const_pointer());

	f32 locSecond = 0.f;

	for(u32 i=0; i<FVertexCount; ++i)
	{
		FVertexList[i] = parVertices[i];

		if(parAxis & Y_AXIS)
		{
			locSecond = FVertexList[i].Y;
		}
		else if(parAxis & Z_AXIS)
		{
			locSecond = FVertexList[i].Z;
		}

		FBBox2D.AddPoint(FVertexList[i].X, locSecond);
	}

	return FVertexList;
}

TVertex3D* TMeshBuffer::CreateArrayList_WithBBoxAndSamePointer(const core::array<TVertex3D>& parVertices, const bb2Df& parBBox)
{
	// We suppose here that to fast up loading 
	// user fill itself indexList instead give it in param
	LAssert(parVertices.size() > 0);

	FVertexCount = parVertices.size();

	FVertexList = const_cast<TVertex3D*>(parVertices.const_pointer());

	FBBox2D = parBBox;

	return FVertexList;
}

void TMeshBuffer::Load(const core::array<TVertex3D>& parVertexList, const core::array<u16>& parIndexList, u8 parAxis)
{
	CreateArrayList(parVertexList, parAxis);
	FIndexList = parIndexList;
}

void TMeshBuffer::Load_WithSamePointer(core::array<TVertex3D>& parVertexList, const core::array<u16>& parIndexList, u8 parAxis)
{
	parVertexList.set_free_when_destroyed(false);
	CreateArrayList_WithSamePointer(parVertexList, parAxis);

	FIndexList = parIndexList;
}

} // namespace video
} // namespace engine
} // namespace psp

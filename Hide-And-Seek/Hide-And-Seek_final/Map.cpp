#include "Map.h"
#include "ReadFile.h"
#include "WriteFile.h"
#include "Alloc.h"
#include "WorldConstantes.h"

namespace psp { namespace engine { 
	using namespace io;

	namespace object {

TMap::TMap()
{
	FWidth = 1;
	FHeight = 1;
}

TMap::TMap(s32 parWidth, s32 parHeight)
{
	LAssert(parWidth*parHeight > 0);
	FWidth = parWidth;
	FHeight = parHeight;
}

TMap::~TMap()
{
	for (u32 i=0; i<FMeshResources.size(); ++i)
	{
		delete FMeshResources[i];
	}
}

TMeshResource* TMap::AddMeshResource(const c8* parFileName, u32 parProperties, array<TTransform> &parTransform)
//TMeshResource* TMap::AddMeshResource(const c8* parFileName, u32 parProperties, const array<TTransform> &parTransform)
{
	LAssert(parFileName);
	LAssert(parTransform.size() > 0);

	TMeshResource* locRes = NEW_IN_DOMAIN(Map) TMeshResource(parFileName, parProperties, parTransform);
	FMeshResources.push_back(locRes);
	//locRes->FId = FMeshResources.size() - 1;

	//LOGC_LOAD("BBoxWorld before adapt L %3.2f R %3.2f T %3.2f B %3.2f : ", FBBoxWorld.GetLeft(), FBBoxWorld.GetRight(), FBBoxWorld.GetTop(), FBBoxWorld.GetBottom());
	for (u32 i=0; i<locRes->FBBox2Df.size(); ++i)
	{
		if(FBBoxWorld.IsInit())
		{
			//LOGC_LOAD("Already Init\n");
			//LOGC_LOAD("\t try to add L %3.2f R %3.2f T %3.2f B %3.2f \n", locRes->FBBox2Df[i].GetLeft(), locRes->FBBox2Df[i].GetRight(), locRes->FBBox2Df[i].GetTop(), locRes->FBBox2Df[i].GetBottom());
			FBBoxWorld.AdaptWith(locRes->FBBox2Df[i]);
		}
		else
		{
			//LOGC_LOAD("Not Init\n");
			//LOGC_LOAD("\t try to add L %3.2f R %3.2f T %3.2f B %3.2f \n", locRes->FBBox2Df[i].GetLeft(), locRes->FBBox2Df[i].GetRight(), locRes->FBBox2Df[i].GetTop(), locRes->FBBox2Df[i].GetBottom());
			FBBoxWorld = locRes->FBBox2Df[i];
		}
	}
	//LOGC_LOAD("BBoxWorld after adapt L %3.2f R %3.2f T %3.2f B %3.2f :\n\n", FBBoxWorld.GetLeft(), FBBoxWorld.GetRight(), FBBoxWorld.GetTop(), FBBoxWorld.GetBottom());
	
	return locRes;
}

TMeshResource* TMap::AddMeshResource(TMeshResource* parMesh)
{
	LAssert(parMesh);
	LAssert(parMesh->GetNbBBox2Df() > 0);

	FMeshResources.push_back(parMesh);

	for (u32 i=0; i<parMesh->FBBox2Df.size(); ++i)
	{
		if(FBBoxWorld.IsInit())
		{
			FBBoxWorld.AdaptWith(parMesh->FBBox2Df[i]);
		}
		else
		{
			FBBoxWorld = parMesh->FBBox2Df[i];
		}
	}
	
	return parMesh;
}

void TMap::SetSubdivisionSize(s32 parWidth, s32 parHeight)
{
	//LOGC_LOAD("draw level %d %d\n", parWidth, parHeight);
	LAssert(parWidth*parHeight > 0);
	FWidth = parWidth;
	FHeight = parHeight;

	CreateLevelBlocksWithMeshId_WithRealloc_AndAutoId();

	LAssert((u32)(parWidth*parHeight) == FBlocksMeshIds.size());
}

array<int2> TMap::GetCornersForBoundingBox(u32 &parIdResource, u32 &parIdBBox)
{	
	LAssert(parIdResource < FMeshResources.size());
	LAssert(parIdBBox < FMeshResources[parIdResource]->FBBox2Df.size());
	LAssert(FBBoxWorld.IsInit());
	bb2Df locBBox = FMeshResources[parIdResource]->FBBox2Df[parIdBBox];
	LAssert(locBBox.IsInit());

	array<float2> locCoordinates;
	array<int2> locCorners(4);
	
	//LOGC_LOAD("\t\tBBox L %3.2f R %3.2f T %3.2f B %3.2f :\n", locBBox.GetLeft(), locBBox.GetRight(), locBBox.GetTop(), locBBox.GetBottom());

	// Store 4 coordinates of Mesh bounding box
	// in this order : TopLeft, TopRight, BottomLeft, BottomRight
	locCoordinates.push_back(float2(locBBox.GetLeft(), locBBox.GetTop()));
	locCoordinates.push_back(float2(locBBox.GetRight(), locBBox.GetTop()));
	locCoordinates.push_back(float2(locBBox.GetLeft(), locBBox.GetBottom()));
	locCoordinates.push_back(float2(locBBox.GetRight(), locBBox.GetBottom()));

	f32 locWorldWidth = FBBoxWorld.GetRight() - FBBoxWorld.GetLeft();
	f32 locWorldHeight = FBBoxWorld.GetTop() - FBBoxWorld.GetBottom();

	//LOGC_LOAD("\t\tBBox L %3.2f R %3.2f T %3.2f B %3.2f :\n", FBBoxWorld.GetLeft(), FBBoxWorld.GetRight(), FBBoxWorld.GetTop(), FBBoxWorld.GetBottom());
	
	s32 coordi;
	s32 coordj;

	for(u32 i=0; i<locCoordinates.size(); ++i)
	{
		// TO DO : verify if this assert is necessary
		LAssert( ROUND(FBBoxWorld.GetTop() - locCoordinates[i].Y) <= ceil(locWorldHeight) );
		LAssert( ROUND(locCoordinates[i].X - FBBoxWorld.GetLeft()) <= ceil(locWorldWidth) );
		
		//LOGC_LOAD("BBoxWorld L %3.2f R %3.2f T %3.2f B %3.2f\n", FBBoxWorld.GetLeft(), FBBoxWorld.GetRight(), FBBoxWorld.GetTop(), FBBoxWorld.GetBottom());

		f32 locPercentX = (locCoordinates[i].X - FBBoxWorld.GetLeft()) / locWorldWidth;
		f32 locPercentY = (FBBoxWorld.GetTop() - locCoordinates[i].Y) / locWorldHeight;	
		LOGC_LOAD("");
		LAssert( !EQUALS(locWorldWidth, 0.f));
		LAssert( !EQUALS(locWorldHeight, 0.f));

		//LOGC_LOAD("\t\t\tpercent : %3.2f %3.2f\n", locPercentX, locPercentY);
		
		if(locPercentX > 1.f)
			locPercentX =  1.f;

		if(locPercentY > 1.f)
			locPercentY = 1.f;

		//LOGC_LOAD("\t\t\tpercent : %3.2f %3.2f\n", locPercentX, locPercentY);
		coordi = (s32)(locPercentY*FWidth);
		coordj = (s32)(locPercentX*FHeight);
	
		if(i<2)
			coordi = ROUND(floor(locPercentY*FWidth));
		else
			coordi = ROUND(ceil(locPercentY*FWidth))-1;

		if(!(i&1))
			coordj = ROUND(floor(locPercentX*FHeight));
		else
			coordj = ROUND(ceil(locPercentX*FHeight))-1;

		//LOGC_LOAD("\t\t\tcoord bef clamp : %d %d\n", coordi, coordj);
		// TO DO : Look if this clamp is really necessary
		if(coordi < 0)
			coordi = 0;

		if(coordj < 0)
			coordj = 0;

		if(coordi >= (s32)FHeight) 
			coordi = FHeight-1;

		if(coordj >= (s32)FWidth)
			coordj = FWidth-1;

		//LOGC_LOAD("\t\t\tcoord aft clamp : %d %d\n\n", coordi, coordj);
	
		LAssert(coordi < (s32)FHeight);
		LAssert(coordj < (s32)FWidth);		
		LAssert(coordi >= 0);
		LAssert(coordj >= 0);
		
		locCorners.push_back(int2(coordi, coordj));
	}

	return locCorners;
}

#define TEMP_SCALE 10

array<int2> TMap::GetCornersForBoundingBox_WithClamp(bb2Df& parBBox)
{	
	LAssert(FBBoxWorld.IsInit());
	LAssert(parBBox.IsInit());

	// Clamp
	if (FBBoxWorld.GetTop() < parBBox.GetTop()) parBBox.SetTop() = FBBoxWorld.GetTop();
	if (FBBoxWorld.GetBottom() > parBBox.GetBottom()) parBBox.SetBottom() = FBBoxWorld.GetBottom();
	if (FBBoxWorld.GetRight() < parBBox.GetRight()) parBBox.SetRight() = FBBoxWorld.GetRight();
	if (FBBoxWorld.GetLeft() > parBBox.GetLeft()) parBBox.SetLeft() = FBBoxWorld.GetLeft();

	array<float2> locCoordinates;
	array<int2> locCorners(4);
	
	// Store 4 coordinates of Mesh bounding box
	// in this order : TopLeft, TopRight, BottomLeft, BottomRight
	locCoordinates.push_back(float2(parBBox.GetLeft(), parBBox.GetTop()));
	locCoordinates.push_back(float2(parBBox.GetRight(), parBBox.GetTop()));
	locCoordinates.push_back(float2(parBBox.GetLeft(), parBBox.GetBottom()));
	locCoordinates.push_back(float2(parBBox.GetRight(), parBBox.GetBottom()));

	f32 locWorldWidth = FBBoxWorld.GetRight() - FBBoxWorld.GetLeft();
	f32 locWorldHeight = FBBoxWorld.GetTop() - FBBoxWorld.GetBottom();

	s32 coordi;
	s32 coordj;

	for(u32 i=0; i<locCoordinates.size(); ++i)
	{
		f32 locPercentX = (locCoordinates[i].X - FBBoxWorld.GetLeft()) / locWorldWidth;
		f32 locPercentY = (FBBoxWorld.GetTop() - locCoordinates[i].Y) / locWorldHeight;	
		LOGC_LOAD("");
		LAssert( !EQUALS(locWorldWidth, 0.f));
		LAssert( !EQUALS(locWorldHeight, 0.f));
		
		if(locPercentX > 1.f)
			locPercentX =  1.f;

		if(locPercentY > 1.f)
			locPercentY = 1.f;

		coordi = (s32)(locPercentY*FWidth);
		coordj = (s32)(locPercentX*FHeight);
	
		if(i<2)
			coordi = ROUND(floor(locPercentY*FWidth));
		else
			coordi = ROUND(ceil(locPercentY*FWidth))-1;

		if(!(i&1))
			coordj = ROUND(floor(locPercentX*FHeight));
		else
			coordj = ROUND(ceil(locPercentX*FHeight))-1;

		// TO DO : Look if this clamp is really necessary
		if(coordi < 0)
			coordi = 0;

		if(coordj < 0)
			coordj = 0;

		if(coordi >= (s32)FHeight) 
			coordi = FHeight - 1;

		if(coordj >= (s32)FWidth)
			coordj = FWidth - 1;

		LAssert(coordi < (s32)FHeight);
		LAssert(coordj < (s32)FWidth);		
		LAssert(coordi >= 0);
		LAssert(coordj >= 0);
		
		locCorners.push_back(int2(coordi, coordj));
	}

	return locCorners;
}

void TMap::CreateLevelBlocksWithMeshId_WithRealloc_AndAutoId()
{
	//LOGC_LOAD("Step CLBWMIWRAA 1\n");
	LAssert(FWidth*FHeight > 0);
	FBlocksMeshIds.clear();
	FBlocksMeshIds.reallocate(FWidth*FHeight);
	
	//LOGC_LOAD("Step CLBWMIWRAA 2 %d %d\n", FWidth, FHeight);
	for(u32 i=0; i<FWidth*FHeight; ++i)
		FBlocksMeshIds.push_back(array< pair<u32,u32> >());
	//LOGC_LOAD("Step CLBWMIWRAA 3\n", FWidth, FHeight);
	
	//LOGC_LOAD("BBoxWorlD on  level creation L %3.2f R %3.2f T %3.2f B %3.2f :\n", FBBoxWorld.GetLeft(), FBBoxWorld.GetRight(), FBBoxWorld.GetTop(), FBBoxWorld.GetBottom());
	for (u32 locIdResource=0; locIdResource < FMeshResources.size(); ++locIdResource)
	{
		//LOGC_LOAD("EXAMINE Mesh %d:\n", locIdResource);
		LAssert(FMeshResources[locIdResource]->GetNbBBox2Df() > 0);
		
		for (u32 locIdBBox=0; locIdBBox<FMeshResources[locIdResource]->FBBox2Df.size(); ++locIdBBox)
		{
			
			//LOGC_LOAD("\tGet corners for BBox%d \n", locIdBBox);
			// Points are stored in this order : TopLeft, TopRight, BottomLeft, BottomRight
			array<int2> locCorners = GetCornersForBoundingBox(locIdResource, locIdBBox);	
			//LOGC_LOAD("\tGet corners success\n");
			//*
			for(u32 i=locCorners[0].X; i<=(u32)locCorners[2].X; ++i)
			{
				for(u32 j=locCorners[0].Y; j<=(u32)locCorners[1].Y; ++j)
				{
					pair<u32,u32> locIds;
					locIds.first = locIdResource;
					locIds.second = locIdBBox;
					LAssert(FBlocksMeshIds[i*FWidth + j].binary_search(locIds) == -1);
					//LOGC_LOAD("Add a mesh %d in block %d %d\n", locIdResource, i, j);
					FBlocksMeshIds[i*FWidth + j].push_back(locIds);
				}
			}
			//*/
		}
	}
	//LOGC_LOAD("Step CLBWMIWRAA 4\n");
}

void TMap::SaveMap(const c8* parOutputFile)
{
	//CreateLevelBlocksWithMeshId_WithRealloc_AndAutoId();

	LAssert(FWidth*FHeight > 0);
	LAssert(parOutputFile);

	//print("Saving %s\n", parOutputFile);

	// calcul de la taille du buffer
	u32 locBufSize = strlen(MAP_VERSION_ID) + sizeof(u32);
	for(u32 locIdResource=0; locIdResource < FMeshResources.size(); ++locIdResource)
		locBufSize += FMeshResources[locIdResource]->SerializedSize();
	locBufSize += 2 * sizeof(u32);

	c8* locBuffer = NEW_IN_DOMAIN(Map) c8[locBufSize];
	c8* locBufferStart = locBuffer;

	// Map creation
	// Writing of file ID
	for (u32 i = 0; i<strlen(MAP_VERSION_ID); ++i)
		locBuffer[i] = MAP_VERSION_ID[i];
	locBuffer += strlen(MAP_VERSION_ID);
	
	// ---------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------

	// Writing Mesh ArrayList datas
	SERIALIZE(locBuffer, u32, FMeshResources.size());
	// Meshes datas
	for(u32 locIdResource=0; locIdResource < FMeshResources.size(); ++locIdResource)
		FMeshResources[locIdResource]->Serialize(&locBuffer);
	
	// ---------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------

	// Writing level blocks datas
	SERIALIZE(locBuffer, u32, FWidth);
	SERIALIZE(locBuffer, u32, FHeight);

	//u32 locSizeSerialized = locBuffer - locBufferStart;

	TWriteFile locOutput(parOutputFile, false, BINARY);
	locOutput.Write(locBufferStart, locBufSize);
	locOutput.Close();

	delete[] locBufferStart;
}

bool TMap::LoadMap(const c8* parIntputFile)
{
	LAssert(parIntputFile);

	//print("Saving %s\n", parIntputFile);

	TReadFile locFile(parIntputFile, BINARY);

	c8* locBuffer = NEW_IN_DOMAIN(Map) c8[locFile.GetSize()];
	locFile.Read(locBuffer, locFile.GetSize());
	c8* locBufferStart = locBuffer;
	locFile.Close();

	c8 S[5];
	S[4] = '\0';

	// Read FileID
	for (u8 i = 0; i<4; ++i) S[i] = locBuffer[i];
	locBuffer+=sizeof(c8)*4;
	if(strncmp(S, MAP_VERSION_ID, 4) != 0)
		return false;

	// ---------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------

	// Reading Mesh ArrayList datas
	// Number of Mesh
	u32 locNbMesh = DESERIALIZE(locBuffer,u32);
	//LOGC("Nombre de meshes : %d\n", locNbMesh);
	// Meshes datas
	FMeshResources.reallocate(locNbMesh);
	for(u32 i=0; i<locNbMesh; ++i)
		AddMeshResource(NEW_IN_DOMAIN(Map) TMeshResource(&locBuffer));

	//LOGC("All Mesh loaded");

	// ---------------------------------------------------------------------------------------------
	// ---------------------------------------------------------------------------------------------

	// Reading level blocks datas
	FWidth = DESERIALIZE(locBuffer,u32);
	FHeight = DESERIALIZE(locBuffer,u32);

	//LOGC("Witdh = %d, Height = %d\n", FWidth, FHeight);

	SetSubdivisionSize(FWidth, FHeight);

	//LOGC("Subdivision done\n");

	delete[] locBufferStart;

	//LOGC("Map loaded\n");

	return true;
}

void TMap::PrepareForDrawing()
{
	for(u32 i=0; i<FMeshResources.size(); ++i) {
		FMeshResources[i]->SetAllStates(NOT_DRAWN);
		FMeshResources[i]->SetAllCheckIAStates(NOT_CHECKIA);
	}
}

void TMap::Clear()
{
	FBlocksMeshIds.clear();

	for(u32 i=0; i<FMeshResources.size(); ++i)
	{
		delete FMeshResources[i];
	}

	FMeshResources.clear();
}

} // object namespace
} // engine namespace
} // psp namespace

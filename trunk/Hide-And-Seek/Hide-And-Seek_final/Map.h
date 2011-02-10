#ifndef MAP_H
#define MAP_H

#include "config.h"
#include "DrawingParameters.h"
#include "MeshResource.h"

using namespace std;
using namespace psp::engine::video;

namespace psp { namespace engine { namespace object {

class TMap
{
	/*	Fields	*/
private:
	u32 FWidth;
	u32 FHeight;
	array< array< pair<u32,u32> > > FBlocksMeshIds;
	bb2Df FBBoxWorld;
	array<TMeshResource*> FMeshResources;

	/*	Method	*/
public:
	TMap(void);
	TMap(s32 parWidth, s32 parHeight);
	~TMap(void);

	//TMeshResource* AddMeshResource(const c8* parFileName, bool parIsInteractive, const array<vector3df> &parTransform);
	TMeshResource* AddMeshResource(const c8* parFileName, u32 parProperties, array<TTransform> &parTransform);
	TMeshResource* AddMeshResource(TMeshResource* parMesh);
	void SetSubdivisionSize(s32 parWidth, s32 parHeight);
	void SaveMap(const c8* parOutputFile);
	bool LoadMap(const c8* parOutputFile);

	void PrepareForDrawing();

	GETTER(u32, Width);
	GETTER(u32, Height);
	GETTER(bb2Df, BBoxWorld)
	GETTER(array<TMeshResource*>, MeshResources)
	const array< array< pair<u32,u32> > >& GetBlocksMeshIds() const { return FBlocksMeshIds; }

	array<int2> GetCornersForBoundingBox(u32 &parIdResource, u32 &parIdBBox);
	array<int2> GetCornersForBoundingBox_WithClamp(bb2Df& parBBox);

	void Clear();
private:
	void CreateLevelBlocksWithMeshId_WithRealloc_AndAutoId();
};

} // object namespace
} // engine namespace
} // psp namespace

#endif

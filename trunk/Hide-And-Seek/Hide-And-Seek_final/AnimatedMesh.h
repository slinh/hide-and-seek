#ifndef ANIMATED_MESH_H
#define ANIMATED_MESH_H

#include "Mesh.h"

namespace psp { namespace engine { namespace object {

class IAnimatedMesh : public IMesh
{
public :
	VIRTUAL_DESTRUCTOR(IAnimatedMesh)

	//! Load a mesh from file parFile
	virtual bool Load(const c8* parFile, const c8* parOther = NULL)=0;

	//! Returns a boolean to tell if this mesh is already loaded
	virtual bool IsLoaded()=0;

	virtual u32 SerializedSize() = 0;
	virtual void Serialize(c8** parBuffer) = 0;
	virtual void Deserialize(c8** parBuffer) = 0;

	//! Returns mesh buffer
	virtual const video::TMeshBuffer& GetMeshBuffer(u32 parFrame=0) const=0;
	// Retrieve frame bounding box 2D
	virtual const bb2Df& Getbb2Df(u32 parFrame=0) const=0;
};

} // namespace object
} // namespace engine
} // namespace psp

#endif

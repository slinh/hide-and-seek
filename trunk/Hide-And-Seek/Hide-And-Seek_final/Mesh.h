#ifndef MESH_H
#define MESH_H

#include "config.h"
#include "Vertex3D.h"
#include "MeshBuffer.h"
#include "WriteFile.h"

namespace psp { namespace engine { 
	
	using namespace io;

	namespace object {

enum MESH_TYPE
{
	//! For unloaded models
	MT_UNKNOW,

	//! Quake 2 MD2 model type :	animated
	MT_MD2,

	//! Standard OBJ model type : not animated
	MT_OBJ
};

class IMesh
{
public :
	VIRTUAL_DESTRUCTOR(IMesh)

	//! Load a mesh from file parFile
	virtual bool Load(const c8* parFile, const c8* parOther = NULL)=0;

	//! Returns a boolean to tell if this mesh is already loaded
	virtual bool IsLoaded()=0;

	//! Returns type of loaded mesh
	virtual MESH_TYPE GetMeshType()
	{
		return MT_UNKNOW;
	}

	virtual u32 SerializedSize() = 0;
	virtual void Serialize(c8** parBuffer) = 0;
	virtual void Deserialize(c8** parBuffer) = 0;

	//! Returns mesh buffer
	virtual const video::TMeshBuffer& GetMeshBuffer(u32 parFrame=0) const=0;
	//! Return bounding box
	virtual const bb2Df& Getbb2Df(u32 parFrame=0) const=0;
};

} // namespace object
} // namespace engine
} // namespace psp

#endif

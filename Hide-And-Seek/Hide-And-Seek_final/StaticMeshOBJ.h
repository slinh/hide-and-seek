#ifndef STATIC_MESH_OBJ_H
#define STATIC_MESH_OBJ_H

#include "StaticMesh.h"
#include "MeshBuffer.h"
#include "WriteFile.h"
#include "ReadFile.h"

namespace psp { namespace engine { 
	
	using namespace io;
	
	namespace object {

class TStaticMeshOBJ : public IStaticMesh
{
public :
	TStaticMeshOBJ();
	TStaticMeshOBJ(video::TMeshBuffer& parMeshBuffer);
	~TStaticMeshOBJ();

	//! Load a mesh from file parFile
	bool Load(const char* parFile, const char* parOther = NULL);

	//! Returns a boolean to tell if this mesh is already loaded
	bool IsLoaded();
	const bb2Df& Getbb2Df(u32 parFrame=0) const;
	const video::TMeshBuffer& GetMeshBuffer(u32 parFrame=0) const { return FMeshBuffer; }

	virtual u32 SerializedSize();
	virtual void Serialize(c8** parBuffer);
	virtual void Deserialize(c8** parBuffer);

	//! Returns type of loaded mesh
	MESH_TYPE GetMeshType()
	{
		return MT_OBJ;
	}

	//! Free allocated memory inside this mesh
	void Free();

	SETTER(video::TMeshBuffer, MeshBuffer)

private:
	video::TMeshBuffer FMeshBuffer;

	// Cannot copy a mesh because a new is necessary in meshBuffer
	NON_COPYABLE(TStaticMeshOBJ)
};

} // object namespace
} // engine namespace
} // psp namespace

#endif

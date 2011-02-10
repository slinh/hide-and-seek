#ifndef ANIMATED_MESH_MD2_H
#define ANIMATED_MESH_MD2_H

#include "config.h"
#include "AnimatedMesh.h"
#include "MeshBuffer.h"
#include "Animation.h"

// ID "IDP2" ou 844121161
#define MD2_IDENT               (('2'<<24) + ('P'<<16) + ('D'<<8) + 'I')

// Version number
#define MD2_VERSION             8

// Predefined normals
#define NUMVERTEXNORMALS        162

namespace psp { namespace engine { namespace object {

// header md2
typedef struct
{
    s32 ident;          // numéro magique : "IDP2"
    s32 version;        // version du format : 8

    s32 skinwidth;      // largeur texture
    s32 skinheight;     // hauteur texture

    s32 framesize;      // taille d'une frame en octets

    s32 num_skins;      // nombre de skins
    s32 num_vertices;   // nombre de vertices par frame
    s32 num_st;         // nombre de coordonnées de texture
    s32 num_tris;       // nombre de triangles
    s32 num_glcmds;     // nombre de commandes opengl
    s32 num_frames;     // nombre de frames

    s32 offset_skins;   // offset données skins
    s32 offset_st;      // offset données coordonnées de texture
    s32 offset_tris;    // offset données triangles
    s32 offset_frames;  // offset données frames
    s32 offset_glcmds;  // offset données commandes OpenGL
    s32 offset_end;     // offset fin de fichier

} md2_header_t;

typedef f32 vec3_t[3];

// données vertex
typedef struct
{
    u8 v[3];         // position dans l'espace (relative au modèle)
    u8 normalIndex;  // index normale du vertex

} md2_vertex_t;

// données triangle
typedef struct
{
    u16 vertex[3];   // indices vertices du triangle
    u16 st[3];       // indices coordonnées de texture

} md2_triangle_t;

// coordonnées de texture
typedef struct
{
    s16 s;
    s16 t;

} md2_texCoord_t;

// données frame
typedef struct
{
    vec3_t          scale;      // redimensionnement
    vec3_t          translate;  // vecteur translation
    c8				name[16];   // nom de la frame
    md2_vertex_t    *verts;     // liste de vertices

} md2_frame_t;

// texture
typedef struct
{
    c8    name[68];    // nom du fichier texture

} md2_skin_t;

// MD2 CLASS

class TAnimatedMeshMD2 : public IAnimatedMesh
{
public :
	TAnimatedMeshMD2();
	~TAnimatedMeshMD2();

	//! Load a mesh from file parFile
	bool Load(const c8* parFile, const c8* parOther = NULL);
	bool Load(const c8* parFile, const c8* parOther, const f32& parScale, const engine::core::vector3df& parTranslate, const engine::core::vector3df& parRotate, const f32& parOffsetU, const f32& parOffsetV, const f32& parWidth, const f32& parHeight);
	bool Load(const c8* parFile, const c8* parOther, const f32& parScale, const engine::core::vector3df& parTranslate, const engine::core::vector3df& parRotate, const f32& parOffsetU, const f32& parOffsetV, const f32& parWidth, const f32& parHeight, const std::pair<u32, u32>& parFrames, const u32& parStaticFrame);
				
	//! Returns a boolean to tell if this mesh is already loaded
	bool IsLoaded();

	const video::TMeshBuffer& GetMeshBuffer(u32 parFrame=0) const;
	const bb2Df& Getbb2Df(u32 parFrame=0) const;

	GETTER(core::vector3df, Rotate)

	//! Returns type of loaded mesh
	MESH_TYPE GetMeshType()
	{
		return MT_MD2;
	}

	virtual u32 SerializedSize();
	virtual void Serialize(c8** parBuffer);
	virtual void Deserialize(c8** parBuffer);

	u32 GetNBFrame()
	{
		return FMeshBufferList.size();
	}

	//! Free allocated memory inside this mesh
	void Free();

	void UpdateAnimation();

private:
	// Parameters for MD2 model source : no necessary to store them
	static vec3_t						m_kAnorms[NUMVERTEXNORMALS];

	// Fields for transfo to applicate before rendering
	core::vector3df						FRotate;

	// Vertex information for MD2
	core::array<video::TMeshBuffer*>	FMeshBufferList;
	s32          						FFrameID;      // model texture ID

	TAnimation							FAnimation;
};

} // object namespace
} // engine namespace
} // psp namespace

#endif

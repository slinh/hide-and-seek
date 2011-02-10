#include "Common.h"
#include "AnimatedMeshMD2.h"

#include "ReadFile.h"
#include "Functions.h"
#include "vector2d.h"
#include "vector3d.h"
#include "fast_atof.h"

namespace psp { namespace engine { namespace object {

vec3_t TAnimatedMeshMD2::m_kAnorms[ NUMVERTEXNORMALS ] = 
{
	#include "anorms.h"
};

TAnimatedMeshMD2::TAnimatedMeshMD2():
FFrameID(0)
{}

TAnimatedMeshMD2::~TAnimatedMeshMD2()
{
	Free();
}

//! Load a mesh from file parFile
bool TAnimatedMeshMD2::Load(const c8* parFile, const c8* parOther)
{
	return Load(parFile, parOther, 1.f, engine::core::vector3df(0.f, 0.f, 0.f), engine::core::vector3df(0.f, 0.f, 0.f), 0, 0, 512, 512);
}

bool TAnimatedMeshMD2::Load(const c8* parFile, const c8* parOther, 
							const f32& parScale, const engine::core::vector3df& parTranslate, const engine::core::vector3df& parRotate,
							const f32& parOffsetU, const f32& parOffsetV, const f32& parWidth, const f32& parHeight)
{
	LAssert(parFile != NULL);
	LAssert(parOther != NULL);

	// MD2 parameters
	md2_header_t	m_kHeader;      // header md2
    md2_skin_t      *m_pSkins;      // skins datas
    md2_texCoord_t  *m_pTexCoords;  // textures coordinates
    md2_triangle_t  *m_pTriangles;  // triangles datas
    md2_frame_t     *m_pFrames;     // frames datas

	// Set rotate
	FRotate = parRotate;

	// Load anim 
	FAnimation.LoadAnim(parOther);

	io::TReadFile file(parFile);
	s32 filesize = (s32)file.GetSize();

	// Debug
	core::array< u16 > locIndexBuffer;
	video::TVertex3D locVertex;

    LAssert(filesize > 0);

    // lecture du header
    file.Read( (c8 *)&m_kHeader, sizeof( md2_header_t ) );

    // vérification de l'authenticité du modèle
    if( (m_kHeader.version != MD2_VERSION) || m_kHeader.ident != MD2_IDENT )
        return false;

    // allocation de mémoire pour les données du modèle
    m_pSkins = NEW_IN_DOMAIN(MD2) md2_skin_t[ m_kHeader.num_skins ];
    m_pTexCoords = NEW_IN_DOMAIN(MD2) md2_texCoord_t[ m_kHeader.num_st ];
    m_pTriangles = NEW_IN_DOMAIN(MD2) md2_triangle_t[ m_kHeader.num_tris ];
    m_pFrames = NEW_IN_DOMAIN(MD2) md2_frame_t[ m_kHeader.num_frames ];

    // lecture des noms de skins
    file.Seek( m_kHeader.offset_skins);
    file.Read( (c8 *)m_pSkins, sizeof( char ) * 68 * m_kHeader.num_skins );
	//LOGC_3D("Num skins : %d \n", m_kHeader.num_skins);

    // lecture des coordonnées de texture
    file.Seek( m_kHeader.offset_st);
    file.Read( (c8 *)m_pTexCoords, sizeof( md2_texCoord_t ) * m_kHeader.num_st );
	LOGC("Num tex coordinates : %d \n", m_kHeader.num_st);
	LOGC("Num vertices : %d \n", m_kHeader.num_vertices);

    // lecture des triangles
    file.Seek( m_kHeader.offset_tris);
    file.Read( (c8 *)m_pTriangles, sizeof( md2_triangle_t ) * m_kHeader.num_tris );
	//LOGC("Num triangles : %d \n", m_kHeader.num_tris);

	LOGC("Num frames : %d \n", m_kHeader.num_frames);

    // lecture des frames
    file.Seek( m_kHeader.offset_frames);
	// Set max frame, tris, vertices to boost reading
	s16 locMaxFrame = m_kHeader.num_frames;
	s16 locMaxTris = m_kHeader.num_tris;
	s16 locMaxVertices = m_kHeader.num_vertices;
	
    for(s16 iFrame=0; iFrame<locMaxFrame; ++iFrame)
    {
        // Allocate memory for vertices
        m_pFrames[iFrame].verts = NEW_IN_DOMAIN(MD2) md2_vertex_t[ m_kHeader.num_vertices ];

        // lecture des données de la frame
        file.Read( (c8*)&m_pFrames[iFrame].scale,		sizeof(vec3_t) );
        file.Read( (c8*)&m_pFrames[iFrame].translate,	sizeof(vec3_t) );
        file.Read( (c8*)&m_pFrames[iFrame].name,		sizeof(c8) * 16 );
        file.Read( (c8*)m_pFrames[iFrame].verts,		sizeof(md2_vertex_t) * m_kHeader.num_vertices );
		
		// Create MeshBuffer to store model datas
		locIndexBuffer.reset();

		// Store vertex frame for to index
		md2_frame_t* pFrame = &m_pFrames[ iFrame ];
		md2_vertex_t* pFrameVertices = pFrame->verts;
		TVertex3D* __attribute__((aligned(16))) locVertexList = NEW_IN_DOMAIN(MD2) TVertex3D[locMaxVertices];

		for(s32 i=0; i<locMaxVertices; ++i)
		{
			locVertexList[i].NX = m_kAnorms[ pFrameVertices[i].normalIndex ][0];
			locVertexList[i].NY = m_kAnorms[ pFrameVertices[i].normalIndex ][1];
			locVertexList[i].NZ = m_kAnorms[ pFrameVertices[i].normalIndex ][2];

			//*
			locVertexList[i].X = (pFrame->scale[0] * pFrameVertices[i].v[0] + pFrame->translate[0] + parTranslate.X) * parScale;
			locVertexList[i].Y = (pFrame->scale[1] * pFrameVertices[i].v[1] + pFrame->translate[1] + parTranslate.Y) * parScale;
			locVertexList[i].Z = (pFrame->scale[2] * pFrameVertices[i].v[2] + pFrame->translate[2] + parTranslate.Z) * parScale;
			//*/
			/*
			locVertexList[i].X = (pFrame->scale[0] * pFrameVertices[i].v[0]) * parScale;
			locVertexList[i].Y = (pFrame->scale[1] * pFrameVertices[i].v[1]) * parScale;
			locVertexList[i].Z = (pFrame->scale[2] * pFrameVertices[i].v[2]) * parScale;
			//*/
		}
		
		for(s32 i=0; i<locMaxTris; ++i)
		{	
			// Draw each triangle vertice
			for(s32 k=0; k<3; ++k)
			{
				u32 index = m_pTriangles[i].vertex[k];
				//*
				locVertexList[index].U = ((f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].s) / m_kHeader.skinwidth) * parWidth + parOffsetU;
				//locVertexList[index].V = BLOffsetV - (((f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].t) / m_kHeader.skinheight) * parHeight);
				locVertexList[index].V = ((f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].t) / m_kHeader.skinheight) * parHeight + parOffsetV;
				//*/
				/*
				locVertexList[index].U = (f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].s) / m_kHeader.skinwidth;
				locVertexList[index].V = (f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].t) / m_kHeader.skinheight;
				//*/

				locIndexBuffer.push_back(m_pTriangles[i].vertex[k]);
			}
		}

		TMeshBuffer* locMeshBuffer = NEW_IN_DOMAIN(MD2) TMeshBuffer(locVertexList, locMaxVertices, locIndexBuffer, X_AXIS|Y_AXIS);
		FMeshBufferList.push_back(locMeshBuffer);
		
		delete m_pFrames[iFrame].verts;
    }

	//LOGC("Total MD2 model size %d Ko\n", (FMeshBufferList.size() * ((FMeshBufferList[0])->GetVertexCount()) * sizeof(TVertex3D)) / 1024 );

	file.Close();

	// Free alocated memory for MD2 reading
	delete m_pSkins;
    delete m_pTexCoords;
    delete m_pTriangles;
    delete m_pFrames;

	return true;
}

bool TAnimatedMeshMD2::Load(const c8* parFile, const c8* parOther, 
							const f32& parScale, const engine::core::vector3df& parTranslate, const engine::core::vector3df& parRotate,
							const f32& parOffsetU, const f32& parOffsetV, const f32& parWidth, const f32& parHeight,
							const std::pair<u32, u32>& parFrames, const u32& parStaticFrame)
{
	LAssert(parFile != NULL);
	LAssert(parOther != NULL);

	// MD2 parameters
	md2_header_t	m_kHeader;      // header md2
    md2_skin_t      *m_pSkins;      // skins datas
    md2_texCoord_t  *m_pTexCoords;  // textures coordinates
    md2_triangle_t  *m_pTriangles;  // triangles datas
    md2_frame_t     *m_pFrames;     // frames datas

	// Set rotate
	FRotate = parRotate;

	// Load anim 
	FAnimation.LoadAnim(parOther);

	io::TReadFile file(parFile);
	s32 filesize = (s32)file.GetSize();

	// Debug
	core::array< u16 > locIndexBuffer;
	video::TVertex3D locVertex;

    LAssert(filesize > 0);

    // lecture du header
    file.Read( (c8 *)&m_kHeader, sizeof( md2_header_t ) );

    // vérification de l'authenticité du modèle
    if( (m_kHeader.version != MD2_VERSION) || m_kHeader.ident != MD2_IDENT )
        return false;

    // allocation de mémoire pour les données du modèle
    m_pSkins = NEW_IN_DOMAIN(MD2) md2_skin_t[ m_kHeader.num_skins ];
    m_pTexCoords = NEW_IN_DOMAIN(MD2) md2_texCoord_t[ m_kHeader.num_st ];
    m_pTriangles = NEW_IN_DOMAIN(MD2) md2_triangle_t[ m_kHeader.num_tris ];
    m_pFrames = NEW_IN_DOMAIN(MD2) md2_frame_t[ m_kHeader.num_frames ];

    // lecture des noms de skins
    file.Seek( m_kHeader.offset_skins);
    file.Read( (c8 *)m_pSkins, sizeof( char ) * 68 * m_kHeader.num_skins );
	//LOGC_3D("Num skins : %d \n", m_kHeader.num_skins);

    // lecture des coordonnées de texture
    file.Seek( m_kHeader.offset_st);
    file.Read( (c8 *)m_pTexCoords, sizeof( md2_texCoord_t ) * m_kHeader.num_st );
	//LOGC("Num tex coordinates : %d \n", m_kHeader.num_st);
	//LOGC("Num vertices : %d \n", m_kHeader.num_vertices);

    // lecture des triangles
    file.Seek( m_kHeader.offset_tris);
    file.Read( (c8 *)m_pTriangles, sizeof( md2_triangle_t ) * m_kHeader.num_tris );
	//LOGC("Num triangles : %d \n", m_kHeader.num_tris);

	//LOGC("Num frames : %d \n", m_kHeader.num_frames);

    // lecture des frames
    file.Seek( m_kHeader.offset_frames);
	// Set max frame, tris, vertices to boost reading
	u32 locMaxFrame = m_kHeader.num_frames;
	u32 locMaxTris = m_kHeader.num_tris;
	u32 locMaxVertices = m_kHeader.num_vertices;

	for(u32 iFrame=0; iFrame<locMaxFrame; ++iFrame)
    {
		//LOGC("MD2 load frame %d\n", iFrame);
        // Allocate memory for vertices
        m_pFrames[iFrame].verts = NEW_IN_DOMAIN(MD2) md2_vertex_t[ m_kHeader.num_vertices ];

        // lecture des données de la frame
        file.Read( (c8*)&m_pFrames[iFrame].scale,		sizeof(vec3_t) );
        file.Read( (c8*)&m_pFrames[iFrame].translate,	sizeof(vec3_t) );
        file.Read( (c8*)&m_pFrames[iFrame].name,		sizeof(c8) * 16 );
        file.Read( (c8*)m_pFrames[iFrame].verts,		sizeof(md2_vertex_t) * m_kHeader.num_vertices );
		
		if( ((iFrame >= parFrames.first) && (iFrame <= parFrames.second)) || (iFrame == parStaticFrame))
		{
			// Create MeshBuffer to store model datas
			locIndexBuffer.reset();

			// Store vertex frame for to index
			md2_frame_t* pFrame = &m_pFrames[ iFrame ];
			md2_vertex_t* pFrameVertices = pFrame->verts;
			TVertex3D* __attribute__((aligned(16))) locVertexList = NEW_IN_DOMAIN(MD2) TVertex3D[locMaxVertices];

			for(u32 i=0; i<locMaxVertices; ++i)
			{
				locVertexList[i].NX = m_kAnorms[ pFrameVertices[i].normalIndex ][0];
				locVertexList[i].NY = m_kAnorms[ pFrameVertices[i].normalIndex ][1];
				locVertexList[i].NZ = m_kAnorms[ pFrameVertices[i].normalIndex ][2];

				//*
				locVertexList[i].X = (pFrame->scale[0] * pFrameVertices[i].v[0] + pFrame->translate[0] + parTranslate.X) * parScale;
				locVertexList[i].Y = (pFrame->scale[1] * pFrameVertices[i].v[1] + pFrame->translate[1] + parTranslate.Y) * parScale;
				locVertexList[i].Z = (pFrame->scale[2] * pFrameVertices[i].v[2] + pFrame->translate[2] + parTranslate.Z) * parScale;
				//*/
				/*
				locVertexList[i].X = (pFrame->scale[0] * pFrameVertices[i].v[0]) * parScale;
				locVertexList[i].Y = (pFrame->scale[1] * pFrameVertices[i].v[1]) * parScale;
				locVertexList[i].Z = (pFrame->scale[2] * pFrameVertices[i].v[2]) * parScale;
				//*/
			}
		
			for(u32 i=0; i<locMaxTris; ++i)
			{	
				// Draw each triangle vertice
				for(u32 k=0; k<3; ++k)
				{
					u32 index = m_pTriangles[i].vertex[k];
					//*
					locVertexList[index].U = ((f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].s) / m_kHeader.skinwidth) * parWidth + parOffsetU;
					//locVertexList[index].V = BLOffsetV - (((f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].t) / m_kHeader.skinheight) * parHeight);
					locVertexList[index].V = ((f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].t) / m_kHeader.skinheight) * parHeight + parOffsetV;
					//*/
					/*
					locVertexList[index].U = (f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].s) / m_kHeader.skinwidth;
					locVertexList[index].V = (f32)(m_pTexCoords[ m_pTriangles[i].st[k] ].t) / m_kHeader.skinheight;
					//*/

					locIndexBuffer.push_back(m_pTriangles[i].vertex[k]);
				}
			}

			TMeshBuffer* locMeshBuffer = NEW_IN_DOMAIN(MD2) TMeshBuffer(locVertexList, locMaxVertices, locIndexBuffer, X_AXIS|Y_AXIS);
			FMeshBufferList.push_back(locMeshBuffer);
		}
		
		delete m_pFrames[iFrame].verts;
    }

	//LOGC("Total MD2 model size %d Ko\n", (FMeshBufferList.size() * ((FMeshBufferList[0])->GetVertexCount()) * sizeof(TVertex3D)) / 1024 );

	file.Close();

	// Free alocated memory for MD2 reading
	delete m_pSkins;
    delete m_pTexCoords;
    delete m_pTriangles;
    delete m_pFrames;

	return true;
}

//! Returns a boolean to tell if this mesh is already loaded
bool TAnimatedMeshMD2::IsLoaded()
{
	return FMeshBufferList.size() > 0;
}

const video::TMeshBuffer& TAnimatedMeshMD2::GetMeshBuffer(u32 parFrame) const
{
	LAssert(parFrame < FMeshBufferList.size());

	return *(FMeshBufferList[parFrame]);
}

u32 TAnimatedMeshMD2::SerializedSize()
{
	// TO DO
	return 0;
}

void TAnimatedMeshMD2::Serialize(c8** parBuffer)
{
	// TO DO
}

void TAnimatedMeshMD2::Deserialize(c8** parBuffer)
{
	// TO DO
}

const bb2Df& TAnimatedMeshMD2::Getbb2Df(u32 parFrame) const
{
	return GetMeshBuffer(parFrame).GetBBox2D();
}

void TAnimatedMeshMD2::UpdateAnimation()
{
	FFrameID = FAnimation.Update();
}

void TAnimatedMeshMD2::Free()
{
	for(u32 i=0; i<FMeshBufferList.size(); ++i)
	{
		delete FMeshBufferList[i];
	}

	FMeshBufferList.clear();
}

} // object namespace
} // namespace object
} // psp namespace

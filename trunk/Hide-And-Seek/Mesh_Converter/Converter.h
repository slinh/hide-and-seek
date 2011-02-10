#ifndef CONVERTER_H
#define CONVERTER_H

#include <config.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <StaticMeshOBJ.h>
#include <AnimatedMeshMD2.h>
#include <vector3d.h>
#include <vector2d.h>
#include "TTriangleInfo.h"
#include <engineArray.h>

using namespace std;

namespace psp {

using namespace engine;
using namespace engine::object;

class TMeshConverter
{
private:
	// Fields to convert OBJ models
	engine::core::array< engine::core::vector3df >	vertexBuffer;
	engine::core::array< engine::core::vector2df >	textureCoordBuffer;
	engine::core::array< engine::core::vector3df >	normalsBuffer;
	engine::core::array< TTriangleInfo >	faces;

	// Fields to convert MD2 models
	static vec3_t m_kAnorms[NUMVERTEXNORMALS];

	md2_header_t    m_kHeader;      // header md2
    md2_skin_t      *m_pSkins;      // skins datas
    md2_texCoord_t  *m_pTexCoords;  // textures coordinates
    md2_triangle_t  *m_pTriangles;  // triangles datas
    md2_frame_t     *m_pFrames;     // frames datas
    int             *m_pGLcmds;     // liste de commandes OpenGL

public:
	bool LoadOBJ(const char* parFile);
	bool SaveOBJ(const char* parFile, const f32	&parOffSetU, const f32 &parOffSetV, const f32 &parUScale, const f32 &parVScale);

	bool LoadMD2(const char* parFile);
	bool SaveMD2(const char* parFile, const f32	&parOffSetU, const f32 &parOffSetV, const f32 &parUScale, const f32 &parVScale);

	void ClearAll();
};

}

#endif
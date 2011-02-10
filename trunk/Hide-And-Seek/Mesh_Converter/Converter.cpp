#include <Common.h>
#include "Converter.h"
#include <ReadFile.h>
#include <Functions.h>
#include <fast_atof.h>
#include "TTriangleInfo.h"

namespace psp {

vec3_t TMeshConverter::m_kAnorms[ NUMVERTEXNORMALS ] = 
{
	#include <anorms.h>
};

bool TMeshConverter::LoadOBJ(const char* parFile)
{
	engine::io::TReadFile file(parFile);

	// LONG_BUFFER_SIZE
	c8			 wordBuffer[LONG_BUFFER_SIZE];

	s32 filesize = (s32)file.GetSize();

    LAssert(filesize > 0);

	c8* buf = NEW_ c8[filesize];
	file.Read((void*)buf, filesize);

	c8* line = buf;
	
	while(line)
	{
		c8* word = line;
		CopyWord(wordBuffer, LONG_BUFFER_SIZE, word);

		if (wordBuffer[0] == 'v' && wordBuffer[1] == 0x0)
		{
			// Vertex
			c8* p1 = GetNextWord(word);
			c8* p2 = GetNextWord(p1);
			c8* p3 = GetNextWord(p2);

			vertexBuffer.push_back(engine::core::vector3df( engine::core::atof(p1),
															engine::core::atof(p2),
															engine::core::atof(p3)));
		}
		else
		if (wordBuffer[0] == 'v' && wordBuffer[1] == 't')
		{
			// Texture coordinates
			c8* p1 = GetNextWord(word);
			c8* p2 = GetNextWord(p1);

			textureCoordBuffer.push_back(engine::core::vector2df(engine::core::atof(p1),
																 engine::core::atof(p2)));
		}
		else
		if (wordBuffer[0] == 'v' && wordBuffer[1] == 'n')
		{
			// Vertex normal
			c8* p1 = GetNextWord(word);
			c8* p2 = GetNextWord(p1);
			c8* p3 = GetNextWord(p2);

			normalsBuffer.push_back(engine::core::vector3df(engine::core::atof(p1),
															engine::core::atof(p2),
															engine::core::atof(p3)));
		}
		else if (wordBuffer[0] == 'f' && wordBuffer[1] == 0x0)
		{
			// face
			c8 faceBuf[20];
			CopyWordLineEnd(wordBuffer, LONG_BUFFER_SIZE, word);
			//copyWord(wordBuffer, LONG_BUFFER_SIZE, word);

			const s32 MAX_FACE_POINT_COUNT = 40;
			u32 facePointCount = 0;
			TTriangleInfo facePoints;

			c8* face = GetNextWord(wordBuffer);

			while(face && face[0])
			{
				CopyWordSpaceEnd(faceBuf, LONG_BUFFER_SIZE, face);

				//im facebuf steht jetzt die face.
				s32 idx = 0;
				s32 len = (s32)strlen(faceBuf);
				s32 z = 0;

				while (idx < len)
				{
					facePoints.GetPointInfo(facePointCount).Set(z, atoi(&faceBuf[idx]));
					for (++idx; idx<len && faceBuf[idx] && faceBuf[idx-1]!='/'; ++idx);
					z++;
				}

				++facePointCount;

				if (facePointCount >= (u32)MAX_FACE_POINT_COUNT)
				{
					DELETE_ buf;
					return false;
				}

				face = GetNextWord(face);
			}

			faces.push_back(facePoints);
		}
		else if (wordBuffer[0] == '#' || wordBuffer[0] == 'u' ||wordBuffer[0] == 'g')
		{
			// comment
			// find end of line
			s32 i=0;
			while(line[i])
			{
				if (line[i]=='\n' || line[i]=='\r')
					break;

				++i;
			}

			line = &line[i];
		}


		line = GetNextWord(line);
	}

	DELETE_ buf;

	return true;
}

bool TMeshConverter::SaveOBJ(const char* parPath,const f32	&parOffSetU, const f32 &parOffSetV, const f32 &parUScale, const f32 &parVScale)
{
	std::fstream outputFile(parPath , std::fstream::out | std::fstream::trunc);
	
	outputFile.setf(ios::fixed, ios::floatfield);
	outputFile.precision(8);

	f32 BLOffsetV = parOffSetV + parVScale;

	for(u32 i=0; i < vertexBuffer.size() ; ++i)
	{
		outputFile << "v " << vertexBuffer[i].X << " " << vertexBuffer[i].Y << " " << vertexBuffer[i].Z << std::endl ;
	}

	outputFile <<  std::endl;

	for(u32 i=0; i < textureCoordBuffer.size() ; ++i)
		
	{
		outputFile << "vt " << textureCoordBuffer[i].X * parUScale + parOffSetU << " " << BLOffsetV - (textureCoordBuffer[i].Y * parVScale)  << std::endl ;
	}

	outputFile <<  std::endl;

	for(u32 i=0; i < normalsBuffer.size() ; ++i)
	{
		outputFile << "vn " << normalsBuffer[i].X << " " << normalsBuffer[i].Y << " " << normalsBuffer[i].Z << std::endl ;
	}
	
	print("save %s\n", parPath);
	for(u32 i=0; i < faces.size() ; ++i)
	{
		outputFile << "f ";
		faces[i].GetPointInfo(0).Write(outputFile) ;
		outputFile << " ";
		faces[i].GetPointInfo(1).Write(outputFile) ;
		outputFile << " ";
		faces[i].GetPointInfo(2).Write(outputFile) ;
		outputFile << std::endl ;
	}

	outputFile.close();

	std::cout << "\nversion speciale pour Mathieu !!" << std::endl;

	ClearAll();
	return true;
	
}

bool TMeshConverter::LoadMD2(const char* parFile)
{
	LAssert(parFile != NULL);

	io::TReadFile file(parFile);
	s32 filesize = (s32)file.GetSize();

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
    m_pGLcmds = NEW_IN_DOMAIN(MD2) int[ m_kHeader.num_glcmds ];

    // lecture des noms de skins
    file.Seek( m_kHeader.offset_skins);
    file.Read( (c8 *)m_pSkins, sizeof( char ) * 68 * m_kHeader.num_skins );
	//LOGC_3D("Num skins : %d \n", m_kHeader.num_skins);

    // lecture des coordonnées de texture
    file.Seek( m_kHeader.offset_st);
    file.Read( (c8 *)m_pTexCoords, sizeof( md2_texCoord_t ) * m_kHeader.num_st );
	printf("Num tex coordinates : %d \n", m_kHeader.num_st);
	printf("Num vertices : %d \n", m_kHeader.num_vertices);

    // lecture des triangles
    file.Seek( m_kHeader.offset_tris);
    file.Read( (c8 *)m_pTriangles, sizeof( md2_triangle_t ) * m_kHeader.num_tris );
	//LOGC("Num triangles : %d \n", m_kHeader.num_tris);

	printf("Num frames : %d \n", m_kHeader.num_frames);

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
		printf("\tDEBUG VERTEX LOAD %3.2f %3.2f %3.2f\n",	m_pFrames[iFrame].scale[0],
															m_pFrames[iFrame].scale[1],
															m_pFrames[iFrame].scale[2]);
    }

	// lecture des commandes opengl
    file.Seek( m_kHeader.offset_glcmds );
    file.Read( (c8*)m_pGLcmds, sizeof(s32) * m_kHeader.num_glcmds );

	file.Close();

	return true;
}

bool TMeshConverter::SaveMD2(const char* parFile, const f32	&parOffSetU, const f32 &parOffSetV, const f32 &parUScale, const f32 &parVScale)
{
	// File to save MD2 model
	io::TWriteFile file(parFile);

	// Ecriture du header
	file.Write(&m_kHeader, sizeof( md2_header_t ));

	printf("skin offset %d\n", m_kHeader.offset_skins);
	// Writing skins datas
	file.Write(m_pSkins, m_kHeader.num_skins * 68 * sizeof(char));
	printf("skin size %d\n", sizeof( char ) * 68 * m_kHeader.num_skins);

	printf("tex offset %d\n", m_kHeader.offset_st);
	// Writing texture coordinates datas : It might be necesary to add a diff
	file.Write(m_pTexCoords, sizeof( md2_texCoord_t ) * m_kHeader.num_st);
	printf("tex size %d\n", sizeof( md2_texCoord_t ) * m_kHeader.num_st);

	// Writing frame datas
	printf("tris offset %d\n", m_kHeader.offset_tris);
	file.Write(m_pTriangles, sizeof( md2_triangle_t ) * m_kHeader.num_tris);
	printf("tris size %d\n", sizeof( md2_triangle_t ) * m_kHeader.num_tris);

	printf("frame offset %d\n", m_kHeader.offset_frames);

	s16 locMaxFrame = m_kHeader.num_frames;
	s16 locMaxTris = m_kHeader.num_tris;
	s16 locMaxVertices = m_kHeader.num_vertices;
	
    for(s16 iFrame=0; iFrame<locMaxFrame; ++iFrame)
	{
		// Writing frame datas
        file.Write( &m_pFrames[iFrame].scale,		sizeof(vec3_t) );
        file.Write( &m_pFrames[iFrame].translate,	sizeof(vec3_t) );
        file.Write( &m_pFrames[iFrame].name,		sizeof(c8) * 16 );
        file.Write( m_pFrames[iFrame].verts,		sizeof(md2_vertex_t) * m_kHeader.num_vertices );
	}

	// Writing opengGL commands info
    file.Write(m_pGLcmds, sizeof(s32) * m_kHeader.num_glcmds);

	file.Close();

	return true;
}

void TMeshConverter::ClearAll()
{
	vertexBuffer.clear();
	textureCoordBuffer.clear();
	normalsBuffer.clear();
	faces.clear();
}

} // psp namespace

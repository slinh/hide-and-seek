#include "Common.h"
#include "StaticMeshOBJ.h"
#include "ReadFile.h"
#include "Functions.h"
#include "vector2d.h"
#include "vector3d.h"
#include "fast_atof.h"
#include "Vertex3D.h"

namespace psp { namespace engine { namespace object {

TStaticMeshOBJ::TStaticMeshOBJ()
{
}

TStaticMeshOBJ::TStaticMeshOBJ(video::TMeshBuffer& parMeshBuffer):
FMeshBuffer(parMeshBuffer)
{}

TStaticMeshOBJ::~TStaticMeshOBJ()
{}
//*
//! Load a mesh from file parFile
bool TStaticMeshOBJ::Load(const c8* parFile, const c8* parOther)
{
	io::TReadFile file(parFile);

	// LONG_BUFFER_SIZE
	c8			wordBuffer[LONG_BUFFER_SIZE];

	core::array< video::TVertex3D >	vertexBuffer;

	core::array< core::vector2df >	textureCoordBuffer;
	core::array< core::vector3df >	normalsBuffer;

	bb2Df locBBox;

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
			
			video::TVertex3D locVertex;
			locVertex.X = core::atof(p1);
			locVertex.Y = core::atof(p2);
			locVertex.Z = core::atof(p3);

			vertexBuffer.push_back(locVertex);
			
			//vertexBuffer.push_back(core::vector3df( core::fast_atof(p1),
			//                                        core::fast_atof(p2),
			//                                        core::fast_atof(p3)));

			locBBox.AddPoint(locVertex.X, locVertex.Z);
			
		}
		else
		if (wordBuffer[0] == 'v' && wordBuffer[1] == 't')
		{
			// Texture coordinates
			c8* p1 = GetNextWord(word);
			c8* p2 = GetNextWord(p1);
			
			//textureCoordBuffer.push_back(core::vector2df(	core::fast_atof(p1),
			//												core::fast_atof(p2)));
			
			textureCoordBuffer.push_back(core::vector2df(	core::atof(p1),
															core::atof(p2)));
		}
		else
		if (wordBuffer[0] == 'v' && wordBuffer[1] == 'n')
		{
			// Vertex normal
			c8* p1 = GetNextWord(word);
			c8* p2 = GetNextWord(p1);
			c8* p3 = GetNextWord(p2);
			
			//normalsBuffer.push_back(core::vector3df(core::fast_atof(p1),
			//										core::fast_atof(p2),
			//                                        core::fast_atof(p3)));
			
			normalsBuffer.push_back(core::vector3df(core::atof(p1),
													core::atof(p2),
			                                        core::atof(p3)));
		}
		else if (wordBuffer[0] == 'f' && wordBuffer[1] == 0x0)
		{
			// face
			c8 faceBuf[20];
			CopyWordLineEnd(wordBuffer, LONG_BUFFER_SIZE, word);
			//copyWord(wordBuffer, LONG_BUFFER_SIZE, word);

			const s32 MAX_FACE_POINT_COUNT = 40;
			u32 facePointCount = 0;
			s32 facePoints[MAX_FACE_POINT_COUNT][3];

			for (s32 k=0; k<MAX_FACE_POINT_COUNT; ++k)
			{
				facePoints[k][0] = -1;
				facePoints[k][1] = -1;
				facePoints[k][2] = -1;
			}

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
					facePoints[facePointCount][z] = atoi(&faceBuf[idx]);
					for (++idx; idx<len && faceBuf[idx] && faceBuf[idx-1]!='/'; ++idx) ;
					z++;
				}

				++facePointCount;

				if (facePointCount >= (u32)MAX_FACE_POINT_COUNT)
				{
#ifdef DEBUG
					LOGC("Face with more than 40 face points found s32 file. Not loading %s", file.GetFileName());
#endif
					delete buf;
					return false;
				}

				face = GetNextWord(face);
			}

			// Now we've got a face.
			// and have to create some vertex and index from them
			for (u32 i=0; i<facePointCount; ++i)
			{
				// Vertex already pushed back in list
				video::TVertex3D& locVertex = vertexBuffer[facePoints[i][0]-1];

				// Push new index in meshBuffer index list
				FMeshBuffer.FIndexList.push_back(facePoints[i][0]-1);

				if (facePoints[i][2]-1 >= 0 && facePoints[i][2]-1 < (s32)normalsBuffer.size())
				{
					locVertex.NX = normalsBuffer[ facePoints[i][2]-1 ].X;
					locVertex.NY = normalsBuffer[ facePoints[i][2]-1 ].Y;
					locVertex.NZ = normalsBuffer[ facePoints[i][2]-1].Z;
				}
				else
				{
					locVertex.NX = locVertex.NY = locVertex.NZ = 0;
				}
				
				if (facePoints[i][1]-1 >= 0 && facePoints[i][1]-1 < (s32)textureCoordBuffer.size())
				{
					locVertex.U = textureCoordBuffer[ facePoints[i][1]-1].X;
					locVertex.V = -textureCoordBuffer[ facePoints[i][1]-1].Y;
				}
				else
				{
					locVertex.U = locVertex.V = 0;
				}
			}
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

	// Creation of vertex array to display
	vertexBuffer.set_free_when_destroyed(false);
	FMeshBuffer.CreateArrayList_WithBBoxAndSamePointer(vertexBuffer, locBBox);	

	delete buf;

	return true;
}
//*/
/*
//! Load a mesh from file parFile
bool TStaticMeshOBJ::Load(const c8* parFile, const c8* parOther)
{
	io::TReadFile file(parFile);

	// LONG_BUFFER_SIZE
	c8			wordBuffer[LONG_BUFFER_SIZE];

	core::array< core::vector3df >	vertexBuffer;
	core::array< core::vector2df >	textureCoordBuffer;
	core::array< core::vector3df >	normalsBuffer;

	s32 filesize = (s32)file.GetSize();

	core::array< video::TVertex3D > locVerticesBuffer;
	bb2Df locBBox;

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

			vertexBuffer.push_back(core::vector3df( core::atof(p1),
			                                        core::atof(p2),
			                                        core::atof(p3)));
		}
		else
		if (wordBuffer[0] == 'v' && wordBuffer[1] == 't')
		{
			// Texture coordinates
			c8* p1 = GetNextWord(word);
			c8* p2 = GetNextWord(p1);

			textureCoordBuffer.push_back(core::vector2df(	core::atof(p1),
															core::atof(p2)));
		}
		else
		if (wordBuffer[0] == 'v' && wordBuffer[1] == 'n')
		{
			// Vertex normal
			c8* p1 = GetNextWord(word);
			c8* p2 = GetNextWord(p1);
			c8* p3 = GetNextWord(p2);

			normalsBuffer.push_back(core::vector3df(core::atof(p1),
													core::atof(p2),
			                                        core::atof(p3)));
		}
		else if (wordBuffer[0] == 'f' && wordBuffer[1] == 0x0)
		{
			// face
			c8 faceBuf[20];
			CopyWordLineEnd(wordBuffer, LONG_BUFFER_SIZE, word);
			//copyWord(wordBuffer, LONG_BUFFER_SIZE, word);

			const s32 MAX_FACE_POINT_COUNT = 40;
			u32 facePointCount = 0;
			s32 facePoints[MAX_FACE_POINT_COUNT][3];

			for (s32 k=0; k<MAX_FACE_POINT_COUNT; ++k)
			{
				facePoints[k][0] = -1;
				facePoints[k][1] = -1;
				facePoints[k][2] = -1;
			}

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
					facePoints[facePointCount][z] = atoi(&faceBuf[idx]);
					for (++idx; idx<len && faceBuf[idx] && faceBuf[idx-1]!='/'; ++idx) ;
					z++;
				}

				++facePointCount;

				if (facePointCount >= (u32)MAX_FACE_POINT_COUNT)
				{
#ifdef DEBUG
					LOGC("Face with more than 40 face points found s32 file. Not loading %s", file.GetFileName());
#endif
					delete buf;
					return false;
				}

				face = GetNextWord(face);
			}

			// Now we've got a face.
			// and have to create some vertices and indices from them

			for (u32 i=0; i<facePointCount; ++i)
			{
				video::TVertex3D locVertex;

				if (facePoints[i][2]-1 >= 0 && facePoints[i][2]-1 < (s32)normalsBuffer.size())
				{
					locVertex.NX = normalsBuffer[ facePoints[i][2]-1 ].X;
					locVertex.NY = normalsBuffer[ facePoints[i][2]-1 ].Y;
					locVertex.NZ = normalsBuffer[ facePoints[i][2]-1].Z;
				}
				else
				{
					locVertex.NX = locVertex.NY = locVertex.NZ = 0;
				}

				if (facePoints[i][0]-1 >= 0 && facePoints[i][0]-1 < (s32)vertexBuffer.size())
				{
					locVertex.X  = vertexBuffer [ facePoints[i][0]-1 ].X;
					locVertex.Y  = vertexBuffer [ facePoints[i][0]-1 ].Y;
					locVertex.Z  = vertexBuffer [ facePoints[i][0]-1 ].Z;					
				}
				else
				{
					locVertex.X = locVertex.Y = locVertex.Z = 0;
				}

				if (facePoints[i][1]-1 >= 0 && facePoints[i][1]-1 < (s32)textureCoordBuffer.size())
				{
					locVertex.U = textureCoordBuffer[ facePoints[i][1]-1].X;
					locVertex.V = -textureCoordBuffer[ facePoints[i][1]-1].Y;
				}
				else
				{
					locVertex.U = locVertex.V = 0;
				}

				// Add new point
				locVerticesBuffer.push_back(locVertex);
				// Update bbox
				locBBox.AddPoint(locVertex.X, locVertex.Z);
			}
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

	// Creation of vertex array to display
	locVerticesBuffer.set_free_when_destroyed(false);
	FMeshBuffer.CreateArrayList_WithBBoxAndSamePointer(locVerticesBuffer, locBBox);	

	delete buf;

	return true;
}
//*/

//! Returns a boolean to tell if this mesh is already loaded
bool TStaticMeshOBJ::IsLoaded()
{
	return FMeshBuffer.FVertexList != NULL;
}

void TStaticMeshOBJ::Free()
{
	if(FMeshBuffer.FVertexList != NULL)
		delete FMeshBuffer.FVertexList;
	FMeshBuffer.FVertexList = NULL;

	FMeshBuffer.FVertexCount = 0;

	FMeshBuffer.FIndexList.clear();

	FMeshBuffer.FBBox2D.Reset();
}

const bb2Df& TStaticMeshOBJ::Getbb2Df(u32 parFrame) const
{
	return GetMeshBuffer(parFrame).GetBBox2D();
}

u32 TStaticMeshOBJ::SerializedSize()
{
	return sizeof(u32) + FMeshBuffer.FVertexCount * TVertex3D::SerializedSize() 
		+ sizeof(u32) + FMeshBuffer.FIndexList.size() * sizeof(s16);
}

void TStaticMeshOBJ::Serialize(c8** parBuffer)
{
	SERIALIZE(*parBuffer, u32, FMeshBuffer.FVertexCount);

	for (u32 i = 0; i<FMeshBuffer.FVertexCount; ++i)
	{
		FMeshBuffer.FVertexList[i].Serialize(parBuffer);
	}
	
	SERIALIZE(*parBuffer, u32, FMeshBuffer.FIndexList.size());

	for (u32 i = 0; i<FMeshBuffer.FIndexList.size(); ++i)
	{
		SERIALIZE(*parBuffer, s16, FMeshBuffer.FIndexList[i]);
	}
}

void TStaticMeshOBJ::Deserialize(c8** parBuffer)
{
	u32 nbVertex = DESERIALIZE(*parBuffer, u32);

	array<TVertex3D> locArrayList;
	locArrayList.reallocate(nbVertex);
	for (u32 i = 0; i < nbVertex; ++i)
	{

		locArrayList.push_back(TVertex3D(parBuffer));
	}
	
	u32 nbIndex = DESERIALIZE(*parBuffer, u32);

	array<u16> locIndexList = 0;
	s16 locBuf = 0;
	for (u32 i = 0; i<nbIndex; ++i)
	{
		locBuf = DESERIALIZE(*parBuffer, s16);
		locIndexList.push_back(locBuf);
	}

	FMeshBuffer.Load_WithSamePointer(locArrayList, locIndexList);
}

} // object namespace
} // engine namespace
} // psp namespace


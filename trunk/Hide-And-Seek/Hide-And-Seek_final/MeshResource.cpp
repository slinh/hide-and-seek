#include "MeshResource.h"
#include "GameConstantes.h"
#include "config.h"
#include "Alloc.h"

namespace psp { namespace engine { namespace object {

	TMeshResource::TMeshResource(c8** parBuffer) :
		FType(MT_UNKNOW),
		FProperties(0)
	{
		Deserialize(parBuffer);
		LAssert(FBBox2Df.size() > 0)
	}

	TMeshResource::TMeshResource(const c8* parFileName, u32 parProperties, array<TTransform> &parTransform, u8 parIdSoundForPathMarker)
	//TMeshResource::TMeshResource(const c8* parFileName, u32 parProperties, const array<TTransform> &parTransform, u8 parIdSoundForPathMarker)
	{
		Init(parFileName, parProperties, parTransform);
		FIdSoundForPathMarker = parIdSoundForPathMarker;
	}

	TMeshResource::~TMeshResource(void)
	{
		delete FMesh;
	}

	void TMeshResource::Init(const c8* parFileName, u32 parProperties, array<TTransform> &parTransform)
	//void TMeshResource::Init(const c8* parFileName, u32 parProperties, const array<TTransform> &parTransform)
	{
		FProperties = parProperties;
		FType = TMeshResource::GetExtension(parFileName);

		/*	load mesh	*/
		switch(FType)
		{
		case MT_OBJ:
			{
				TStaticMeshOBJ* locMesh = NEW_IN_DOMAIN(Map) TStaticMeshOBJ();
		
				//print("Open mesh %s :\n", parFileName);
				locMesh->Load(parFileName);
				LAssert(locMesh->IsLoaded());

				// Store mesh buffer to put it later in level loading file
				FMesh = locMesh;
			break;
			}

		case MT_MD2:
			FMesh = NULL;
			break;

		default:
			FMesh = NULL;
			break;
		}

		for (u32 i = 0; i < parTransform.size(); ++i)
			AddTransformation(parTransform[i]);
		
	}

	//void TMeshResource::AddTransformation(const TTransform &parTransform)
	void TMeshResource::AddTransformation(TTransform &parTransform)
	{
		// Add a new translation
		// TO DO : delete later because its a fucking rustine
		// It mmight bug with map file
		//parTransform.SetTranslation().Z = -parTransform.GetTranslation().Z;
		FTransform.push_back(parTransform);

		// Add a new bbox
		bb2Df locBBox = FMesh->Getbb2Df();
		//LOGC("Before transfo on bbox L %3.2f R %3.2f T %3.2f B %3.2f\n", locBBox.GetLeft(), locBBox.GetRight(), locBBox.GetTop(), locBBox.GetBottom());
		parTransform.ApplyTransform(locBBox);
		FBBox2Df.push_back(locBBox);
		//LOGC("After transfo on bbox L %3.2f R %3.2f T %3.2f B %3.2f\n\n", locBBox.GetLeft(), locBBox.GetRight(), locBBox.GetTop(), locBBox.GetBottom());

		// Add a new mesh state
		FState.push_back(NOT_DRAWN);
		
		FCheckIAState.push_back(NOT_CHECKIA);

		// TO DO : Use else if - if necesary
		if( FProperties & O_SECRET_PATH )
			FGameState.push_back( OS_ACTIVATE );
		
		if( FProperties & O_PATH_MARKER )
			FGameState.push_back( OS_DESACTIVATE );
		
		if( FProperties & O_INTERACTIVE )
			FGameState.push_back( OS_DESACTIVATE );
	}

	void TMeshResource::SetAllStates(const u32& parState)
	{
		for(u32 i=0; i<FState.size(); ++i)
			FState[i] = parState;
	}

	void TMeshResource::SetAllCheckIAStates(const u32& parState)
	{
		for(u32 i=0; i<FCheckIAState.size(); ++i)
			FCheckIAState[i] = parState;
	}

	MESH_TYPE TMeshResource::GetExtension(const c8* parFileName)
	{
		if (CompareExtension(parFileName, "obj")) return MT_OBJ;
		else if (CompareExtension(parFileName, "md2")) return MT_MD2;
		else return MT_UNKNOW;
	}

	bool TMeshResource::CompareExtension(const c8* parFileName, const c8* parExt)
	{
		u32 res = 0;
		u32 lenght = strlen(parFileName);

		for (u32 i = 0; i < 3; ++i)
			res += parFileName[lenght - 3 + i] - parExt[i];

		return (res==0);
	}

	u32 TMeshResource::SerializedSize()
	{
		return sizeof(MESH_TYPE) + sizeof(u32) + FMesh->SerializedSize() + sizeof(u32) 
			+ FTransform.size() * TTransform::SerializedSize();
	}

	void TMeshResource::Serialize(c8** parBuffer)
	{
		SERIALIZE(*parBuffer, u32, FType);
		SERIALIZE(*parBuffer, u32, FProperties);

		// Sauvegarde du mesh
		switch(FType)
		{
		case MT_OBJ:
			FMesh->Serialize(parBuffer);
			break;

		case MT_MD2:
			break;

		case MT_UNKNOW:
			break;
		}

		// Mesh FTransform array : 4o + n * sizeof(vector3df) : 4o + n *  + n * 12o
		SERIALIZE(*parBuffer, u32, FTransform.size());
		for (u32 i = 0; i < FTransform.size(); ++i)
			FTransform[i].Serialize(parBuffer);
	}

	void TMeshResource::Deserialize(c8** parBuffer)
	{
		//LOGC("Load Mesh Ressource\n");
		// FType
		FType = DESERIALIZE(*parBuffer, MESH_TYPE);
		//LOGC("Type : %d\n", FType);
		// FProperties
		FProperties = DESERIALIZE(*parBuffer, u32);
		//LOGC("Properties : %d\n", FProperties);

		//LOGC("Tranformations loaded\n");
		// Chargement du mesh
		switch(FType)
		{
		case MT_OBJ:
			{
				TStaticMeshOBJ* locMesh = NEW_IN_DOMAIN(Map) TStaticMeshOBJ();
				locMesh->Deserialize(parBuffer);
				LAssert(locMesh->IsLoaded());

				FMesh = locMesh;
			}
			break;

		case MT_MD2:
			FMesh = NULL;
			break;

		case MT_UNKNOW:
			FMesh = NULL;
			break;
		}

		LAssert(FMesh != NULL);
		//LOGC("Mesh loaded\n");

		// FTransform
		u32 locNbTransform = DESERIALIZE(*parBuffer, u32);
		LAssert(locNbTransform>0);
		//LOGC("Nb Transformations : %d\n", locNbTransform);
		FTransform.reallocate(locNbTransform);
		FBBox2Df.reallocate(locNbTransform);
		for (u32 i = 0; i < locNbTransform; ++i)
		{
			// TO DO : fucking rustine because of const in param in AddTransformation
			TTransform locTransfo(parBuffer);
			AddTransformation(locTransfo);
		}
		//LOGC("Mesh Ressource Loaded\n\n");
	}
} // object namespace
} // engine namespace
} // psp namespace

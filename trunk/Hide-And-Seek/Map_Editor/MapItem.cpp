#include <QtGui/QStandardItem>

// 34Lettres functions
#include <Alloc.h>
#include <LoggerTypes.h>
#include <fstream>
#include <GameConstantes.h>

#include "MapItem.h"

namespace psp { namespace MapEditor {

	/* ----------------------------------------------------------------------- */

	class TMeshInformation
	{
	public:
		TMeshInformation(char* parName) : FProperty(0)
		{
			FName = parName;
			FName += ".obj";
		}

		void SetTranslation(float tx, float ty, float tz)
		{
			FTrans[0] = tx;
			FTrans[1] = ty;
			FTrans[2] = tz;
		}

		void SetRotation(float rx, float ry, float rz)
		{
			FRot[0] = rx;
			FRot[1] = ry;
			FRot[2] = rz;
		}

		vector3df GetTranslation()
		{
			return vector3df(FTrans[0], FTrans[1], FTrans[2]);
		}

		vector3df GetRotation()
		{
			return vector3df(FRot[0], FRot[1], FRot[2]);
		}

		TTransform GetTransform()
		{
			return TTransform(GetTranslation(), GetRotation());
		}

	public:
		stringc FName;
		float FTrans[3];
		float FRot[3];
		u32 FProperty;
	};

	/* ----------------------------------------------------------------------- */
	
TMapItem::TMapItem() : TTreeModel(), FPath(),
	FMeshFolder("")
{
	FMap = NEW_IN_DOMAIN(Tools) TMap(8,8);
}

TMapItem::TMapItem(u32 parWidth, u32 parHeight, const stringc& parMeshFolder) : TTreeModel(), FPath(),
	FMeshFolder(parMeshFolder)
{
	FMap = NEW_IN_DOMAIN(Tools) TMap(parWidth, parHeight);
}

TMapItem::~TMapItem()
{
	for (u32 i = 0; i < FMeshList.size(); ++i) DELETE_IN_DOMAIN(Tools) FMeshList[i];
	DELETE_IN_DOMAIN(Tools) FMap;
}

void TMapItem::AddMesh(const stringc &parPath)
{
	array<TTransform> locTransform;
	locTransform.push_back(TTransform());
	TMeshResource* locRes = FMap->AddMeshResource(parPath.c_str(), false, locTransform);

	TMeshItem* locMesh = NEW_IN_DOMAIN(Tools) TMeshItem(FRootItem, TMeshItem::extractFileName(parPath), locRes);
	FMeshList.push_back(locMesh);

	//FRootItem->appendChild(NEW_IN_DOMAIN(Tools) TTreeItem(static_cast<TTreeItem*>(locMesh), FRootItem));
	//insertRow(static_cast<QStandardItem*>(locMesh));

	FRootItem->insertChildren(FRootItem->childCount(), 1, FRootItem->columnCount());
	FRootItem->child(FRootItem->childCount() - 1)->setData(1, QVariant(locMesh->GetName().c_str()));
}

void TMapItem::RemoveMesh(QModelIndex& locItem)
{
	TMeshItem* locMesh = static_cast<TMeshItem*>(getItem(locItem));//static_cast<TMeshItem*>(itemFromIndex(locItem));
	FMeshList.erase(FMeshList.binary_search(locMesh));
	removeRow(locItem.row()); // delete locMesh par Qt
	#pragma message ("WARNING!!! " __FILE__" : DONT FORGET TO RESOLVE THIS Leak PROBLEM!!! ")
	//DELETE_IN_DOMAIN(Tools) locMesh;
}

void TMapItem::AddMeshes(const QStringList &parPathMeshes)
{
	for (int i = 0; i < parPathMeshes.size(); ++i)
	{
		AddMesh(parPathMeshes[i].toStdString().c_str());
	}	
}

void TMapItem::RemoveMeshes(QModelIndexList &parMeshes)
{
	QModelIndexList locModelList;

	int cnt;
	bool locInserted;
	for (int i = 0; i < parMeshes.size(); ++i) 
	{
		cnt=0;
		locInserted = false;
		while ((!locInserted)&&(cnt<locModelList.count()))
		{
			if (parMeshes[i].row() > locModelList[cnt].row())
			{
				locModelList.insert(cnt, parMeshes[i]);
				locInserted=true;
			}
			++cnt;
		}
		if (!locInserted) locModelList.push_back(parMeshes[i]);
	}

	for (int i = 0; i < locModelList.size(); ++i)
		RemoveMesh(locModelList[i]);
}

//void TMapItem::insertRow(QStandardItem * locItem)
//{
//	//QStandardItemModel::insertRow(FMeshList.size()-1, locItem);
//}
//
//void TMapItem::removeRow(const u32 &parRow)
//{
//	//QStandardItemModel::removeRow(parRow);
//}

void TMapItem::Save(const stringc &parPath, const u32& parWidth, const u32& parHeight)
{
	/*c8** locMeshList = NEW_IN_DOMAIN(Tools) c8*[FMeshList.size()];
	for (u32 i=0; i<FMeshList.size(); ++i) 
	{
		locMeshList[i] = NEW_IN_DOMAIN(Tools) c8[FMeshList[i]->GetPath().size()+1];
		strncpy_s(locMeshList[i], FMeshList[i]->GetPath().size()+1, FMeshList[i]->GetPath().c_str(), FMeshList[i]->GetPath().size());
		locMeshList[i][FMeshList[i]->GetPath().size()] = '\0';
	}*/
	
	//TMap* locConverter = NEW_IN_DOMAIN(Tools) TMap(parWidth,parHeight);
	FMap->SaveMap(parPath.c_str());

	/*TConverter* locConverter = NEW_IN_DOMAIN(Tools) TConverter(parWidth, parHeight);
	locConverter->GenerateMapWithAutoId(parPath.c_str(), locMeshList, FMeshList.size());*/
	//DELETE_IN_DOMAIN(Tools) locConverter;

	/*for (u32 i=0; i<FMeshList.size(); ++i) DELETE_IN_DOMAIN(Tools) locMeshList[i];
	DELETE_IN_DOMAIN(Tools) locMeshList;*/
}

void TMapItem::Load(const stringc &parPath)
{
	/*TConverter* locConverter = NEW_IN_DOMAIN(Tools) TConverter(8, 8);
	locConverter.LoadMap(parPath.c_str());*/
	FMap->LoadMap(parPath.c_str());

	//array<TMeshResource*> locResources = FMap->GetMeshResources();
	//for (u32 i = 0; i < locResources.size(); ++i)
	//{
	//	//locResources[i]->
	//}
}

void TMapItem::LoadBSI(const stringc &parPath)
{
	/* Parsing du fichier bsi */
	fstream inputFile(parPath.c_str(), fstream::in);

	char buf[255];
	vector<TMeshInformation*> locMeshList;
	float* locTrans = new float[6];
	TMeshInformation* locMesh;

	while (inputFile.getline(buf, 255))
	{
		if (buf[0] == '(')
		{
			// translation
			float tx, ty, tz;

			sscanf(buf,"(%f, %f, %f)\n", &tx, &ty, &tz);
			locMesh->SetTranslation(tx, tz, -1*ty);
		}
		else if (buf[0] == '[')
		{
			// translation
			float rx, ry, rz;
			sscanf(buf,"[%f, %f, %f](euler)\n", &rx, &ry, &rz);
			locMesh->SetRotation(rx * RAD_TO_DEG, rz * RAD_TO_DEG, ry * RAD_TO_DEG);
		}
		else if (buf[0] == '#')
		{
			char buffer[50];
			sscanf(buf,"#property %s\n", buffer);

			if (strcmp(buffer,"O_INTERACTIVE") == 0) locMesh->FProperty |= O_INTERACTIVE;
			else if (strcmp(buffer,"O_PATH_MARKER") == 0) locMesh->FProperty |= O_PATH_MARKER;
			else if (strcmp(buffer,"O_SECRET_PATH") == 0) locMesh->FProperty |= O_SECRET_PATH;
			else if (strcmp(buffer,"O_VISUAL") == 0) locMesh->FProperty |= O_VISUAL;
			else if (strcmp(buffer,"O_SOUND") == 0) locMesh->FProperty |= O_SOUND;
			else if (strcmp(buffer,"O_PASS_ITEM") == 0) locMesh->FProperty |= O_PASS_ITEM;
		}
		else if (strlen(buf) != 0)
		{
			// nom d'objet
			for (int i = 0; i < strlen(buf); ++i)
				if (buf[i] == '.')
				{
					buf[i] = '\0';
					break;
				}

				locMesh = new TMeshInformation(buf);
		}
		else
		{
			if (locMesh->FProperty == 0) locMesh->FProperty = O_NORMAL;
			if (locMeshList.size()>0)
			{
				if (locMeshList[locMeshList.size()-1] != locMesh)
					locMeshList.push_back(locMesh);
			}
			else locMeshList.push_back(locMesh);
		}
	}

	inputFile.close();

	/* Ajout dans fichiers dans FMap */

	stringc locStr;
	array<TTransform> locTransformVect;
	vector<TMeshInformation*> locMeshToSave;
	int cnt = 0;

	do
	{
		cnt = 0;
		for (int i = 0; i < locMeshList.size(); ++i)
		{
			if (locMeshList[i] != NULL)
			{
				if (locStr.size()<2)
				{
					locStr = locMeshList[i]->FName;
				}

				if (locMeshList[i]->FName == locStr)
				{
					locMeshToSave.push_back(locMeshList[i]);
					locMeshList[i] = NULL;
				}
			}
			else cnt++;
		}

		if (locMeshToSave.size()>0)
		{
			u32 locProperty =  locMeshToSave[0]->FProperty;

			locTransformVect.clear();
			locTransformVect.reallocate(locMeshToSave.size());
			for (int i = 0; i < locMeshToSave.size(); ++i)
			{
				locTransformVect.push_back(locMeshToSave[i]->GetTransform());
				delete locMeshToSave[i];
				locMeshToSave[i] = NULL;
			}
			stringc path = FMeshFolder; 
			if (path[path.size()-1] != '/') path += '/';
			path += locStr;
			FMap->AddMeshResource(path.c_str(), locProperty, locTransformVect);
			locMeshToSave.clear();
			locStr = "";
		}

	} while (cnt != locMeshList.size());
}

TMeshItem* TMapItem::GetMesh(QModelIndex& locItem)
{
	return static_cast<TMeshItem*>(getItem(locItem));
}

} // namespace MapEditor
} // namespace psp

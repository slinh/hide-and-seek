#ifndef ME_MAP_H
#define ME_MAP_H

#include <config.h>
#include <engineString.h>
#include <engineArray.h>
#include <Map.h>
#include <QtCore/QAbstractItemModel>
#include "MeshItem.h"
#include "TreeModel.h"

using namespace psp::engine::core;
using namespace psp::engine::object;
using namespace psp::engine::io;
using namespace std;

namespace psp { namespace MapEditor {

class TMapItem : public TTreeModel
{
	Q_OBJECT

	/*	Fields	*/
private:
	TMap* FMap;
	array<TMeshItem*> FMeshList;
	stringc FPath;
	stringc FMeshFolder;

	/*	Method	*/
public:
	TMapItem();
	TMapItem(u32 parWidth, u32 parHeight, const stringc& parMeshFolder);
	~TMapItem();

	void AddMeshes(const QStringList &parPathMeshes);
	void RemoveMeshes(QModelIndexList &parMeshes);
	void Save(const stringc &parPath, const u32& parWidth, const u32& parHeight);
	void Load(const stringc &parPath);
	void LoadBSI(const stringc &parPath);
	TMeshItem* GetMesh(QModelIndex& locItem);
	
protected:
	void AddMesh(const stringc &parPath);
	void RemoveMesh(QModelIndex& locItem);
};

} // namespace MapEditor
} // namespace psp

#endif

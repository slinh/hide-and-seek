#pragma once

#include <config.h>
#include <engineString.h>
#include <QtGui/QStandardItem>
#include <Vertex3D.h>
#include <StaticMeshOBJ.h>
#include <MeshResource.h>
#include "TreeItem.h"

using namespace psp::engine::video;
using namespace psp::engine::core;
using namespace psp::engine::object;

namespace psp { namespace MapEditor {

class TMeshItem : public TTreeItem
{
	/*	Fields	*/
private:
	stringc FName;
	TMeshResource* FMesh;

	/*	Methods	*/
public:
	TMeshItem(TTreeItem *parent);
	TMeshItem(TTreeItem *parent, const stringc &parName, const TMeshResource* parMesh);
	~TMeshItem(void);
	
	QVariant data(int column) const;

	static QString extractFileName(const QString &path);
	static stringc extractFileName(const stringc &path);

	/*	Accessors	*/
public:
	GETTER(stringc, Name)
	GETTER_PTR(TMeshResource, Mesh)
};

} // namespace MapEditor
} // namespace psp
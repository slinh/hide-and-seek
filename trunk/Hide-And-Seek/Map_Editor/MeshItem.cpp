#include "MeshItem.h"
#include <Alloc.h>

namespace psp { namespace MapEditor {

TMeshItem::TMeshItem(TTreeItem *parent) : TTreeItem(parent)
{
}

TMeshItem::TMeshItem(TTreeItem *parent, const stringc &parName, const TMeshResource* parMesh) : TTreeItem(parent),
	FName(parName)
{

}

TMeshItem::~TMeshItem(void)
{

}

QVariant TMeshItem::data(int column) const
{
	if (column == 1)
		return QString(FName.c_str());

	return QVariant();
}

QString TMeshItem::extractFileName(const QString &path)
{
	return path.split("\\").last().split(".").first();
}
stringc TMeshItem::extractFileName(const stringc &path)
{
	QString locString = path.c_str();
	return extractFileName(locString).toStdString().c_str();
}

} // namespace MapEditor
} // namespace psp
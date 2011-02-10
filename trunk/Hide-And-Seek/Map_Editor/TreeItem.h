#ifndef ME_TreeItem_H
#define ME_TreeItem_H

#include <QtCore/QList>
#include <QtCore/QVariant>
#include <QtCore/QVector>

namespace psp { namespace MapEditor {

class TTreeItem
{
public:
	TTreeItem(TTreeItem *parent = 0);
    TTreeItem(const QVector<QVariant> &data, TTreeItem *parent = 0);
    virtual ~TTreeItem();

    TTreeItem *child(int number);
    int childCount() const;
    int columnCount() const;
    virtual QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    TTreeItem *parent();
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
    bool setData(int column, const QVariant &value);

private:
    QList<TTreeItem*> childItems;
    QVector<QVariant> itemData;
    TTreeItem *parentItem;
};

} // namespace MapEditor
} // namespace psp

#endif

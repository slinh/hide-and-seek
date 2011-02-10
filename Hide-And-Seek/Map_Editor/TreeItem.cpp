#include <QtCore/QStringList>

#include "TreeItem.h"

namespace psp { namespace MapEditor {

TTreeItem::TTreeItem(TTreeItem *parent)
{
    parentItem = parent;
}

TTreeItem::TTreeItem(const QVector<QVariant> &data, TTreeItem *parent)
{
    parentItem = parent;
    itemData = data;
}

TTreeItem::~TTreeItem()
{
    qDeleteAll(childItems);
}

TTreeItem *TTreeItem::child(int number)
{
    return childItems.value(number);
}

int TTreeItem::childCount() const
{
    return childItems.count();
}

int TTreeItem::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<TTreeItem*>(this));

    return 0;
}

int TTreeItem::columnCount() const
{
    return itemData.count();
}

QVariant TTreeItem::data(int column) const
{
    return itemData.value(column);
}

bool TTreeItem::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > childItems.size())
        return false;

    for (int row = 0; row < count; ++row) {
        QVector<QVariant> data(columns);
        TTreeItem *item = new TTreeItem(data, this);
        childItems.insert(position, item);
    }

    return true;
}

bool TTreeItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.insert(position, QVariant());

    foreach (TTreeItem *child, childItems)
        child->insertColumns(position, columns);

    return true;
}

TTreeItem *TTreeItem::parent()
{
    return parentItem;
}

bool TTreeItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childItems.takeAt(position);

    return true;
}

bool TTreeItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.remove(position);

    foreach (TTreeItem *child, childItems)
        child->removeColumns(position, columns);

    return true;
}

bool TTreeItem::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= itemData.size())
        return false;

    itemData[column] = value;
    return true;
}

} // namespace MapEditor
} // namespace psp

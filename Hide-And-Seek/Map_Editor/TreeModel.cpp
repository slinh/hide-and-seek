#include <QtGui/QtGui>

#include "TreeModel.h"

namespace psp { namespace MapEditor {

TTreeModel::TTreeModel(QObject *parent) : QAbstractItemModel(parent)
{
    QVector<QVariant> rootData;
    FRootItem = new TTreeItem(rootData);
}

TTreeModel::TTreeModel(const QStringList &headers, const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    QVector<QVariant> rootData;
    foreach (QString header, headers)
        rootData << header;

    FRootItem = new TTreeItem(rootData);
    setupModelData(data.split(QString("\n")), FRootItem);
}

TTreeModel::~TTreeModel()
{
    delete FRootItem;
}

int TTreeModel::columnCount(const QModelIndex & /* parent */) const
{
    return FRootItem->columnCount();
}

QVariant TTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TTreeItem *item = getItem(index);

    return item->data(index.column());
}

Qt::ItemFlags TTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

TTreeItem *TTreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TTreeItem *item = static_cast<TTreeItem*>(index.internalPointer());
        if (item) return item;
    }
    return FRootItem;
}

QVariant TTreeModel::headerData(int section, Qt::Orientation orientation,
                            int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return FRootItem->data(section);

    return QVariant();
}

QModelIndex TTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    TTreeItem *parentItem = getItem(parent);

    TTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

bool TTreeModel::insertColumns(int position, int columns, const QModelIndex &parent)
{
    bool success;

    beginInsertColumns(parent, position, position + columns - 1);
    success = FRootItem->insertColumns(position, columns);
    endInsertColumns();

    return success;
}

bool TTreeModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    TTreeItem *parentItem = getItem(parent);
    bool success;

    beginInsertRows(parent, position, position + rows - 1);
    success = parentItem->insertChildren(position, rows, FRootItem->columnCount());
    endInsertRows();

    return success;
}

QModelIndex TTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TTreeItem *childItem = getItem(index);
    TTreeItem *parentItem = childItem->parent();

    if (parentItem == FRootItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

bool TTreeModel::removeColumns(int position, int columns, const QModelIndex &parent)
{
    bool success;

    beginRemoveColumns(parent, position, position + columns - 1);
    success = FRootItem->removeColumns(position, columns);
    endRemoveColumns();

    if (FRootItem->columnCount() == 0)
        removeRows(0, rowCount());

    return success;
}

bool TTreeModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    TTreeItem *parentItem = getItem(parent);
    bool success = true;

    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}

int TTreeModel::rowCount(const QModelIndex &parent) const
{
    TTreeItem *parentItem = getItem(parent);

    return parentItem->childCount();
}

bool TTreeModel::setData(const QModelIndex &index, const QVariant &value,
                        int role)
{
    if (role != Qt::EditRole)
        return false;

    TTreeItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index);

    return result;
}

bool TTreeModel::setHeaderData(int section, Qt::Orientation orientation,
                            const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    bool result = FRootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}

void TTreeModel::setupModelData(const QStringList &lines, TTreeItem *parent)
{
    QList<TTreeItem*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    int number = 0;

    while (number < lines.count()) {
        int position = 0;
        while (position < lines[number].length()) {
            if (lines[number].mid(position, 1) != " ")
                break;
            position++;
        }

        QString lineData = lines[number].mid(position).trimmed();

        if (!lineData.isEmpty()) {
            // Read the column data from the rest of the line.
            QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
            QVector<QVariant> columnData;
            for (int column = 0; column < columnStrings.count(); ++column)
                columnData << columnStrings[column];

            if (position > indentations.last()) {
                // The last child of the current parent is now the new parent
                // unless the current parent has no children.

                if (parents.last()->childCount() > 0) {
                    parents << parents.last()->child(parents.last()->childCount()-1);
                    indentations << position;
                }
            } else {
                while (position < indentations.last() && parents.count() > 0) {
                    parents.pop_back();
                    indentations.pop_back();
                }
            }

            // Append a new item to the current parent's list of children.
            TTreeItem *parent = parents.last();
            parent->insertChildren(parent->childCount(), 1, FRootItem->columnCount());
            for (int column = 0; column < columnData.size(); ++column)
                parent->child(parent->childCount() - 1)->setData(column, columnData[column]);
        }

        number++;
    }
}

} // namespace MapEditor
} // namespace psp

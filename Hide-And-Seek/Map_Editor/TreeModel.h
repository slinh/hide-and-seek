#ifndef TTreeModel_H
#define TTreeModel_H

#include <QtCore/QAbstractItemModel>
#include <QtCore/QModelIndex>
#include <QtCore/QVariant>
#include "TreeItem.h"

namespace psp { namespace MapEditor {

class TTreeModel : public QAbstractItemModel
{
    Q_OBJECT

	/*	Method	*/
public:
	TTreeModel(QObject *parent = 0);
    TTreeModel(const QStringList &headers, const QString &data, QObject *parent = 0);
    virtual ~TTreeModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole);

    bool insertColumns(int position, int columns, const QModelIndex &parent = QModelIndex());
    bool removeColumns(int position, int columns, const QModelIndex &parent = QModelIndex());
    bool insertRows(int position, int rows, const QModelIndex &parent = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &parent = QModelIndex());

protected:
    void setupModelData(const QStringList &lines, TTreeItem *parent);
    TTreeItem *getItem(const QModelIndex &index) const;

	/*	Fields	*/
protected:
	TTreeItem *FRootItem;
};

} // namespace MapEditor
} // namespace psp


#endif

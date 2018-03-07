#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include <QDebug>

#include "TreeItem.h"

class TreeModel: public QAbstractItemModel
{
    Q_OBJECT

public:
    TreeItem *m_rootItem;

    TreeItem *getItem(const QModelIndex &index) const;

public:
    TreeModel(QObject *parent = NULL);

    enum{
        LineRole = Qt::UserRole + 1,
        StationRole,
        TimeRole
    };

    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;

    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QHash<int,QByteArray> roleNames() const;

    void insertRow(const QModelIndex &parent , TreeItem* ad);

    void reomoveRow();
    void removeALL();


public slots:

    QAbstractItemModel *model();
};

#endif // TREEMODEL_H

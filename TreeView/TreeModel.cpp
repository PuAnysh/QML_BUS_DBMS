#include "TreeModel.h"

TreeModel::TreeModel(QObject *parent):
    QAbstractItemModel(parent)
{
    m_rootItem = new TreeItem( { "A", "B" , "" } );

//    auto item1 = new TreeItem( { "a", "a" } );
//    auto item2 = new TreeItem( { "aa", "bb" } );
//    auto item3 = new TreeItem( { "aaa", "bbb" } );

//    m_rootItem->appendChild(item1);
//    m_rootItem->appendChild(new TreeItem( {"dsaf" , "dsfa"}  ));
//    m_rootItem->appendChild(new TreeItem( {"dsaf" , "dsfa"}  ));
//    m_rootItem->appendChild(new TreeItem( {"dsaf" , "dsfa"}  ));
//    m_rootItem->appendChild(new TreeItem( {"dsaf" , "dsfa"}  ));
}

TreeModel::~TreeModel()
{
    delete m_rootItem;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    }
    else
    {
        return m_rootItem->columnCount();
    }
}

QHash<int, QByteArray> TreeModel::roleNames() const
{
    /*
      roleName可以自己定义，我这里是随便写的
     */

    QHash<int, QByteArray> roles(QAbstractItemModel::roleNames());
    roles[LineRole] = "line";
    roles[StationRole] = "station";
    roles[TimeRole] = "time";
    return roles;
}

void TreeModel::insertRow(const QModelIndex &parent , TreeItem* ad)
{
    TreeItem* parentItem = getItem(parent);
    beginInsertRows(parent , parentItem->childCount() ,  parentItem->childCount());
    parentItem->appendChild(ad);
    endInsertRows();
}

void TreeModel::reomoveRow()
{
    QModelIndex parent = index( -1 , -1);

    beginRemoveRows(parent,0, 0);
    m_rootItem->removeChild();
    endRemoveRows();
}

void TreeModel::removeALL()
{

    while(m_rootItem->childCount() > 1){
        TreeModel::reomoveRow();
    }
    TreeModel::reomoveRow();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    switch(role)
    {
        case LineRole:
        {
            return static_cast<TreeItem*>(index.internalPointer())->data(0);
        }
        case StationRole:
        {
            return static_cast<TreeItem*>(index.internalPointer())->data(1);
        }
        case TimeRole:
        {
            return static_cast<TreeItem*>(index.internalPointer())->data(2);
        }
        case Qt::DisplayRole:
        {
            return static_cast<TreeItem*>(index.internalPointer())->data(index.column());
        }
        default:
        {
            return QVariant();
        }
    }
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return 0;
    }

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        return m_rootItem->data(section);
    }

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }

    TreeItem *parentItem;
    if(!parent.isValid())
    {
        parentItem = m_rootItem;
    }
    else
    {
        parentItem = static_cast<TreeItem*>(parent.internalPointer());
    }

    TreeItem *childItem = parentItem->child(row);
    if(childItem)
    {
        return createIndex(row, column, childItem);
    }
    else
    {
        return QModelIndex();
    }
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return QModelIndex();
    }

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if(parentItem == m_rootItem)
    {
        return QModelIndex();
    }

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if(parent.column() > 0)
    {
        return 0;
    }

    if(!parent.isValid())
    {
        parentItem = m_rootItem;
    }
    else
    {
        parentItem = static_cast<TreeItem*>(parent.internalPointer());
    }

    return parentItem->childCount();
}

QAbstractItemModel *TreeModel::model()
{
    return this;
}


TreeItem *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return m_rootItem;
}

#include "TreeItem.h"

TreeItem::TreeItem(const QList<QVariant> &data, QObject *parent) :QObject(parent)
{
//    m_parentItem = parent;
    m_itemData = data;
}

TreeItem::~TreeItem()
{
    qDeleteAll(m_childItems);
}

void TreeItem::appendChild(TreeItem *item)
{
    item->setParent(this);
    m_childItems.append(item);
}

void TreeItem::removeChild()
{
    if(m_childItems.size() > 1){
        delete m_childItems.takeAt(0);
    }

}

TreeItem *TreeItem::child(int row)
{
    return m_childItems.value(row);
}

int TreeItem::childCount() const
{
    return m_childItems.count();
}

int TreeItem::columnCount() const
{
    return m_itemData.count();
}

QVariant TreeItem::data(int column) const
{
    return m_itemData.value(column);
}

TreeItem *TreeItem::parent()
{
    assert(m_parentItem);
    return m_parentItem;
}

void TreeItem::setParent(TreeItem *parent)
{
    m_parentItem = parent;
}

int TreeItem::row() const
{
    if(!m_parentItem) { return 0; }

    return m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));
}


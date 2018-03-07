#ifndef TREEITEM_H
#define TREEITEM_H

// C lib import
#include <assert.h>
#include <QObject>
// Qt lib import
#include <QList>
#include <QVariant>
#include <QStringList>
#include <QDebug>

class TreeItem : public QObject
{
private:
    TreeItem *m_parentItem;
    QList<TreeItem*> m_childItems;
    QList<QVariant> m_itemData;

public:
    TreeItem(const QList<QVariant> &data , QObject *parent = 0);

    ~TreeItem();

    void appendChild(TreeItem *child);

    void removeChild();

    TreeItem *child(int row);

    int childCount() const;

    int columnCount() const;

    QVariant data(int column) const;

    int row() const;

    TreeItem *parent();

    void setParent(TreeItem *parent);
};
#endif

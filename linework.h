#ifndef LINEWORK_H
#define LINEWORK_H

#include <QObject>
#include <sql_link.h>
#include <QtSql>
#include <TreeView/TreeModel.h>
class LineWork : public QObject
{
    Q_OBJECT
public:
    LineWork(TreeModel* model ,QObject *parent = 0);
    Q_INVOKABLE void Insert(TreeItem* ti);
    Q_INVOKABLE void RemoveRow();
    Q_INVOKABLE void RemoveAll();
    Q_INVOKABLE void linequery(QString str , QString str2);
    Q_INVOKABLE void deleteLine();
    Q_INVOKABLE void setIndex(QModelIndex index);
    Q_INVOKABLE QVariant getLno();
signals:

public slots:
private:
    TreeModel* p_model;
    QSqlDatabase database;
    QSqlQuery query;
    QString lno;
//    QMap<QVariant , TreeItem*> mp;

};

#endif // LINEWORK_H

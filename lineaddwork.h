#ifndef LINEADDWORK_H
#define LINEADDWORK_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <lineaddmodel.h>
#include <sql_link.h>

class LineAddWork : public QObject
{
    Q_OBJECT
public:
    LineAddWork(LineAddModel* model , QObject *parent = 0);
public:
    Q_INVOKABLE void querys(QString str , QString str2);
    Q_INVOKABLE void delItem(int index);
    Q_INVOKABLE void addItem(int index , QString str , QString str1);
    Q_INVOKABLE void btnok(QString str);
    Q_INVOKABLE void modify(QString str);
private:
    QSqlDatabase database;
    QSqlQuery query;
    LineAddModel* p_model;
signals:

public slots:
};

#endif // LINEADDWORK_H

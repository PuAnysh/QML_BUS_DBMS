#ifndef STATIONWORK_H
#define STATIONWORK_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <stationmodel.h>
#include <sql_link.h>

class StationWork : public QObject
{
    Q_OBJECT
public:
    StationWork(StationModel* model ,QObject *parent = 0);
public:
    Q_INVOKABLE void execSQL(QString str);
    Q_INVOKABLE void querys(QString str , QString str2);
    Q_INVOKABLE void delItem(int index);
    Q_INVOKABLE QVariant redata(int index , QString str);
private:
    QSqlDatabase database;
    QSqlQuery query;
    StationModel* p_model;
signals:

public slots:
    Q_INVOKABLE void addItem(QString str1 , QString str2);
};

#endif // STATIONWORK_H

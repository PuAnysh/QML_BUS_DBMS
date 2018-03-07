#ifndef SCHEDULEWORK_H
#define SCHEDULEWORK_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <schedulemodel.h>
#include <QMessageBox>
#include <sqlwidget.h>
#include <sql_link.h>

class ScheduleWork : public QObject
{
    Q_OBJECT
public:
    ScheduleWork(ScheduleModel* model ,QObject *parent = 0);
public:
    Q_INVOKABLE void execSQL(QString str);
    Q_INVOKABLE void querys(QString str , QString str2);
    Q_INVOKABLE void delItem(int index);
    Q_INVOKABLE QVariant redata(int index , QString str);
private:
    QSqlDatabase database;
    QSqlQuery query;
    ScheduleModel* p_model;

signals:

public slots:
    Q_INVOKABLE void addItem(QString str1 , QString str2 , QString str3 , QString str4 ,
                 QString str5 );
};

#endif // SCHEDULEWORK_H

#ifndef STAFFWORK_H
#define STAFFWORK_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <staffmodel.h>
#include <staffadd.h>
#include <QApplication>
#include <sql_link.h>
class StaffWork : public QObject
{
    Q_OBJECT
public:
    StaffWork(StaffModel* model , QObject *parent = 0);

public:
    Q_INVOKABLE void test();
    Q_INVOKABLE void testGet(int index);
    Q_INVOKABLE void execSQL(QString str);
    Q_INVOKABLE void querys(QString str , QString str2);
    Q_INVOKABLE void delItem(int index);
    Q_INVOKABLE QVariant redata(int index , QString str);
private:
    QSqlDatabase database;
    QSqlQuery query;
    StaffModel* p_model;

signals:

public slots:
    Q_INVOKABLE void addItem(QString str1 , QString str2 , QString str3 , QString str4 ,
                 QString str5 , QString str6 , QString str7 , QString str8 );
};

#endif // STAFFWORK_H

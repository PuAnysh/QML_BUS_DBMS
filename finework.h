#ifndef FINEWORK_H
#define FINEWORK_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <finemodel.h>
#include <sql_link.h>

class FineWork : public QObject
{
    Q_OBJECT
public:
    FineWork(FineModel *model ,QObject *parent = 0);
public:
    Q_INVOKABLE void execSQL(QString str);
    Q_INVOKABLE void querys(QString str , QString str2);
    Q_INVOKABLE void delItem(int index);
    Q_INVOKABLE QVariant redata(int index , QString str);
private:
    QSqlDatabase database;
    QSqlQuery query;
    FineModel* p_model;

signals:

public slots:
    Q_INVOKABLE void addItem(QString str1 , QString str2 , QString str3 , QString str4 ,
                 QString str5 );
};

#endif // FINEWORK_H

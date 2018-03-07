#ifndef CARWORK_H
#define CARWORK_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <carmodel.h>
#include <sql_link.h>
class CarWork : public QObject
{
    Q_OBJECT
public:
    CarWork( CarModel *model ,QObject *parent = 0);

public:
    Q_INVOKABLE void execSQL(QString str);
    Q_INVOKABLE void querys(QString str , QString str2);
    Q_INVOKABLE void delItem(int index);
    Q_INVOKABLE QVariant redata(int index , QString str);
private:
    QSqlDatabase database;
    QSqlQuery query;
    CarModel* p_model;

signals:

public slots:
    Q_INVOKABLE void addItem(QString str1 , QString str2 , QString str3 , QString str4 ,
                 QString str5 , QString str6  );
};

#endif // CARWORK_H

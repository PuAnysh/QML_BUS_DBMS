#ifndef LOGINWORK_H
#define LOGINWORK_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <carremodel.h>
#include <QMessageBox>
#include <sql_link.h>

class LoginWork : public QObject
{
    Q_OBJECT
public:
    LoginWork(QObject *parent = 0);
    Q_INVOKABLE QVariant retype(QString name , QString passwd);
private:
    QSqlDatabase database;
    QSqlQuery query;
signals:

public slots:
};

#endif // LOGINWORK_H

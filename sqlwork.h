#ifndef SQLWORK_H
#define SQLWORK_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QtGui>
#include <qdebug.h>
#include <QObject>
class SQLwork : public QObject
{
    Q_OBJECT
public:
    explicit SQLwork(QObject *parent = 0);
    QSqlDatabase db;
    QSqlQuery query;

signals:

public slots:
private:

};


#endif // SQLWORK_H

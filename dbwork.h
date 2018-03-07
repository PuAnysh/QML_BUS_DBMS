#ifndef DBWORK_H
#define DBWORK_H

#include <QObject>
#include <QtSql>
#include <QFileDialog>
#include <QMessageBox>
#include <sql_link.h>
#include <QFile>
#include <QDebug>
class DBwork : public QObject
{
    Q_OBJECT
public:
    DBwork(QObject *parent = 0);
    Q_INVOKABLE void saveDB();
    Q_INVOKABLE void reDB();
    Q_INVOKABLE void keyOpen();
    Q_INVOKABLE void keyClose();
signals:

public slots:
private:
    QSqlDatabase database;
    QSqlQuery query;
};

#endif // DBWORK_H

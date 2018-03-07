#include "sqlwork.h"

SQLwork::SQLwork(QObject *parent) : QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    query = QSqlQuery(db);
}

#ifndef DRIVERMODEL_H
#define DRIVERMODEL_H
#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QObject>

class Driver
{
public:
    Driver() {}

};


class DriverModel : public QAbstractListModel
{
public:
    DriverModel();
};

#endif // DRIVERMODEL_H

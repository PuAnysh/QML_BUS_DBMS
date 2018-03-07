#ifndef STATIONMODEL_H
#define STATIONMODEL_H

#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QDebug>
#include <QObject>

class Station{
public:
    Station(const QVariant& sname,
            const QVariant& saddress);
    QVariant sname , saddress;
};


class StationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
        snameRole = Qt::UserRole + 1,
        saddressRole
    };
    StationModel(QObject *parent = 0);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    QList<Station> GetQlist();
    void delItem(int index);
    Station reItem(int index);
    void deletall();
    void addItem(const Station& station);

signals:

public slots:
private:
    QList<Station> m_Stations;
};

#endif // STATIONMODEL_H

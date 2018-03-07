#include "stationmodel.h"

StationModel::StationModel(QObject *parent) : QAbstractListModel(parent)
{

}

int StationModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Stations.count();
}

QVariant StationModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_Stations.count())
        return QVariant();

    const Station &station = m_Stations[index.row()];
    if (role == saddressRole)
        return station.saddress;
    else if (role == snameRole)
        return station.sname;
    return QVariant();
}

QHash<int, QByteArray> StationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[saddressRole] = "saddress";
    roles[snameRole] = "sname";
    return roles;
}

QList<Station> StationModel::GetQlist()
{
    return m_Stations;
}

void StationModel::delItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_Stations.erase(m_Stations.begin() + index);
    endRemoveRows();
}

Station StationModel::reItem(int index)
{
    return m_Stations[index];
}

void StationModel::deletall()
{
    while(m_Stations.count() > 0){
        int index = 0;
        beginRemoveRows(QModelIndex(), index, index);
        m_Stations.erase(m_Stations.begin() + index);
        endRemoveRows();
    }
}

void StationModel::addItem(const Station &station)
{
    beginInsertRows(QModelIndex() ,rowCount(), rowCount());
    m_Stations<<station;
    endInsertRows();
    qDebug()<<station.sname<<" "<<station.saddress<<endl;
}

Station::Station(const QVariant &sname, const QVariant &saddress)
{
    this->sname = sname;
    this->saddress= saddress;
}

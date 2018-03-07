#include "carmodel.h"

Car::Car(const QVariant &CNO, const QVariant &CServertime, const QVariant &CModel,
         const QVariant &CLine, const QVariant &CServicedtime, const QVariant &CBrand)
{
    this->CNO = CNO;
    this->CServertime = CServertime;
    this->CModel = CModel;
    this->CLine = CLine;
    this->CServicedtime = CServicedtime;
    this->CBrand = CBrand;

}

CarModel::CarModel(QObject *parent)
    : QAbstractListModel(parent)
{
}






int CarModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_Cars.count();
}


QVariant CarModel::data(const QModelIndex & index, int role ) const
{
    if (index.row() < 0 || index.row() >= m_Cars.count())
        return QVariant();

    const Car &car = m_Cars[index.row()];
    if (role ==CModelRole)
        return car.CModel;
    else if (role == CNORole)
        return car.CNO;
    else if (role == CServertimeRole)
        return car.CServertime;
    else if (role == CLineRole)
        return car.CLine;
    else if (role == CServicedtimeRole)
        return car.CServicedtime;
    else if (role == CBrandRole)
        return car.CBrand;
    return QVariant();
}


QHash<int, QByteArray> CarModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[CNORole] = "CNO";
    roles[CServertimeRole] = "CServertime";
    roles[CModelRole] = "CModel";
    roles[CLineRole] = "CLine";
    roles[CServicedtimeRole] = "CServicedtime";
    roles[CBrandRole] = "CBrand";
    return roles;
}

QList<Car> CarModel::GetQlist()
{
    return m_Cars;
}


void CarModel::delItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_Cars.erase(m_Cars.begin() + index);
    endRemoveRows();
}

Car CarModel::reItem(int index)
{
    return m_Cars[index];
}

void CarModel::deletall()
{
    while(m_Cars.count() > 0){
        int index = 0;
        beginRemoveRows(QModelIndex(), index, index);
        m_Cars.erase(m_Cars.begin() + index);
        endRemoveRows();
    }
}

void CarModel::addItem(const Car &car)
{
    beginInsertRows(QModelIndex() ,rowCount(), rowCount());
    m_Cars<<car;
    endInsertRows();
}



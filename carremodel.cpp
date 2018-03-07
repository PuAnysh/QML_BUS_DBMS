#include "carremodel.h"

CarRemodel::CarRemodel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int CarRemodel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_CarRe.count();
}

QVariant CarRemodel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_CarRe.count())
            return QVariant();

    const CarRe &carRe = m_CarRe[index.row()];
    if (role ==RecarRole)
        return carRe.Recar;
    else if (role == RecostRole)
        return carRe.Recost;
    else if (role == RedepartmentRole)
        return carRe.Redepartment;
    else if (role == RenoRole)
        return carRe.Reno;
    else if (role == RepairdetailRole)
        return carRe.Repairdetail;
    else if (role == RetimeRole)
        return carRe.Retime;
    return QVariant();
}

QHash<int, QByteArray> CarRemodel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RecarRole] = "Recar";
    roles[RecostRole] = "Recost";
    roles[RedepartmentRole] = "Redepartment";
    roles[RenoRole] = "Reno";
    roles[RepairdetailRole] = "Repairdetail";
    roles[RetimeRole] = "Retime";
    return roles;
}

QList<CarRe> CarRemodel::GetQlist()
{
    return m_CarRe;
}

void CarRemodel::delItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_CarRe.erase(m_CarRe.begin() + index);
    endRemoveRows();
}

CarRe CarRemodel::reItem(int index)
{
    return m_CarRe[index];
}

void CarRemodel::deletall()
{
    while(m_CarRe.count() > 0){
        int index = 0;
        beginRemoveRows(QModelIndex(), index, index);
        m_CarRe.erase(m_CarRe.begin() + index);
        endRemoveRows();
    }
}

void CarRemodel::addItem(const CarRe &carre)
{
    beginInsertRows(QModelIndex() ,rowCount(), rowCount());
    m_CarRe<<carre;
    endInsertRows();
}



CarRe::CarRe(const QVariant &Reno, const QVariant &Retime, const QVariant &Recost, const QVariant &Repairdetail, const QVariant &Redepartment, const QVariant &Recar)
{
    this->Recar = Recar;
    this->Recost = Recost;
    this->Redepartment = Redepartment;
    this->Reno = Reno;
    this->Repairdetail = Repairdetail;
    this->Retime = Retime;
}

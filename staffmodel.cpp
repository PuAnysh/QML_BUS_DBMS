#include "staffmodel.h"


Staff::Staff(const QVariant &DNO, const QVariant &DName,
             const QVariant &DID, const QVariant &DPosition,
             const QVariant &DWorkTime, const QVariant &DAccount,
             const QVariant &DSalary, const QVariant &DAddress)
{
    this->DNO = DNO;
    this->DName = DName;
    this->DID = DID;
    this->DWorkTime = DWorkTime;
    this->DAccount = DAccount;
    this->DAddress = DAddress;
    this->DSalary = DSalary;
    this->DPosition = DPosition;
}


StaffModel::StaffModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void StaffModel::deletall()
{
   while(m_Staffs.count() > 0){
       int index = 0;
       beginRemoveRows(QModelIndex(), index, index);
       m_Staffs.erase(m_Staffs.begin() + index);
       endRemoveRows();
   }
}


void StaffModel::addItem(const Staff& staff){
    beginInsertRows(QModelIndex() ,rowCount(), rowCount());
    m_Staffs<<staff;
    endInsertRows();
}





int StaffModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_Staffs.count();
}


QVariant StaffModel::data(const QModelIndex & index, int role ) const
{
    if (index.row() < 0 || index.row() >= m_Staffs.count())
        return QVariant();

    const Staff &staff = m_Staffs[index.row()];
    if (role == DNORole)
        return staff.DNO;
    else if (role == DNameRole)
        return staff.DName;
    else if (role == DIDRole)
        return staff.DID;
    else if (role == DAccountRole)
        return staff.DAccount;
    else if (role == DAddressRole)
        return staff.DAddress;
    else if (role == DSalaryRole)
        return staff.DSalary;
    else if (role == DWorkTimeRole)
        return staff.DWorkTime;
    else if(role == DPositionRole)
        return staff.DPosition;

    return QVariant();
}


QHash<int, QByteArray> StaffModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[DNORole] = "DNO";
    roles[DNameRole] = "DName";
    roles[DIDRole] = "DID";
    roles[DWorkTimeRole] = "DWorkTime";
    roles[DAccountRole] = "DAccount";
    roles[DSalaryRole] = "DSalary";
    roles[DAddressRole] = "DAddress";
    roles[DPositionRole] = "DPosition";
    return roles;
}

const QList<Staff> StaffModel::GetQlist()
{
    return this->m_Staffs;
}

void StaffModel::delItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_Staffs.erase(m_Staffs.begin() + index);
    endRemoveRows();
}

Staff StaffModel::reItem(int index)
{
    return m_Staffs[index];
}

#include "salarymodel.h"

SalaryModel::SalaryModel(QObject *parent) : QAbstractListModel(parent)
{

}

int SalaryModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Salarys.count();
}

QVariant SalaryModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_Salarys.count())
            return QVariant();

    const Salary &salary = m_Salarys[index.row()];
    if (role ==SaccountRole)
        return salary.Saccount;
    else if (role == SnoRole)
        return salary.Sno;
    else if (role == SsumRole)
        return salary.Ssum;
    else if (role == StimeRole)
        return salary.Stime;
    else if (role == SnameRole)
        return salary.Sname;
    else if(role == SidRole)
        return salary.Sid;
    return QVariant();
}

QHash<int, QByteArray> SalaryModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[SaccountRole] = "Saccount";
    roles[SnoRole] = "Sno";
    roles[SsumRole] = "Ssum";
    roles[StimeRole] = "Stime";
    roles[SnameRole] = "Sname";
    roles[SidRole] = "Sid";

    return roles;
}

QList<Salary> SalaryModel::GetQlist()
{
    return m_Salarys;
}

void SalaryModel::delItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_Salarys.erase(m_Salarys.begin() + index);
    endRemoveRows();
}

Salary SalaryModel::reItem(int index)
{
    return m_Salarys[index];
}

void SalaryModel::deletall()
{
    while(m_Salarys.count() > 0){
        int index = 0;
        beginRemoveRows(QModelIndex(), index, index);
        m_Salarys.erase(m_Salarys.begin() + index);
        endRemoveRows();
    }
}

void SalaryModel::addItem(const Salary &salary)
{
    beginInsertRows(QModelIndex() ,rowCount(), rowCount());
    m_Salarys<<salary;
    endInsertRows();
}

Salary::Salary(const QVariant &Sno, const QVariant &Stime, const QVariant &Ssum,
               const QVariant&  Sid,const QVariant &Saccount , const QVariant &Sname)
{
    this->Saccount = Saccount;
    this->Sno = Sno;
    this->Ssum = Ssum;
    this->Sid = Sid;
    this->Stime = Stime;
    this->Sname = Sname;
}

#include "finemodel.h"

FineModel::FineModel(QObject *parent) : QAbstractListModel(parent)
{

}


int FineModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_fines.count();
}

QVariant FineModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_fines.count())
            return QVariant();

    const Fine &fine = m_fines[index.row()];
    if (role ==BdetialRole)
        return fine.Bdetial;
    else if (role == BnoRole)
        return fine.Bno;
    else if (role == BreakcarRole)
        return fine.Breakcar;
    else if (role == BreakdriverRole)
        return fine.Breakdriver;
    else if (role == BtimeRole)
        return fine.Btime;
    return QVariant();
}

QHash<int, QByteArray> FineModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[BdetialRole] = "Bdetial";
    roles[BnoRole] = "Bno";
    roles[BreakcarRole] = "Breakcar";
    roles[BreakdriverRole] = "Breakdriver";
    roles[BtimeRole] = "Btime";
    return roles;
}

QList<Fine> FineModel::GetQlist()
{
    return m_fines;
}

void FineModel::delItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_fines.erase(m_fines.begin() + index);
    endRemoveRows();
}

Fine FineModel::reItem(int index)
{
    return m_fines[index];
}

void FineModel::deletall()
{
    while(m_fines.count() > 0){
        int index = 0;
        beginRemoveRows(QModelIndex(), index, index);
        m_fines.erase(m_fines.begin() + index);
        endRemoveRows();
    }
}

void FineModel::addItem(const Fine &fine)
{
    beginInsertRows(QModelIndex() ,rowCount(), rowCount());
    m_fines<<fine;
    endInsertRows();
}


Fine::Fine(const QVariant &Bno, const QVariant &Btime,
           const QVariant &Bdetial, const QVariant &Breakcar,
           const QVariant &Breakdriver)
{
    this->Bdetial = Bdetial;
    this->Bno = Bno;
    this->Breakcar = Breakcar;
    this->Breakdriver = Breakdriver;
    this->Btime = Btime;
}

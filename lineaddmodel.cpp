#include "lineaddmodel.h"

LineAddModel::LineAddModel(QObject *parent) : QAbstractListModel(parent)
{
}

int LineAddModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_lines.count();
}

QVariant LineAddModel::data(const QModelIndex &index, int role) const
{

    if (index.row() < 0 || index.row() >= m_lines.count())
        return QVariant();
    const Line & line = m_lines[index.row()];
    if(role == StationRole)
        return line.station;
    else if(role == TimeRole)
        return line.time;
    return QVariant();
}

QHash<int, QByteArray> LineAddModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[StationRole] = "station";
    roles[TimeRole] = "time";
    return roles;
}

void LineAddModel::delItem(int index)
{
    if(index < 0 || index>m_lines.size()) return ;
    beginRemoveRows(QModelIndex(), index, index);
    m_lines.erase(m_lines.begin() + index);
    endRemoveRows();
}

Line LineAddModel::reItem(int index)
{
    return m_lines[index];
}

void LineAddModel::deletall()
{
    while(m_lines.count() > 0){
        int index = 0;
        beginRemoveRows(QModelIndex(), index, index);
        m_lines.erase(m_lines.begin() + index);
        endRemoveRows();
    }
}

void LineAddModel::addItem(const Line &line , int index)
{
    index++;
    //if(index < 0) index = 0;
    if(index < 0 || index > rowCount()) return ;
    beginInsertRows(QModelIndex() ,index, index);
    m_lines.insert(index , line);
    endInsertRows();
}

Line::Line(QVariant station , QVariant time)
{
    this->station = station;
    this->time = time;
}

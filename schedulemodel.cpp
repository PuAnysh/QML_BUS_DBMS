#include "schedulemodel.h"

Schedule::Schedule(const QVariant &weekth, const QVariant &scline, const QVariant &driverno, const QVariant &drivername, const QVariant &begintime, const QVariant &endtime)
{
    this->begintime = begintime;
    this->drivername = drivername;
    this->driverno = driverno;
    this->endtime = endtime;
    this->scline = scline;
    this->weekth = weekth;
}


ScheduleModel::ScheduleModel(QObject *parent) : QAbstractListModel(parent)
{

}

int ScheduleModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Schedule.count();
}

QVariant ScheduleModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_Schedule.count())
        return QVariant();

    const Schedule &schedule = m_Schedule[index.row()];
    if (role ==begintimeRole)
        return schedule.begintime;
    else if (role == drivernameRole)
        return schedule.drivername;
    else if (role == drivernoRole)
        return schedule.driverno;
    else if (role == endtimeRole)
        return schedule.endtime;
    else if (role == sclineRole)
        return schedule.scline;
    else if (role == weekthRole)
        return schedule.weekth;
    return QVariant();
}

QHash<int, QByteArray> ScheduleModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[begintimeRole] = "begintime";
    roles[drivernameRole] = "drivername";
    roles[drivernoRole] = "driverno";
    roles[endtimeRole] = "endtime";
    roles[sclineRole] = "scline";
    roles[weekthRole] = "weekth";
    return roles;
}

QList<Schedule> ScheduleModel::GetQlist()
{
    return m_Schedule;
}

void ScheduleModel::delItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_Schedule.erase(m_Schedule.begin() + index);
    endRemoveRows();
}

Schedule ScheduleModel::reItem(int index)
{
    return m_Schedule[index];
}

void ScheduleModel::deletall()
{
    while(m_Schedule.count() > 0){
        int index = 0;
        beginRemoveRows(QModelIndex(), index, index);
        m_Schedule.erase(m_Schedule.begin() + index);
        endRemoveRows();
    }
}

void ScheduleModel::addItem(const Schedule &schedule)
{
    beginInsertRows(QModelIndex() ,rowCount(), rowCount());
    m_Schedule<<schedule;
    endInsertRows();
}


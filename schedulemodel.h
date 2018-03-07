#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QObject>


class Schedule
{
public:
    Schedule(const QVariant&  weekth,
             const QVariant&  scline,
             const QVariant&  driverno ,
             const QVariant&  drivername,
             const QVariant&  begintime,
             const QVariant&  endtime);
    QVariant weekth,scline,driverno ,drivername,begintime,endtime;
};


class ScheduleModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
        weekthRole = Qt::UserRole + 1,
        sclineRole,
        drivernoRole,
        drivernameRole,
        begintimeRole,
        endtimeRole
    };
    ScheduleModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    QList<Schedule> GetQlist();
    void delItem(int index);
    Schedule reItem(int index);
    void deletall();
    void addItem(const Schedule& schedule);

signals:

public slots:
private:
    QList<Schedule> m_Schedule;
};

#endif // SCHEDULEMODEL_H

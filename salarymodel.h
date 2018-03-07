#ifndef SALARYMODEL_H
#define SALARYMODEL_H

#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QObject>

class Salary
{
public:
    Salary(const QVariant&  Sno  ,
           const QVariant&  Stime,
           const QVariant&  Ssum ,
           const QVariant&  Sid,
           const QVariant&  Saccount,
           const QVariant&  Sname);
    QVariant Sno  ,  Stime,Ssum , Sid, Saccount , Sname;
};

class SalaryModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
        SnoRole = Qt::UserRole + 1,
        StimeRole,
        SsumRole,
        SaccountRole,
        SnameRole,
        SidRole
    };
    SalaryModel(QObject *parent = 0);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    QList<Salary> GetQlist();
    void delItem(int index);
    Salary reItem(int index);
    void deletall();
    void addItem(const Salary& salary);

signals:

public slots:
private:
    QList<Salary> m_Salarys;
};

#endif // SALARYMODEL_H

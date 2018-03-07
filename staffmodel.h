#ifndef STAFFDOMEL_H
#define STAFFDOMEL_H
#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QObject>


class Staff{
public:
    Staff(const QVariant&  DNO  ,
          const QVariant& DName,
          const QVariant& DID ,
          const QVariant& DPosition,
          const QVariant& DWorkTime,
          const QVariant& DAccount,
          const QVariant& DSalary,
          const QVariant& DAddress);
    QVariant DNO, DName,DID ,DWorkTime,DAccount,
              DSalary,DAddress , DPosition;
};



class StaffModel :public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
        DNORole = Qt::UserRole + 1,
        DNameRole,
        DIDRole,
        DWorkTimeRole,
        DAccountRole,
        DSalaryRole,
        DAddressRole,
        DPositionRole
    };
    StaffModel(QObject *parent = 0);
    void addItem(const Staff& staff);
    void deletall();
//    Q_INVOKABLE void addStaff(const QString&  DNO  ,
//                              const QString& DName,
//                              const QString& DID ,
//                              const QString& DWorkTime,
//                              const QString& DAccount,
//                              const QString& DSalary,
//                              const QString&DAddress);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    const QList<Staff> GetQlist();
    void delItem(int index);
    Staff reItem(int index);
signals:

public slots:

private:
    QList<Staff> m_Staffs;
};




#endif // STAFFDOMEL_H

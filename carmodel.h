#ifndef CARMODEL_H
#define CARMODEL_H
#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QObject>


class Car{
public:
    Car(const QVariant&  CNO  ,
          const QVariant& CServertime,
          const QVariant& CModel ,
          const QVariant& CLine,
          const QVariant& CServicedtime,
          const QVariant& CBrand);
    QVariant CNO  ,CServertime,CModel ,CLine,CServicedtime,CBrand;
};



class CarModel :public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
        CNORole = Qt::UserRole + 1,
        CServertimeRole,
        CModelRole,
        CLineRole,
        CServicedtimeRole,
        CBrandRole
    };
    CarModel(QObject *parent = 0);
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
    QList<Car> GetQlist();
    void delItem(int index);
    Car reItem(int index);
    void deletall();
    void addItem(const Car& car);
signals:

public slots:

private:
    QList<Car> m_Cars;
};


#endif // CARMODEL_H

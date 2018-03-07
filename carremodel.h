#ifndef CARREMODEL_H
#define CARREMODEL_H
#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QObject>

class CarRe{
public:
    CarRe(const QVariant&  Reno  ,
          const QVariant&  Retime,
          const QVariant&  Recost ,
          const QVariant&  Repairdetail,
          const QVariant&  Redepartment,
          const QVariant&  Recar);
    QVariant Reno  ,Retime,Recost ,Repairdetail,Redepartment,Recar;
};



class CarRemodel:public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
        RenoRole = Qt::UserRole + 1,
        RetimeRole,
        RecostRole,
        RepairdetailRole,
        RedepartmentRole,
        RecarRole
    };
    CarRemodel(QObject *parent = 0);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    QList<CarRe> GetQlist();
    void delItem(int index);
    CarRe reItem(int index);
    void deletall();
    void addItem(const CarRe& carre);
private:
     QList<CarRe> m_CarRe;
};

#endif // CARREMODEL_H

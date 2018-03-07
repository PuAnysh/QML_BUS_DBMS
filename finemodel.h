#ifndef FINEMODEL_H
#define FINEMODEL_H

#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QObject>



class Fine{
public:
    Fine(const QVariant&  Bno  ,
          const QVariant&  Btime,
          const QVariant&  Bdetial ,
          const QVariant&  Breakcar,
          const QVariant&  Breakdriver);
    QVariant Bno  ,Btime,Bdetial ,Breakcar,Breakdriver;
};



class FineModel : public QAbstractListModel
{
    Q_OBJECT
public:
    FineModel(QObject *parent = 0);
    enum{
        BnoRole = Qt::UserRole + 1,
        BtimeRole,
        BdetialRole,
        BreakcarRole,
        BreakdriverRole
    };
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    QList<Fine> GetQlist();
    void delItem(int index);
    Fine reItem(int index);
    void deletall();
    void addItem(const Fine& fine);
private:
     QList<Fine> m_fines;
};

#endif // FINEMODEL_H

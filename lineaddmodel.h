#ifndef LINEADDMODEL_H
#define LINEADDMODEL_H

#include <QAbstractListModel>
#include <QAbstractTableModel>
#include <QStringList>
#include <QObject>


class Line{
public:
    Line(QVariant station , QVariant time) ;
    QVariant station , time;
};

class LineAddModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum{
        StationRole = Qt::UserRole+1,
        TimeRole
    };
    LineAddModel(QObject *parent = 0);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    void delItem(int index);
    Line reItem(int index);
    void deletall();
    void addItem(const Line& line, int index);
signals:

public slots:
public:
    QList<Line> m_lines;
};

#endif // LINEADDMODEL_H

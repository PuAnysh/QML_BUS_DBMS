#ifndef SQLWIDGET_H
#define SQLWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QTableWidget>
#include <QDebug>
#include <QPoint>
#include <sql_link.h>
class SQLWidget : public QDialog
{
    Q_OBJECT
public:
    SQLWidget(QString q, QDialog *parent = 0);
    Q_INVOKABLE QVariant setSQL(QString str ,int index = 0);

signals:

public slots:
    void onBtnOKclick();
    void TEST();
private:
    int p = 0;
    QVariant  temp;
    QSqlDatabase database;
    QSqlQuery query;
    QSqlQueryModel * model;
    QTableView* view;
    QVBoxLayout *layoutmain;
    QHBoxLayout *layoutbtn;
    QPushButton *btnok;
    QPushButton *btncal;
};

#endif // SQLWIDGET_H

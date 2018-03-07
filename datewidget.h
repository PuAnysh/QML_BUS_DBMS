#ifndef DATEWIDGET_H
#define DATEWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QDateEdit>
#include <QCollator>
#include <QCalendarWidget>
#include <QDateTimeEdit>
#include <QTimeEdit>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QDebug>
class DateWidget : public QDialog
{
    Q_OBJECT
public:
    DateWidget(QWidget *parent = 0);
    Q_INVOKABLE QVariant getDate();
    Q_INVOKABLE QVariant getCal();

signals:

public slots:
    void onBtn();
    void onBtne();
private:
    QStackedWidget* sw;
    QWidget* w1;
    QWidget* w2;
    QVariant t;
    QPushButton* btnok;
    QPushButton* btncal;
    QPushButton* btnoke;
    QPushButton* btncale;
    QTimeEdit* edittime;
    QCalendarWidget* calWidget;
    QVBoxLayout * layoutmain1;
    QVBoxLayout * layoutmain2;
    QHBoxLayout * layoutbtn;
    QHBoxLayout * layoutbtne;
    QVBoxLayout* mainlayout;
};

#endif // DATEWIDGET_H

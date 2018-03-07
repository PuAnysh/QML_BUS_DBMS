#ifndef STAFFWIDGETWORK_H
#define STAFFWIDGETWORK_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QMetaObject>
#include <QQuickView>
#include <QQuickItem>
#include <QUrl>
#include <QQmlProperty>

class StaffWidgetWork : public QObject
{
    Q_OBJECT
public:
    StaffWidgetWork(QQmlApplicationEngine& engine , QObject *parent = 0);
    //QML连接使用必要变量
    QQmlApplicationEngine engine;
    QObject * object = NULL;

    Q_INVOKABLE void setItem();
    Q_INVOKABLE void delItem();
    Q_INVOKABLE void test();
    Q_INVOKABLE void Couttt();
    explicit StaffWidgetWork(QObject *parent = 0);
    ~StaffWidgetWork();

signals:

public slots:
};

#endif // STAFFWIDGETWORK_H

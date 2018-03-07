#ifndef RECQMLSIGNAL_H
#define RECQMLSIGNAL_H

#include <QObject>
#include <QQuickItem>
#include <QDebug>
class RecQMLSignal : public QObject
{
    Q_OBJECT
public slots:
    void OnClick(QString str){
        qDebug()<<str<<endl;
    }
};

#endif // RECQMLSIGNAL_H

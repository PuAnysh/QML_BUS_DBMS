#include "myclass.h"

#include <QtGui/QGuiApplication>

#include <QtQml/QQmlContext>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickView>

MyClass::MyClass(QObject *parent) :
    QObject(parent)
{
}

//十六进制转十进制
void MyClass::slot_hex2dec(QString str_num)
{
    qDebug() << "11" << str_num;
    bool ok;

    emit sig_disp("dec:" + QString::number(str_num.toInt(&ok,16),10));
}

//十进制转十六进制
void MyClass::slot_dec2hex(QString str_num)
{
    qDebug() << "22" << str_num;
    bool ok;

    emit sig_disp("hex:0x" + QString::number(str_num.toInt(&ok,10),16));
}

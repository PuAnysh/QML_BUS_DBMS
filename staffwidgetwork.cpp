#include "staffwidgetwork.h"

StaffWidgetWork::StaffWidgetWork(QObject *parent) : QObject(parent)
{
    QQmlComponent component(&engine , QUrl("qrc:/StaffWidget.qml"));
    object = component.create();
    qDebug()<<object->objectName()<<endl;
}

StaffWidgetWork::~StaffWidgetWork(){

    delete object;
}


void StaffWidgetWork::delItem(){
    QMetaObject::invokeMethod(object , "deleteALL"
                              );
}

void StaffWidgetWork::setItem(){
 //   QVariant DNO = "2" , DName = "1232" , DID  = "123221", DWorkTime  = "12132", DAccount  = "11232132", DSalary  = "1212321", DAddres = "1213212";
    QVariant re;
    QVariant DNO = "12324" , DName = "32412" , DID  = "124", DWorkTime  = "1254", DAccount  = "1432", DSalary  = "1422", DAddres = "12";
  //  QVariant avg2;
    //avg = "12,12,12,12,12,12,12";
    QQmlProperty::write(object , "gDNO" , "12");
    QQmlProperty::write(object , "gDName" , "12");
    QQmlProperty::write(object , "gDID" , "12");
    QQmlProperty::write(object , "gDWorkTime" , "12");
    QQmlProperty::write(object , "gDAccount" , "12");
    QQmlProperty::write(object , "gDSalary" , "12");
    QQmlProperty::write(object , "gDAddres" , "12");
    QMetaObject::invokeMethod(object , "addItem" ,
                              Q_RETURN_ARG(QVariant , re),
                              Q_ARG(QVariant , DNO),
                              Q_ARG(QVariant , DName),
                              Q_ARG(QVariant , DID),
                              Q_ARG(QVariant , DWorkTime),
                              Q_ARG(QVariant , DAccount),
                              Q_ARG(QVariant , DSalary),
                              Q_ARG(QVariant , DAddres));
}


void StaffWidgetWork::test(){
    QVariant st;
     QMetaObject::invokeMethod(object , "modify" ,
                               Q_RETURN_ARG(QVariant , st),
                               Q_ARG(QVariant , "dsfas") );
}




void StaffWidgetWork::Couttt(){
    //debug
    QVariant st;
    QMetaObject::invokeMethod(object , "debug" ,
                              Q_RETURN_ARG(QVariant , st),
                              Q_ARG(QVariant , "dsfas") );
    qDebug()<<st<<endl;
}

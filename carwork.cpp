#include "carwork.h"



CarWork::CarWork(CarModel *model, QObject *parent) :QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
    p_model = model;
}

void CarWork::execSQL(QString str)
{
    query.exec(str);
}

void CarWork::querys(QString str, QString str2)
{
    str.simplified();
    str2.simplified();
    QString serch_sql = "select*\
            from car";
    if(str.size() > 0){
        serch_sql.append(QString(" where cno = '%1';").arg(str));
    }
    else if(str2.size() > 0){
        serch_sql.append(QString(" where dname = '%1';").arg(str2));
    }
    p_model->deletall();
    query.exec(serch_sql);
    qDebug()<<serch_sql;
    while(query.next()){
        p_model->addItem(Car(query.value("cno"),
                               query.value("serverlife"),
                               query.value("cmodel"),
                               query.value("lno"),
                               query.value("servicedtime"),
                               query.value("cbrand")
                               ));
    }
    qDebug()<<"OK3";
}

void CarWork::delItem(int index)
{
    if(index < 0) return ;
    //MAINquery.exec("PRAGMA foreign_keys = OFF");
    Car t = p_model->reItem(index);
    p_model->delItem(index);
    QString slt_sql = QString("delete\
            from car\
             where cno = '%1'").arg(t.CNO.toString());
            qDebug()<<slt_sql<<endl;
    qDebug()<<query.exec(slt_sql);
    //MAINquery.exec("PRAGMA foreign_keys = ON");
}

QVariant CarWork::redata(int index, QString str)
{
    if(index < 0 || index >= p_model->GetQlist().size()) return "";
    Car t = p_model->reItem(index);
    if(str == "cbrand") return t.CBrand;
    if(str=="lno") return t.CLine;
    if(str == "cmodel") return t.CModel;
    if(str == "cno") return t.CNO;
    if(str == "serverlife") return t.CServertime;
    if(str == "servicedtime") return t.CServicedtime;
    return "";
}

void CarWork::addItem(QString str1, QString str2, QString str3, QString str4, QString str5, QString str6)
{
    qDebug()<<"OK,addItem";

    QString insert_sql = "insert\
            into car(cno,serverlife ,cmodel,lno,servicedtime,cbrand)\
            values(?,?,?,?,?,?);";
    query.prepare(insert_sql);
    query.addBindValue(str1);
    query.addBindValue(str2);
    query.addBindValue(str3);
    query.addBindValue(str4);
    query.addBindValue(str5);
    query.addBindValue(str6);
    if(!query.exec() ){
        QMessageBox::information(NULL, "出现错误", "插入失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    CarWork::querys("" , "");
    qDebug()<<"OK";
}

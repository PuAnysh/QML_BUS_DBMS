#include "schedulework.h"

ScheduleWork::ScheduleWork(ScheduleModel* model ,QObject *parent) : QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
    p_model = model;
}

void ScheduleWork::execSQL(QString str)
{
    query.exec(str);
}

void ScheduleWork::querys(QString str, QString str2)
{
    str.simplified();
    str2.simplified();

    QString serch_sql = "select*\
            from Schedule , driver\
            where Schedule.driverno = driver.dno";
    if(str.size() > 0){
        serch_sql.append(QString(" and Schedule.weekth = '%1'").arg(str));
    }
    if(str2.size() > 0){
        serch_sql.append(QString(" and driver.dno = '%1'").arg(str2));
    }
    p_model->deletall();
    query.exec(serch_sql);
    qDebug()<<serch_sql;
    while(query.next()){
        p_model->addItem(Schedule(query.value("weekth"),
                               query.value("scline"),
                               query.value("driverno"),
                               query.value("dname"),
                               query.value("begintime"),
                               query.value("endtime")
                               ));
    }
    qDebug()<<"OK3";
}

void ScheduleWork::delItem(int index)
{
    if(index < 0) return ;
    //MAINquery.exec("PRAGMA foreign_keys = OFF");
    Schedule t = p_model->reItem(index);
    p_model->delItem(index);
    QString slt_sql = QString("delete\
            from Schedule\
            where weekth ='%1' and driverno = '%2';").arg(t.weekth.toString()).arg(t.driverno.toString());
            qDebug()<<slt_sql<<endl;
    query.exec(slt_sql);
    //MAINquery.exec("PRAGMA foreign_keys = ON");
}

QVariant ScheduleWork::redata(int index, QString str)
{
    if(index < 0 || index >= p_model->GetQlist().size()) return "";
    Schedule t = p_model->reItem(index);
    if(str == "begintime") return t.begintime;
    if(str=="drivername") return t.drivername;
    if(str == "driverno") return t.driverno;
    if(str == "endtime") return t.endtime;
    if(str == "scline") return t.scline;
    if(str == "weekth") return t.weekth;
    return "";
}



void ScheduleWork::addItem(QString str1, QString str2, QString str3, QString str4, QString str5)
{
    qDebug()<<"OK,addItem";
    QString insert_sql = "insert\
            into Schedule(weekth,scline ,driverno,begintime,endtime)\
            values(?,?,?,?,?);";
    query.prepare(insert_sql);
    query.addBindValue(str1);
    query.addBindValue(str2);
    query.addBindValue(str3);
    query.addBindValue(str4);
    query.addBindValue(str5);
    if(!query.exec() ){
        QMessageBox::information(NULL, "出现错误", "插入失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    ScheduleWork::querys("" , "");
    qDebug()<<"OK";
}

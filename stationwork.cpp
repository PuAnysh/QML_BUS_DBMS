#include "stationwork.h"

StationWork::StationWork(StationModel *model, QObject *parent) : QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
    p_model = model;
}

void StationWork::execSQL(QString str)
{
    query.exec(str);
}

void StationWork::querys(QString str, QString str2)
{
    str.simplified();
    str2.simplified();
    QString serch_sql = "select*\
            from station";
    if(str.size()> 0){
        serch_sql.append(QString(" where sname = '%1'").arg(str));
    }
    p_model->deletall();
    query.exec(serch_sql);
    qDebug()<<serch_sql;
    while(query.next()){
        qDebug()<<query.value("sname")<<" "<<query.value("saddress")<<endl;
        p_model->addItem(Station(query.value("sname"),
                               query.value("saddress")
                               ));
    }
    qDebug()<<"OK3";
}

void StationWork::delItem(int index)
{
    if(index < 0) return ;
    //MAINquery.exec("PRAGMA foreign_keys = OFF");
    Station t = p_model->reItem(index);
    p_model->delItem(index);
    QString slt_sql = QString("delete\
            from station\
            where sname='%1';").arg(t.sname.toString());
            qDebug()<<slt_sql<<endl;
    query.exec(slt_sql);
    //MAINquery.exec("PRAGMA foreign_keys = ON");
}

QVariant StationWork::redata(int index, QString str)
{
    if(index < 0 || index >= p_model->GetQlist().size()) return "";
    Station t = p_model->reItem(index);
    if(str == "sname") return t.sname;
    if(str=="saddress") return t.saddress;
    return "";
}

void StationWork::addItem(QString str1, QString str2)
{
    qDebug()<<"OK,addItem";
    QString insert_sql = "insert\
            into station(sname,saddress )\
            values(?,?);";
    query.prepare(insert_sql);
    query.addBindValue(str1);
    query.addBindValue(str2);
    query.exec();
    StationWork::querys("" , "");
    qDebug()<<"OK";
}

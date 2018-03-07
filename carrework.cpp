#include "carrework.h"

CarReWork::CarReWork(CarRemodel *model, QObject *parent) : QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;

    p_model = model;
}

void CarReWork::execSQL(QString str)
{
    query.exec(str);
}

void CarReWork::querys(QString str, QString str2)
{
    str.simplified();
    str2.simplified();

    QString serch_sql = "select*\
            from repairrecord";
    if(str.size() > 0) {
        serch_sql.append(QString(" where recar = '%1'") .arg(str));
    }
    p_model->deletall();
    query.exec(serch_sql);
    qDebug()<<serch_sql;
    while(query.next()){
        p_model->addItem(CarRe(query.value("reno"),
                               query.value("retime"),
                               query.value("recost"),
                               query.value("repairdetail"),
                               query.value("redepartment"),
                               query.value("recar")
                               ));
    }
    qDebug()<<"OK3";
}

void CarReWork::delItem(int index)
{
    if(index < 0) return ;
    //MAINquery.exec("PRAGMA foreign_keys = OFF");
    CarRe t = p_model->reItem(index);
    p_model->delItem(index);
    QString slt_sql = QString("delete\
            from repairrecord\
            where reno='%1';").arg(t.Reno.toString());
            qDebug()<<slt_sql<<endl;
    query.exec(slt_sql);
   // MAINquery.exec("PRAGMA foreign_keys = ON");
}

QVariant CarReWork::redata(int index, QString str)
{
    if(index < 0 || index >= p_model->GetQlist().size()) return "";
    CarRe t = p_model->reItem(index);
    if(str == "recar") return t.Recar;
    if(str=="recost") return t.Recost;
    if(str == "redepartment") return t.Redepartment;
    if(str == "reno") return t.Reno;
    if(str == "repairdetail") return t.Repairdetail;
    if(str == "retime") return t.Retime;
    return "";
}

void CarReWork::addItem(QString str1, QString str2, QString str3, QString str4, QString str5, QString str6)
{
    qDebug()<<"OK,addItem";
    QString insert_sql = "insert\
            into repairrecord(reno,retime ,recost,repairdetail,redepartment,recar)\
            values(?,?,?,?,?,?);";
    query.prepare(insert_sql);
    query.addBindValue(str1);
    query.addBindValue(str2);
    query.addBindValue(str3.toInt());
    query.addBindValue(str4);
    query.addBindValue(str5);
    query.addBindValue(str6);
    if(!query.exec() ){
        QMessageBox::information(NULL, "出现错误", "插入失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    CarReWork::querys("" , "");
    qDebug()<<"OK";
}


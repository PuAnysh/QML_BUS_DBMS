#include "finework.h"

FineWork::FineWork(FineModel *model ,QObject *parent) : QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
    p_model = model;
}


void FineWork::execSQL(QString str)
{
    query.exec(str);
}

void FineWork::querys(QString str, QString str2)
{
    str.simplified();
    str2.simplified();
    QString serch_sql = "select*\
            from fine , car , driver\
            where fine.breakcar = car.cno \
            and breakdriver = driver.dno";
    p_model->deletall();
    if(str.size() > 0){
        serch_sql.append(QString(" and car.cno = '%1'").arg(str) );
    }
    if(str2.size() > 0){
        serch_sql.append(QString(" and driver.dno = '%1'").arg(str2) );
    }
    query.exec(serch_sql);
    qDebug()<<serch_sql;
    while(query.next()){
        p_model->addItem(Fine(query.value("bno"),
                               query.value("btime"),
                               query.value("bdetial"),
                               query.value("breakcar"),
                               query.value("dname")
                               ));
    }
    qDebug()<<"OK3";
}

void FineWork::delItem(int index)
{
    if(index < 0) return ;
    //MAINquery.exec("PRAGMA foreign_keys = OFF");
    Fine t = p_model->reItem(index);
    p_model->delItem(index);
    QString slt_sql = QString("delete\
            from fine\
            where bno='%1';").arg(t.Bno.toString());
            qDebug()<<slt_sql<<endl;
    query.exec(slt_sql);
    //MAINquery.exec("PRAGMA foreign_keys = ON");
}

QVariant FineWork::redata(int index, QString str)
{
    if(index < 0 || index >= p_model->GetQlist().size()) return "";
    Fine t = p_model->reItem(index);
    if(str == "bno") return t.Bno;
    if(str=="bdetial") return t.Bdetial;
    if(str == "breakcar") return t.Breakcar;
    if(str == "breakdriver") return t.Breakdriver;
    if(str == "btime") return t.Btime;
    return "";
}

void FineWork::addItem(QString str1, QString str2, QString str3, QString str4, QString str5)
{
    qDebug()<<"OK,addItem";
    QString insert_sql = "insert into fine(bno,btime,bdetial,breakcar,breakdriver)\
            values (?,?,?,?,?);";
    query.prepare(insert_sql);
    query.addBindValue(str1);
    query.addBindValue(str2);
    query.addBindValue(str3);
    query.addBindValue(str4);
    query.addBindValue(str5);
    if(!query.exec() ){
        QMessageBox::information(NULL, "出现错误", "插入失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    FineWork::querys("" , "");
    qDebug()<<"OK";
}

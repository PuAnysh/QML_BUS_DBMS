#include "staffwork.h"

StaffWork::StaffWork(StaffModel* model , QObject *parent) : p_model(model) , QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
}


void StaffWork::test(){
    p_model->addItem(Staff("1","2","3","4","5","6","7","8") );
    qDebug()<<"test"<<endl;
}

void StaffWork::testGet(int index)
{
    const QList<Staff> t = p_model->GetQlist();
    if(index == -1) return ;
    qDebug()<<t[index].DNO<<endl;
}

void StaffWork::execSQL(QString str)
{
    query.exec(str);
}

void StaffWork::querys(QString str, QString str2)
{
    str.simplified();
    str2.simplified();
    QString serch_sql = "select*\
            from driver";
    if(str.size() > 0){
        serch_sql.append(QString(" where dno = '%1';").arg(str));
    }
    else if(str2.size() > 0){
        serch_sql.append(QString(" where dname = '%1';").arg(str2));
    }
    p_model->deletall();
    query.exec(serch_sql);
    qDebug()<<serch_sql;
    while(query.next()){
        p_model->addItem(Staff(query.value("dno"),
                               query.value("dname"),
                               query.value("dID"),
                               query.value("dposition"),
                               query.value("posttime"),
                               query.value("daccount"),
                               query.value("dsalary"),
                               query.value("daddress")
                               ));
    }
    qDebug()<<"OK3";
}


void StaffWork::delItem(int index)
{
    if(index < 0) return ;
    //MAINquery.exec("PRAGMA foreign_keys = OFF");
    Staff t = p_model->reItem(index);
    p_model->delItem(index);
    QString slt_sql = QString("delete\
            from driver\
            where dno='%1';").arg(t.DNO.toString());
            qDebug()<<slt_sql<<endl;
    query.exec(slt_sql);
    //MAINquery.exec("PRAGMA foreign_keys = ON");
}

QVariant StaffWork::redata(int index , QString str)
{
    if(index < 0 || index >= p_model->GetQlist().size()) return "";
    Staff t = p_model->reItem(index);
    if(str == "dno") return t.DNO;
    if(str=="dname") return t.DName;
    if(str == "did") return t.DID;
    if(str == "dposttime") return t.DWorkTime;
    if(str == "dsalary") return t.DSalary;
    if(str == "daddress") return t.DAddress;
    if(str == "daccount") return t.DAccount;
    if(str == "dposition") return t.DPosition;
    return "";
}

void StaffWork::addItem(QString str1, QString str2, QString str3,
                        QString str4, QString str5, QString str6,
                        QString str7, QString str8)
{
    QString insert_sql = "insert\
            into driver(dno,dname,dID,Posttime,dsalary,daddress,daccount,dposition)\
            values(?,?,?,?,?,?,?,?);";
    query.prepare(insert_sql);
    query.addBindValue(str1);
    query.addBindValue(str2);
    query.addBindValue(str3);
    query.addBindValue(str4);
    query.addBindValue(str5.toInt());
    query.addBindValue(str6);
    query.addBindValue(str7);
    query.addBindValue(str8);
    if(!query.exec() ){
        QMessageBox::information(NULL, "出现错误", "插入失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    StaffWork::querys("" , "");
    qDebug()<<"OK";
}




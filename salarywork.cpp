#include "salarywork.h"

SalaryWork::SalaryWork(SalaryModel *model ,QObject *parent) : QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
    p_model = model;
}

void SalaryWork::execSQL(QString str)
{
    query.exec(str);
}

void SalaryWork::querys(QString str, QString str2)
{
    str.simplified();
    str2.simplified();

    QString serch_sql = "select salary.* , driver.*\
            from   salary , driver\
            where salary.saccount = driver.dno";
    if(str.size() > 0){
           serch_sql.append(QString(" and driver.dno = '%1'").arg(str));
    }
    serch_sql.append(";");
    p_model->deletall();
    query.exec(serch_sql);
    qDebug()<<serch_sql;
    while(query.next()){
        p_model->addItem(Salary(query.value("sno"),
                               query.value("stime"),
                               query.value("ssum"),
                               query.value("dID"),
                               query.value("saccount"),
                               query.value("dname")
                               ));
    }
    qDebug()<<"OK3";
}

void SalaryWork::delItem(int index)
{
    if(index < 0) return ;
    //MAINquery.exec("PRAGMA foreign_keys = OFF");
    Salary t = p_model->reItem(index);
    p_model->delItem(index);
    QString slt_sql = QString("delete\
            from salary\
            where sno='%1';").arg(t.Sno.toString());
            qDebug()<<slt_sql<<endl;
    query.exec(slt_sql);
   // MAINquery.exec("PRAGMA foreign_keys = ON");
}

QVariant SalaryWork::redata(int index, QString str)
{
    if(index < 0 || index >= p_model->GetQlist().size()) return "";
    Salary t = p_model->reItem(index);
    if(str == "saccount") return t.Saccount;
    if(str=="did") return t.Sid;
    if(str == "sname") return t.Sname;
    if(str == "sno") return t.Sno;
    if(str == "ssum") return t.Ssum;
    if(str == "stime") return t.Stime;
    return "";
}

void SalaryWork::addItem(QString str1, QString str2, QString str3, QString str4)
{
    qDebug()<<"OK,addItem";
    QString insert_sql = "insert\
            into salary(sno , stime , ssum , saccount)\
            values(? , ? , ?, ?)";
    query.prepare(insert_sql);
    query.addBindValue(str1);
    query.addBindValue(str2);
    query.addBindValue(str3.toInt());
    query.addBindValue(str4);
    if(!query.exec() ){
        QMessageBox::information(NULL, "出现错误", "插入失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    SalaryWork::querys("" , "");
    qDebug()<<"OK";
}

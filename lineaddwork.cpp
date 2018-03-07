#include "lineaddwork.h"

LineAddWork::LineAddWork(LineAddModel *model, QObject *parent) :QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
    p_model = model;
}

void LineAddWork::querys(QString str, QString str2)
{
    str.simplified();
    str2.simplified();
    p_model->deletall();
    QString e = QString("select* from line where lno = '%1' order by lposition").arg(str);
    qDebug()<<e<<endl;
    query.exec(e);
    int index = -1;
    while (query.next()) {
        addItem(index++ , query.value("lstation").toString() ,query.value("costtime").toString() );

    }
}

void LineAddWork::delItem(int index)
{
    p_model->delItem(index);
}

void LineAddWork::btnok(QString str)
{
    query.exec(QString("delete from line where lno = '%1'").arg(str));
    int t = 1;
    for(int i = 0 ; i < p_model->m_lines.size() ; i++){
        Line tt = p_model->m_lines[i];
        query.prepare(QString("insert into\
                       line(lno,lposition,lstation,costtime)\
                        values(?,?,?,?)"));
        query.addBindValue(str);
        query.addBindValue(t++);
        query.addBindValue(tt.station.toString());
        query.addBindValue(tt.time.toInt());
        query.exec();
    }
}

void LineAddWork::modify(QString str)
{
    querys(str , "");

}

void LineAddWork::addItem(int index , QString str , QString str1)
{

    str.simplified();str1.simplified();
    if(str.size()== 0 || str1.size() == 0) return ;
    Line t( str , str1.toInt());
    qDebug()<<str<<" "<<str1<<endl;
    p_model->addItem(t , index);
}

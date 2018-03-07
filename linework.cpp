#include "linework.h"

LineWork::LineWork(TreeModel *model, QObject *parent) :QObject(parent)
{
    p_model = model;
    database = MAINdatabase;
    query = MAINquery;
    lno = "";
}

void LineWork::Insert(TreeItem* ti)
{
    p_model->insertRow(p_model->index(-1 ,-1), ti);
}

void LineWork::RemoveRow()
{
    p_model->reomoveRow();
}

void LineWork::RemoveAll()
{
    p_model->removeALL();
}

void LineWork::linequery(QString str , QString str2)
{
    RemoveAll();
    str.simplified();
 //   mp.clear();
    QString e ="select distinct lno\
            from line";

    if(str.size() > 0){
                   e.append (QString(" where lno = '%1'").arg(str));
               }
    qDebug()<<e;
    query.exec(e);
    qDebug()<<query.size()<<endl;
    while(query.next()){
       QVariant t = query.value("lno");
       TreeItem* item = new TreeItem({t.toString() , "" , ""});
       QSqlQuery t_query = query;
       t_query.exec(QString("select lstation , costtime\
                   from line\
                   where lno = '%1'\
                   order by lposition").arg(t.toString()) );
       while(t_query.next()){

                       QString station = t_query.value("lstation").toString();
                        int time = t_query.value("costtime").toInt();
               //        qDebug()<<station<<" "<<time<<endl;
                       item->appendChild(new TreeItem({"" , station , time}));
                   }
                   Insert(item);


    }

}

void LineWork::deleteLine()
{
    qDebug()<<"delete "<<lno;
  //  MAINquery.exec("PRAGMA foreign_keys = OFF");
    QString str= QString("delete \
                           from line\
                         where lno = '%1';").arg(lno);
    //QString strr = "select * from line";
    qDebug()<<query.exec(str);
    linequery("" , "");
  //  MAINquery.exec("PRAGMA foreign_keys = ON");
}

void LineWork::setIndex(QModelIndex index)
{
    if(index.parent().isValid()){
        index= index.parent();
    }
    lno = index.data(TreeModel::LineRole).toString();
//    index = index.parent();
    qDebug()<<index.data(TreeModel::LineRole);
    //    qDebug()<<index.parent().isValid();
}

QVariant LineWork::getLno()
{
    return lno;
}

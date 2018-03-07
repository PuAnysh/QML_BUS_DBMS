#include "sqlwidget.h"

SQLWidget::SQLWidget(QString q , QDialog *parent) : QDialog(parent)
{
    query = MAINquery;
    model = new QSqlQueryModel;
 //   model->setQuery(q);
    view = new QTableView;
    view->setModel(model);


    layoutmain = new QVBoxLayout();
    layoutbtn = new QHBoxLayout();

    btncal = new QPushButton("取消");
    btnok = new QPushButton("确定");

    layoutbtn->addWidget(btnok);
    layoutbtn->addWidget(btncal);

    layoutmain->addWidget(view);
    layoutmain->addLayout(layoutbtn);
    setLayout(layoutmain);


    connect(btnok , SIGNAL(clicked(bool)) , this , SLOT(onBtnOKclick()) );
    connect(btncal , SIGNAL(clicked(bool)) , this ,SLOT(close()) );
}

QVariant SQLWidget::setSQL(QString str , int index)
{
    p = index;
    temp = "";
    model->setQuery(str);
    this->exec();

    qDebug()<<temp<<endl;
    return temp;
}

void SQLWidget::onBtnOKclick()
{
     QModelIndex t =  view->currentIndex();
     qDebug()<<t.row();

     QModelIndex tt =model->index(t.row() , p);
     temp = tt.data(0);
     this->close();

     qDebug()<<tt.data(0);
}

void SQLWidget::TEST()
{
    setSQL("select  *\
           from driver");
}

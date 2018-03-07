#include "datewidget.h"

DateWidget::DateWidget(QWidget *parent) : QDialog(parent)
{
    sw = new QStackedWidget();
    w1 = new QWidget();
    w2 = new QWidget();
    layoutmain1 = new QVBoxLayout();
    layoutmain2 = new QVBoxLayout();
    layoutbtn = new QHBoxLayout();
    layoutbtne = new QHBoxLayout();
    btncal = new QPushButton("取消");
    btnok = new QPushButton("确定");
    btncale = new QPushButton("取消");
    btnoke = new QPushButton("确定");

    calWidget = new QCalendarWidget();
    edittime = new QTimeEdit();
    edittime->setDisplayFormat("HH:mm");
    layoutbtn->addWidget(btnok);
    layoutbtn->addWidget(btncal);

    layoutbtne->addWidget(btnoke);
    layoutbtne->addWidget(btncale);

    layoutmain1->addWidget(calWidget);
    layoutmain1->addLayout(layoutbtn);

    layoutmain2->addWidget(edittime);
    layoutmain2->addLayout(layoutbtne);

    w1->setLayout(layoutmain1);
    w2->setLayout(layoutmain2);

    sw->addWidget(w1);
    sw->addWidget(w2);

    mainlayout = new QVBoxLayout();
    mainlayout->addWidget(sw);
    setLayout(mainlayout);


    connect(btnok , SIGNAL(clicked(bool)) , this ,SLOT(onBtn()) );
    connect(btnoke , SIGNAL(clicked(bool)) , this ,SLOT(onBtne()) );

//    setLayout(layoutmain);
}

QVariant DateWidget::getDate()
{
    t = "";
    sw->setCurrentIndex(1);
    this->exec();

    return t;
}

QVariant DateWidget::getCal()
{
    t = "";
    sw->setCurrentIndex(0);
    this->exec();
    return t;

}

void DateWidget::onBtn()
{
    t = calWidget->selectedDate().toString("yyyy-MM-dd");
    this->close();
}

void DateWidget::onBtne()
{
    t = edittime->time().toString("HH:mm");
    qDebug()<<edittime->time().toString("HH:mm")<<endl;
    this->close();
}

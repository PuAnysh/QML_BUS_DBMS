#include "staffadd.h"
#include "ui_staffadd.h"

StaffAdd::StaffAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffAdd)
{
    ui->setupUi(this);
    connect(ui->btnadd , SIGNAL(clicked(bool)) , this ,SLOT(addItem()));
}

StaffAdd::~StaffAdd()
{
    delete ui;
}

void StaffAdd::addItem()
{
    emit execItem(ui->editCno->text() , ui->EditCname->text() , ui->EditCid->text(),
                  ui->editworktime->text() , ui->Editcsalary->text() ,
                  ui->EditCaddress->text(), ui->editaccount->text() ,
                  ui->Editpossition->text());
    this->close();
}

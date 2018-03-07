#include "dbwork.h"

DBwork::DBwork(QObject *parent) : QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
}

void DBwork::saveDB()
{
     QString file = QFileDialog::getSaveFileName(0, tr("Save File"),
                                                 "",
                                                 tr("*.bak"));
    QString e = QString("Backup   Database   BUS  To disk='%1'").arg(file);
    if(file =="") return;
    qDebug()<<e<<endl;

    if(QFile::copy("memory" , file)){
        QMessageBox::information(NULL, "备份成功", "备份成功", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else{
        QMessageBox::information(NULL, "备份错误", "备份失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }

}

void DBwork::reDB()
{
    QString file = QFileDialog::getOpenFileName(0,
                                                "Select one files to open",
                                                "",
                                                "*.bak ");
    if(file == "") return;

    MAINdatabase.close();
    QFile::remove("memory");
 //   QString e = QString("restore database BUS from disk = '%1'").arg(file);
    if(QFile::copy(file,"memory" )){
        QMessageBox::information(NULL, "恢复成功", "恢复成功，请重启", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else{
        QMessageBox::information(NULL, "恢复错误", "恢复失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    exit(0);
}

void DBwork::keyOpen()
{
    MAINquery.exec("PRAGMA foreign_keys = ON");
}

void DBwork::keyClose()
{
    MAINquery.exec("PRAGMA foreign_keys = OFF");
}

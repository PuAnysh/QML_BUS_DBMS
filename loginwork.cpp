#include "loginwork.h"

LoginWork::LoginWork(QObject *parent) : QObject(parent)
{
    database = MAINdatabase;
    query = MAINquery;
}

QVariant LoginWork::retype(QString name, QString passwd)
{
    qDebug()<<name<<" "<<passwd;
    if(query.exec(QString("select * from login where name = '%1'").arg(name)) ){
        while(query.next()){
            QString t = query.value("passwd").toString();
            qDebug()<<t<<endl;
            if(t == passwd){
                return query.value("type").toInt();
            }
            else
            {
                QMessageBox::information(NULL, "登入错误", "用户名或密码失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
                qDebug()<<"dfsa";
                return -1;
            }
        }
    }
    else
    {
        QMessageBox::information(NULL, "登入错误", "用户名或密码失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    QMessageBox::information(NULL, "登入错误", "用户名或密码失败", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    return -1;

}

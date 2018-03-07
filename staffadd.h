#ifndef STAFFADD_H
#define STAFFADD_H

#include <QDialog>

namespace Ui {
class StaffAdd;
}

class StaffAdd : public QDialog
{
    Q_OBJECT

public:
    explicit StaffAdd(QWidget *parent = 0);
    ~StaffAdd();
signals:
    void execItem(QString str1 , QString str2 , QString str3 , QString str4 ,
                  QString str5 , QString str6 , QString str7 , QString str8 );
public slots:
    void addItem();
private:
    Ui::StaffAdd *ui;
};

#endif // STAFFADD_H

#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = 0);

signals:

    void sig_disp(QVariant str_num);

public slots:

    void slot_hex2dec(QString str_num);
    void slot_dec2hex(QString str_num);
};
#endif // MYCLASS_H

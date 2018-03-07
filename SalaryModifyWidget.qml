import QtQuick 2.6
import QtQuick.Window 2.2

Window{
    id: mainWindow
    visible: true
    width: 500
    height: 215
    flags: Qt.Window | Qt.FramelessWindowHint
    property int index: 0
    function setIndex(x){
        index = x
        sno.mytext =  SalaryWork.redata(index , "sno")
        stime.mytext = SalaryWork.redata(index , "stime")
        ssum.mytext = SalaryWork.redata(index , "ssum")
        saccount.mytext = SalaryWork.redata(index , "saccount")
        if(x != -1) sno.disedit()
        else sno.abledit()
    }
    Rectangle{
        id:widget
        anchors.centerIn: parent;
        width: parent.width - 2;
        height: parent.height - 2;

        //标题部分
        TitleBar{
            id: titleBar;
            mainWindow: mainWindow;
            width: parent.width;
            height: 50;
        }
        //主窗口
        Rectangle{
            id:mainRect
            width: parent.width
            height: parent.height-50
            anchors.top: titleBar.bottom
            RectItem{
                id: sno
                anchors.top: mainRect.top
                mytitle:"工资单号"
            }
            RectItem{
                id: stime
                anchors.top: sno.bottom
                mytitle:"放款时间"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        stime.mytext =  DateWidget.getCal();
                    }
                }
            }
            RectItem{
                id: ssum
                anchors.top: stime.bottom
                mytitle:"工资"
            }
            RectItem{
                id:saccount
                anchors.top: ssum.bottom
                mytitle:"工资账户"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        saccount.mytext = SQLWIGHT.setSQL( " select *
                                        from driver " )
                    }
                }
            }


            //PushButton RectItem
            MyButton{
                id:btncal
                width: 100
                height: 34
                myText: "取消"
                source: "qrc:/src/icon/delete/6.png"
               // anchors.verticalCenter: parent.verticalCenter
                anchors.top: saccount.bottom
                anchors.right:  parent.right
                onBtnClicked: mainWindow.close()
            }
            MyButton{
                id:btnadd
                width: 100
                height: 34
                myText: "添加"
                source: "qrc:/src/icon/new/6.png"
               // anchors.verticalCenter: parent.verticalCenter
                anchors.top: saccount.bottom
                anchors.right:  btncal.left
                anchors.rightMargin: 10
                onBtnClicked:{
                    SalaryWork.delItem(index)
                    SalaryWork.addItem(
                                sno.getText(),
                                stime.getText(),
                                ssum.getText(),
                                saccount.getText()
                                 )
                    sno.mytext =  ""
                    stime.mytext = ""
                    ssum.mytext = ""
                    saccount.mytext = ""
                    mainWindow.close()
                }
            }

        }

    }
}

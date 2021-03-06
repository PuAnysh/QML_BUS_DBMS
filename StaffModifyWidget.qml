import QtQuick 2.6
import QtQuick.Window 2.2

Window{
    id: mainWindow
    visible: true
    width: 500
    height: 285
    flags: Qt.Window | Qt.FramelessWindowHint
    property int index: 0
    function setIndex(x){
        index = x
        dno.mytext = StaffWork.redata(index , "dno")
        dname.mytext = StaffWork.redata(index , "dname")
        did.mytext = StaffWork.redata(index , "did")
        dposttime.mytext = StaffWork.redata(index , "dposttime")
        dsalary.mytext = StaffWork.redata(index , "dsalary")
        daddress.mytext = StaffWork.redata(index , "daddress")
        daccount.mytext = StaffWork.redata(index , "daccount")
        dposition.mytext =StaffWork.redata(index , "dposition")
        if(x != -1){
            dno.disedit()
        }
        else{
            dno.abledit()
        }
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
                id: dno
                anchors.top: mainRect.top
                mytitle:"职工号"
            }
            RectItem{
                id: dname
                anchors.top: dno.bottom
                mytitle:"职工姓名"
            }
            RectItem{
                id: did
                anchors.top: dname.bottom
                mytitle:"职工身份证号"
            }
            RectItem{
                id:dposttime
                anchors.top: did.bottom
                mytitle:"入职时间"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        dposttime.mytext = DateWidget.getCal()
                    }
                }
            }
            RectItem{
                id:dsalary
                anchors.top: dposttime.bottom
                mytitle:"职工工资"
            }
            RectItem{
                id:daddress
                anchors.top: dsalary.bottom
                mytitle:"职工住址"
            }
            RectItem{
                id:daccount
                anchors.top: daddress.bottom
                mytitle:"职工账户"
            }
            RectItem{
                id:dposition
                anchors.top: daccount.bottom
                mytitle:"职称"
            }
            //PushButton RectItem
            MyButton{
                id:btncal
                width: 100
                height: 34
                myText: "取消"
                source: "qrc:/src/icon/delete/6.png"
               // anchors.verticalCenter: parent.verticalCenter
                anchors.top: dposition.bottom
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
                anchors.top: dposition.bottom
                anchors.right:  btncal.left
                anchors.rightMargin: 10
                onBtnClicked:{
                    StaffWork.delItem(index)
                    DBWork.keyOpen()
                    StaffWork.addItem(
                                      dno.getText(),
                                      dname.getText(),
                                      did.getText(),
                                      dposttime.getText(),
                                      dsalary.getText(),
                                      daddress.getText(),
                                      daccount.getText(),
                                      dposition.getText()
                                      )
                    dno.mytext = ""
                    dname.mytext = ""
                    did.mytext = ""
                    dposttime.mytext = ""
                    dsalary.mytext = ""
                    daddress.mytext = ""
                    daccount.mytext = ""
                    dposition.mytext =""
                    mainWindow.close()
                }
            }

        }

    }
}

import QtQuick 2.6
import QtQuick.Window 2.2

Window{
    id: mainWindow
    visible: true
    width: 500
    height: 140
    flags: Qt.Window | Qt.FramelessWindowHint
    property int index: 0
    function setIndex(x){
        index = x
        sname.mytext = StationWork.redata(index , "sname")
        saddress.mytext = StationWork.redata(index , "saddress")
        if(x != -1) {
            sname.disedit()
        }
        else{
            sname.abledit()
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
                id: sname
                anchors.top: mainRect.top
                mytitle:"站点名"
            }
            RectItem{
                id: saddress
                anchors.top: sname.bottom
                mytitle:"站点地址"
            }
            //PushButton RectItem
            MyButton{
                id:btncal
                width: 100
                height: 34
                myText: "取消"
                source: "qrc:/src/icon/delete/6.png"
               // anchors.verticalCenter: parent.verticalCenter
                anchors.top: saddress.bottom
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
                anchors.top: saddress.bottom
                anchors.right:  btncal.left
                anchors.rightMargin: 10
                onBtnClicked:{
                    StationWork.delItem(index)
                    StationWork.addItem(
                                      sname.getText(),
                                      saddress.getText()
                                      )
                    sname.mytext = ""
                    saddress.mytext = ""
                    mainWindow.close()
                }
            }

        }

    }
}

import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
Window{
    id: mainWindow
    visible: true
    width: 500
    height: 255
    flags: Qt.Window | Qt.FramelessWindowHint
    property int index: 0
    function setIndex(x){
        index = x
        cno.mytext = CarWork.redata(index , "cno")
        serverlife.mytext = CarWork.redata(index , "serverlife")
        cmodel.mytext = CarWork.redata(index , "cmodel")
        cline.mytext = CarWork.redata(index , "lno")
        servicedtime.mytext = CarWork.redata(index , "servicedtime")
        cbrand.mytext = CarWork.redata(index , "cbrand")
        if(x != -1) cno.disedit()
        else cno.abledit()
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
                id: cno
                anchors.top: mainRect.top
                mytitle:"车牌号"
            }
            RectItem{
                id: serverlife
                anchors.top: cno.bottom
                mytitle:"使用年限"
            }
            RectItem{
                id: cmodel
                anchors.top: serverlife.bottom
                mytitle:"车型"

            }
            RectItem{
                id:cline
                anchors.top: cmodel.bottom
                mytitle:"所属线路"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        cline.mytext = SQLWIGHT.setSQL( " select  distinct lno
                                        from line " )
                    }
                }
            }
            RectItem{
                id:servicedtime
                anchors.top: cline.bottom
                mytitle:"服役时间"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        servicedtime.mytext = DateWidget.getCal()
                    }
                }
            }
            RectItem{
                id:cbrand
                anchors.top: servicedtime.bottom
                mytitle:"厂商"
            }


            //PushButton RectItem
            MyButton{
                id:btncal
                width: 100
                height: 34
                myText: "取消"
                source: "qrc:/src/icon/delete/6.png"
               // anchors.verticalCenter: parent.verticalCenter
                anchors.top: cbrand.bottom
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
                anchors.top: cbrand.bottom
                anchors.right:  btncal.left
                anchors.rightMargin: 10
                onBtnClicked:{
                    CarWork.delItem(index)
                    DBWork.keyOpen()
                    CarWork.addItem(
                                cno.getText(),
                                serverlife.getText(),
                                cmodel.getText(),
                                cline.getText(),
                                servicedtime.getText(),
                                cbrand.getText() )

                    cno.mytext = ""
                    serverlife.mytext = ""
                    cmodel.mytext = ""
                    cline.mytext = ""
                    servicedtime.mytext = ""
                    cbrand.mytext = ""
                    mainWindow.close()
                }
            }

        }

    }
}

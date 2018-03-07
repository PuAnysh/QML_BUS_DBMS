import QtQuick 2.6
import QtQuick.Window 2.2

Window{
    id: mainWindow
    visible: true
    width: 500
    height: 250
    flags: Qt.Window | Qt.FramelessWindowHint
    property int index: 0
    function setIndex(x){
        index = x
        reno.mytext = CarReWork.redata(index , "reno");
        retime.mytext = CarReWork.redata(index , "retime");
        recost.mytext = CarReWork.redata(index , "recost");
        repairdetail.mytext = CarReWork.redata(index , "repairdetail");
        redepartment.mytext = CarReWork.redata(index , "redepartment");
        redepartment.mytext = CarReWork.redata(index , "redepartment");
        recar.mytext = CarReWork.redata(index , "recar");
        if(x != -1) reno.disedit()
        else reno.abledit()
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
                id: reno
                anchors.top: mainRect.top
                mytitle:"维修号"
            }
            RectItem{
                id: retime
                anchors.top: reno.bottom
                mytitle:"维修时间"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        retime.mytext = DateWidget.getCal()
                    }
                }
            }
            RectItem{
                id: recost
                anchors.top: retime.bottom
                mytitle:"维修费用"
            }
            RectItem{
                id:repairdetail
                anchors.top: recost.bottom
                mytitle:"维修详情"
            }
            RectItem{
                id:redepartment
                anchors.top: repairdetail.bottom
                mytitle:"维修部门"
            }
            RectItem{
                id:recar
                anchors.top: redepartment.bottom
                mytitle: "维修车号"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        recar.mytext = SQLWIGHT.setSQL( " select *
                                        from car " )
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
                anchors.top: recar.bottom
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
                anchors.top: recar.bottom
                anchors.right:  btncal.left
                anchors.rightMargin: 10
                onBtnClicked:{
                    CarReWork.delItem(index)
                    CarReWork.addItem(
                                reno.getText(),
                                retime.getText(),
                                recost.getText(),
                                repairdetail.getText(),
                                redepartment.getText(),
                                recar.getText())
                    mainWindow.close()
                }
            }

        }

    }
}

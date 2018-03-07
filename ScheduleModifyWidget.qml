import QtQuick 2.6
import QtQuick.Window 2.2
Window{
    id: mainWindow
    visible: true
    width: 500
    height: 225
    flags: Qt.Window | Qt.FramelessWindowHint
    property int index: 0
    function setIndex(x){
        index = x
        weekth.mytext = ScheduleWork.redata(index , "weekth")
        scline.mytext = ScheduleWork.redata(index , "scline")
        driverno.mytext = ScheduleWork.redata(index , "driverno")
        begintime.mytext = ScheduleWork.redata(index , "begintime")
        endtime.mytext = ScheduleWork.redata(index , "endtime")
        if(x != -1 ) {
            weekth.disedit()
            scline.disedit()
        }
        else{
            weekth.abledit()
            scline.abledit()
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
                id: weekth
                anchors.top: mainRect.top
                mytitle:"星期"
            }
            RectItem{
                id: scline
                anchors.top: weekth.bottom
                mytitle:"线路"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        scline.mytext = SQLWIGHT.setSQL( " select  distinct lno
                                        from line " )
                    }
                }
            }
            RectItem{
                id: driverno
                anchors.top: scline.bottom
                mytitle:"职工号"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        driverno.mytext = SQLWIGHT.setSQL( " select  *
                                        from driver " )
                    }
                }
            }
            RectItem{
                id:begintime
                anchors.top: driverno.bottom
                mytitle:"开始时间"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        begintime.mytext = DateWidget.getDate()
                    }
                }
            }
            RectItem{
                id:endtime
                anchors.top: begintime.bottom
                mytitle:"结束时间"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        endtime.mytext = DateWidget.getDate()
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
                anchors.top: endtime.bottom
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
                anchors.top: endtime.bottom
                anchors.right:  btncal.left
                anchors.rightMargin: 10
                onBtnClicked:{
                    ScheduleWork.delItem(index)
                    ScheduleWork.addItem(
                                weekth.getText(),
                                scline.getText(),
                                driverno.getText(),
                                begintime.getText(),
                                endtime.getText()
                                )
                    weekth.mytext = ""
                    scline.mytext = ""
                    driverno.mytext = ""
                    begintime.mytext = ""
                    endtime.mytext = ""
                    mainWindow.close()

                }
            }

        }

    }
}

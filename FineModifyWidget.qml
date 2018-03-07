import QtQuick 2.6
import QtQuick.Window 2.2

Window{
    id: mainWindow
    visible: true
    width: 500
    height: 220
    flags: Qt.Window | Qt.FramelessWindowHint
    property int index: 0
    function setIndex(x){
        index = x
        bno.mytext = FineWork.redata(index , "bno");
        btime.mytext = FineWork.redata(index , "btime")
        bdetail.mytext = FineWork.redata(index ,"bdetial")
        breakcar.mytext = FineWork.redata(index , "breakcar")
        breakdriver.mytext = FineWork.redata(index ,"breakdriver")
        if(x != -1) bno.disedit()
        else bno.abledit()
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
                id: bno
                anchors.top: mainRect.top
                mytitle:"罚单号"
            }
            RectItem{
                id: btime
                anchors.top: bno.bottom
                mytitle:"开单时间"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log(1)
                        btime.mytext = DateWidget.getCal()
                    }
                }
            }
            RectItem{
                id: bdetail
                anchors.top: btime.bottom
                mytitle:"罚单详情"
            }
            RectItem{
                id:breakcar
                anchors.top: bdetail.bottom
                mytitle:"事故车辆"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        breakcar.mytext = SQLWIGHT.setSQL( " select  *
                                        from car " )
                    }
                }
            }
            RectItem{
                id:breakdriver
                anchors.top: breakcar.bottom
                mytitle:"事故司机"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        breakdriver.mytext = SQLWIGHT.setSQL( " select *
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
                anchors.top: breakdriver.bottom
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
                anchors.top: breakdriver.bottom
                anchors.right:  btncal.left
                anchors.rightMargin: 10
                onBtnClicked:{
                    FineWork.delItem(index)
                    FineWork.addItem(
                                bno.getText(),
                                btime.getText(),
                                bdetail.getText(),
                                breakcar.getText(),
                                breakdriver.getText()
                                )

                    bno.mytext = ""
                    btime.mytext = ""
                    bdetail.mytext = ""
                    breakcar.mytext = ""
                    breakdriver.mytext = ""
                    mainWindow.close()
                }
            }

        }

    }
}

import QtQuick 2.6
import QtQuick.Window 2.2

Window{
    id: mainWindow
    visible: true
    width: 500
    height: 600
    flags: Qt.Window | Qt.FramelessWindowHint
    property int index: 0
    function  setBegin(str){
        LineAddWork.querys(str , "");
        lno.mytext = str;
         if(str != "") {
            lno.disedit()
            console.log(str)
         }
         else
         {
             lno.abledit()
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
        RectItem{
            id:lno
            anchors.top: titleBar.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            mytitle:"线路号"
        }
        //主窗口
        Rectangle{
            id:mainRect
            width: parent.width
            height: parent.height-50
            anchors.top: lno.bottom

            LineTableView{
                id:lineTableView
                anchors.top:mainRect.top
                anchors.bottom: down.top
                anchors.left: parent.left
                anchors.right: parent.right
            }
            Rectangle{
                id:down
                height: 100
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                RectItem{
                    id:inout
                    anchors.top: down.top
                    anchors.left:down.left
                    anchors.right: btnok.left
                    height: 34
                    mytitle:"站点"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            inout.mytext = SQLWIGHT.setSQL(" select *
                                        from station ")
                        }
                    }
                }
                RectItem{
                    id:intime
                    anchors.top: inout.bottom
                    anchors.left: down.left
                    height: 20
          //          anchors.right: btnok.left
                    mytitle:"时间"
                }

                MyButton{
                    id:btncal
                    width: 100
                    height: 34
                    myText: "删除"
                    source: "qrc:/src/icon/delete/6.png"
                   // anchors.verticalCenter: parent.verticalCenter
                    anchors.top: down.top
                    anchors.right:  parent.right
                    onBtnClicked: { LineAddWork.delItem(lineTableView.currentRow)}
                }
                MyButton{
                    id:btnadd
                    width: 100
                    height: 34
                    myText: "添加"
                    source: "qrc:/src/icon/new/6.png"
                   // anchors.verticalCenter: parent.verticalCenter
                    anchors.top: down.top
                    anchors.right:  btncal.left
                    onBtnClicked:{
                            LineAddWork.addItem(lineTableView.currentRow , inout.getText() , intime.getText())
                            console.log(intime.mytext)
                            inout.mytext = ""
                            intime.mytext = ""
                        lineTableView.currentRow = -1
                    }
                }
                MyButton{
                    id:btnok
                    width: 100
                    height: 34
                    myText: "确定"
                    source: "qrc:/src/icon/delete/6.png"
                   // anchors.verticalCenter: parent.verticalCenter
                    anchors.top: down.top
                    anchors.right:  btnadd.left
                    onBtnClicked: {
                        LineAddWork.btnok(lno.getText())
                        LineWork.linequery("" , "");
                        mainWindow.close()


                    }
                }

            }

        }

    }
}

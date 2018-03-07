import QtQuick 2.6
import QtQuick.Window 2.2
Item{
    id: mainWindow
    visible: true
    width: 500
    height: 140
    property int index: 0
    signal loged(var index);
    Rectangle{
        id:widget
        anchors.centerIn: parent;
        width: parent.width - 2;
        height: parent.height - 2;
        //主窗口
        Rectangle{
            id:mainRect
            width: parent.width
            height: parent.height-50
            anchors.top: widget.top
            RectItem{
                id: dno
                anchors.top: mainRect.top
                mytitle:"帐号"
            }
            RectItem{
                id: dname
                anchors.top: dno.bottom
                mytitle:"密码"
            }

            //PushButton RectItem
            MyButton{
                id:btncal
                width: 100
                height: 34
                myText: "匿名登入"
                source: "qrc:/src/icon/delete/6.png"
               // anchors.verticalCenter: parent.verticalCenter
                anchors.top: dname.bottom
                anchors.right:  parent.right
                onBtnClicked: {
                   loged(2)
                }
            }
            MyButton{
                id:btnadd
                width: 100
                height: 34
                myText: "登入"
                source: "qrc:/src/icon/new/6.png"
               // anchors.verticalCenter: parent.verticalCenter
                anchors.top: dname.bottom
                anchors.right:  btncal.left
                anchors.rightMargin: 10
                onBtnClicked:{
                    index = LoginWork.retype(dno.getText() , dname.getText());
                    console.log(index)
                    if(index != -1){
                        loged(index)
                    }
                }
            }

        }

    }
    Component.onCompleted: {
        dname.setMyEcho()
    }

}





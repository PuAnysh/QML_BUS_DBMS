import QtQuick 2.6
import QtQuick.Window 2.2


Window {
    id: mainWindow
    visible: true
    width: 500
    height: 140
    color: "#666666"
    flags: Qt.Window | Qt.FramelessWindowHint
    function setVis(index){
        mainWidget.setVis(index)
    }
    function afterlogin(index){
        mainWindow.width = 1024
        mainWindow.height = 670
        loginWindow.visible = false
        mainWidget.visible = true
        setVis(index)
    }

    Rectangle{
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
        MainWidget{
            id:mainWidget
            width: parent.width
            height: parent.height - 50
            anchors.top: titleBar.bottom
            anchors.left:parent.left
            anchors.right: parent.right
            visible: false
        }
        //登入窗口
        LoginWidget{
            id: loginWindow
            visible: true
            width: 500
            height: 140
            anchors.top: titleBar.bottom
            onLoged: {
                afterlogin(index)
            }

        }
    }

}


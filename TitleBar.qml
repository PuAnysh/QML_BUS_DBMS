import QtQuick 2.2
import QtQuick.Window 2.0
import QtQuick.Controls 1.4

Rectangle{
    id: titleRect;
    height: 50;
    width: 1024;
    color: "#C62F2F";
    property Window mainWindow: parent;

    MouseArea { //为窗口添加鼠标事件
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton //只处理鼠标左键
        property point clickPos: "0,0"
        onPressed: { //接收鼠标按下事件
            clickPos  = Qt.point(mouse.x,mouse.y)
        }
        onPositionChanged: { //鼠标按下后改变位置
            if(mainWindow == null || mainWindow.visibility == Window.FullScreen)
                return;
            //鼠标偏移量
            var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)

            //如果mainwindow继承自QWidget,用setPos
            mainWindow.setX(mainWindow.x+delta.x)
            mainWindow.setY(mainWindow.y+delta.y)
        }
    }

    Image{
        id: titleImg
        cache: true;
        sourceSize.width: 200;
        sourceSize.height: 50;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.leftMargin: 15;
        source: "qrc:/src/icon/main/icont.png";
    }

    //添加控制最大最小关闭按钮
    Row{
        id:btnQuick
        spacing: 12
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 20
        Image {
            id: btnMini
            source: "qrc:/src/topwidget/btnMini1.png"
            opacity: miniArea.containsMouse ? 1.0 : 0.5
            MouseArea{
                id: miniArea
                anchors.fill: parent
                hoverEnabled: true
                onReleased: {
                    if(mainWindow == null)
                        return
                    mainWindow.visibility = Window.Minimized
                }
            }
        }
        //最大化
        Rectangle{
            width: 20
            height: 20
            color: "#C62F2F"
            Rectangle{
                id:btnMax
                anchors.centerIn: parent
                width: 15
                height: 10
                border.width: 1
                border.color: maxArea.containsMouse ? "#FFFFFF":"#E29595"
                color: "#C62F2F"
                radius: 2
            }
            MouseArea{
                id:maxArea
                anchors.fill: parent
                hoverEnabled: true
                onReleased: {
                    if(mainWindow == null)
                        return;
                    if(mainWindow.visibility == Window.FullScreen)
                        mainWindow.showNormal();
                    else
                        mainWindow.visibility = Window.FullScreen;
                }
            }
        }
        //关闭
        Image {
            id: btnClose
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/src/topwidget/btnClose1.png"
            opacity: closeArea.containsMouse ? 1.0 : 0.5
            MouseArea{
                id:closeArea
                anchors.fill: parent
                hoverEnabled: true
                onReleased: {
                    if(mainWindow == null) return
                    mainWindow.close()
                }
            }
        }

    }

}

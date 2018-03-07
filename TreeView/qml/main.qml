import QtQuick 2.4
import QtQuick.Controls 1.4

ApplicationWindow {
    title: qsTr("TreeView")
    width: 400
    height: 300
    visible: true

    TreeView {
        anchors.fill: parent

        Component.onCompleted: {
            model = TreeModel.model();
            print(model);
        }
        rowDelegate:Rectangle{
            height: 30;
            color: styleData.selected ? "#ecedee" :
                                        (styleData.alternate ? "#F5F5F7" : "#FAFAFA");
        }
        itemDelegate: Item{
            property bool isPlaying: ( (rootView.playingRow === styleData.row )&& (styleData.column === 0)) ?
                                         true : false;
            Image{
                id: img;
                anchors{
                    verticalCenter: parent.verticalCenter;
                    right: parent.right;
                    rightMargin: 10 - img.width / 2;
                }
                source: "qrc:/src/middlewidget/select.png";
                visible: parent.isPlaying;
            }

            Text{
                anchors.left: parent.left;
                anchors.leftMargin: 10;
                anchors.right: parent.right;
                anchors.rightMargin: 10;
                anchors.verticalCenter: parent.verticalCenter;
                color: "black";
                text: styleData.value;
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter;
                horizontalAlignment: styleData.textAlignment;
                visible: !parent.isPlaying;
            }
        }

        TableViewColumn {
            title: "A"
            role: "text"
            width: 200
        }

        TableViewColumn {
            title: "B"
            role: "text2"
            width: 200
        }
    }
}

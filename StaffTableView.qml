import QtQuick 2.6
import QtQuick.Controls 1.5
import QtQuick.Controls.Styles 1.4





TableView{
    id: rootView
  //  textRole: "ueRoleName"
    headerDelegate: mMLHeader
    rowDelegate: mMLRow
    itemDelegate: mMLItem
    verticalScrollBarPolicy: Qt.ScrollBarAsNeeded
    horizontalScrollBarPolicy: Qt.ScrollBarAsNeeded
    property var playingRow

    model: MylistModel

    style: TableViewStyle{
        scrollBarBackground: Rectangle{
            color: "#FAFAFA"

            //注意，height指定下方的scrollbar的高，
            //width指定右方的scroolbar的宽
            height: 8
            width: 8
        }
        handle:Button{
            id: button
            property var hovered: styleData.hovered
            style:ButtonStyle{
                background: Rectangle{
                    radius: 4
                    color: button.hovered ? "#CFCFD1" : "#E1E2E2"
                }
            }
        }
        incrementControl: Item{}
        decrementControl: Item{}
    }
    TableViewColumn{
        role: "DNO"
        title: "职工号"
        width: 150
    }
    TableViewColumn{
        role:"DName"
        title: "姓名"
        width: 150
    }

    TableViewColumn{
        role: "DID"
        title: "身份证号码"
        width: 150
    }
    TableViewColumn{
        role: "DPosition";title: "职称";width: 150;
    }
    TableViewColumn{
        role: "DWorkTime";title: "上岗时间";width: 150;
    }
    TableViewColumn{
        role: "DAccount";title: "工资账户";width: 150;

    }
    TableViewColumn{
        role: "DSalary";title: "职工工资";width: 150;
    }
    TableViewColumn{
        role: "DAddress";title: "住址";width: 250;resizable: false;
    }


    Component{
        id: mMLHeader;
        Rectangle{
            color: "#ECEDEE";
            width: 200;
            height: 30;

            Rectangle{
                width: parent.width - 2;
                height: parent.height - 2;
                anchors.centerIn: parent;
                property var pressedG: Gradient{
                    GradientStop{ position: 0.0; color: "#ECEDEE" }
                    GradientStop{ position: 1.0; color: "#FAFAFA" }
                }
                property var hoverG: Gradient{
                    GradientStop{ position: 0.0; color: "#FAFAFA" }
                    GradientStop{ position: 1.0; color: "#ECEDEE" }
                }
                property var normalG: Gradient{
                    GradientStop{ position: 0.0; color: "#FAFAFA" }
                    GradientStop{ position: 1.0; color: "#FAFAFA" }
                }

                gradient: styleData.pressed ? pressedG :
                                              (styleData.containsMouse ? hoverG : normalG);

                Text{
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    text: styleData.value
                    color: "#666666"
                }
            }
        }
    }

    Component{
        id: mMLRow;
        Rectangle{
            height: 30;
            color: styleData.selected ? "#ecedee" :
                                        (styleData.alternate ? "#F5F5F7" : "#FAFAFA");
        }
    }

    Component{
        id: mMLItem;
        Item{
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
                verticalAlignment: Text.AlignVCenter;
                horizontalAlignment: styleData.textAlignment;
                visible: !parent.isPlaying;
            }
        }
    }
}





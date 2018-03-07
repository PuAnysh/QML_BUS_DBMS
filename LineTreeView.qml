import QtQuick 2.4
import QtQuick.Controls 1.4

    TreeView {
        signal indexChange(var linename)
        id: treeview
        anchors.fill: parent

        Component.onCompleted: {
            model = TreeModel.model();
        }
        rowDelegate:Rectangle{
            height: 30;
            color: styleData.selected ? "#ecedee" :
                                        (styleData.alternate ? "#F5F5F7" : "#FAFAFA");
        }
        itemDelegate: Item{
            Image{
                id: img;
                anchors{
                    verticalCenter: parent.verticalCenter;
                    right: parent.right;
                    rightMargin: 10 - img.width / 2;
                }
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
            }
        }

        TableViewColumn {
            title: "线路"
            role: "line"
            width: 200
        }

        TableViewColumn {
            title: "站点"
            role: "station"
            width: 200
        }
        TableViewColumn {
            title: "时间"
            role: "time"
            width: 200
        }
        property bool isCollapse: true
                onClicked: {
                    //
                  //  console.log(TreeModel.data(index , 1));
                    LineWork.setIndex(index)
//                    console.log("onClicked:", index.parent.row)
//                    console.log("isExpanded:",isExpanded(index))
//                    if (isCollapse)
//                    {
//                        console.log("expand")

//                        isCollapse = false;
//                    }
//                    else
//                    {
//                        console.log("collapse")

//                        isCollapse = true;
//                    }
                }
    }

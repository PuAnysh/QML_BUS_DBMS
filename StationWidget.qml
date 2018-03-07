import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.1
Rectangle{
    objectName: "SatffWidget"
    id:carReWidget
    width: 824
    height: 620
    border.color: "#FAFAFC"
    signal qmlIsClick(string type)

    property var gDNO:"21"
    property var gDName:"221"
    property var gDWorkTime:"213"
    property var  gDID:"123sda"
    property var  gDAccount:"213dsf"

    property var  gDSalary:"213dsf"
    property var  gDAddress:"2dsasa"
    signal setTableItem(var DNO , var DName ,var DID ,
                        var DWorkTime ,var  DAccount , var DSalary,var DAddress);



    ///////////////////////////////////
    //设置分支格式
    function setVis(index){
        switch (index)
        {
        case 1:
            btnnew.visible =false
            btnmodify.visible = false
            btndel.visible =false
            break;
        case 2:
            btnnew.visible =false
            btnmodify.visible = false
            btndel.visible =false
            break;
        }
    }




    function modify(String){
        console.log(gDNO)
        gDNO= String
        console.log(gDNO)

    }

    function deleteALL(){
        staffTableView.model.clear()
        return
    }

    function addItem( DNO , DName , DID ,
                      DWorkTime , DAccount , DSalary, DAddress){
        console.log("addItem")
    }




    function debug(type)
    {
        console.log(gDNO)
        gDNO = type
        console.log(gDNO)
        staffTableView.addItem()
        return "IJ"
    }


    StationTableView{
            id:salaryTableView
            anchors.top:parent.top
            anchors.bottom: upRect.top
            anchors.left: parent.left
            anchors.right: parent.right
        }
        Rectangle{
             id:upRect
        //     anchors.top:staffTableView.bottom
             anchors.left: parent.left
             anchors.right: parent.right
             anchors.bottom: parent.bottom
             width: parent.width
             height: 50
         //    color: "#FAFAFC"
             Rectangle{
                 id:rowName
                 anchors.left: parent.left
                 //anchors.right: parent.right
                 anchors.verticalCenter: parent.verticalCenter
                 anchors.margins: 15
                 width: 200
                 height: 50
                 Rectangle{
                     id:name
                     width: 70
                     height: 20
                     anchors.left: rowName.left
                     anchors.verticalCenter:rowName.verticalCenter
                     anchors.margins: 15
                     Text {
                         id: tname
                         text: qsTr("站点名字:")
                         anchors.left: parent.left
                         anchors.verticalCenter: name.verticalCenter
                         font.pixelSize: 15
                         width: parent.width
                         height: parent.height
                     }
                 }
                 Rectangle{
                     id:iname

                     anchors.left: name.right
                     anchors.verticalCenter: rowName.verticalCenter

                     width: 100
                     height: 20
                     color: "#FFFFFF"
                     border.color: "#E4E4E7"
                     TextInput{
                         id:tiname
                         width: parent.width
                         height: parent.height
                         font.pixelSize: 15
                         anchors.verticalCenter: iname.verticalCenter
                     }
                 }
             }


             //按钮框架
             Rectangle{
                 id:buttomRect
                 anchors.right: upRect.right
                 //anchors.top:parent.top
                 anchors.verticalCenter: upRect.verticalCenter
                 width: 400
                 height: parent.height
//                 id: fdStaff
//                 width: parent.width
//                 height: 34
//                 source: "qrc:/src/middlewidget/people.png"
//                 myText: "司机查找"
                 MyButton{
                     id:btnfind
                     width: 70
                     height: 30
                     myText: "查找"
                     source: "qrc:/src/icon/find/2.png"
                     anchors.verticalCenter: parent.verticalCenter
                     anchors.margins: 20
                     onBtnClicked: {
                            StationWork.querys(tiname.text , "")
                     }
                 }

                 MyButton{
                     id:btnnew
                     width: 70
                     height: 30
                     myText: "新建"
                     anchors.left: btnfind.right
                     source: "qrc:/src/icon/new/1.png"
                     anchors.verticalCenter: parent.verticalCenter
                     anchors.margins: 20
                     onBtnClicked: {
                         modify.setIndex(-1)
                         modify.show()
                     }
                 }

                 MyButton{
                     id:btnmodify
                     width: 70
                     height: 30
                     myText: "修改"
                     anchors.left: btnnew.right
                     source: "qrc:/src/icon/modify/7.png"
                     anchors.verticalCenter: parent.verticalCenter
                     anchors.margins: 20
                     onBtnClicked: {
                         DBWork.keyClose()
                         modify.setIndex(salaryTableView.currentRow)
                         modify.show()
                         DBWork.keyOpen()
                     }
                 }

                 MyButton{
                     id:btndel
                     width: 70
                     height: 30
                     myText: "删除"
                     anchors.left: btnmodify.right
                     source: "qrc:/src/icon/delete/3.png"
                     anchors.verticalCenter: parent.verticalCenter
                     anchors.margins: 20
                     onBtnClicked: {
                         StationWork.delItem(salaryTableView.currentRow )
                     }
                 }

             }

        }
        StationModifyWidget{
            id:modify
            visible: false
        }

//    StaffTableView{
//        id:staffTableView
//        anchors.top:t.bottom
//        anchors.bottom: parent.bottom
//        anchors.left: parent.left
//        anchors.right: parent.right


//        function createItem(){
//                staffTableView.model.append({
//                         "DNO":  gDNO,
//                         "DName":gDName,
//                         "DID":gDID,
//                         "DWorkTime":gDWorkTime,
//                         "DAccount":gDAccount,
//                         "DSalary":gDSalary,
//                         "DAddress":gDAddress
//                     });
//        }
//        }

 }

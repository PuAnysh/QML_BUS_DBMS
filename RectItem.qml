import QtQuick 2.0

Rectangle{
    id:item
    width: parent.width
    height: 25
   // anchors.verticalCenter: parent.verticalCenter
    color: "#C2C2C2"
    property  var mytitle: teet
    property var mytext: ""
    function getText(){
        return inputedit.text
    }
    function setMyEcho(){
        inputedit.echoMode = TextInput.Password
    }

    function disedit(){
        inputedit.enabled = false
    }

    function abledit(){
        inputedit.enabled = true
    }

    Text{
        id:label
        text: mytitle
        width: 100
        height: item.height
        font.pixelSize: 20
        anchors.left: item.left
        anchors.top: item.top
     //   anchors.verticalCenter: item.verticalCenter

    }
    Rectangle{
        id:input
        color: "#FFFFFF"
        border.color: "#E4E4E7"
        width: item.width-100
        height: item.height
        anchors.left: label.right
     //   anchors.verticalCenter: item.verticalCenter
        TextInput{
            id:inputedit
            width: parent.width
            height: parent.height
            font.pixelSize: 20
            anchors.left: parent.left
            text: mytext
            focus: true
        }
    }
}

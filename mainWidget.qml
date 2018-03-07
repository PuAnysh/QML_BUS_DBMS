import QtQuick 2.5
import QtMultimedia 5.5
Item {
    id:mainWRoot
    width: 1024
    height: 620
    function disvis(){
        staffWidget.visible = false
        carWidget.visible = false
        carReWidget.visible = false
        fineWidget.visible = false
        salaryWidget.visible = false
        scheduleWidget.visible = false
        stationWidget.visible = false
        lineWidget.visible = false
    }
    function setVis(index){
        disvis()
        staffWidget.setVis(index)
        carWidget.setVis(index)
        carReWidget.setVis(index)
        fineWidget.setVis(index)
        salaryWidget.setVis(index)
        scheduleWidget.setVis(index)
        stationWidget.setVis(index)
        lineWidget.setVis(index)
        switch (index)
        {
        case 1:
            staffWidget.visible = true
            break;
        case 2:
            leftWidget.setVis(index)
            stationWidget.visible = true
            lineWidget.visible = false
            break;
        default:
            staffWidget.visible = true

        }
    }
    function loadContent(type){
        disvis()
        switch (type)
        {
        case 0:
            staffWidget.visible = true
            break
        case 1:
            scheduleWidget.visible = true
            break
        case 2:
            salaryWidget.visible = true
            break
        case 3:
            carWidget.visible = true
            break
        case 4:
            carReWidget.visible = true
            break
        case 5:
            fineWidget.visible = true
            break
        case 6:
            stationWidget.visible = true
            break
        case 7:
            lineWidget.visible = true
            break
        default:


        }
    }

    LeftWidget{
        id:leftWidget
        anchors.top:parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        width: 200
        onBtnPressed: mainWRoot.loadContent(btnType);
    }
    StaffWidget{
        id:staffWidget
        visible: true
        width: parent.width - 200
        height: parent.height
        anchors.top:parent.top
        anchors.left: leftWidget.right
        anchors.bottom: parent.bottom

    }
    CarWidget{
        id:carWidget
        visible: false
        width: parent.width - 200
        height: parent.height
        anchors.top:parent.top
        anchors.left: leftWidget.right
        anchors.bottom: parent.bottom
    }
    CarReWidget{
        id:carReWidget
        visible: false
        width: parent.width - 200
        height: parent.height
        anchors.top:parent.top
        anchors.left: leftWidget.right
        anchors.bottom: parent.bottom
    }
    FineWidget{
        id:fineWidget
        visible: false
        width: parent.width - 200
        height: parent.height
        anchors.top:parent.top
        anchors.left: leftWidget.right
        anchors.bottom: parent.bottom
    }
    SalaryWidget{
        id:salaryWidget
        visible: false
        width: parent.width - 200
        height: parent.height
        anchors.top:parent.top
        anchors.left: leftWidget.right
        anchors.bottom: parent.bottom
    }
    ScheduleWidget{
        id:scheduleWidget
        visible: false
        width: parent.width - 200
        height: parent.height
        anchors.top:parent.top
        anchors.left: leftWidget.right
        anchors.bottom: parent.bottom
    }
    StationWidget{
        id:stationWidget
        visible: false
        width: parent.width - 200
        height: parent.height
        anchors.top:parent.top
        anchors.left: leftWidget.right
        anchors.bottom: parent.bottom
    }
    LineWidget{
        id:lineWidget
        visible: false
        width: parent.width - 200
        height: parent.height
        anchors.top:parent.top
        anchors.left: leftWidget.right
        anchors.bottom: parent.bottom
    }
}

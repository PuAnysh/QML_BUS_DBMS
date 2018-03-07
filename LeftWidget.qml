import QtQuick 2.5
import QtQuick 2.5
import QtQuick.Controls 2.1

Rectangle{
    id: leftWidget
    width: 200
    height: 620
    signal btnPressed(var btnType)
    function setVis(index){
        switch (index)
        {
        case 1:
            mySave.visible = false
            fsave.visible = false
            fre.visible = false
            break;
        case 2:
            mySave.visible = false
            fsave.visible = false
            fre.visible = false
            recommendPart.visible = false
            fdStaff.visible = false
            fdWorkTable.visible = false
            fdSalary.visible = false
            myBusSet.visible = false
            fdAllBus.visible = false
            fdMainTiance.visible = false
            fd.visible = false

            break;
        }
    }

    //右边分割线
    Rectangle{
        id: lWRightSeparator;
        width: 1;
        height: parent.height;
        color:  "#E1E1E2";
        anchors.top: parent.top;
        anchors.right: parent.right;
    }
    //主列表
    Column{
        id: mainList;
        width: parent.width - lWRightSeparator.width;
        height: parent.height;
        anchors.top: parent.top;
        anchors.left: parent.left;
        spacing: 20;

        //表基本查找工具列表
        Column{
            width: parent.width;
            //推荐
            Text{
                id: recommendPart;
                width: parent.width;
                height: 34;
                text: " 员工管理";
                color: "#999999";
                verticalAlignment: Text.AlignVCenter;

            }
            //职工查找
            MyButton{
                id: fdStaff
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/people.png"
                myText: "司机查找"
                onBtnClicked: leftWidget.btnPressed(0)
            }
            //排班表
            MyButton{
                id:fdWorkTable
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/table.png"
                myText: "排班安排"
                onBtnClicked: leftWidget.btnPressed(1)
            }
            //工资结算
            MyButton{
                id:fdSalary
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/money.png"
                myText: "工资结算"
                onBtnClicked: leftWidget.btnPressed(2);
            }
        }
        //车辆表集合
        Column{
            width: parent.width
            Text {
                id: myBusSet
                width: parent.width
                height: 34
                text:" 车辆管理"
                color:"#999999"
                verticalAlignment:  Text.AlignVCenter
            }
            //所有公交车的档案登记
            MyButton{
                id: fdAllBus
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/BUS.png"
                myText: "车辆查找"
                onBtnClicked: leftWidget.btnPressed(3)
            }

            //车辆维修的记录
            MyButton{
                id: fdMainTiance
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/maintenance.png"
                myText: "车辆维修"
                onBtnClicked: leftWidget.btnPressed(4)
            }

            //车辆违章表
            MyButton{
                id:fd
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/fine.png"
                myText: "车辆违章"
                onBtnClicked: leftWidget.btnPressed(5)
            }
        }
        Column{
            width: parent.width
            Text {
                id: myLine
                width: parent.width
                height: 34
                text: " 线路管理"
                color: "#999999"
                verticalAlignment: Text.AlignVCenter
            }
            //站点
            MyButton{
                id:fdsite
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/site.png"
                myText: "公交站点"
                onBtnClicked: leftWidget.btnPressed(6)
            }

            //线路
            MyButton{
                id:fdLine
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/line.png"
                myText: "公交线路"
                onBtnClicked:{ leftWidget.btnPressed(7) ; setVis()}
            }
        }
        Column{
            width: parent.width
            Text {
                id: mySave
                width: parent.width
                height: 34
                text: " 数据库备份"
                color: "#999999"
                verticalAlignment: Text.AlignVCenter
            }
            //站点
            MyButton{
                id:fsave
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/save.png"
                myText: "数据备份"
                onBtnClicked: {
                    DBWork.saveDB()
                }
            }

            //线路
            MyButton{
                id:fre
                width: parent.width
                height: 34
                source: "qrc:/src/middlewidget/restore.png"
                myText: "数据恢复"
                onBtnClicked:{
                    DBWork.reDB();
                }
            }
        }
    }
    Rectangle{
        anchors.bottom: parent.bottom
        width: parent.width
        height: 2
        color: "#999999"
    }
}

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>
#include <recqmlsignal.h>
#include <staffwidgetwork.h>
#include <QQmlEngine>
#include <QtQml>
#include <QtSql/QSqlDatabase>
#include <staffmodel.h>
#include <staffwork.h>
#include <carmodel.h>
#include <carremodel.h>
#include <carwork.h>
#include <finemodel.h>
#include <salarymodel.h>
#include <sqlwork.h>
#include <salarywork.h>
#include <carrework.h>
#include <finework.h>
#include <schedulework.h>
#include <stationmodel.h>
#include <stationwork.h>
#include <TreeView/TreeModel.h>
#include <linework.h>
#include <sqlwidget.h>
#include <datewidget.h>
#include <lineaddmodel.h>
#include <lineaddwork.h>
#include <loginwork.h>
#include <dbwork.h>
#include <sql_link.h>
int main(int argc, char *argv[])
{
//    QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon("qrc:/src/icon/main/icon.png"));

    QQmlApplicationEngine engine;
    MAINdatabase = QSqlDatabase::addDatabase("QSQLITE");
    MAINdatabase.setDatabaseName("memory");
    MAINdatabase.open();
    MAINquery = QSqlQuery(MAINdatabase);
    MAINquery.exec("PRAGMA foreign_keys = ON");


    SQLWidget * W = new SQLWidget("select  *\
                                  from driver");
    DateWidget* d = new DateWidget();


    LoginWork loginwork;
    DBwork dbwork;


    StaffModel sd;
    CarModel    cd;
    CarWork carwork(&cd);
    CarRemodel  RcarRe;
    CarReWork carrework(&RcarRe);
    SalaryModel salary;
    SalaryWork salarywork(&salary);
    FineModel   fine;
    FineWork finework(&fine);
    StaffWork sw(&sd );
    ScheduleModel scheduleModel;
    ScheduleWork schedulework(&scheduleModel);
    StationModel stationmodel;
    StationWork stationwork(&stationmodel);
    TreeModel treemodel;
    LineWork linework(&treemodel);
    LineAddModel lineaddmodel ;
    LineAddWork lineaddwork(&lineaddmodel);




    engine.rootContext()->setContextProperty("SQLWIGHT" , W);
    engine.rootContext()->setContextProperty("DateWidget" , d);
    engine.rootContext()->setContextProperty("MylistModel" , &sd);
    engine.rootContext()->setContextProperty("MyCarModel" , &cd);
    engine.rootContext()->setContextProperty("MyCarReModel" , &RcarRe);
    engine.rootContext()->setContextProperty("MyFine" , &fine);
    engine.rootContext()->setContextProperty("MySalaryModel" , &salary);
    engine.rootContext()->setContextProperty("ScheduleModel" , &scheduleModel);
    engine.rootContext()->setContextProperty("StationModel" , &stationmodel);
    engine.rootContext()->setContextProperty("TreeModel" , &treemodel);
    engine.rootContext()->setContextProperty("LineAddModel" , &lineaddmodel);
    engine.rootContext()->setContextProperty("StaffWork" , &sw);
    engine.rootContext()->setContextProperty("CarWork" , &carwork);
    engine.rootContext()->setContextProperty("SalaryWork" , &salarywork);
    engine.rootContext()->setContextProperty("CarReWork" , &carrework);
    engine.rootContext()->setContextProperty("FineWork" , &finework);
    engine.rootContext()->setContextProperty("ScheduleWork" , &schedulework);
    engine.rootContext()->setContextProperty("StationWork" , &stationwork);
    engine.rootContext()->setContextProperty("LineWork" , &linework);
    engine.rootContext()->setContextProperty("LineAddWork" , &lineaddwork);
    engine.rootContext()->setContextProperty("LoginWork" , &loginwork);
    engine.rootContext()->setContextProperty("DBWork" , &dbwork);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

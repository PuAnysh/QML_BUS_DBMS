#include <QApplication>
#include <QtQuick>

#include "TreeModel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("TreeModel", new TreeModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return a.exec();
}

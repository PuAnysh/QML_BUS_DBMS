TEMPLATE = app

QT += qml quick
QT +=sql
QT += widgets
QT       += core gui widgets quick
CONFIG += c++11

SOURCES += main.cpp \
    staffmodel.cpp \
    staffwork.cpp \
    carmodel.cpp \
    carwork.cpp \
    carremodel.cpp \
    finemodel.cpp \
    schedulemodel.cpp \
    salarymodel.cpp \
    sql_link.cpp \
    salarywork.cpp \
    carrework.cpp \
    finework.cpp \
    schedulework.cpp \
    stationmodel.cpp \
    stationwork.cpp \
    TreeView/TreeItem.cpp \
    TreeView/TreeModel.cpp \
    linework.cpp \
    sqlwidget.cpp \
    datewidget.cpp \
    lineaddmodel.cpp \
    lineaddwork.cpp \
    loginwork.cpp \
    dbwork.cpp

RESOURCES += qml.qrc \
    pic.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    staffmodel.h \
    staffwork.h \
    carmodel.h \
    carwork.h \
    carremodel.h \
    finemodel.h \
    schedulemodel.h \
    salarymodel.h \
    sql_link.h \
    salarywork.h \
    carrework.h \
    finework.h \
    schedulework.h \
    stationmodel.h \
    stationwork.h \
    TreeView/TreeItem.h \
    TreeView/TreeModel.h \
    linework.h \
    sqlwidget.h \
    datewidget.h \
    lineaddmodel.h \
    lineaddwork.h \
    loginwork.h \
    dbwork.h

FORMS += \
    staffadd.ui

DISTFILES +=

RC_ICONS = app.ico


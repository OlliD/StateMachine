#-------------------------------------------------
#
# Project created by QtCreator 2010-06-03T16:11:40
#
#-------------------------------------------------

QT       += core gui xml dbus

TARGET = StateMachine
TEMPLATE = app

CONFIG += uitools

SOURCES += main.cpp\
        mainwindow.cpp\
        logger.cpp \
    ssmcontroller.cpp \
    starttrial.cpp \
    smengine.cpp \
    infowidget.cpp \
    inputwidget.cpp \
    smgui.cpp \
    dialogwidget.cpp \
    initialwidget.cpp \
    datawidget.cpp \
    domparser.cpp \
    guiwidget.cpp \
    controlwidget.cpp \
    vinceadapter.cpp \
    weekendwidget.cpp \
    textwidget.cpp \
    utterancelist.cpp \
    customwidget.cpp \
    vincedbusadapter.cpp \
    xmldatalogger.cpp \
    widgetfactory.cpp

HEADERS  += mainwindow.h\
            logger.h \
    ssmcontroller.h \
    starttrial.h \
    smengine.h \
    infowidget.h \
    inputwidget.h \
    smgui.h \
    dialogwidget.h \
    initialwidget.h \
    datawidget.h \
    widgetinterface.h \
    domparser.h \
    guiwidget.h \
    controlwidget.h \
    vinceadapter.h \
    weekendwidget.h \
    textwidget.h \
    utterancelist.h \
    customwidget.h \
    vincedbusadapter.h \
    agentinterface.h \
    datainterface.h \
    xmldatalogger.h \
    widgetfactory.h

include(/Users/odamm/develop/projects/StateMachine/qtstatemachine/src/qtstatemachine.pri)
include(/Users/odamm/develop/projects/soaArchitecture.lib/src/soaArchitecture.pri)
#include(/Users/odamm/develop/projects/soaDBusArchitecture.lib/src/soaDBusArchitecture.pri)

FORMS    += mainwindow.ui \
    ui/dialog01.ui \
    ui/dialog02.ui \
    dockwidget.ui \
    ui/dialog.ui

RESOURCES += \
    forms.qrc

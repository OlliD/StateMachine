#include <QtGui/QApplication>
#include "mainwindow.h"
#include "smengine.h"
#include <QtScriptedStateMachine>
#include <QtScript/QScriptEngine>
#include "qscriptedstatemachine.h"
#include <QtScript/QScriptContext>

#include "logger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Logger::getInstance().log(QObject::tr("starting app"), 1);
    MainWindow *m = new MainWindow(&a);
    m->show();


/*
    QtScriptedStateMachine *stateMachine = QtScriptedStateMachine::load("../../../../StateMachine/xml/trial.xml");
    QObject::connect (stateMachine, SIGNAL(finished()), &a, SLOT(quit()));


    SMEngine *e = new SMEngine();

    e->setObjectName("smengine");

    e->startEngine();
    stateMachine->registerObject(e);
    stateMachine->start();
*/
    return a.exec();
}

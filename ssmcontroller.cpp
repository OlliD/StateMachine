#include "ssmcontroller.h"

ssmController::ssmController(QObject *parent) :
    QObject(parent)
{

}
bool ssmController::loadSCXML(QString scxml){
    if (true)
        //ssm = QtScriptedStateMachine::load(scxml)){
        return true;
    //}
    else
        return false;
}

void ssmController::executeSSM(){
    //ssm->start();
}

void ssmController::registerFunc(QObject* o, QString name, bool recursive){
    //ssm->registerObject(o, name, recursive);
}


#include "vincedbusadapter.h"

VinceDBusAdapter::VinceDBusAdapter(QObject *parent) :
    AgentInterface()
{
    Logger::getInstance().log("VinceDBusAdapter startet", loglevel);
}

void VinceDBusAdapter::executeMurml(QString murmlSpec){
}

void VinceDBusAdapter::repeatLastMurml(){

}

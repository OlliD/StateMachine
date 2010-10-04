#include "vinceadapter.h"
#include "logger.h"

VinceAdapter::VinceAdapter(QObject *parent) :
    AgentInterface()
{
}

void VinceAdapter::executeMurml(QString murmlSpec){
    //lastMurmlSpec = str;

    Logger::getInstance().log("got to play spec: "+ murmlSpec, 1);
    setLastPlayed(murmlSpec);

    QString str = "./simple_murml.py " + murmlSpec;
    //char cmd[40] = str;
    const char *c;
    c =str.toAscii();
  //  killTimer = new QTimer(this);
  //  QTimer::singleShot(1000, this, SLOT(killCommand()));
    system(c);

}

void VinceAdapter::repeatLastMurml(){
    Logger::getInstance().log("repeating: "+ lastMurmlSpec, 1);
    setLastPlayed(lastMurmlSpec);

    QString str = "./simple_murml.py " + lastMurmlSpec;
    //char cmd[40] = str;
    const char *c;
    c =str.toAscii();
//    killTimer = new QTimer(this);
//    QTimer::singleShot(1000, this, SLOT(killCommand()));
    system(c);

}

void VinceAdapter::setLastPlayed(QString murmlSpec){ lastMurmlSpec = murmlSpec; }

void VinceAdapter::processState(){
    Logger::getInstance().log("process started", 1);

}

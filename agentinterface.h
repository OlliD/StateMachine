//This Interface needs to be implemented by every new AgentAdapter, the Adapter to the WAS is currently missing

#ifndef AGENTINTERFACE_H
#define AGENTINTERFACE_H

#include <QObject>

class AgentInterface : public QObject {

public:
    virtual void executeMurml(QString str) = 0;
    virtual void repeatLastMurml() = 0;


protected:
    ~AgentInterface(){}

};



#endif // AGENTINTERFACE_H

#ifndef VINCEDBUSADAPTER_H
#define VINCEDBUSADAPTER_H

#include <QObject>

#include "logger.h"
#include "agentinterface.h"

class VinceDBusAdapter : public AgentInterface
{
    Q_OBJECT
public:
    explicit VinceDBusAdapter(QObject *parent = 0);

signals:

public slots:
    void repeatLastMurml();
    void executeMurml(QString murmlSpec);

private:
    const static int loglevel = 1;

};

#endif // VINCEDBUSADAPTER_H

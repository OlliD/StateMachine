#ifndef VINCEADAPTER_H
#define VINCEADAPTER_H

#include <QObject>
#include <QProcess>
#include <QTimer>
#include <QString>

#include "agentinterface.h"



class VinceAdapter : public AgentInterface
{
    Q_OBJECT
public:
    explicit VinceAdapter(QObject *parent = 0);

signals:

public slots:
    void executeMurml(QString str);
    void repeatLastMurml();
    void processState();

private:
    QString lastMurmlSpec;
    const static int loglevel = 1;
    QProcess *scriptProcess, *killProcess;
    QTimer *killTimer;
    void setLastPlayed(QString);
};

#endif // VINCEADAPTER_H

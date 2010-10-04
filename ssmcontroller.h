#ifndef SSMCONTROLLER_H
#define SSMCONTROLLER_H

#include <QObject>

#include <QtScriptedStateMachine>


class ssmController : public QObject
{
    Q_OBJECT
public:
    explicit ssmController(QObject *parent = 0);
    bool loadSCXML(QString scxml);
    void executeSSM();
    void registerFunc(QObject* o, QString name, bool recursive);
signals:

public slots:

private:
    //QtScriptedStateMachine* ssm;


};

#endif // SSMCONTROLLER_H

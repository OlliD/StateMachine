// This interface should be used for implementing an dataLogging-component.
// This component should offer these functions to log all relevant data during a study-pass


#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <QObject>
#include <QWidget>

#include "logger.h"

class DataInterface : public QWidget
{
    Q_OBJECT

protected:
    ~DataInterface(){}
public slots:
    virtual void saveData(QString state, QString choice) = 0;
    virtual void startTimer() = 0;
    virtual void stopTimer() = 0;
    virtual void writeToFile() = 0;

signals:
    void dataWritten();
};

#endif // DATAINTERFACE_H

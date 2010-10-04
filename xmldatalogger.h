#ifndef XMLDATALOGGER_H
#define XMLDATALOGGER_H

#include <QObject>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QFileDialog>

#include "datainterface.h"
#include "domparser.h"


class XmlDataLogger : public DataInterface
{
    Q_OBJECT
public:
    explicit XmlDataLogger(QString trialName, QObject *parent = 0);

private:
    void createXML();
    void writeXML();

    QDomDocument *doc;
public slots:


    void saveData(QString state, QString choice);
    void startTimer();
    void stopTimer();
    void writeToFile();

signals:
    void dataWritten();


};

#endif // XMLDATALOGGER_H

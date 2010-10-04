#include "xmldatalogger.h"

XmlDataLogger::XmlDataLogger(QString trialName, QObject *parent) :
    DataInterface()
{
    QDate currentData = QDate::currentDate();
    QString datumvalue=currentData.toString ("dd.MM.yyyy");
    doc = new QDomDocument;
    QDomElement root = doc->createElement(trialName);
    doc->appendChild(root);

    QDomElement date = doc->createElement("date");
    root.appendChild(date);
    QDomText t = doc->createTextNode(datumvalue);
    date.appendChild(t);

}

void XmlDataLogger::saveData(QString state, QString choice){

    QDomElement root = doc->elementById("root");
    QDomElement data = doc->createElement(state);
    QTime currentTime = QTime::currentTime();
    QString timevalue=currentTime.toString ("hh:mm:ss");
    data.setAttribute("time", timevalue);
    root.appendChild(data);
    QDomText t = doc->createTextNode(choice);
    data.appendChild(t);
}

void XmlDataLogger::startTimer(){

}

void XmlDataLogger::stopTimer(){

}


// shows an fileDialog to select the destination-file and writes the collected data to
// this file
void XmlDataLogger::writeToFile(){

    QString xml = doc->toString();
    QString fileName = QFileDialog::getSaveFileName(this,
                                tr("QFileDialog::getSaveFileName()"),
                                tr("All Files (*);;XML Files (*.xml)"));

    QFile qFile(fileName);//"/Users/odamm/out.xml");
    qFile.open( QIODevice::WriteOnly );

    QTextStream out( &qFile );
    out << xml;

    out.flush();        // Würde ich jedem empfehlen
    qFile.flush();      // Sicher ist sicher :-)
    qFile.close();

}

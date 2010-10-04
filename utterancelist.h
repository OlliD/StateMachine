#ifndef UTTERANCELIST_H
#define UTTERANCELIST_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QString>


#include "logger.h"
#include "domparser.h"

class UtteranceList : public QObject
{
    Q_OBJECT
public:
    explicit UtteranceList(QDomDocument doc, QObject *parent = 0);

signals:

public slots:
    void getUtteranceByName();
    void getRandomUtteranceByTag(QString);
    void executeExercise();
    void loadExercisesToList(QDomDocument);
    //void checkForFirstExercise();

private:
    const static int loglevel = 1;

    QMap<QString, QString> *utteranceMap;
    QList< QString> *exerciseList;
    QString *nextExercise;
    DOMParser *domParser;
    void repeatExercise();
    bool firstExercise;

};

#endif // UTTERANCELIST_H

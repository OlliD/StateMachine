#include <QDomDocument>

#include "utterancelist.h"

// simple class to store and offer all utterances who are needed during a trial

UtteranceList::UtteranceList(QDomDocument doc, QObject *parent) :
    QObject(parent)
{
    domParser = new DOMParser();
    //loadExercisesToList(doc);
    utteranceMap = new QMap<QString, QString>;


    UtteranceList::exerciseList = new QList<QString>;
}

void UtteranceList::loadExercisesToList(QDomDocument doc){

    domParser->parseUtteranceFile(doc, "utterance", utteranceMap);
}

void UtteranceList::getUtteranceByName(){

}

void UtteranceList::getRandomUtteranceByTag(QString){

}

// JUST FOR THE DUISBURG-CASE
void UtteranceList::executeExercise(){
    //executeMurmlSpec(exerciseList->at(0));
    Logger::getInstance().log("SMENGINE->EXECUTEEXERCISE: sending exercise" + exerciseList->at(0), 1 );
    QString shift = exerciseList->at(0);
    exerciseList->removeFirst();
    exerciseList->append(shift);
}
// JUST FOR THE DUISBURG-CASE
void UtteranceList::repeatExercise(){
    //emit repeatMurml();
}

// JUST FOR THE DUISBURG-CASE
/*void UtteranceList::checkForFirstExercise(){
    if (UtteranceList::firstExercise==false){
        Logger::getInstance().log("firstexercise: NOPE", loglevel);
        emit declineButton();
    }else if (UtteranceList::firstExercise == true){
        Logger::getInstance().log("firstexercise: YOPE", loglevel);
        emit acceptButton();
    }
    firstExercise = false;

}*/

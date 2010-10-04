#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMapIterator>
#include <iostream>
#include <QStringList>

#include "smengine.h"
#include "domparser.h"


SMEngine::SMEngine(QDomDocument *trialData, QDomDocument *utteranceList, QObject *parent) :
    QObject(parent)
{
    firstUse = true;
    document = new QDomDocument(*trialData);
    utteranceDocument = new QDomDocument(*utteranceList);
    smGui = new SMGui();
    widgetFactory = new WidgetFactory();
    domParser = new DOMParser();
    //utterances = new UtteranceList(*utteranceList);
}

void SMEngine::startEngine(){

    //this should happen in the utterance-class
    SMEngine::personData = new QList< QMap<QString, QString> >;
    SMEngine::widgetData = new QList< QMap<QString, QString> >;
    SMEngine::resultMap = new QMap<QString, QString>;

    parseXMLFile("fileName");   //TODO: change signature
    // initialize the layout to take new widgets
    layout = new QVBoxLayout();
    // a list to store the information which widgets a currently displayed
    currentWidgets = new QList<QString>;
    createControlWidget();
    // time to get connected
    connectSlots();
    layout = new QVBoxLayout();
    Logger::getInstance().log("SMEngine->STARTENGINE: initialized", loglevel);

}


void SMEngine::connectSlots(){
    //QObject::connect(this, SIGNAL(getWidget(QString,WidgetInterface*)), widgetFactory, SLOT(getWidget(QString,WidgetInterface*)));
    QObject::connect(this, SIGNAL(enablePreviousButton(bool)), controlWidget, SLOT(enablePreviousButton(bool)));
    QObject::connect(this, SIGNAL(enableSkipButton(bool)), controlWidget, SLOT(enableSkipButton(bool)));

    QObject::connect(this, SIGNAL(setWidget(QWidget*)), smGui, SLOT(setCurrentWidget(QWidget*)));
    QObject::connect(this, SIGNAL(setLayout(QLayout*)), smGui, SLOT(setCurrentLayout(QLayout*)));
    QObject::connect(this, SIGNAL(moveToLowerScreen()), smGui, SLOT(setLower()));
    QObject::connect(this, SIGNAL(moveToMiddleOfScreen()), smGui, SLOT(setCenter()));
    Logger::getInstance().log("SMENGINE->CONNECTSSLOT: SLOTS connected", loglevel);
}

void SMEngine::addLayout(){
    Logger::getInstance().log("SMENGINE->ADDLAYOUT: adding widget to gui: " , loglevel);
    emit setLayout(layout);
}


// removes all the widget from gui-layout and disconnect the slot from signals
void SMEngine::removeWidgetFromLayout(const QString name){
    QWidget *myWidget = layout->findChild<QWidget*>(name);
    QObject::disconnect(controlWidget);
    layout->removeWidget(myWidget);

    layout->update();
}

void SMEngine::createControlWidget(){
    controlWidget = new ControlWidget("controlWidget");
    controlWidget->setMaximumSize(300,120);
    QObject::connect(this, SIGNAL(changeButtonLabel(QString)), controlWidget, SLOT(changeLabel(QString)));
    QObject::connect(controlWidget, SIGNAL(nextClicked()), this, SLOT(acceptButton()));
    QObject::connect(controlWidget, SIGNAL(previousClicked()), this, SLOT(declineButton()));
    QObject::connect(controlWidget, SIGNAL(skipClicked()), this, SLOT(skipButton()));
    Logger::getInstance().log("SMENGINE->SHOWCONTROLWIDGET: ControlWidget created ", loglevel);

}

// the control-widget
void SMEngine::showControlWidget(QString buttonLabel){
    currentWidgets->append("controlWidget");
    emit changeButtonLabel(buttonLabel);
    layout->addWidget(controlWidget);

}


void SMEngine::showWidget(QString name){
    WidgetInterface *w = widgetFactory->getWidget(name);
    Logger::getInstance().log("SMENGINE->showWidget: adding widget: " + name, loglevel);
    layout->addWidget(w);
    layout->addWidget(controlWidget);
    currentWidgets->append("controlWidget");
    currentWidgets->append(name);

    emit setLayout(layout);

}




void SMEngine::removeLayout(){
        for (int i=0; !currentWidgets->empty(); i++){
        QString name = currentWidgets->at(0);
        WidgetInterface *w = widgetFactory->getWidget(name);
        layout->removeWidget(w);
        currentWidgets->removeAt(0);
        Logger::getInstance().log("SMENGINE->REMOVELAYOUT: removing " + name,  loglevel);

    }
    emit setLayout(layout);

}

void SMEngine::executeMurmlSpec(QString murmlspec){
    QStringList specs;
    specs = murmlspec.split(",");

    int i = qrand()%specs.size();
    QString ran;
    ran.setNum(i);

    Logger::getInstance().log("SMENGINE->INITIALIZEMAP: created random number " + ran,  loglevel);
    emit executeMurml(specs.at(i));
}


void SMEngine::sendMurmlSpec(QString str){
    emit executeMurml(str);
}



void SMEngine::saveToDom(QString tagName, QString data){
    Logger::getInstance().log("receiving data: " + tagName + " and: " + data, loglevel);

}


void SMEngine::parseXMLFile(QString filename){
    Logger::getInstance().log("got something to parse: " + filename, loglevel);

    emit domParser->parseElements(*document, "Person", personData );
    emit domParser->parseElements(*document, "Widgets", widgetData );

}

QString SMEngine::getElementByTag(QList<QMap<QString, QString> > *list, QString str){
    QString rStr;
    for (int i = 0; i < list->length(); i++){
        QMap<QString, QString>  map = widgetData->at(i);
        rStr = map.value(str);
        //Logger::getInstance().log("in map: " + str, loglevel);

    }
    return rStr;
}


// A pause of xxx msec will be added, during this time the window will not
// be displayed

void SMEngine::addPause(int msec){
    Logger::getInstance().log("time to take a break ", loglevel);
    timer = new QTimer(this);
    QTimer::singleShot(msec, this, SLOT(timeOut()));
    //QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timeOut()));
    this->smGui->hide();

}

void SMEngine::timeOut(){
    smGui->show();
    emit declineButton();
}

// The next step ist randomized with a chance of 50:50 for state a or b
void SMEngine::getRandom(){
    int i = irand(0, 100);
    std::cerr << "SMENGINE->GETRANDOM: " << i << std::endl;
    //Logger::getInstance().log("SMENGINE->GETRANDOM: " + i, loglevel);
    if (i >= 49){
        emit acceptButton();
    } else{
        emit declineButton();
    }
}

//Return a random integer between the value a and e
int SMEngine::irand( int a, int e){
    double r = e - a + 1;
    return a + (int)(r * qrand()/(RAND_MAX+1.0));
}

void SMEngine::finished(){
    Logger::getInstance().log("it's all been done", loglevel);
}

void SMEngine::repaintGui(){
    smGui->repaint();
    smGui->update();
}

void SMEngine::stop(){
    smGui->hide();
    emit stopEngine();
}

void SMEngine::acceptButton(){
    removeLayout();
    emit yesSignal();
}

void SMEngine::declineButton(){
    emit noSignal();
}

void SMEngine::skipButton(){
    emit skipSignal();
}

void SMEngine::toggleFirstUse(bool b){
    firstUse = b;
}

void SMEngine::logStateMachine(QString string){
    Logger::getInstance().log("SMENGINE: acutal state: " + string, loglevel);
}


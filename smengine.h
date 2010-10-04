#ifndef SMENGINE_H
#define SMENGINE_H

#include <QObject>
#include <QString>
#include <QtScriptedStateMachine>
#include <QList>
#include <QMap>
#include <QLayoutIterator>
#include <QTimer>
#include <QSet>
#include <QDomDocument>
#include <QVBoxLayout>
#include <QDate>
#include <string>
#include <QProcess>

#include "widgetinterface.h"
#include "smgui.h"
#include "logger.h"
#include "domparser.h"
#include "utterancelist.h"
#include "controlwidget.h"
#include "widgetfactory.h"

class SMEngine : public QObject
{
    Q_OBJECT

public:
    explicit SMEngine(QDomDocument *trialData, QDomDocument *utteranceList, QObject *parent = 0);
    void startEngine();
    SMEngine getEngine();
    SMEngine *smEngine;
    // the controlWidget is the same all time, so it is only created once
    ControlWidget *controlWidget;
    void createControlWidget();


public slots:
    void repaintGui();
    void parseXMLFile(QString);

//    void showInfoWidget(QString widget, QString label="");
//    void showDialogWidget();
//    void showWeekendWidget();
    void showControlWidget(QString);
    void addLayout();
    void showWidget(QString);
    void removeWidgetFromLayout(const QString name);
    void removeLayout();
    void finished();
//    void getDialogResults();
    void executeMurmlSpec(QString murmlspec);
    void saveToDom(QString tagName, QString data);
    void stop();
    void addPause(int);
    void getRandom();
    void logStateMachine(QString);
//    void checkForShortDay();
//    void checkForLastDay();
    void toggleFirstUse(bool);


private slots:

    void timeOut();
    void sendMurmlSpec(QString);
    void declineButton();
    void acceptButton();
    void skipButton();

private:

    const static int loglevel = 1;
    void showInfoWidget(SMGui* smGui);
    void open();
    void connectSlots();
    QString getElementByTag(QList< QMap<QString, QString> >* list, QString str);
    bool firstUse;
    SMGui *smGui;
    DOMParser *domParser;
    int irand( int a, int e);
    QMap<QString, QWidget *> *widgets;
    QList< QMap<QString, QString> >* personData;
    QList< QMap<QString, QString> >* widgetData;
    QMap<QString, WidgetInterface*> widgetMap;
    QMap<QString, QString>* resultMap;
    QTimer *timer, *killTimer;
    QDomElement *child;
    QDomDocument *document, *utteranceDocument;
    QList<QString> *currentWidgets;
    QVBoxLayout *layout;
    WidgetFactory *widgetFactory;
    UtteranceList *utterances;



signals:
    void showMe();
    void setLabel(QString); //TODO: check for relevance
    void setWidget(QWidget *w);
    void setLayout(QLayout *l);
    void breakIsOver();
    void yesSignal();
    void noSignal();

    void confirnClicked();
    void skipSignal();
    void createGuiWithList(QList< QMap<QString, QString> >*);
    void createInputGuiWithDataSet(QMap<QString, QString>);
    void getWidget(QString name, WidgetInterface *w);
    void setLanguage(QString);
    void enableNextButton(bool);
    void enablePreviousButton(bool);
    void enableSkipButton(bool);
    void changeButtonLabel(QString str);
    void changeLabel(QString);
    void executeMurml(QString str);
    void repeatMurml();
    void requestResults(QMap<QString, QString>*);
    void stopEngine();
    void moveToLowerScreen();
    void moveToMiddleOfScreen();
};

#endif // SMENGINE_H

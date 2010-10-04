#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdlib.h>
#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QAction>
#include <QActionGroup>
#include <QMenu>
#include <QFile>
#include <QList>
#include <QStatusBar>
#include <QPushButton>
#include <QMenuBar>
#include <QPixmap>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QSize>
#include <QtScriptedStateMachine>
#include <QStatusBar>
#include <QFileDialog>
#include <QString>
#include <QTimer>
#include <QDomDocument>
#include <QCheckBox>
#include <QComboBox>
#include <QMap>
#include <QMapIterator>

#include "smengine.h"
#include "logger.h"
#include "smgui.h"
#include "domparser.h"
#include "vinceadapter.h"
#include "vincedbusadapter.h"
#include "agentinterface.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QApplication *a, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showWindow();
    void open();
    void showGui();
    void logging();

private slots:
    void startScript();
    void openDataFile();
    void openUtteranceFile();
    void setAdapter(QString adapter);


private:

    //methods
    void initGui();
    void initConnectors();
    void connectSlots();
    void createActions();

    //DataFields
    const static int loglevel = 1;
    SMEngine *smEngine;
    VinceAdapter *vinceAdapter;
    VinceDBusAdapter *vinceDBusAdapter;
    Logger *logger;
    DOMParser *domParser;

    QWidget *myWidget;
    QLabel* label, *infoLabel, *agentAdapterLabel;
    QPushButton *loadUtteranceFile, *loadSm, *loadDataFile, *loadExistingProfile, *createSm, *quit, *submit;
    QLineEdit *line;
    QCheckBox *firstUseBox, *startAgent;
    QHBoxLayout *hlayout;
    QVBoxLayout *widgetlayout, *agentAdapterLayout, *startLayout, *vlayout, *tableWidgetLayout, *loadLayout;;

    QGroupBox *tableGroup, *loadBox, *startBox, *vGroup, *agentAdaperBox;
    QWidget *centralWidget;

    QMenu *helpMenu, *fileMenu, *extraMenu, *logMenu;
    QMenuBar *menu;
    QString *fileName, developerPath;

    QtScriptedStateMachine *stateMachine;
    QDomElement *child;
    QDomDocument *document, *utteranceDocument;
    QList< QMap<QString, QString> > *data ;
    QMap <QString, AgentInterface*> *adapterMap;

    QComboBox *agentAdapterCombo;

    QFile *file;
    //SMGui *smGui;

    QAction *openAct, *utteranceAct, *exitAct, *loggerAct, *noLog, *logToConsole, *logToFile;
    void createAction();
    void createMenu();
    void loadFile(const QString &fileName);

signals:
    void firstUse(bool);
    void setLogLevel(int);

};

#endif // MAINWINDOW_H

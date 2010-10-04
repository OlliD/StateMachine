
#include "mainwindow.h"

#include "vinceadapter.h"

MainWindow::MainWindow(QApplication *a, QWidget *parent) :
    QMainWindow(parent)
{
    MainWindow::quit= new QPushButton("Quit App");
    QObject::connect(quit, SIGNAL(clicked()), a, SLOT(quit()));
    domParser = new DOMParser();
    initGui();
    connectSlots();
    adapterMap = new QMap<QString, AgentInterface*>;
    initConnectors();
}


MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::initConnectors(){
    adapterMap = new QMap<QString, AgentInterface*>;
    vinceAdapter = new VinceAdapter;
    vinceAdapter->setObjectName("agent");
    vinceDBusAdapter = new VinceDBusAdapter;
    vinceDBusAdapter->setObjectName("agent");
    adapterMap->insert("Script-Adapter", vinceAdapter);
    adapterMap->insert("DBus-Adapter", vinceDBusAdapter);

    QMapIterator<QString, AgentInterface*> i(*adapterMap);
    while (i.hasNext()) {
        i.next();
        agentAdapterCombo->addItem(i.key());
    }
}

void MainWindow::initGui(){
    this->setWindowTitle("Framework for empirical virtual agent studies");
    vGroup = new QGroupBox;
    vlayout = new QVBoxLayout;
    createAction();
    menu = new QMenuBar();
    fileMenu = new QMenu(tr("&Datei"), this);
    fileMenu->addAction(openAct);
    fileMenu->addAction(exitAct);
    menu->addMenu(fileMenu);
    extraMenu = new QMenu(tr("&Extras"), this);
    //extraMenu->addAction(loggerAct);
    menu->addMenu(extraMenu);
    logMenu = new QMenu(tr("&Logging"), this);
    extraMenu->addMenu(logMenu);
    logMenu->addAction(noLog);
    logMenu->addAction(logToConsole);
    logMenu->addAction(logToFile);

    QSize pixMapSize(80,50);
    QPixmap image(pixMapSize);

    developerPath = std::getenv("WBS_DEVELOPER_ROOT");

    image.load(developerPath + "/projects/StateMachine/image.bmp");
    //QPixmap image();
    label = new QLabel();
    label->setPixmap(image);
    hlayout = new QHBoxLayout();

    agentAdapterLabel = new QLabel("Select Agent Adapter");
    agentAdapterCombo = new QComboBox;
    agentAdapterCombo->setEnabled(false);
    agentAdaperBox = new QGroupBox(tr("Select Agent Adapter"));
    agentAdapterLayout = new QVBoxLayout;
    agentAdapterLayout->addWidget(agentAdapterCombo);
    startAgent = new QCheckBox("Start the agent");
    startAgent->setEnabled(false);
    agentAdapterLayout->addWidget(startAgent);
    agentAdaperBox->setLayout(agentAdapterLayout);

    MainWindow::firstUseBox = new QCheckBox("Nehmen Sie erste mal teil?");
    MainWindow::loadExistingProfile = new QPushButton("Profil laden");
    MainWindow::createSm = new QPushButton("execute state machine");
    MainWindow::loadSm = new QPushButton("load state machine");
    MainWindow::loadDataFile = new QPushButton("load Datafile");
    MainWindow::loadUtteranceFile = new QPushButton("load utterance file");

    loadLayout = new QVBoxLayout;
    loadBox = new QGroupBox(tr("Load Files"));
    loadLayout->addWidget(loadSm);
    //vlayout->addWidget(firstUseBox);
    firstUseBox->setEnabled(false);
    loadLayout->addWidget(loadUtteranceFile);
    loadUtteranceFile->setEnabled(false);
    loadLayout->addWidget(loadDataFile);
    loadBox->setLayout(loadLayout);
    vlayout->addWidget(loadBox);
    vlayout->addWidget(agentAdaperBox);

    startLayout = new QVBoxLayout;
    startLayout->addWidget(createSm);
    startBox = new QGroupBox(tr("Start StateMachine"));
    startBox->setLayout(startLayout);
    vlayout->addWidget(startBox);
    vlayout->addSpacing(30);
    //TODO:for testing onlay
    //vlayout->addLayout(testLayout);
    vlayout->addWidget(quit);
    createSm->setEnabled(false);
    loadDataFile->setEnabled(false);
    hlayout->addWidget(label);
    hlayout->addLayout(vlayout);
    vGroup->setLayout(hlayout);

    setCentralWidget(vGroup);
    this->show();
}

void MainWindow::showWindow(){
    statusBar()->showMessage(tr("Durchlauf abgeschlossen"),3000);

    this->show();
}

void MainWindow::createMenu(){

}

void MainWindow::createAction(){
    openAct = new QAction(tr("&Open..."), this);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    exitAct = new QAction(tr("&Exit"), this);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    loggerAct = new QAction(tr("&Logger"), this);
    connect(loggerAct,SIGNAL(triggered()), this, SLOT(logging()));

    noLog = new QAction(tr("&no Logging"), this);
    connect(noLog,SIGNAL(triggered()), this, SLOT(logging()));
    noLog->setCheckable(true);

    logToConsole = new QAction(tr("&Log to console"), this);
    connect(logToConsole,SIGNAL(triggered()), this, SLOT(logging()));
    logToConsole->setCheckable(true);

    logToFile = new QAction(tr("&Log to file"), this);
    connect(logToFile,SIGNAL(triggered()), this, SLOT(logging()));
    logToFile->setCheckable(true);

    utteranceAct = new QAction(tr("&Open utterance file"), this);
    connect(utteranceAct, SIGNAL(triggered()), this, SLOT(openUtteranceFile()));

    QActionGroup* loggerGroup = new QActionGroup(this);
    loggerGroup->addAction(noLog);
    loggerGroup->addAction(logToConsole);
    loggerGroup->addAction(logToFile);
    logToConsole->setChecked(true);

}

void MainWindow::logging(){

}

void MainWindow::connectSlots(){
    //QObject::connect(MainWindow::createSm, SIGNAL(clicked()), this, SLOT(startScript()));
    QObject::connect(loadDataFile, SIGNAL(clicked()), this, SLOT(openDataFile()));
    QObject::connect(loadUtteranceFile, SIGNAL(clicked()), this, SLOT(openUtteranceFile()));
    QObject::connect(loadSm, SIGNAL(clicked()),this, SLOT(open()) );
    QObject::connect(firstUseBox, SIGNAL(clicked()), this, SLOT(openDataFile()));
    QObject::connect(createSm, SIGNAL(clicked()), this, SLOT(startScript()));
    QObject::connect(agentAdapterCombo, SIGNAL(activated(QString)),this, SLOT(setAdapter(QString)));
}

void MainWindow::open()
{
    //fileName = new QString();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     developerPath + "/projects/StateMachine/xml",
                                                     tr("XML-Files (*.xml)"));
    if (!fileName.isEmpty()){
        statusBar()->showMessage(tr("Datei erfolgreich geladen"),3000);
        stateMachine = QtScriptedStateMachine::load(fileName);
        loadSm->setEnabled(false);
        loadUtteranceFile->setEnabled(true);
    }
}

void MainWindow::setAdapter(QString adapter){
    Logger::getInstance().log("Setting Adapter to: " + adapter, loglevel);
    stateMachine->registerObject(adapterMap->value(adapter));
}

void MainWindow::openDataFile(){
    if (firstUseBox->isChecked())
        loadDataFile->setEnabled(false);
    else
        firstUseBox->setEnabled(false);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     developerPath + "/projects/StateMachine/xml",
                                                     tr("XML-Files (*.xml)"));
    QFile file(fileName);
    document = new QDomDocument();
    child = new QDomElement();
    if(domParser->read(&file, *document ) && !fileName.isEmpty()){
        statusBar()->showMessage(tr("Datei erfolgreich geladen"), 3000);
        loadDataFile->setEnabled(false);
        createSm->setEnabled(true);
        agentAdapterCombo->setEnabled(true);
        startAgent->setEnabled(true);
    }

}
void MainWindow::openUtteranceFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     developerPath + "/projects/StateMachine/xml",
                                                     tr("XML-Files (*.xml)"));
    QFile utteranceFile(fileName);
    utteranceDocument = new QDomDocument();
    child = new QDomElement();
    if(domParser->read(&utteranceFile, *utteranceDocument ) && !fileName.isEmpty()){
        statusBar()->showMessage(tr("Datei erfolgreich geladen"), 3000);
        loadDataFile->setEnabled(true);
        firstUseBox->setEnabled(true);
        loadUtteranceFile->setEnabled(false);
    }

}
void MainWindow::startScript(){
    Logger::getInstance().log("lets run the SSM, registering the SMEngine" ,loglevel);
    if (startAgent->isChecked()){
        Logger::getInstance().log("Gonna to start a QProcess with the Agent now", loglevel);
    }

    vinceAdapter = new VinceAdapter();
    smEngine = new SMEngine(document, utteranceDocument);
    smEngine->setObjectName("smEngine");
    stateMachine->registerObject(smEngine);
    QTimer timer;
    timer.start(2000);
    this->hide();

    QObject::connect(smEngine, SIGNAL(executeMurml(QString)), vinceAdapter, SLOT(executeMurml(QString)));
    QObject::connect(this, SIGNAL(firstUse(bool)), smEngine, SLOT(toggleFirstUse(bool)));
    QObject::connect(stateMachine, SIGNAL(finished()), smEngine, SLOT(finished()));
    QObject::connect(smEngine, SIGNAL(stopEngine()), this, SLOT(showGui()));
    stateMachine->start();
    if (firstUseBox->isChecked())
        emit firstUse(true);
    smEngine->startEngine();
    Logger::getInstance().log("StateMachine started", loglevel);

}

void MainWindow::showGui(){
    this->show();
}

#include <QMapIterator>

#include "logger.h"
#include "dialogwidget.h"

DialogWidget::DialogWidget(QString objectName, QWidget *parent) :
    WidgetInterface()
{
    this->setObjectName(objectName);
    layout = new QVBoxLayout;
    title = new QLabel("Persoenliche Angaben");
    layout->addWidget(title);

    genderGroup = new QGroupBox();
    mondayMorningCheckBox = new QCheckBox("Montag");
    tuesdayMorningCheckBox = new QCheckBox("Dienstag");
    wednesdayMorningCheckBox = new QCheckBox("Mittwoch");
    thursdayMorningCheckBox = new QCheckBox("Donnerstag");
    fridayMorningCheckBox = new QCheckBox("Freitag");
    saturdayMorningCheckBox = new QCheckBox("Samstag");
    sundayMorningCheckBox = new QCheckBox("Sonntag");
    mondayAfternoonCheckBox = new QCheckBox();
    tuesdayAfternoonCheckBox = new QCheckBox();
    wednesdayAfternoonCheckBox = new QCheckBox();
    thursdayAfternoonCheckBox = new QCheckBox();
    fridayAfternoonCheckBox = new QCheckBox();
    saturdayAfternoonCheckBox = new QCheckBox();
    sundayAfternoonCheckBox = new QCheckBox();
    buttonBoxGender = new QHBoxLayout;
    dayCheckBoxLayout = new QGridLayout;
    spacer = new QLabel("Arbeitstage");
    spacer->setToolTip("blablub");

    dayCheckBoxLayout->addWidget(spacer,0,0);
    dayCheckBoxLayout->addWidget(mondayMorningCheckBox,1,0);
    dayCheckBoxLayout->addWidget(tuesdayMorningCheckBox,2,0);
    dayCheckBoxLayout->addWidget(wednesdayMorningCheckBox,3,0);
    dayCheckBoxLayout->addWidget(thursdayMorningCheckBox,4,0);
    dayCheckBoxLayout->addWidget(fridayMorningCheckBox,5,0);
    dayCheckBoxLayout->addWidget(saturdayMorningCheckBox,6,0);
    dayCheckBoxLayout->addWidget(sundayMorningCheckBox,7,0);

    dayCheckBoxLayout->addWidget(mondayAfternoonCheckBox,1,2);
    dayCheckBoxLayout->addWidget(tuesdayAfternoonCheckBox,2,2);
    dayCheckBoxLayout->addWidget(wednesdayAfternoonCheckBox,3,2);
    dayCheckBoxLayout->addWidget(thursdayAfternoonCheckBox,4,2);
    dayCheckBoxLayout->addWidget(fridayAfternoonCheckBox,5,2);
    dayCheckBoxLayout->addWidget(saturdayAfternoonCheckBox,6,2);
    dayCheckBoxLayout->addWidget(sundayAfternoonCheckBox,7,2);

    male = new QRadioButton("maennlich");
    female = new QRadioButton("weiblich");
    buttonBoxGender->addWidget(male);
    buttonBoxGender->addWidget(female);
    genderGroup->setLayout(buttonBoxGender);
    layout->addWidget(genderGroup);

    name  = new QLineEdit();
    nameLabel = new QLabel("Nachname");
    nameInputLayout = new QHBoxLayout;
    nameInputLayout->addWidget(nameLabel);
    nameInputLayout->addWidget(name);
    layout->addLayout(nameInputLayout);
    forNameLabel = new QLabel("Vorname");
    forname  = new QLineEdit();
    forNameLayout = new QHBoxLayout;
    forNameLayout->addWidget(forNameLabel);
    forNameLayout->addWidget(forname);
    layout->addLayout(forNameLayout);
    sportLabel = new QLabel("Ich treibe regelmaessig Sport");
    sportRate = new QComboBox();
    sportRate->addItem("einige Male im Monat");
    sportRate->addItem("1-2 Mal pro Woche");
    sportRate->addItem("mehrere Male pro Woche");
    sportRate->addItem("fast taeglich bis taeglich");

     // Radiobuttons


    // VLayouts
    vBoxLayout = new QVBoxLayout();
    days = new QVBoxLayout();
    morningVBox = new QVBoxLayout();
    afternoonVBox = new QVBoxLayout();
    nameLayout = new QVBoxLayout();
    // HLayouts
    genderLayout = new QHBoxLayout();
    weekLayout = new QHBoxLayout();
    workingLayout = new QHBoxLayout();
    muscleLayout = new QHBoxLayout();
    hBoxLayout = new QHBoxLayout();

    sportLayout = new QHBoxLayout();

    workConditions = new QLabel("Meine Arbeitsbedingungen schaden meiner Gesundheit:");
    workingLayout->addWidget(workConditions);
    conditionsGroup = new QGroupBox();
    buttonBoxHealth = new QHBoxLayout;

    conditions_pro = new QRadioButton("Ja");
    conditions_contra = new QRadioButton("Nein");
    buttonBoxHealth->addWidget(conditions_pro);
    buttonBoxHealth->addWidget(conditions_contra);
    conditionsGroup->setLayout(buttonBoxHealth);
    workingLayout->addWidget(conditionsGroup);
    //Sport
    buttonBoxSport = new QHBoxLayout;
    sportLayout->addWidget(sportLabel);
    sportGroup = new QGroupBox();
    sport_yes = new QRadioButton("Ja");
    sport_no = new QRadioButton("Nein");
    buttonBoxSport->addWidget(sport_yes);
    buttonBoxSport->addWidget(sport_no);
    sportGroup->setLayout(buttonBoxSport);
    sportLayout->addWidget(sportGroup);
    sportLayout->addWidget(sportRate);

    //Arbeitszeitentabelle
    officetime = new QLabel("Arbeitszeiten");
    officetime->setToolTip("blablub");
    days->addWidget(officetime);
    monday = new QLabel("Montag");
    days->addWidget(monday);
    tuesday = new QLabel("Dienstag");
    days->addWidget(tuesday);
    wednesday = new QLabel("Mittwoch");
    days->addWidget(wednesday);
    thursday = new QLabel("Donnerstag");
    days->addWidget(thursday);
    friday = new QLabel("Freitag");
    days->addWidget(friday);
    saturday = new QLabel("Samstag");
    days->addWidget(saturday);
    sunday = new QLabel("Sonntag");
    days->addWidget(sunday);
    //Lineedits
    afternoon = new QLabel("nachmittags");
    dayCheckBoxLayout->addWidget(afternoon,0,3);
    mondayA = new QLineEdit();
    mondayA->setInputMask("00:00");
    dayCheckBoxLayout->addWidget(mondayA,1,3);
    mondayA->setEnabled(false);
    tuesdayA = new QLineEdit();
    dayCheckBoxLayout->addWidget(tuesdayA,2,3);
    tuesdayA->setEnabled(false);
    wednesdayA = new QLineEdit();
    dayCheckBoxLayout->addWidget(wednesdayA,3,3);
    wednesdayA->setEnabled(false);
    thursdayA = new QLineEdit();
    dayCheckBoxLayout->addWidget(thursdayA,4,3);
    thursdayA->setEnabled(false);
    fridayA = new QLineEdit();
    dayCheckBoxLayout->addWidget(fridayA,5,3);
    fridayA->setEnabled(false);
    saturdayA = new QLineEdit();
    dayCheckBoxLayout->addWidget(saturdayA,6,3);
    saturdayA->setEnabled(false);
    sundayA = new QLineEdit();
    dayCheckBoxLayout->addWidget(sundayA,7,3);
    sundayA->setEnabled(false);
    //Lineedits
    morning = new QLabel("vormittags");
    dayCheckBoxLayout->addWidget(morning,0,1);
    mondayM = new QLineEdit();
    dayCheckBoxLayout->addWidget(mondayM,1,1);
    mondayM->setEnabled(false);
    tuesdayM = new QLineEdit();
    dayCheckBoxLayout->addWidget(tuesdayM,2,1);
    tuesdayM->setEnabled(false);
    wednesdayM = new QLineEdit();
    dayCheckBoxLayout->addWidget(wednesdayM,3,1);
    wednesdayM->setEnabled(false);
    thursdayM = new QLineEdit();
    dayCheckBoxLayout->addWidget(thursdayM,4,1);
    thursdayM->setEnabled(false);
    fridayM = new QLineEdit();
    dayCheckBoxLayout->addWidget(fridayM,5,1);
    fridayM->setEnabled(false);
    saturdayM = new QLineEdit();
    dayCheckBoxLayout->addWidget(saturdayM,6,1);
    saturdayM->setEnabled(false);
    sundayM = new QLineEdit();
    dayCheckBoxLayout->addWidget(sundayM,7,1);
    sundayM->setEnabled(false);
    //weekLayout->addLayout(days);
    weekLayout->addLayout(dayCheckBoxLayout);
    //weekLayout->addLayout(morningVBox);
    //weekLayout->addLayout(afternoonVBox);

    lower = new QCheckBox("unterer Ruecken");
    upper = new QCheckBox("oberer Ruecken");
    shoulder = new QCheckBox("Schultern");
    neck = new QCheckBox("Nacken");
    spine = new QCheckBox("Wirbelsaeule");
    checkBoxLayout = new QHBoxLayout;
    checkBoxLayout->addWidget(lower);
    checkBoxLayout->addWidget(upper);
    checkBoxLayout->addWidget(shoulder);
    checkBoxLayout->addWidget(neck);
    checkBoxLayout->addWidget(spine);
    muscleLabel = new QLabel("Folgende Muskelgruppen machen mir besonders/regelmaessig Probleme");
    layout->addLayout(weekLayout);
    layout->addLayout(sportLayout);
    layout->addLayout(workingLayout);
    layout->addLayout(muscleLayout);
    layout->addWidget(muscleLabel);
    layout->addLayout(checkBoxLayout);

    this->setLayout(layout);


   // this->show();
    Logger::getInstance().log("DIALOGWIDGET added", 1);
    connectSignals();
}

void DialogWidget::connectSignals(){
    QObject::connect(mondayMorningCheckBox,SIGNAL(clicked(bool)), mondayM, SLOT(setEnabled(bool)));
    QObject::connect(tuesdayMorningCheckBox,SIGNAL(clicked(bool)), tuesdayM, SLOT(setEnabled(bool)));
    QObject::connect(wednesdayMorningCheckBox,SIGNAL(clicked(bool)), wednesdayM, SLOT(setEnabled(bool)));
    QObject::connect(thursdayMorningCheckBox,SIGNAL(clicked(bool)), thursdayM, SLOT(setEnabled(bool)));
    QObject::connect(fridayMorningCheckBox,SIGNAL(clicked(bool)), fridayM, SLOT(setEnabled(bool)));
    QObject::connect(saturdayMorningCheckBox,SIGNAL(clicked(bool)), saturdayM, SLOT(setEnabled(bool)));
    QObject::connect(sundayMorningCheckBox,SIGNAL(clicked(bool)), sundayM, SLOT(setEnabled(bool)));

    QObject::connect(mondayAfternoonCheckBox,SIGNAL(clicked(bool)), mondayA, SLOT(setEnabled(bool)));
    QObject::connect(tuesdayAfternoonCheckBox,SIGNAL(clicked(bool)), tuesdayA, SLOT(setEnabled(bool)));
    QObject::connect(wednesdayAfternoonCheckBox,SIGNAL(clicked(bool)), wednesdayA, SLOT(setEnabled(bool)));
    QObject::connect(thursdayAfternoonCheckBox,SIGNAL(clicked(bool)), thursdayA, SLOT(setEnabled(bool)));
    QObject::connect(fridayAfternoonCheckBox,SIGNAL(clicked(bool)), fridayA, SLOT(setEnabled(bool)));
    QObject::connect(saturdayAfternoonCheckBox,SIGNAL(clicked(bool)), saturdayA, SLOT(setEnabled(bool)));
    QObject::connect(sundayAfternoonCheckBox,SIGNAL(clicked(bool)), sundayA, SLOT(setEnabled(bool)));

}

void DialogWidget::setLabelText(QString text){
    label->setText(text);
}

void DialogWidget::acivateSkipButton(bool state){
    skipButton->setEnabled(state);
}

void DialogWidget::results(QMap<QString, QString> *resultMap){
    //QMap<QString, QString>*resultMap = new QMap<QString, QString>;
    if (male->isChecked()) resultMap->insert("gender", "maennlich");
    if (female->isChecked()) resultMap->insert("gender", "weiblich");
    resultMap->insert("name", name->text());
    resultMap->insert("vorname", forname->text());

    resultMap->insert("montag", mondayM->text() + " " + mondayA->text());
    resultMap->insert("dienstag", tuesdayM->text() + " " +  tuesdayA->text());
    resultMap->insert("mittwoch", wednesdayM->text() + " " + wednesdayA->text());
    resultMap->insert("donnerstag", thursdayM->text() + " " + thursdayA->text());
    resultMap->insert("freitag", fridayM->text() + " " + fridayA->text());
    resultMap->insert("samstag", saturdayM->text() + " " + saturdayA->text());
    resultMap->insert("sonntag", sundayM->text() + " " + sundayA->text());
    if (sport_yes->isChecked()) resultMap->insert("regular_sport", "ja");
    if (sport_yes->isChecked()) resultMap->insert("sportrate", sportRate->currentText());
    if (sport_no->isChecked()) resultMap->insert("regular_sport", "nein");
    if (conditions_pro->isChecked()) resultMap->insert("bad_conditions", "ja");
    if (conditions_contra->isChecked()) resultMap->insert("bad_conditions","nein");
    if (lower->isChecked()) resultMap->insertMulti("muscle_problems","unterer Ruecken");
    if (upper->isChecked()) resultMap->insertMulti("muscle_problems","oberer Ruecken");
    if (shoulder->isChecked()) resultMap->insertMulti("muscle_problems","Schultern");
    if (neck->isChecked()) resultMap->insertMulti("muscle_problems","Nacken");
    if (spine->isChecked()) resultMap->insertMulti("muscle_problems","Wirbelsaeule");
    QList<QString> list;
    QString str;

    if (mondayMorningCheckBox->isChecked()) list.append("montag");
    if (tuesdayMorningCheckBox->isChecked()) list.append("dienstag");
    if (wednesdayMorningCheckBox->isChecked()) list.append("mittwoch");
    if (thursdayMorningCheckBox->isChecked()) list.append("donnerstag");
    if (fridayMorningCheckBox->isChecked()) list.append("freitag");
    if (saturdayMorningCheckBox->isChecked()) list.append("samstag");
    if (sundayMorningCheckBox->isChecked()) list.append("sonntag");
    for (int i = 0; i < list.size(); i++){
        str = str + list.at(i) + " ";
    }
    resultMap->insert("dayofweek", str);
    list.clear();

    if (mondayMorningCheckBox->isChecked() && mondayAfternoonCheckBox->isChecked()) list.append("montag");
    if (tuesdayMorningCheckBox->isChecked() && tuesdayAfternoonCheckBox->isChecked()) list.append("dienstag");
    if (wednesdayMorningCheckBox->isChecked() && wednesdayAfternoonCheckBox->isChecked()) list.append("mittwoch");
    if (thursdayMorningCheckBox->isChecked() && thursdayAfternoonCheckBox->isChecked()) list.append("donnerstag");
    if (fridayMorningCheckBox->isChecked() && fridayAfternoonCheckBox->isChecked()) list.append("freitag");
    if (saturdayMorningCheckBox->isChecked() && saturdayAfternoonCheckBox->isChecked()) list.append("samstag");
    if (sundayMorningCheckBox->isChecked() && sundayAfternoonCheckBox->isChecked()) list.append("sonntag");

    str ="";
    for (int i = 0; i < list.size(); i++){
        str = str + list.at(i) + " ";
    }
    resultMap->insert("longdays", str);

    Logger::getInstance().log("sending items to engine: " + str , 1);
    emit resultsWritten();
}

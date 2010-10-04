#include "weekendwidget.h"

WeekendWidget::WeekendWidget(QString objectName, QWidget *parent) :
    WidgetInterface()
{
    this->setObjectName(objectName);
    layout = new QVBoxLayout;
    title = new QLabel("Wochenabschluss");
    layout->addWidget(title);

    scheduleGroup = new QGroupBox();

    scheduleBox = new QHBoxLayout;
    scheduleYes = new QRadioButton("ja");
    scheduleNo = new QRadioButton("nein");
    scheduleBox->addWidget(scheduleYes);
    scheduleBox->addWidget(scheduleNo);
    scheduleGroup->setLayout(scheduleBox);
    scheduleLabel = new QLabel("Werden Sie in der kommenden Woche zu den selben Zeiten arbeiten wie in dieser?");
    layout->addWidget(scheduleLabel);
    layout->addWidget(scheduleGroup);

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

    recoveryLayout = new QHBoxLayout();
    // WorkConditions
       //Sport

    buttonBoxRecovery = new QHBoxLayout;
    //recoveryLayout->addWidget(sportLabel);
    sportGroup = new QGroupBox();
    recovery_yes = new QRadioButton("Ja");
    recovery_no = new QRadioButton("Nein");
    buttonBoxRecovery->addWidget(recovery_yes);
    buttonBoxRecovery->addWidget(recovery_no);
    sportGroup->setLayout(buttonBoxRecovery);
    recoveryLayout->addWidget(sportGroup);
    //recoveryLayout->addWidget(sportRate);


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
    muscleLabel = new QLabel("Haben Sie das Gefuehl, dass sich ihre Beschwerden gebessert haben?");


    workConditions = new QLabel("Haben Sie das Gefuehl, dass sich ihr Koerpergefuehl am Arbeitsplatz bessert?:");
    workingLayout->addWidget(workConditions);
    conditionsGroup = new QGroupBox();
    buttonBoxHealth = new QHBoxLayout;

    conditions_pro = new QRadioButton("Ja");
    conditions_contra = new QRadioButton("Nein");
    buttonBoxHealth->addWidget(conditions_pro);
    buttonBoxHealth->addWidget(conditions_contra);
    conditionsGroup->setLayout(buttonBoxHealth);
    workingLayout->addWidget(conditionsGroup);

    layout->addLayout(weekLayout);
    layout->addLayout(recoveryLayout);
    layout->addLayout(workingLayout);
    layout->addLayout(muscleLayout);
    layout->addWidget(muscleLabel);
    layout->addLayout(checkBoxLayout);

    this->setLayout(layout);


   // this->show();
    Logger::getInstance().log("WEEKENDWIDGET added", 1);

}

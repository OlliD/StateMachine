#include <QFileDialog>

#include "initialwidget.h"

InitialWidget::InitialWidget(QString name, QWidget *parent) :
    WidgetInterface()
{
    this->setObjectName(name);
    this->init();
}

void InitialWidget::init(){
    gridLayout = new QGridLayout();
    nameLabel = new QLabel("Name");
    gridLayout->addWidget(nameLabel,0,0);
    foreNameLabel = new QLabel("Vorname");
    gridLayout->addWidget(foreNameLabel,0,1);
    jobLabel = new QLabel("Beruf");
    gridLayout->addWidget(jobLabel,0,2);
    residenceLabel = new QLabel("Wohnort");
}

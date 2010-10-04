#include <QLabel>
#include "logger.h"
#include "infowidget.h"

InfoWidget::InfoWidget(QString name, QWidget *parent) :
    WidgetInterface()
{
    this->setObjectName(name);
    label = new QLabel();
    textArea = new QTextEdit();
    textArea->setEnabled(false);

    button = new QPushButton("weiter");

    centralWidget = new QWidget;
    vGroup = new QGroupBox;


    vlayout = new QVBoxLayout;
    vlayout->addWidget(textArea);
    //vlayout->addWidget(button);
    vGroup->setLayout(vlayout);

    widgetlayout = new QVBoxLayout;
    //widgetlayout->addWidget(label);

    widgetlayout->addWidget(vGroup);
    centralWidget->setLayout(widgetlayout);
    Logger::getInstance().log("INFOWIDGET added", 1);
    this->setLayout(vlayout);
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(click()));
}

void InfoWidget::setLabelText(QString text){
    textArea->setText(text);
    //label->setText(text);
    Logger::getInstance().log("INFOWIDGET: setting text to: " + text, 1);

}

void InfoWidget::click(){
    emit buttonClicked();
}

void InfoWidget::showMe(){
    this->show();
}

void InfoWidget::setButtonLabel(QString label){
    InfoWidget::button->setText(label);
}

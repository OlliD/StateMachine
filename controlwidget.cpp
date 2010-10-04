#include "controlwidget.h"

ControlWidget::ControlWidget(QString objectName, QWidget *parent) :
    WidgetInterface()
{
    this->setObjectName(objectName);
    hLayout = new QHBoxLayout;
    next = new QPushButton(QString::fromUtf8("weiter"));
    previous = new QPushButton(QString::fromUtf8("zurück"));
    skip = new QPushButton(QString::fromUtf8("überspringen"));
    hLayout->addWidget(previous);
    previous->setEnabled(false);
    hLayout->addWidget(skip);
    skip->setEnabled(false);
    hLayout->addWidget(next);
    QObject::connect(previous, SIGNAL(clicked()), this, SLOT(previousButtonClicked()));
    QObject::connect(skip, SIGNAL(clicked()), this, SLOT(skipButtonClicked()));
    QObject::connect(next, SIGNAL(clicked()), this, SLOT(nextButtonClicked()));
    Logger::getInstance().log("CONTROLWIDGET added", 1);

    this->setLayout(hLayout);
}

void ControlWidget::setLanguage(QString lang){
    QString eng[] = { "step back","skip", "continue"};
    QString deu[] = {"zurück", "überspringen", "weiter"};
    if (lang == "eng"){
        next->setText(eng[2]);
        previous->setText(eng[0]);
        skip->setText(eng[1]);
    } else if ( lang =="deu" ){
        next->setText(deu[2]);
        previous->setText(deu[0]);
        skip->setText(deu[1]);
    } else {
        Logger::getInstance().log("Language unkown, nothing to do", loglevel);
    }

}
void ControlWidget::changeLabel(QString style){
    if (style == "standard"){

        next->setText(QString::fromUtf8("weiter"));
        skip->setText(QString::fromUtf8("überspringen"));
        previous->setText(QString::fromUtf8("zurück"));
        next->setEnabled(true);
        skip->setEnabled(false);
        previous->setEnabled(true);
        Logger::getInstance().log("CONTROLWIDGET->changeLabel: changed to standard", loglevel);

    }else if (style == "continue"){

        next->setText(QString::fromUtf8("weiter"));
        skip->setText(QString::fromUtf8("überspringen"));
        previous->setText(QString::fromUtf8("zurück"));
        next->setEnabled(true);
        next->hide();
        skip->setEnabled(false);
        previous->setEnabled(false);
        Logger::getInstance().log("CONTROLWIDGET->changeLabel: changed to continue", loglevel);

    } else if (style == "yesno"){
        next->setText("Ja");
        skip->setText("Vielleicht");
        previous->setText("Nein");
        next->setEnabled(true);
        skip->setEnabled(false);
        previous->setEnabled(true);
        Logger::getInstance().log("CONTROLWIDGET->changeLabel: changed to yesno", loglevel);

    } else if (style == "murml"){
        next->setText("Ja");
        skip->setText("wiederholen");
        previous->setText("Nein");
        next->setEnabled(true);
        skip->setEnabled(false);
        previous->setEnabled(true);
        Logger::getInstance().log("CONTROLWIDGET->changeLabel: changed to murml", loglevel);


    } else {
        Logger::getInstance().log("Layout not known", loglevel);
    }
}

void ControlWidget::nextButtonClicked(){
    emit nextClicked();
}

void ControlWidget::previousButtonClicked(){
    emit previousClicked();
}

void ControlWidget::skipButtonClicked(){
    emit skipClicked();
}

void ControlWidget::enableNextButton(bool state){
    next->setEnabled(state);
}

void ControlWidget::enablePreviousButton(bool state){
    previous->setEnabled(state);
}

void ControlWidget::enableSkipButton(bool state){
    skip->setEnabled(state);
}


void ControlWidget::setLabelSkipButton(QString str){
    previous->setText(str);
}

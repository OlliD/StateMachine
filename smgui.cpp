#include <QRect>
#include <QDesktopWidget>
#include "smgui.h"
#include "logger.h"

SMGui::SMGui(QWidget *parent) :
    QMainWindow(parent)
{
    QRect available_geom = QDesktopWidget().availableGeometry();
    QRect current_geom = frameGeometry();
    setGeometry(available_geom.width() / 2 - current_geom.width() / 2,
                            available_geom.height()  - current_geom.height() / 2,
                            current_geom.width()/2,
                            current_geom.height()/2);


    this->setMaximumHeight(400);
    this->setMaximumWidth(300);
    vlayout = new QVBoxLayout;
    vGroup = new QGroupBox;
    vGroup->setLayout(vlayout);

    widgetlayout = new QVBoxLayout;
    centralWidget = new QWidget;

    this->setMaximumWidth(300);
    this->show();
    Logger::getInstance().log("creating GUI", 1);

}
void SMGui::setCenter(){
    QRect available_geom = QDesktopWidget().availableGeometry();
    QRect current_geom = frameGeometry();
    setGeometry(available_geom.width() / 2 - current_geom.width() / 2,
                            available_geom.height() /2  - current_geom.height() / 2,
                            current_geom.width()/2,
                            current_geom.height()/2);

}

void SMGui::setLower(){
    QRect available_geom = QDesktopWidget().availableGeometry();
    QRect current_geom = frameGeometry();
    setGeometry(available_geom.width() / 2 - current_geom.width() / 2,
                            available_geom.height()  - current_geom.height() / 2,
                            current_geom.width()/2,
                            current_geom.height()/2);

}

void SMGui::setCurrentWidget(QWidget *w){
    Logger::getInstance().log("SMGUI: changing GUI", 1);
    //widgetlayout->addWidget(w);
    SMGui::setCentralWidget(w);
    this->minimumSize();
    this->repaint();
    this->resize(300,200);

}

void SMGui::setCurrentLayout(QLayout *l){
    centralWidget = new QWidget;

    Logger::getInstance().log("SMGUI: adding new Layout", 1);
    //widgetlayout->addWidget(w);
    centralWidget->setLayout(l);
    setCentralWidget(centralWidget);
    this->hide();

    //SMGui::setCentralWidget(l);
    this->update();
    this->repaint();
    this->show();
}


void SMGui::setMenu(QMenuBar *m){
    this->setMenuBar(m);
}


void SMGui::initialize(){
    Logger::getInstance().log("SMGUI: inializing GUI", 1);
    this->show();
}


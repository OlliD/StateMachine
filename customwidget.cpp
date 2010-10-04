#include "customwidget.h"

CustomWidget::CustomWidget(QWidget *parent) :
    WidgetInterface()
{
    initializeGui();
    //inputLine[] = new QLineEdit;
    //label = new QLabel;
}

void CustomWidget::initializeGui(){
    labelLayout = new QVBoxLayout();
    textLayput = new QVBoxLayout();


}

void CustomWidget::addGuiElement(QList< QMap<QString, QString> >* elements){

 /*   for (int i = 0; i < elements->size(); ++i){
        QMap<QString, QString> e = elements->at(i);
        QMapIterator<QString, QString> strIter(e);
        strIter.next();
        label[i] = new QLabel(strIter.key());
        labelLayout->addWidget(label[i]);
        inputLine[i] = new QLineEdit();
        textLayput->addWidget(inputLine.at(i));
    }*/
}

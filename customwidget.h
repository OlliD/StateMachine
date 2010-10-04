#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QList>
#include <QString>
#include <QMap>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "widgetinterface.h"

class CustomWidget : public WidgetInterface
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = 0);

private:
    //methods
    void initializeGui();
    QVBoxLayout *labelLayout, *textLayput;

    QList< QMap<QString, QString> >* guiElements;
    QLineEdit *inputLine[];
    QLabel *label[];

signals:

public slots:
    void addGuiElement(QList< QMap<QString, QString> >* elements);

};

#endif // CUSTOMWIDGET_H

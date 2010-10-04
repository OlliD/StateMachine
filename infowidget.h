#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

#include "widgetinterface.h"

class InfoWidget : public WidgetInterface
{
    Q_OBJECT
public:
    explicit InfoWidget(QString name, QWidget *parent = 0);

private:


    QWidget* centralWidget;
    QGroupBox* vGroup;
    QTextEdit* textArea;
    QLabel* label;
    QVBoxLayout* vlayout, *widgetlayout;
    QPushButton* button;


signals:
    void buttonClicked();

public slots:
    void click();

    void setLabelText(QString);
    void showMe();
    void setButtonLabel(QString);

};

#endif // INFOWIDGET_H

#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "logger.h"
#include "widgetinterface.h"


class ControlWidget : public WidgetInterface
{
    Q_OBJECT
public:
    explicit ControlWidget(QString objectName, QWidget *parent = 0);

signals:
    void nextClicked();
    void previousClicked();
    void skipClicked();

public slots:
    void setLanguage(QString);
    void enableNextButton(bool);
    void enablePreviousButton(bool);
    void enableSkipButton(bool);
    void nextButtonClicked();
    void previousButtonClicked();
    void skipButtonClicked();
    void changeLabel(QString);
    void setLabelSkipButton(QString str); //TODO: change this to something less ugly


private:
    QPushButton *next, *previous, *skip;
    QHBoxLayout *hLayout;
    const static int loglevel = 1;

};

#endif // CONTROLWIDGET_H

#ifndef SMGUI_H
#define SMGUI_H

#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QStackedWidget>
#include <QLayout>

#include "inputwidget.h"
#include "infowidget.h"
#include "dialogwidget.h"
//#include "initialwidget.h"


class SMGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit SMGui(QWidget *parent = 0);
    void initialize();
    void changeWidget();
    QWidget* centralWidget;

private:
    QVBoxLayout* vlayout;
    QVBoxLayout* tableWidgetLayout;
    QVBoxLayout* widgetlayout;
    QGroupBox* vGroup;
    QGroupBox* tableGroup;
    QStackedWidget *widgetStack;


signals:

public slots:
    void setCurrentWidget(QWidget *w);
    void setCurrentLayout(QLayout *l);
    void setMenu(QMenuBar *m);
    void setCenter();
    void setLower();
};

#endif // SMGUI_H

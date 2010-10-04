#ifndef INITIALWIDGET_H
#define INITIALWIDGET_H

#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QAction>
#include <QActionGroup>
#include <QMenu>
#include <QFile>
#include <QList>
#include <QStatusBar>
#include <QPushButton>
#include <QMenuBar>
#include <QPixmap>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QString>

#include "logger.h"
#include "widgetinterface.h"

class InitialWidget : public WidgetInterface
{
    Q_OBJECT
public:
    explicit InitialWidget(QString name, QWidget *parent = 0);

signals:

    void enterClicked();

public slots:



private:
    QWidget *myWidget;
    QLabel* nameLabel, *foreNameLabel, *jobLabel, *residenceLabel;
    QLineEdit *nameLine, *foreNameLine, *jobLine, *residenceLine;
    QGridLayout *gridLayout;

    //methods
    void init();
};

#endif // INITIALWIDGET_H

#ifndef WIDGETINTERFACE_H
#define WIDGETINTERFACE_H

#include <QObject>
#include <QWidget>

#include "logger.h"


class WidgetInterface : public QWidget
{
    //explicit WidgetInterface(QObject *parent);

protected:
    ~WidgetInterface(){}

public:
    //TODO: should be virtual or so
    int loglevel;

};

#endif // WIDGETINTERFACE_H

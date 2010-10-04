#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H


#include <QObject>
#include <QMap>
#include <QString>

#include "logger.h"
#include "infowidget.h"
#include "inputwidget.h"
#include "initialwidget.h"
#include "dialogwidget.h"
#include "controlwidget.h"
#include "weekendwidget.h"
#include "vinceadapter.h"

#include "widgetinterface.h"

class WidgetFactory : public QObject
{
    Q_OBJECT
public:
    explicit WidgetFactory(QObject *parent = 0);
    WidgetInterface* getWidget(QString name );

signals:

public slots:

private:
    const static int loglevel = 1;
    QMap<QString, WidgetInterface*> widgetMap;



};

#endif // WIDGETFACTORY_H

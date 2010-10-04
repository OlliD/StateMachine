// All new Widget should be inserted here to be available for the smEngine
//

#include "widgetfactory.h"


WidgetFactory::WidgetFactory(QObject *parent) :
    QObject(parent)
{
    widgetMap.insert("weekendWidget", new WeekendWidget("weekendWidget"));
    widgetMap.insert("infoWidget", new InfoWidget("infoWidget"));
    widgetMap.insert("dialogWidget", new DialogWidget("dialogWidget"));
    widgetMap.insert("initialWidget", new InitialWidget("initialWidget"));
}

// this methods return a pointer to the requested widget
WidgetInterface* WidgetFactory::getWidget(QString name){
    WidgetInterface *widget;
    if (widgetMap.contains(name)){
        Logger::getInstance().log("WIDGETFACTORY->getWidget: returning Widget", loglevel);
        widget = widgetMap.value(name);
        return widget;
 }

}

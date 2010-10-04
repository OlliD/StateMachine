#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtUiTools/QUiLoader>
#include <QFile>
#include <QTextEdit>
#include <QList>
#include <QLineEdit>

#include "logger.h"
#include "widgetinterface.h"

class InputWidget : public WidgetInterface
{
    Q_OBJECT
public:
    explicit InputWidget(QString name, QWidget *parent = 0);
    void setText(QString text);
    QWidget& loadUI(QString fileName);
    void setTitle(QString title);


signals:
    void buttonClicked();
    void submitData(QString tagName, QString data);

public slots:
    void click();
    void createGuiWithDataSet(QMap<QString, QString>);
    void createGuiWithList(QList< QMap<QString, QString> >*);
    void createGuiWithUiFile(QString fileName);

private:
    //Methods

    //data items
    QHBoxLayout *hLayout;
    QVBoxLayout *layout, *vLayout, *vLayoutLeft, *vLayoutright;
    QLabel *label;
    QPushButton *enter;
    QTextEdit *input;
    QList<QLineEdit*> inList;
    QList<QLabel*> labList;

    QLineEdit *inputList[];
    QLabel *labelList[];
    QList< QList<QString> >* retValues;


};

#endif // INPUTWIDGET_H

#ifndef WEEKENDWIDGET_H
#define WEEKENDWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QComboBox>
#include <QGridLayout>
#include <QButtonGroup>
#include <QGroupBox>

#include "logger.h"
#include "widgetinterface.h"

class WeekendWidget : public WidgetInterface
{
    Q_OBJECT
public:
    explicit WeekendWidget(QString objectName, QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *morning, *afternoon, *officetime, *sportLabel, *title, *workConditions, *muscleLabel, *scheduleLabel, *forscheduleLabel;
    QLabel *label, *monday, *tuesday, *wednesday, *thursday, *friday, *saturday, *sunday;

    QHBoxLayout *hBoxLayout, *genderLayout, *weekLayout, *recoveryLayout, *workingLayout, *muscleLayout, *checkBoxLayout, *forNameLayout;
    QHBoxLayout *buttonBoxRecovery, *buttonBoxHealth, *scheduleBox, *nameInputLayout;
    QVBoxLayout *layout, *vBoxLayout, *days, *morningVBox, *afternoonVBox, *nameLayout;

    QLineEdit *mondayA, *tuesdayA, *wednesdayA, *thursdayA, *fridayA, *saturdayA, *sundayA, *name, *forname;
    QLineEdit *mondayM, *tuesdayM, *wednesdayM, *thursdayM, *fridayM, *saturdayM, *sundayM;
    QComboBox *sportRate;
    QRadioButton *scheduleYes, *scheduleNo, *recovery_yes, *recovery_no, *conditions_pro, *conditions_contra;
    QCheckBox *lower, *upper, *shoulder, *neck, *spine;
    QGroupBox *scheduleGroup, *sportGroup, *conditionsGroup;


    QPushButton *yesButton, *noButton, *skipButton;



};

#endif // WEEKENDWIDGET_H

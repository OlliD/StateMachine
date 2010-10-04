#ifndef DIALOGWIDGET_H
#define DIALOGWIDGET_H

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
#include <QToolTip>

#include "widgetinterface.h"


class DialogWidget : public WidgetInterface
{
    Q_OBJECT
public:
    explicit DialogWidget(QString objectName, QWidget *parent = 0);

signals:
    void sendResults();
    void resultsWritten();

public slots:
    void setLabelText(QString);
    void acivateSkipButton(bool state);

    void results(QMap<QString, QString> *resultMap);

private:
    QLabel *morning, *afternoon, *officetime, *sportLabel, *title, *workConditions, *muscleLabel, *nameLabel, *forNameLabel;
    QLabel *label, *monday, *tuesday, *wednesday, *thursday, *friday, *saturday, *sunday, *spacer;

    QHBoxLayout *hBoxLayout, *genderLayout, *weekLayout, *sportLayout, *workingLayout, *muscleLayout, *checkBoxLayout, *forNameLayout;
    QHBoxLayout *buttonBoxSport, *buttonBoxHealth, *buttonBoxGender, *nameInputLayout;
    QVBoxLayout *layout, *vBoxLayout, *days, *morningVBox, *afternoonVBox, *nameLayout;
    QGridLayout *dayCheckBoxLayout;

    QLineEdit *mondayA, *tuesdayA, *wednesdayA, *thursdayA, *fridayA, *saturdayA, *sundayA, *name, *forname;
    QLineEdit *mondayM, *tuesdayM, *wednesdayM, *thursdayM, *fridayM, *saturdayM, *sundayM;
    QComboBox *sportRate;
    QRadioButton *male, *female, *sport_yes, *sport_no, *conditions_pro, *conditions_contra;
    QCheckBox *lower, *upper, *shoulder, *neck, *spine;
    QCheckBox *mondayMorningCheckBox, *tuesdayMorningCheckBox, *wednesdayMorningCheckBox, *thursdayMorningCheckBox, *fridayMorningCheckBox, *saturdayMorningCheckBox, *sundayMorningCheckBox;
    QCheckBox *mondayAfternoonCheckBox, *tuesdayAfternoonCheckBox, *wednesdayAfternoonCheckBox, *thursdayAfternoonCheckBox, *fridayAfternoonCheckBox, *saturdayAfternoonCheckBox, *sundayAfternoonCheckBox;
    QGroupBox *genderGroup, *sportGroup, *conditionsGroup;


    QPushButton *yesButton, *noButton, *skipButton;

    void connectSignals();

};

#endif // DIALOGWIDGET_H

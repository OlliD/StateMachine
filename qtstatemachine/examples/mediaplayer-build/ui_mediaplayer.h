/********************************************************************************
** Form generated from reading UI file 'mediaplayer.ui'
**
** Created: Tue Jun 1 10:54:46 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPLAYER_H
#define UI_MEDIAPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QSlider>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mediaPlayerWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QListView *listView;
    QWidget *playerPage;
    QLabel *playingLabel;
    QLabel *midLabel;
    QSlider *posSlider;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QToolButton *homeButton;
    QToolButton *playButton;
    QToolButton *prevButton;
    QToolButton *nextButton;
    QToolButton *stopButton;
    QSlider *volumeSlider;
    QToolButton *selectButton;
    QToolButton *backButton;

    void setupUi(QWidget *mediaPlayerWidget)
    {
        if (mediaPlayerWidget->objectName().isEmpty())
            mediaPlayerWidget->setObjectName(QString::fromUtf8("mediaPlayerWidget"));
        mediaPlayerWidget->resize(394, 287);
        horizontalLayout = new QHBoxLayout(mediaPlayerWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(mediaPlayerWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listView = new QListView(page);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);

        stackedWidget->addWidget(page);
        playerPage = new QWidget();
        playerPage->setObjectName(QString::fromUtf8("playerPage"));
        playingLabel = new QLabel(playerPage);
        playingLabel->setObjectName(QString::fromUtf8("playingLabel"));
        playingLabel->setGeometry(QRect(0, 50, 291, 61));
        midLabel = new QLabel(playerPage);
        midLabel->setObjectName(QString::fromUtf8("midLabel"));
        midLabel->setGeometry(QRect(0, 120, 291, 21));
        posSlider = new QSlider(playerPage);
        posSlider->setObjectName(QString::fromUtf8("posSlider"));
        posSlider->setGeometry(QRect(0, 180, 301, 16));
        posSlider->setMaximum(0);
        posSlider->setOrientation(Qt::Horizontal);
        stackedWidget->addWidget(playerPage);

        horizontalLayout->addWidget(stackedWidget);

        widget1 = new QWidget(mediaPlayerWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        homeButton = new QToolButton(widget1);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));

        verticalLayout->addWidget(homeButton);

        playButton = new QToolButton(widget1);
        playButton->setObjectName(QString::fromUtf8("playButton"));

        verticalLayout->addWidget(playButton);

        prevButton = new QToolButton(widget1);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));

        verticalLayout->addWidget(prevButton);

        nextButton = new QToolButton(widget1);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        verticalLayout->addWidget(nextButton);

        stopButton = new QToolButton(widget1);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        verticalLayout->addWidget(stopButton);

        volumeSlider = new QSlider(widget1);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(volumeSlider);

        selectButton = new QToolButton(widget1);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        verticalLayout->addWidget(selectButton);

        backButton = new QToolButton(widget1);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        verticalLayout->addWidget(backButton);


        horizontalLayout->addWidget(widget1);


        retranslateUi(mediaPlayerWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mediaPlayerWidget);
    } // setupUi

    void retranslateUi(QWidget *mediaPlayerWidget)
    {
        mediaPlayerWidget->setWindowTitle(QApplication::translate("mediaPlayerWidget", "SCXML Media Player", 0, QApplication::UnicodeUTF8));
        playingLabel->setStyleSheet(QApplication::translate("mediaPlayerWidget", "QLabel {font-size: 24px; color: #336699}", 0, QApplication::UnicodeUTF8));
        playingLabel->setText(QApplication::translate("mediaPlayerWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        midLabel->setText(QApplication::translate("mediaPlayerWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        homeButton->setText(QApplication::translate("mediaPlayerWidget", "Home", 0, QApplication::UnicodeUTF8));
        playButton->setText(QApplication::translate("mediaPlayerWidget", "Play", 0, QApplication::UnicodeUTF8));
        prevButton->setText(QApplication::translate("mediaPlayerWidget", "Prev", 0, QApplication::UnicodeUTF8));
        nextButton->setText(QApplication::translate("mediaPlayerWidget", "Next", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("mediaPlayerWidget", "Stop", 0, QApplication::UnicodeUTF8));
        selectButton->setText(QApplication::translate("mediaPlayerWidget", "Select", 0, QApplication::UnicodeUTF8));
        backButton->setText(QApplication::translate("mediaPlayerWidget", "Back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mediaPlayerWidget: public Ui_mediaPlayerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYER_H

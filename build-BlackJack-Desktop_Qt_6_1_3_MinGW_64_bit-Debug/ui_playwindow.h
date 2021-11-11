/********************************************************************************
** Form generated from reading UI file 'playwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYWINDOW_H
#define UI_PLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QLabel *tableLabel;
    QLabel *statusLabel;
    QLabel *computerStatusLabel;
    QWidget *gridLayoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *card1Label_6;
    QLabel *card2Label_6;
    QLabel *card4Label_6;
    QLabel *card3Label_6;
    QLabel *card5Label_6;
    QLabel *card6Label_6;
    QLabel *statusLabel_2;
    QWidget *gridLayoutWidget_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *card1Label_7;
    QLabel *card2Label_7;
    QLabel *card3Label_7;
    QLabel *card4Label_7;
    QLabel *card5Label_7;
    QLabel *card6Label_7;
    QLabel *computerLabel;
    QWidget *gridLayoutWidget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *card1Label_8;
    QLabel *card2Label_8;
    QLabel *card3Label_8;
    QLabel *card4Label_8;
    QLabel *card5Label_8;
    QLabel *card6Label_8;
    QLabel *computerScoreLabel;
    QLabel *youLabel;
    QWidget *gridLayoutWidget_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *card1Label_9;
    QLabel *card2Label_9;
    QLabel *card3Label_9;
    QLabel *card4Label_9;
    QLabel *card5Label_9;
    QLabel *card6Label_9;
    QLabel *outcomeLabel_2;
    QLabel *playertotalLabel;
    QWidget *gridLayoutWidget;
    QHBoxLayout *horizontalLayout_11;
    QLabel *card1Label_10;
    QLabel *card2Label_10;
    QLabel *card4Label_10;
    QLabel *card3Label_10;
    QLabel *card5Label_10;
    QLabel *card6Label_10;
    QLabel *card7Label_2;
    QLabel *card8Label_2;
    QLabel *card9Label_2;
    QLabel *card10Label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *playagainButton_2;
    QPushButton *twistButton_2;
    QPushButton *okaybutton;
    QLabel *playercurrentLabel;
    QLabel *computercurrentLabel;
    QPushButton *four_random_card;
    QMenuBar *menubar;
    QMenu *menuQuit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName(QString::fromUtf8("PlayWindow"));
        PlayWindow->resize(800, 511);
        PlayWindow->setBaseSize(QSize(800, 500));
        actionQuit = new QAction(PlayWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(PlayWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableLabel = new QLabel(centralwidget);
        tableLabel->setObjectName(QString::fromUtf8("tableLabel"));
        tableLabel->setGeometry(QRect(0, 0, 800, 500));
        tableLabel->setBaseSize(QSize(800, 500));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(115, 350, 47, 13));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        statusLabel->setPalette(palette);
        computerStatusLabel = new QLabel(centralwidget);
        computerStatusLabel->setObjectName(QString::fromUtf8("computerStatusLabel"));
        computerStatusLabel->setGeometry(QRect(630, 350, 47, 13));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        computerStatusLabel->setPalette(palette1);
        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(420, 60, 381, 101));
        horizontalLayout_7 = new QHBoxLayout(gridLayoutWidget_4);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        card1Label_6 = new QLabel(gridLayoutWidget_4);
        card1Label_6->setObjectName(QString::fromUtf8("card1Label_6"));

        horizontalLayout_7->addWidget(card1Label_6);

        card2Label_6 = new QLabel(gridLayoutWidget_4);
        card2Label_6->setObjectName(QString::fromUtf8("card2Label_6"));

        horizontalLayout_7->addWidget(card2Label_6);

        card4Label_6 = new QLabel(gridLayoutWidget_4);
        card4Label_6->setObjectName(QString::fromUtf8("card4Label_6"));

        horizontalLayout_7->addWidget(card4Label_6);

        card3Label_6 = new QLabel(gridLayoutWidget_4);
        card3Label_6->setObjectName(QString::fromUtf8("card3Label_6"));

        horizontalLayout_7->addWidget(card3Label_6);

        card5Label_6 = new QLabel(gridLayoutWidget_4);
        card5Label_6->setObjectName(QString::fromUtf8("card5Label_6"));

        horizontalLayout_7->addWidget(card5Label_6);

        card6Label_6 = new QLabel(gridLayoutWidget_4);
        card6Label_6->setObjectName(QString::fromUtf8("card6Label_6"));

        horizontalLayout_7->addWidget(card6Label_6);

        statusLabel_2 = new QLabel(centralwidget);
        statusLabel_2->setObjectName(QString::fromUtf8("statusLabel_2"));
        statusLabel_2->setGeometry(QRect(115, 360, 47, 13));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        statusLabel_2->setPalette(palette2);
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(420, 160, 381, 101));
        horizontalLayout_8 = new QHBoxLayout(gridLayoutWidget_2);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        card1Label_7 = new QLabel(gridLayoutWidget_2);
        card1Label_7->setObjectName(QString::fromUtf8("card1Label_7"));

        horizontalLayout_8->addWidget(card1Label_7);

        card2Label_7 = new QLabel(gridLayoutWidget_2);
        card2Label_7->setObjectName(QString::fromUtf8("card2Label_7"));

        horizontalLayout_8->addWidget(card2Label_7);

        card3Label_7 = new QLabel(gridLayoutWidget_2);
        card3Label_7->setObjectName(QString::fromUtf8("card3Label_7"));

        horizontalLayout_8->addWidget(card3Label_7);

        card4Label_7 = new QLabel(gridLayoutWidget_2);
        card4Label_7->setObjectName(QString::fromUtf8("card4Label_7"));

        horizontalLayout_8->addWidget(card4Label_7);

        card5Label_7 = new QLabel(gridLayoutWidget_2);
        card5Label_7->setObjectName(QString::fromUtf8("card5Label_7"));

        horizontalLayout_8->addWidget(card5Label_7);

        card6Label_7 = new QLabel(gridLayoutWidget_2);
        card6Label_7->setObjectName(QString::fromUtf8("card6Label_7"));

        horizontalLayout_8->addWidget(card6Label_7);

        computerLabel = new QLabel(centralwidget);
        computerLabel->setObjectName(QString::fromUtf8("computerLabel"));
        computerLabel->setGeometry(QRect(580, 10, 161, 41));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        computerLabel->setPalette(palette3);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        computerLabel->setFont(font);
        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(420, 360, 381, 101));
        horizontalLayout_9 = new QHBoxLayout(gridLayoutWidget_5);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        card1Label_8 = new QLabel(gridLayoutWidget_5);
        card1Label_8->setObjectName(QString::fromUtf8("card1Label_8"));

        horizontalLayout_9->addWidget(card1Label_8);

        card2Label_8 = new QLabel(gridLayoutWidget_5);
        card2Label_8->setObjectName(QString::fromUtf8("card2Label_8"));

        horizontalLayout_9->addWidget(card2Label_8);

        card3Label_8 = new QLabel(gridLayoutWidget_5);
        card3Label_8->setObjectName(QString::fromUtf8("card3Label_8"));

        horizontalLayout_9->addWidget(card3Label_8);

        card4Label_8 = new QLabel(gridLayoutWidget_5);
        card4Label_8->setObjectName(QString::fromUtf8("card4Label_8"));

        horizontalLayout_9->addWidget(card4Label_8);

        card5Label_8 = new QLabel(gridLayoutWidget_5);
        card5Label_8->setObjectName(QString::fromUtf8("card5Label_8"));

        horizontalLayout_9->addWidget(card5Label_8);

        card6Label_8 = new QLabel(gridLayoutWidget_5);
        card6Label_8->setObjectName(QString::fromUtf8("card6Label_8"));

        horizontalLayout_9->addWidget(card6Label_8);

        computerScoreLabel = new QLabel(centralwidget);
        computerScoreLabel->setObjectName(QString::fromUtf8("computerScoreLabel"));
        computerScoreLabel->setGeometry(QRect(730, 20, 56, 12));
        youLabel = new QLabel(centralwidget);
        youLabel->setObjectName(QString::fromUtf8("youLabel"));
        youLabel->setGeometry(QRect(20, 10, 61, 41));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        youLabel->setPalette(palette4);
        youLabel->setFont(font);
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(420, 260, 381, 101));
        horizontalLayout_10 = new QHBoxLayout(gridLayoutWidget_3);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        card1Label_9 = new QLabel(gridLayoutWidget_3);
        card1Label_9->setObjectName(QString::fromUtf8("card1Label_9"));

        horizontalLayout_10->addWidget(card1Label_9);

        card2Label_9 = new QLabel(gridLayoutWidget_3);
        card2Label_9->setObjectName(QString::fromUtf8("card2Label_9"));

        horizontalLayout_10->addWidget(card2Label_9);

        card3Label_9 = new QLabel(gridLayoutWidget_3);
        card3Label_9->setObjectName(QString::fromUtf8("card3Label_9"));

        horizontalLayout_10->addWidget(card3Label_9);

        card4Label_9 = new QLabel(gridLayoutWidget_3);
        card4Label_9->setObjectName(QString::fromUtf8("card4Label_9"));

        horizontalLayout_10->addWidget(card4Label_9);

        card5Label_9 = new QLabel(gridLayoutWidget_3);
        card5Label_9->setObjectName(QString::fromUtf8("card5Label_9"));

        horizontalLayout_10->addWidget(card5Label_9);

        card6Label_9 = new QLabel(gridLayoutWidget_3);
        card6Label_9->setObjectName(QString::fromUtf8("card6Label_9"));

        horizontalLayout_10->addWidget(card6Label_9);

        outcomeLabel_2 = new QLabel(centralwidget);
        outcomeLabel_2->setObjectName(QString::fromUtf8("outcomeLabel_2"));
        outcomeLabel_2->setGeometry(QRect(70, 290, 281, 121));
        QPalette palette5;
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        outcomeLabel_2->setPalette(palette5);
        outcomeLabel_2->setFont(font);
        outcomeLabel_2->setAlignment(Qt::AlignCenter);
        playertotalLabel = new QLabel(centralwidget);
        playertotalLabel->setObjectName(QString::fromUtf8("playertotalLabel"));
        playertotalLabel->setGeometry(QRect(80, 20, 56, 12));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 160, 381, 101));
        horizontalLayout_11 = new QHBoxLayout(gridLayoutWidget);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        card1Label_10 = new QLabel(gridLayoutWidget);
        card1Label_10->setObjectName(QString::fromUtf8("card1Label_10"));

        horizontalLayout_11->addWidget(card1Label_10);

        card2Label_10 = new QLabel(gridLayoutWidget);
        card2Label_10->setObjectName(QString::fromUtf8("card2Label_10"));

        horizontalLayout_11->addWidget(card2Label_10);

        card4Label_10 = new QLabel(gridLayoutWidget);
        card4Label_10->setObjectName(QString::fromUtf8("card4Label_10"));

        horizontalLayout_11->addWidget(card4Label_10);

        card3Label_10 = new QLabel(gridLayoutWidget);
        card3Label_10->setObjectName(QString::fromUtf8("card3Label_10"));

        horizontalLayout_11->addWidget(card3Label_10);

        card5Label_10 = new QLabel(gridLayoutWidget);
        card5Label_10->setObjectName(QString::fromUtf8("card5Label_10"));

        horizontalLayout_11->addWidget(card5Label_10);

        card6Label_10 = new QLabel(gridLayoutWidget);
        card6Label_10->setObjectName(QString::fromUtf8("card6Label_10"));

        horizontalLayout_11->addWidget(card6Label_10);

        card7Label_2 = new QLabel(gridLayoutWidget);
        card7Label_2->setObjectName(QString::fromUtf8("card7Label_2"));

        horizontalLayout_11->addWidget(card7Label_2);

        card8Label_2 = new QLabel(gridLayoutWidget);
        card8Label_2->setObjectName(QString::fromUtf8("card8Label_2"));

        horizontalLayout_11->addWidget(card8Label_2);

        card9Label_2 = new QLabel(gridLayoutWidget);
        card9Label_2->setObjectName(QString::fromUtf8("card9Label_2"));

        horizontalLayout_11->addWidget(card9Label_2);

        card10Label_2 = new QLabel(gridLayoutWidget);
        card10Label_2->setObjectName(QString::fromUtf8("card10Label_2"));

        horizontalLayout_11->addWidget(card10Label_2);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 430, 401, 30));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        playagainButton_2 = new QPushButton(layoutWidget);
        playagainButton_2->setObjectName(QString::fromUtf8("playagainButton_2"));
        playagainButton_2->setEnabled(false);

        horizontalLayout_12->addWidget(playagainButton_2);

        twistButton_2 = new QPushButton(layoutWidget);
        twistButton_2->setObjectName(QString::fromUtf8("twistButton_2"));

        horizontalLayout_12->addWidget(twistButton_2);

        okaybutton = new QPushButton(layoutWidget);
        okaybutton->setObjectName(QString::fromUtf8("okaybutton"));

        horizontalLayout_12->addWidget(okaybutton);

        playercurrentLabel = new QLabel(centralwidget);
        playercurrentLabel->setObjectName(QString::fromUtf8("playercurrentLabel"));
        playercurrentLabel->setGeometry(QRect(80, 50, 56, 12));
        computercurrentLabel = new QLabel(centralwidget);
        computercurrentLabel->setObjectName(QString::fromUtf8("computercurrentLabel"));
        computercurrentLabel->setGeometry(QRect(730, 40, 54, 21));
        four_random_card = new QPushButton(centralwidget);
        four_random_card->setObjectName(QString::fromUtf8("four_random_card"));
        four_random_card->setGeometry(QRect(10, 390, 101, 23));
        PlayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuQuit = new QMenu(menubar);
        menuQuit->setObjectName(QString::fromUtf8("menuQuit"));
        PlayWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PlayWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PlayWindow->setStatusBar(statusbar);

        menubar->addAction(menuQuit->menuAction());
        menuQuit->addAction(actionQuit);

        retranslateUi(PlayWindow);

        QMetaObject::connectSlotsByName(PlayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlayWindow)
    {
        PlayWindow->setWindowTitle(QCoreApplication::translate("PlayWindow", "BlackJack C++ Made by Dominic Heal", nullptr));
        actionQuit->setText(QCoreApplication::translate("PlayWindow", "Quit", nullptr));
        tableLabel->setText(QString());
        statusLabel->setText(QString());
        computerStatusLabel->setText(QString());
        card1Label_6->setText(QString());
        card2Label_6->setText(QString());
        card4Label_6->setText(QString());
        card3Label_6->setText(QString());
        card5Label_6->setText(QString());
        card6Label_6->setText(QString());
        statusLabel_2->setText(QString());
        card1Label_7->setText(QString());
        card2Label_7->setText(QString());
        card3Label_7->setText(QString());
        card4Label_7->setText(QString());
        card5Label_7->setText(QString());
        card6Label_7->setText(QString());
        computerLabel->setText(QCoreApplication::translate("PlayWindow", "Computer", nullptr));
        card1Label_8->setText(QString());
        card2Label_8->setText(QString());
        card3Label_8->setText(QString());
        card4Label_8->setText(QString());
        card5Label_8->setText(QString());
        card6Label_8->setText(QString());
        computerScoreLabel->setText(QCoreApplication::translate("PlayWindow", "total:0", nullptr));
        youLabel->setText(QCoreApplication::translate("PlayWindow", "You", nullptr));
        card1Label_9->setText(QString());
        card2Label_9->setText(QString());
        card3Label_9->setText(QString());
        card4Label_9->setText(QString());
        card5Label_9->setText(QString());
        card6Label_9->setText(QString());
        outcomeLabel_2->setText(QString());
        playertotalLabel->setText(QCoreApplication::translate("PlayWindow", "total:0", nullptr));
        card1Label_10->setText(QString());
        card2Label_10->setText(QString());
        card4Label_10->setText(QString());
        card3Label_10->setText(QString());
        card5Label_10->setText(QString());
        card6Label_10->setText(QString());
        card7Label_2->setText(QString());
        card8Label_2->setText(QString());
        card9Label_2->setText(QString());
        card10Label_2->setText(QString());
        playagainButton_2->setText(QCoreApplication::translate("PlayWindow", "Play Again", nullptr));
        twistButton_2->setText(QCoreApplication::translate("PlayWindow", "Twist", nullptr));
        okaybutton->setText(QCoreApplication::translate("PlayWindow", "okay", nullptr));
        playercurrentLabel->setText(QCoreApplication::translate("PlayWindow", "current:0", nullptr));
        computercurrentLabel->setText(QCoreApplication::translate("PlayWindow", "current:0", nullptr));
        four_random_card->setText(QCoreApplication::translate("PlayWindow", "random_four", nullptr));
        menuQuit->setTitle(QCoreApplication::translate("PlayWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H

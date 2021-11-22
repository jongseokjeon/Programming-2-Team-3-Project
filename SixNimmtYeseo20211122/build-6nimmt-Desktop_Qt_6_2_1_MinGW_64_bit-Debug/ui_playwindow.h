/********************************************************************************
** Form generated from reading UI file 'playwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYWINDOW_H
#define UI_PLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
    QLabel *statusLabel;
    QLabel *statusLabel_2;
    QLabel *statusLabel_3;
    QLabel *youLabel;
    QLabel *playertotalLabel_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QLabel *card1Label_10;
    QLabel *card2Label_10;
    QLabel *card7Label_2;
    QLabel *card8Label_2;
    QLabel *card5Label_10;
    QLabel *card3Label_10;
    QLabel *card10Label_2;
    QLabel *card4Label_10;
    QLabel *card9Label_2;
    QLabel *card6Label_10;
    QLabel *playercurrentLabel_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *playagainButton_3;
    QPushButton *twistButton_2;
    QPushButton *stickButton_2;
    QLabel *computerLabel_2;
    QLabel *computercurrentLabel;
    QLabel *computerStatusLabel;
    QWidget *gridLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *card1Label_14;
    QLabel *tableLabel_2;
    QLabel *card2Label_4;
    QLabel *card3Label_4;
    QLabel *card4Label_4;
    QLabel *card5Label_4;
    QLabel *card6Label_4;
    QLabel *card7Label_4;
    QLabel *card8Label_4;
    QLabel *card9Label_4;
    QLabel *card10Label_4;
    QWidget *gridLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *card1Label_13;
    QLabel *tableLabel_3;
    QLabel *card2Label_5;
    QLabel *card3Label_5;
    QLabel *card4Label_5;
    QLabel *card5Label_5;
    QLabel *card6Label_5;
    QLabel *card7Label_5;
    QLabel *card8Label_5;
    QLabel *card9Label_5;
    QLabel *card10Label_5;
    QWidget *gridLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *card1Label_11;
    QLabel *tableLabel_4;
    QLabel *card2Label_6;
    QLabel *card3Label_6;
    QLabel *card4Label_6;
    QLabel *card5Label_6;
    QLabel *card6Label_6;
    QLabel *card7Label_6;
    QLabel *card8Label_6;
    QLabel *card9Label_6;
    QLabel *card10Label_6;
    QWidget *gridLayoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *card1Label_12;
    QLabel *tableLabel_5;
    QLabel *card2Label_7;
    QLabel *card3Label_7;
    QLabel *card4Label_7;
    QLabel *card5Label_7;
    QLabel *card6Label_7;
    QLabel *card7Label_7;
    QLabel *card8Label_7;
    QLabel *card9Label_7;
    QLabel *card10Label_7;
    QPushButton *OKAYButton;
    QMenuBar *menubar;
    QMenu *menuQuit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName(QString::fromUtf8("PlayWindow"));
        PlayWindow->resize(883, 494);
        PlayWindow->setBaseSize(QSize(800, 500));
        PlayWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/table.png);"));
        actionQuit = new QAction(PlayWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(PlayWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
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
        statusLabel_2 = new QLabel(centralwidget);
        statusLabel_2->setObjectName(QString::fromUtf8("statusLabel_2"));
        statusLabel_2->setGeometry(QRect(115, 360, 47, 13));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        statusLabel_2->setPalette(palette1);
        statusLabel_3 = new QLabel(centralwidget);
        statusLabel_3->setObjectName(QString::fromUtf8("statusLabel_3"));
        statusLabel_3->setGeometry(QRect(115, 310, 47, 13));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        statusLabel_3->setPalette(palette2);
        youLabel = new QLabel(centralwidget);
        youLabel->setObjectName(QString::fromUtf8("youLabel"));
        youLabel->setGeometry(QRect(190, 360, 61, 41));
        QPalette palette3;
        QBrush brush2(QColor(255, 0, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        QBrush brush3(QColor(255, 0, 127, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        QBrush brush4(QColor(255, 0, 127, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        QBrush brush5(QColor(255, 0, 127, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        youLabel->setPalette(palette3);
        QFont font;
        font.setFamilies({QString::fromUtf8("Impact")});
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        youLabel->setFont(font);
        youLabel->setStyleSheet(QString::fromUtf8("font: 9pt \"Impact\";\n"
"color: rgb(255, 0, 127);"));
        playertotalLabel_2 = new QLabel(centralwidget);
        playertotalLabel_2->setObjectName(QString::fromUtf8("playertotalLabel_2"));
        playertotalLabel_2->setGeometry(QRect(30, 430, 47, 20));
        QPalette palette4;
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush7(QColor(0, 0, 0, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush7);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        playertotalLabel_2->setPalette(palette4);
        playertotalLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Impact\";"));
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(30, 60, 211, 371));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        card1Label_10 = new QLabel(gridLayoutWidget_3);
        card1Label_10->setObjectName(QString::fromUtf8("card1Label_10"));

        gridLayout_2->addWidget(card1Label_10, 0, 0, 1, 1);

        card2Label_10 = new QLabel(gridLayoutWidget_3);
        card2Label_10->setObjectName(QString::fromUtf8("card2Label_10"));

        gridLayout_2->addWidget(card2Label_10, 0, 1, 1, 1);

        card7Label_2 = new QLabel(gridLayoutWidget_3);
        card7Label_2->setObjectName(QString::fromUtf8("card7Label_2"));

        gridLayout_2->addWidget(card7Label_2, 2, 0, 1, 1);

        card8Label_2 = new QLabel(gridLayoutWidget_3);
        card8Label_2->setObjectName(QString::fromUtf8("card8Label_2"));

        gridLayout_2->addWidget(card8Label_2, 2, 1, 1, 1);

        card5Label_10 = new QLabel(gridLayoutWidget_3);
        card5Label_10->setObjectName(QString::fromUtf8("card5Label_10"));

        gridLayout_2->addWidget(card5Label_10, 1, 1, 1, 1);

        card3Label_10 = new QLabel(gridLayoutWidget_3);
        card3Label_10->setObjectName(QString::fromUtf8("card3Label_10"));

        gridLayout_2->addWidget(card3Label_10, 0, 2, 1, 1);

        card10Label_2 = new QLabel(gridLayoutWidget_3);
        card10Label_2->setObjectName(QString::fromUtf8("card10Label_2"));

        gridLayout_2->addWidget(card10Label_2, 3, 0, 1, 1);

        card4Label_10 = new QLabel(gridLayoutWidget_3);
        card4Label_10->setObjectName(QString::fromUtf8("card4Label_10"));

        gridLayout_2->addWidget(card4Label_10, 1, 0, 1, 1);

        card9Label_2 = new QLabel(gridLayoutWidget_3);
        card9Label_2->setObjectName(QString::fromUtf8("card9Label_2"));

        gridLayout_2->addWidget(card9Label_2, 2, 2, 1, 1);

        card6Label_10 = new QLabel(gridLayoutWidget_3);
        card6Label_10->setObjectName(QString::fromUtf8("card6Label_10"));

        gridLayout_2->addWidget(card6Label_10, 1, 2, 1, 1);

        playercurrentLabel_2 = new QLabel(centralwidget);
        playercurrentLabel_2->setObjectName(QString::fromUtf8("playercurrentLabel_2"));
        playercurrentLabel_2->setGeometry(QRect(190, 430, 111, 16));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush10);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QBrush brush12(QColor(0, 0, 0, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        playercurrentLabel_2->setPalette(palette5);
        playercurrentLabel_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Impact\";\n"
"color: rgb(0, 0, 0);"));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 30, 254, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        playagainButton_3 = new QPushButton(layoutWidget_2);
        playagainButton_3->setObjectName(QString::fromUtf8("playagainButton_3"));
        playagainButton_3->setEnabled(false);

        horizontalLayout_2->addWidget(playagainButton_3);

        twistButton_2 = new QPushButton(layoutWidget_2);
        twistButton_2->setObjectName(QString::fromUtf8("twistButton_2"));

        horizontalLayout_2->addWidget(twistButton_2);

        stickButton_2 = new QPushButton(layoutWidget_2);
        stickButton_2->setObjectName(QString::fromUtf8("stickButton_2"));

        horizontalLayout_2->addWidget(stickButton_2);

        computerLabel_2 = new QLabel(centralwidget);
        computerLabel_2->setObjectName(QString::fromUtf8("computerLabel_2"));
        computerLabel_2->setGeometry(QRect(720, 400, 161, 41));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        QBrush brush13(QColor(255, 0, 127, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        QBrush brush14(QColor(255, 0, 127, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        QBrush brush15(QColor(255, 0, 127, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
#endif
        computerLabel_2->setPalette(palette6);
        computerLabel_2->setFont(font);
        computerLabel_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"color: rgb(255, 0, 127);\n"
"font: 9pt \"Impact\";"));
        computercurrentLabel = new QLabel(centralwidget);
        computercurrentLabel->setObjectName(QString::fromUtf8("computercurrentLabel"));
        computercurrentLabel->setGeometry(QRect(300, 430, 111, 21));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush16(QColor(0, 0, 0, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush16);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QBrush brush17(QColor(0, 0, 0, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush17);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QBrush brush18(QColor(0, 0, 0, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush18);
#endif
        computercurrentLabel->setPalette(palette7);
        computercurrentLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 9pt \"Impact\";"));
        computerStatusLabel = new QLabel(centralwidget);
        computerStatusLabel->setObjectName(QString::fromUtf8("computerStatusLabel"));
        computerStatusLabel->setGeometry(QRect(590, 380, 47, 13));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        computerStatusLabel->setPalette(palette8);
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(320, 130, 381, 101));
        horizontalLayout_4 = new QHBoxLayout(gridLayoutWidget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        card1Label_14 = new QLabel(gridLayoutWidget_2);
        card1Label_14->setObjectName(QString::fromUtf8("card1Label_14"));

        horizontalLayout_4->addWidget(card1Label_14);

        tableLabel_2 = new QLabel(gridLayoutWidget_2);
        tableLabel_2->setObjectName(QString::fromUtf8("tableLabel_2"));
        tableLabel_2->setBaseSize(QSize(800, 500));

        horizontalLayout_4->addWidget(tableLabel_2);

        card2Label_4 = new QLabel(gridLayoutWidget_2);
        card2Label_4->setObjectName(QString::fromUtf8("card2Label_4"));

        horizontalLayout_4->addWidget(card2Label_4);

        card3Label_4 = new QLabel(gridLayoutWidget_2);
        card3Label_4->setObjectName(QString::fromUtf8("card3Label_4"));

        horizontalLayout_4->addWidget(card3Label_4);

        card4Label_4 = new QLabel(gridLayoutWidget_2);
        card4Label_4->setObjectName(QString::fromUtf8("card4Label_4"));

        horizontalLayout_4->addWidget(card4Label_4);

        card5Label_4 = new QLabel(gridLayoutWidget_2);
        card5Label_4->setObjectName(QString::fromUtf8("card5Label_4"));

        horizontalLayout_4->addWidget(card5Label_4);

        card6Label_4 = new QLabel(gridLayoutWidget_2);
        card6Label_4->setObjectName(QString::fromUtf8("card6Label_4"));

        horizontalLayout_4->addWidget(card6Label_4);

        card7Label_4 = new QLabel(gridLayoutWidget_2);
        card7Label_4->setObjectName(QString::fromUtf8("card7Label_4"));

        horizontalLayout_4->addWidget(card7Label_4);

        card8Label_4 = new QLabel(gridLayoutWidget_2);
        card8Label_4->setObjectName(QString::fromUtf8("card8Label_4"));

        horizontalLayout_4->addWidget(card8Label_4);

        card9Label_4 = new QLabel(gridLayoutWidget_2);
        card9Label_4->setObjectName(QString::fromUtf8("card9Label_4"));

        horizontalLayout_4->addWidget(card9Label_4);

        card10Label_4 = new QLabel(gridLayoutWidget_2);
        card10Label_4->setObjectName(QString::fromUtf8("card10Label_4"));

        horizontalLayout_4->addWidget(card10Label_4);

        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(320, 230, 381, 101));
        horizontalLayout_5 = new QHBoxLayout(gridLayoutWidget_4);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        card1Label_13 = new QLabel(gridLayoutWidget_4);
        card1Label_13->setObjectName(QString::fromUtf8("card1Label_13"));

        horizontalLayout_5->addWidget(card1Label_13);

        tableLabel_3 = new QLabel(gridLayoutWidget_4);
        tableLabel_3->setObjectName(QString::fromUtf8("tableLabel_3"));
        tableLabel_3->setBaseSize(QSize(800, 500));

        horizontalLayout_5->addWidget(tableLabel_3);

        card2Label_5 = new QLabel(gridLayoutWidget_4);
        card2Label_5->setObjectName(QString::fromUtf8("card2Label_5"));

        horizontalLayout_5->addWidget(card2Label_5);

        card3Label_5 = new QLabel(gridLayoutWidget_4);
        card3Label_5->setObjectName(QString::fromUtf8("card3Label_5"));

        horizontalLayout_5->addWidget(card3Label_5);

        card4Label_5 = new QLabel(gridLayoutWidget_4);
        card4Label_5->setObjectName(QString::fromUtf8("card4Label_5"));

        horizontalLayout_5->addWidget(card4Label_5);

        card5Label_5 = new QLabel(gridLayoutWidget_4);
        card5Label_5->setObjectName(QString::fromUtf8("card5Label_5"));

        horizontalLayout_5->addWidget(card5Label_5);

        card6Label_5 = new QLabel(gridLayoutWidget_4);
        card6Label_5->setObjectName(QString::fromUtf8("card6Label_5"));

        horizontalLayout_5->addWidget(card6Label_5);

        card7Label_5 = new QLabel(gridLayoutWidget_4);
        card7Label_5->setObjectName(QString::fromUtf8("card7Label_5"));

        horizontalLayout_5->addWidget(card7Label_5);

        card8Label_5 = new QLabel(gridLayoutWidget_4);
        card8Label_5->setObjectName(QString::fromUtf8("card8Label_5"));

        horizontalLayout_5->addWidget(card8Label_5);

        card9Label_5 = new QLabel(gridLayoutWidget_4);
        card9Label_5->setObjectName(QString::fromUtf8("card9Label_5"));

        horizontalLayout_5->addWidget(card9Label_5);

        card10Label_5 = new QLabel(gridLayoutWidget_4);
        card10Label_5->setObjectName(QString::fromUtf8("card10Label_5"));

        horizontalLayout_5->addWidget(card10Label_5);

        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(320, 330, 381, 101));
        horizontalLayout_6 = new QHBoxLayout(gridLayoutWidget_5);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        card1Label_11 = new QLabel(gridLayoutWidget_5);
        card1Label_11->setObjectName(QString::fromUtf8("card1Label_11"));

        horizontalLayout_6->addWidget(card1Label_11);

        tableLabel_4 = new QLabel(gridLayoutWidget_5);
        tableLabel_4->setObjectName(QString::fromUtf8("tableLabel_4"));
        tableLabel_4->setBaseSize(QSize(800, 500));

        horizontalLayout_6->addWidget(tableLabel_4);

        card2Label_6 = new QLabel(gridLayoutWidget_5);
        card2Label_6->setObjectName(QString::fromUtf8("card2Label_6"));

        horizontalLayout_6->addWidget(card2Label_6);

        card3Label_6 = new QLabel(gridLayoutWidget_5);
        card3Label_6->setObjectName(QString::fromUtf8("card3Label_6"));

        horizontalLayout_6->addWidget(card3Label_6);

        card4Label_6 = new QLabel(gridLayoutWidget_5);
        card4Label_6->setObjectName(QString::fromUtf8("card4Label_6"));

        horizontalLayout_6->addWidget(card4Label_6);

        card5Label_6 = new QLabel(gridLayoutWidget_5);
        card5Label_6->setObjectName(QString::fromUtf8("card5Label_6"));

        horizontalLayout_6->addWidget(card5Label_6);

        card6Label_6 = new QLabel(gridLayoutWidget_5);
        card6Label_6->setObjectName(QString::fromUtf8("card6Label_6"));

        horizontalLayout_6->addWidget(card6Label_6);

        card7Label_6 = new QLabel(gridLayoutWidget_5);
        card7Label_6->setObjectName(QString::fromUtf8("card7Label_6"));

        horizontalLayout_6->addWidget(card7Label_6);

        card8Label_6 = new QLabel(gridLayoutWidget_5);
        card8Label_6->setObjectName(QString::fromUtf8("card8Label_6"));

        horizontalLayout_6->addWidget(card8Label_6);

        card9Label_6 = new QLabel(gridLayoutWidget_5);
        card9Label_6->setObjectName(QString::fromUtf8("card9Label_6"));

        horizontalLayout_6->addWidget(card9Label_6);

        card10Label_6 = new QLabel(gridLayoutWidget_5);
        card10Label_6->setObjectName(QString::fromUtf8("card10Label_6"));

        horizontalLayout_6->addWidget(card10Label_6);

        gridLayoutWidget_6 = new QWidget(centralwidget);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(320, 30, 381, 101));
        horizontalLayout_7 = new QHBoxLayout(gridLayoutWidget_6);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        card1Label_12 = new QLabel(gridLayoutWidget_6);
        card1Label_12->setObjectName(QString::fromUtf8("card1Label_12"));

        horizontalLayout_7->addWidget(card1Label_12);

        tableLabel_5 = new QLabel(gridLayoutWidget_6);
        tableLabel_5->setObjectName(QString::fromUtf8("tableLabel_5"));
        tableLabel_5->setBaseSize(QSize(800, 500));

        horizontalLayout_7->addWidget(tableLabel_5);

        card2Label_7 = new QLabel(gridLayoutWidget_6);
        card2Label_7->setObjectName(QString::fromUtf8("card2Label_7"));

        horizontalLayout_7->addWidget(card2Label_7);

        card3Label_7 = new QLabel(gridLayoutWidget_6);
        card3Label_7->setObjectName(QString::fromUtf8("card3Label_7"));

        horizontalLayout_7->addWidget(card3Label_7);

        card4Label_7 = new QLabel(gridLayoutWidget_6);
        card4Label_7->setObjectName(QString::fromUtf8("card4Label_7"));

        horizontalLayout_7->addWidget(card4Label_7);

        card5Label_7 = new QLabel(gridLayoutWidget_6);
        card5Label_7->setObjectName(QString::fromUtf8("card5Label_7"));

        horizontalLayout_7->addWidget(card5Label_7);

        card6Label_7 = new QLabel(gridLayoutWidget_6);
        card6Label_7->setObjectName(QString::fromUtf8("card6Label_7"));

        horizontalLayout_7->addWidget(card6Label_7);

        card7Label_7 = new QLabel(gridLayoutWidget_6);
        card7Label_7->setObjectName(QString::fromUtf8("card7Label_7"));

        horizontalLayout_7->addWidget(card7Label_7);

        card8Label_7 = new QLabel(gridLayoutWidget_6);
        card8Label_7->setObjectName(QString::fromUtf8("card8Label_7"));

        horizontalLayout_7->addWidget(card8Label_7);

        card9Label_7 = new QLabel(gridLayoutWidget_6);
        card9Label_7->setObjectName(QString::fromUtf8("card9Label_7"));

        horizontalLayout_7->addWidget(card9Label_7);

        card10Label_7 = new QLabel(gridLayoutWidget_6);
        card10Label_7->setObjectName(QString::fromUtf8("card10Label_7"));

        horizontalLayout_7->addWidget(card10Label_7);

        OKAYButton = new QPushButton(centralwidget);
        OKAYButton->setObjectName(QString::fromUtf8("OKAYButton"));
        OKAYButton->setGeometry(QRect(710, 430, 75, 23));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Showcard Gothic")});
        OKAYButton->setFont(font1);
        PlayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 883, 21));
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
        PlayWindow->setWindowTitle(QCoreApplication::translate("PlayWindow", "6nimmt c++", nullptr));
        actionQuit->setText(QCoreApplication::translate("PlayWindow", "Quit", nullptr));
        statusLabel->setText(QString());
        statusLabel_2->setText(QString());
        statusLabel_3->setText(QString());
        youLabel->setText(QCoreApplication::translate("PlayWindow", "You", nullptr));
        playertotalLabel_2->setText(QCoreApplication::translate("PlayWindow", "Total: 0", nullptr));
        card1Label_10->setText(QString());
        card2Label_10->setText(QString());
        card7Label_2->setText(QString());
        card8Label_2->setText(QString());
        card5Label_10->setText(QString());
        card3Label_10->setText(QString());
        card10Label_2->setText(QString());
        card4Label_10->setText(QString());
        card9Label_2->setText(QString());
        card6Label_10->setText(QString());
        playercurrentLabel_2->setText(QCoreApplication::translate("PlayWindow", "Current Cardl: 0", nullptr));
        playagainButton_3->setText(QCoreApplication::translate("PlayWindow", "Play Again", nullptr));
        twistButton_2->setText(QCoreApplication::translate("PlayWindow", "Twist", nullptr));
        stickButton_2->setText(QCoreApplication::translate("PlayWindow", "Stick", nullptr));
        computerLabel_2->setText(QCoreApplication::translate("PlayWindow", "Computer", nullptr));
        computercurrentLabel->setText(QCoreApplication::translate("PlayWindow", "Computer:", nullptr));
        computerStatusLabel->setText(QString());
        card1Label_14->setText(QString());
        tableLabel_2->setText(QString());
        card2Label_4->setText(QString());
        card3Label_4->setText(QString());
        card4Label_4->setText(QString());
        card5Label_4->setText(QString());
        card6Label_4->setText(QString());
        card7Label_4->setText(QString());
        card8Label_4->setText(QString());
        card9Label_4->setText(QString());
        card10Label_4->setText(QString());
        card1Label_13->setText(QString());
        tableLabel_3->setText(QString());
        card2Label_5->setText(QString());
        card3Label_5->setText(QString());
        card4Label_5->setText(QString());
        card5Label_5->setText(QString());
        card6Label_5->setText(QString());
        card7Label_5->setText(QString());
        card8Label_5->setText(QString());
        card9Label_5->setText(QString());
        card10Label_5->setText(QString());
        card1Label_11->setText(QString());
        tableLabel_4->setText(QString());
        card2Label_6->setText(QString());
        card3Label_6->setText(QString());
        card4Label_6->setText(QString());
        card5Label_6->setText(QString());
        card6Label_6->setText(QString());
        card7Label_6->setText(QString());
        card8Label_6->setText(QString());
        card9Label_6->setText(QString());
        card10Label_6->setText(QString());
        card1Label_12->setText(QString());
        tableLabel_5->setText(QString());
        card2Label_7->setText(QString());
        card3Label_7->setText(QString());
        card4Label_7->setText(QString());
        card5Label_7->setText(QString());
        card6Label_7->setText(QString());
        card7Label_7->setText(QString());
        card8Label_7->setText(QString());
        card9Label_7->setText(QString());
        card10Label_7->setText(QString());
        OKAYButton->setText(QCoreApplication::translate("PlayWindow", "OKAY", nullptr));
        menuQuit->setTitle(QCoreApplication::translate("PlayWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H

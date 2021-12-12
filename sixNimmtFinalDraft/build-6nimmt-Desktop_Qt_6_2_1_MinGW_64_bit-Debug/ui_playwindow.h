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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
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
    QLabel *card6Label_10;
    QLabel *card5Label_10;
    QLabel *card4Label_10;
    QLabel *card1Label_10;
    QLabel *card3Label_10;
    QLabel *card10Label_2;
    QLabel *card9Label_2;
    QLabel *card2Label_10;
    QLabel *card8Label_2;
    QLabel *card7Label_2;
    QLabel *playercurrentLabel_2;
    QLabel *computerLabel_2;
    QLabel *computercurrentLabel;
    QLabel *computerStatusLabel;
    QWidget *gridLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *cl_2_1;
    QLabel *cl_2_2;
    QLabel *cl_2_3;
    QLabel *cl_2_4;
    QLabel *cl_2_5;
    QLabel *cl_2_6;
    QWidget *gridLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *cl_3_1;
    QLabel *cl_3_2;
    QLabel *cl_3_3;
    QLabel *cl_3_4;
    QLabel *cl_3_5;
    QLabel *cl_3_6;
    QWidget *gridLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *cl_4_1;
    QLabel *cl_4_2;
    QLabel *cl_4_3;
    QLabel *cl_4_4;
    QLabel *cl_4_5;
    QLabel *cl_4_6;
    QWidget *gridLayoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *cl_1_1;
    QLabel *cl_1_2;
    QLabel *cl_1_3;
    QLabel *cl_1_4;
    QLabel *cl_1_5;
    QLabel *cl_1_6;
    QPushButton *FINISH;
    QLabel *computertotalLabel_2;
    QLabel *playertotalLabel_3;
    QLabel *Directions;
    QLabel *Directions2;
    QLabel *promptLabel;
    QDialogButtonBox *regameButton;
    QMenuBar *menubar;
    QMenu *menuQuit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName(QString::fromUtf8("PlayWindow"));
        PlayWindow->resize(883, 549);
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
        playertotalLabel_2->setGeometry(QRect(190, 390, 47, 13));
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
        gridLayoutWidget_3->setGeometry(QRect(40, 60, 211, 311));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        card6Label_10 = new QLabel(gridLayoutWidget_3);
        card6Label_10->setObjectName(QString::fromUtf8("card6Label_10"));

        gridLayout_2->addWidget(card6Label_10, 1, 2, 1, 1);

        card5Label_10 = new QLabel(gridLayoutWidget_3);
        card5Label_10->setObjectName(QString::fromUtf8("card5Label_10"));

        gridLayout_2->addWidget(card5Label_10, 1, 1, 1, 1);

        card4Label_10 = new QLabel(gridLayoutWidget_3);
        card4Label_10->setObjectName(QString::fromUtf8("card4Label_10"));

        gridLayout_2->addWidget(card4Label_10, 1, 0, 1, 1);

        card1Label_10 = new QLabel(gridLayoutWidget_3);
        card1Label_10->setObjectName(QString::fromUtf8("card1Label_10"));

        gridLayout_2->addWidget(card1Label_10, 0, 0, 1, 1);

        card3Label_10 = new QLabel(gridLayoutWidget_3);
        card3Label_10->setObjectName(QString::fromUtf8("card3Label_10"));

        gridLayout_2->addWidget(card3Label_10, 0, 2, 1, 1);

        card10Label_2 = new QLabel(gridLayoutWidget_3);
        card10Label_2->setObjectName(QString::fromUtf8("card10Label_2"));

        gridLayout_2->addWidget(card10Label_2, 3, 0, 1, 1);

        card9Label_2 = new QLabel(gridLayoutWidget_3);
        card9Label_2->setObjectName(QString::fromUtf8("card9Label_2"));

        gridLayout_2->addWidget(card9Label_2, 2, 2, 1, 1);

        card2Label_10 = new QLabel(gridLayoutWidget_3);
        card2Label_10->setObjectName(QString::fromUtf8("card2Label_10"));

        gridLayout_2->addWidget(card2Label_10, 0, 1, 1, 1);

        card8Label_2 = new QLabel(gridLayoutWidget_3);
        card8Label_2->setObjectName(QString::fromUtf8("card8Label_2"));

        gridLayout_2->addWidget(card8Label_2, 2, 1, 1, 1);

        card7Label_2 = new QLabel(gridLayoutWidget_3);
        card7Label_2->setObjectName(QString::fromUtf8("card7Label_2"));

        gridLayout_2->addWidget(card7Label_2, 2, 0, 1, 1);

        playercurrentLabel_2 = new QLabel(centralwidget);
        playercurrentLabel_2->setObjectName(QString::fromUtf8("playercurrentLabel_2"));
        playercurrentLabel_2->setGeometry(QRect(190, 410, 111, 16));
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
        computerLabel_2 = new QLabel(centralwidget);
        computerLabel_2->setObjectName(QString::fromUtf8("computerLabel_2"));
        computerLabel_2->setGeometry(QRect(480, 400, 161, 41));
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
        computercurrentLabel->setGeometry(QRect(190, 430, 111, 21));
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
        computerStatusLabel->setGeometry(QRect(40, 440, 47, 13));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        computerStatusLabel->setPalette(palette8);
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(310, 130, 411, 81));
        horizontalLayout_4 = new QHBoxLayout(gridLayoutWidget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        cl_2_1 = new QLabel(gridLayoutWidget_2);
        cl_2_1->setObjectName(QString::fromUtf8("cl_2_1"));
        cl_2_1->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_4->addWidget(cl_2_1);

        cl_2_2 = new QLabel(gridLayoutWidget_2);
        cl_2_2->setObjectName(QString::fromUtf8("cl_2_2"));
        cl_2_2->setBaseSize(QSize(800, 500));
        cl_2_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_4->addWidget(cl_2_2);

        cl_2_3 = new QLabel(gridLayoutWidget_2);
        cl_2_3->setObjectName(QString::fromUtf8("cl_2_3"));
        cl_2_3->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_4->addWidget(cl_2_3);

        cl_2_4 = new QLabel(gridLayoutWidget_2);
        cl_2_4->setObjectName(QString::fromUtf8("cl_2_4"));
        cl_2_4->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_4->addWidget(cl_2_4);

        cl_2_5 = new QLabel(gridLayoutWidget_2);
        cl_2_5->setObjectName(QString::fromUtf8("cl_2_5"));
        cl_2_5->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_4->addWidget(cl_2_5);

        cl_2_6 = new QLabel(gridLayoutWidget_2);
        cl_2_6->setObjectName(QString::fromUtf8("cl_2_6"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        cl_2_6->setFont(font1);
        cl_2_6->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_4->addWidget(cl_2_6);

        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(310, 210, 411, 81));
        horizontalLayout_5 = new QHBoxLayout(gridLayoutWidget_4);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        cl_3_1 = new QLabel(gridLayoutWidget_4);
        cl_3_1->setObjectName(QString::fromUtf8("cl_3_1"));
        cl_3_1->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_5->addWidget(cl_3_1);

        cl_3_2 = new QLabel(gridLayoutWidget_4);
        cl_3_2->setObjectName(QString::fromUtf8("cl_3_2"));
        cl_3_2->setBaseSize(QSize(800, 500));
        cl_3_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_5->addWidget(cl_3_2);

        cl_3_3 = new QLabel(gridLayoutWidget_4);
        cl_3_3->setObjectName(QString::fromUtf8("cl_3_3"));
        cl_3_3->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_5->addWidget(cl_3_3);

        cl_3_4 = new QLabel(gridLayoutWidget_4);
        cl_3_4->setObjectName(QString::fromUtf8("cl_3_4"));
        cl_3_4->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_5->addWidget(cl_3_4);

        cl_3_5 = new QLabel(gridLayoutWidget_4);
        cl_3_5->setObjectName(QString::fromUtf8("cl_3_5"));
        cl_3_5->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_5->addWidget(cl_3_5);

        cl_3_6 = new QLabel(gridLayoutWidget_4);
        cl_3_6->setObjectName(QString::fromUtf8("cl_3_6"));
        cl_3_6->setFont(font1);
        cl_3_6->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_5->addWidget(cl_3_6);

        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(310, 290, 411, 147));
        horizontalLayout_6 = new QHBoxLayout(gridLayoutWidget_5);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        cl_4_1 = new QLabel(gridLayoutWidget_5);
        cl_4_1->setObjectName(QString::fromUtf8("cl_4_1"));
        cl_4_1->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_6->addWidget(cl_4_1);

        cl_4_2 = new QLabel(gridLayoutWidget_5);
        cl_4_2->setObjectName(QString::fromUtf8("cl_4_2"));
        cl_4_2->setBaseSize(QSize(800, 500));
        cl_4_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_6->addWidget(cl_4_2);

        cl_4_3 = new QLabel(gridLayoutWidget_5);
        cl_4_3->setObjectName(QString::fromUtf8("cl_4_3"));
        cl_4_3->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_6->addWidget(cl_4_3);

        cl_4_4 = new QLabel(gridLayoutWidget_5);
        cl_4_4->setObjectName(QString::fromUtf8("cl_4_4"));
        cl_4_4->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_6->addWidget(cl_4_4);

        cl_4_5 = new QLabel(gridLayoutWidget_5);
        cl_4_5->setObjectName(QString::fromUtf8("cl_4_5"));
        cl_4_5->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_6->addWidget(cl_4_5);

        cl_4_6 = new QLabel(gridLayoutWidget_5);
        cl_4_6->setObjectName(QString::fromUtf8("cl_4_6"));
        cl_4_6->setFont(font1);
        cl_4_6->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_6->addWidget(cl_4_6);

        gridLayoutWidget_6 = new QWidget(centralwidget);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(310, 50, 411, 81));
        horizontalLayout_7 = new QHBoxLayout(gridLayoutWidget_6);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        cl_1_1 = new QLabel(gridLayoutWidget_6);
        cl_1_1->setObjectName(QString::fromUtf8("cl_1_1"));
        cl_1_1->setEnabled(true);
        cl_1_1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/card_bg.png);\n"
"background-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_7->addWidget(cl_1_1);

        cl_1_2 = new QLabel(gridLayoutWidget_6);
        cl_1_2->setObjectName(QString::fromUtf8("cl_1_2"));
        cl_1_2->setBaseSize(QSize(800, 500));
        cl_1_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_7->addWidget(cl_1_2);

        cl_1_3 = new QLabel(gridLayoutWidget_6);
        cl_1_3->setObjectName(QString::fromUtf8("cl_1_3"));
        cl_1_3->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_7->addWidget(cl_1_3);

        cl_1_4 = new QLabel(gridLayoutWidget_6);
        cl_1_4->setObjectName(QString::fromUtf8("cl_1_4"));
        cl_1_4->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_7->addWidget(cl_1_4);

        cl_1_5 = new QLabel(gridLayoutWidget_6);
        cl_1_5->setObjectName(QString::fromUtf8("cl_1_5"));
        cl_1_5->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_7->addWidget(cl_1_5);

        cl_1_6 = new QLabel(gridLayoutWidget_6);
        cl_1_6->setObjectName(QString::fromUtf8("cl_1_6"));
        cl_1_6->setFont(font1);
        cl_1_6->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/card_bg.png);\n"
"border-image: url(:/images/images/card_bg.png);"));

        horizontalLayout_7->addWidget(cl_1_6);

        FINISH = new QPushButton(centralwidget);
        FINISH->setObjectName(QString::fromUtf8("FINISH"));
        FINISH->setGeometry(QRect(650, 400, 101, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(14);
        FINISH->setFont(font2);
        FINISH->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        computertotalLabel_2 = new QLabel(centralwidget);
        computertotalLabel_2->setObjectName(QString::fromUtf8("computertotalLabel_2"));
        computertotalLabel_2->setGeometry(QRect(40, 380, 101, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Impact")});
        computertotalLabel_2->setFont(font3);
        playertotalLabel_3 = new QLabel(centralwidget);
        playertotalLabel_3->setObjectName(QString::fromUtf8("playertotalLabel_3"));
        playertotalLabel_3->setGeometry(QRect(40, 410, 101, 31));
        playertotalLabel_3->setFont(font3);
        Directions = new QLabel(centralwidget);
        Directions->setObjectName(QString::fromUtf8("Directions"));
        Directions->setGeometry(QRect(40, 20, 191, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial Black")});
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setItalic(false);
        Directions->setFont(font4);
        Directions->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 127);\n"
"font: 87 16pt \"Arial Black\";"));
        Directions2 = new QLabel(centralwidget);
        Directions2->setObjectName(QString::fromUtf8("Directions2"));
        Directions2->setGeometry(QRect(10, 10, 261, 41));
        Directions2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 87 16pt \"Arial Black\";"));
        promptLabel = new QLabel(centralwidget);
        promptLabel->setObjectName(QString::fromUtf8("promptLabel"));
        promptLabel->setGeometry(QRect(180, 140, 451, 171));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(48);
        promptLabel->setFont(font5);
        regameButton = new QDialogButtonBox(centralwidget);
        regameButton->setObjectName(QString::fromUtf8("regameButton"));
        regameButton->setGeometry(QRect(280, 320, 193, 28));
        regameButton->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        PlayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 883, 26));
        menuQuit = new QMenu(menubar);
        menuQuit->setObjectName(QString::fromUtf8("menuQuit"));
        PlayWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(PlayWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PlayWindow->setStatusBar(statusBar);

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
        card6Label_10->setText(QString());
        card5Label_10->setText(QString());
        card4Label_10->setText(QString());
        card1Label_10->setText(QString());
        card3Label_10->setText(QString());
        card10Label_2->setText(QString());
        card9Label_2->setText(QString());
        card2Label_10->setText(QString());
        card8Label_2->setText(QString());
        card7Label_2->setText(QString());
        playercurrentLabel_2->setText(QCoreApplication::translate("PlayWindow", "Current Card: 0", nullptr));
        computerLabel_2->setText(QCoreApplication::translate("PlayWindow", "Computer", nullptr));
        computercurrentLabel->setText(QCoreApplication::translate("PlayWindow", "Computer:", nullptr));
        computerStatusLabel->setText(QString());
        cl_2_1->setText(QString());
        cl_2_2->setText(QString());
        cl_2_3->setText(QString());
        cl_2_4->setText(QString());
        cl_2_5->setText(QString());
        cl_2_6->setText(QCoreApplication::translate("PlayWindow", "   This row!", nullptr));
        cl_3_1->setText(QString());
        cl_3_2->setText(QString());
        cl_3_3->setText(QString());
        cl_3_4->setText(QString());
        cl_3_5->setText(QString());
        cl_3_6->setText(QCoreApplication::translate("PlayWindow", "   This row!", nullptr));
        cl_4_1->setText(QString());
        cl_4_2->setText(QString());
        cl_4_3->setText(QString());
        cl_4_4->setText(QString());
        cl_4_5->setText(QString());
        cl_4_6->setText(QCoreApplication::translate("PlayWindow", "   This row!", nullptr));
        cl_1_1->setText(QString());
        cl_1_2->setText(QString());
        cl_1_3->setText(QString());
        cl_1_4->setText(QString());
        cl_1_5->setText(QString());
        cl_1_6->setText(QCoreApplication::translate("PlayWindow", "   This row!", nullptr));
        FINISH->setText(QCoreApplication::translate("PlayWindow", "QUIT", nullptr));
        computertotalLabel_2->setText(QCoreApplication::translate("PlayWindow", "Com Score : ", nullptr));
        playertotalLabel_3->setText(QCoreApplication::translate("PlayWindow", "My Score :", nullptr));
        Directions->setText(QCoreApplication::translate("PlayWindow", "Choose a card!", nullptr));
        Directions2->setText(QCoreApplication::translate("PlayWindow", "Woops! Choose a row!", nullptr));
        promptLabel->setText(QString());
        menuQuit->setTitle(QCoreApplication::translate("PlayWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H

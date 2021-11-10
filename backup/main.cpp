#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QtCore/QCoreApplication>
#include <QString>
#include <QDebug>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}

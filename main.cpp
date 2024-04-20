#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/Qss/PChatQss.css");
    file.open(QFile::ReadOnly);
    QString qssStyle = QString::fromLatin1(file.readAll());
    MainWindow w;
    w.setStyleSheet(qssStyle);
    w.show();
    return a.exec();
}

#include <QCoreApplication>
#include <QDebug>
#include "include/homepage.h"
#include <QApplication>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Homepage w;

    w.setWindowState(w.windowState() | Qt::WindowFullScreen);

    w.show();
    return a.exec();
}
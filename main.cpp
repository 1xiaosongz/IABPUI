#include <QCoreApplication>
#include <QDebug>
#include "include/homepage.h"
#include <QApplication>
#include "readfile.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    const char* datFilePath = "D:/IABP/IABPUI/5124.dat";   // 请修改为实际路径
    // ReadFile readFile;
    // read_dat(datFilePath);
    // readAndPrintSignalData(datFilePath);


    Homepage w;

    w.setWindowState(w.windowState() | Qt::WindowFullScreen);

    w.show();
    return a.exec();
}
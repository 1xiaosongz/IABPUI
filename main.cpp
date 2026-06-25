#include <QCoreApplication>
#include <QDebug>
#include "include/homepage.h"
#include <QApplication>
#include <QFile>
#include <QFontDatabase>
QString loadQss(const QString& path)
{
    QFile file(path);

    if(file.open(QFile::ReadOnly))
    {
        return QLatin1String(file.readAll());
    }

    return "";
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    int fontId = QFontDatabase::addApplicationFont(
        ":/Typeface/SourceHanSansCN-Bold.otf");
    QString style;

    style += loadQss(":/QSS/CSS.qss");


    a.setStyleSheet(style);

    HomePage w;

    w.setWindowState(w.windowState() | Qt::WindowFullScreen);

    w.show();
    return a.exec();
}
#include "view/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Memory m;
    MainWindow w(m);
    w.show();
    return a.exec();
}

#include "maintuneladorawindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainTuneladoraWindow w;
    w.show();

    return a.exec();
}

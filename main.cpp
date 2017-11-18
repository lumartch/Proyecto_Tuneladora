#include "versionprogramadialog.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    VersionProgramaDialog w;
    w.show();

    return a.exec();
}

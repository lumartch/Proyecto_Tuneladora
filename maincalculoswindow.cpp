#include "maincalculoswindow.h"
#include "ui_maincalculoswindow.h"

MainCalculosWindow::MainCalculosWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainCalculosWindow)
{
    ui->setupUi(this);
}

MainCalculosWindow::~MainCalculosWindow()
{
    delete ui;
}

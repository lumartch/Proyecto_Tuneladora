#include "mainondaswindow.h"
#include "ui_mainondaswindow.h"

MainOndasWindow::MainOndasWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainOndasWindow)
{
    ui->setupUi(this);
}

MainOndasWindow::~MainOndasWindow()
{
    delete ui;
}

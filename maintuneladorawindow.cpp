#include "maintuneladorawindow.h"
#include "ui_maintuneladorawindow.h"

MainTuneladoraWindow::MainTuneladoraWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainTuneladoraWindow)
{
    ui->setupUi(this);
}

MainTuneladoraWindow::~MainTuneladoraWindow()
{
    delete ui;
}

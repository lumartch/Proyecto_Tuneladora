#include "maincalculoswindow.h"
#include "ui_maincalculoswindow.h"

MainCalculosWindow::MainCalculosWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainCalculosWindow){
    ui->setupUi(this);
    ui->tipoPiedraTE->hide();
}

MainCalculosWindow::~MainCalculosWindow(){
    delete ui;
}

void MainCalculosWindow::on_pushButton_clicked(){
    close();
}

void MainCalculosWindow::on_piedraBB_accepted(){
    ui->tipoPiedraTE->show();
    if(ui->ondasPLE->text() > 4500 && ui->ondasPLE->text() < 7500 && ui->ondasSLE->text() > 3500 && ui->ondasSLE->text() < 4000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se está trabajando son Rocas Inglesas");
    }else if(ui->ondasPLE->text() > 1400 && ui->ondasPLE->text() < 1800 && ui->ondasSLE->text() > 50 && ui->ondasSLE->text() < 100 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es cieno");
    }else if(ui->ondasPLE->text() > 300 && ui->ondasPLE->text() < 1400 && ui->ondasSLE->text() > 100 && ui->ondasSLE->text() < 500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es (Sedimentos no consolidados)");
    }else if(ui->ondasPLE->text() > 1800 && ui->ondasPLE->text() < 2500 && ui->ondasSLE->text() > 100 && ui->ondasSLE->text() < 500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es (Sedimentos no consolidados)");
    }else if(ui->ondasPLE->text() > 1400 && ui->ondasPLE->text() < 1800 && ui->ondasSLE->text() > 100 && ui->ondasSLE->text() < 300 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es cieno ó (Sedimentos no consolidados )");
    }else if(ui->ondasPLE->text() > 3000 && ui->ondasPLE->text() < 3500 && ui->ondasSLE->text() > 2000 && ui->ondasSLE->text() < 3000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Limos");
    }else if(ui->ondasPLE->text() > 1500 && ui->ondasPLE->text() < 5400 && ui->ondasSLE->text() > 800 && ui->ondasSLE->text() < 1500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es (Arenas compactas)");
    }else if(ui->ondasPLE->text() > 3500 && ui->ondasPLE->text() < 5400 && ui->ondasSLE->text() > 1500 && ui->ondasSLE->text() < 2000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Rocas sedimentarias ó (Arenas compactas)");
    }else if(ui->ondasPLE->text() > 5400 && ui->ondasPLE->text() < 5500 && ui->ondasSLE->text() > 1500 && ui->ondasSLE->text() < 2000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Rocas sedimentarias");
    }else if(ui->ondasPLE->text() > 4500 && ui->ondasPLE->text() < 6000 && ui->ondasSLE->text() > 3000 && ui->ondasSLE->text() < 3500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Rocas metamórficas");
    }else if(ui->ondasPLE->text() > 4500 && ui->ondasPLE->text() < 5500 && ui->ondasSLE->text() > 2500 && ui->ondasSLE->text() < 3000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Limos ó Rocas sedimentarias ó Rocas Metamórficas");
    }else if(ui->ondasPLE->text() > 3000 && ui->ondasPLE->text() < 6000 && ui->ondasSLE->text() > 2000 && ui->ondasSLE->text() < 2500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Rocas sedimentarias o Limos");
    }else if(ui->ondasPLE->text() > 5500 && ui->ondasPLE->text() < 6000 && ui->ondasSLE->text() > 2000 && ui->ondasSLE->text() < 2500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Limos");
    }else if(ui->ondasPLE->text() == "1500"  && ui->ondasSLE->text() > "0"  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es agua");
    }else if(ui->ondasPLE->text() == "5200"  && ui->ondasSLE->text() > "3000"  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es granito");
    }else if(ui->ondasPLE->text() == "6400"  && ui->ondasSLE->text() > "3200"  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es basalto");
    }else if(ui->ondasPLE->text() == "2400"  && ui->ondasSLE->text() > "1350"  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es calizas");
    }else if(ui->ondasPLE->text() == "3500"  && ui->ondasSLE->text() > "2150"  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Areniscas");
    }else if(ui->ondasPLE->text() < 250){
        ui->tipoPiedraTE->setText("No hay registro de ondas P tan bajas para ningún material");
    }else if(ui->ondasPLE->text() > 750){
        ui->tipoPiedraTE->setText("No hay registro de ondas P tan altas para ningún material");
    }else if(ui->ondasSLE->text() > 4000){
        ui->tipoPiedraTE->setText("No hay registro de ondas S tan altas para ningún material");
    }else if(ui->ondasPLE->text() < 50){
        ui->tipoPiedraTE->setText("No hay registro de ondas S tan bajas para ningún material");
    }else{
        ui->tipoPiedraTE->setText("No hay registro de ondas P u ondas S para ningún material con esos parametros");
    }
}

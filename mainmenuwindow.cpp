#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"
#include "maincalculoswindow.h"
#include "maintuneladorawindow.h"

MainMenuWindow::MainMenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuWindow){
    ui->setupUi(this);
    ui->descripcionTE->setEnabled(false);
    ui->descripcionTE->setText("Bienvenido al asistente de datos de la tuneladora.");
    ui->imagenLabel->hide();
    ui->label->hide();
    /*QMessageBox::information(
                    this,
                    tr("Administracion de datos - Tuneladora"),
                    tr("Esta interfaz de usuario le permitira.. etc etc.") );*/
}

MainMenuWindow::~MainMenuWindow(){
    delete ui;
}

void MainMenuWindow::on_eleccionCB_currentIndexChanged(int index){
    if(index == 1){
        ui->descripcionTE->setText("Esta interfaz permite al usuario la administración de los datos que arroje la tuneladora"
                                   ", dichos datos podran ser usados para calculos posteriores por el operario...");
        ui->label->show();
    }else if(index == 2){
        ui->descripcionTE->setText("Esta interfaz permitira al operario realizar operaciones referentes al tipo de suelo,"
                                   "bajo ciertas circunstancias la interfaz arrojara señales de aviso por si la tuneladora"
                                   "esta presentando un uso inadecuado o falta de mantenimiento....");
        ui->imagenLabel->show();
    }else{
        ui->descripcionTE->setText("Bienvenido al asistente de datos de la tuneladora.");
    }
}

void MainMenuWindow::on_aceptarPb_clicked(){
    if(ui->eleccionCB->currentIndex() == 1){
        //this->hide();
        if(contRegistro == 0){
            contRegistro++;
            ventanaBitacora = new MainTuneladoraWindow;
            ventanaBitacora->show();
            ui->label->hide();
            ui->imagenLabel->hide();
            ui->eleccionCB->setCurrentIndex(0);
        }
    }else if(ui->eleccionCB->currentIndex() == 2){
        //this->hide();
        if(contCalculos == 0){
            contCalculos++;
            ventanaCalculos = new MainCalculosWindow;
            ventanaCalculos->show();
            ui->label->hide();
            ui->imagenLabel->hide();
            ui->eleccionCB->setCurrentIndex(0);
        }
    }else{
        QMessageBox::information(
                        this,
                        tr("Administracion de datos - Tuneladora"),
                        tr("El administrador de datos solo puede mostrar la opcion Bitacora y calculos, intente de nuevo.") );
    }
    ui->eleccionCB->setCurrentIndex(0);
    ui->descripcionTE->setText("Bienvenido al asistente de datos de la tuneladora.");
}

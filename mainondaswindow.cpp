#include "mainondaswindow.h"
#include "ui_mainondaswindow.h"

MainOndasWindow::MainOndasWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainOndasWindow){
    ui->setupUi(this);
}

MainOndasWindow::~MainOndasWindow(){
    delete ui;
}

void MainOndasWindow::on_frentePB_clicked(){
    close();
}

void MainOndasWindow::on_frenteBB_accepted(){
    float presionInt = ui->interiorLE->text().toFloat();
    float presionSobrecarga = ui->sobrecargaLE->text().toFloat();
    float densidad = ui->densidadLE->text().toFloat();
    float cobertura = ui->coberturaLE->text().toFloat();
    float diametro = ui->diametroLE->text().toFloat();
    float resistencia = ui->resistenciaLE->text().toFloat();

    float estabilidad = (presionSobrecarga - presionInt + (densidad *(cobertura + (diametro/2))))/resistencia;
    ui->estabilidadTE->show();
    if(resistencia < 1){
        ui->estabilidadTE->setText("Por los margenes obtenidos el trabajo en estas medidas es DESPRECIABLE");
    }else if(estabilidad > 1 and estabilidad < 2){
        ui->estabilidadTE->setText("Con los margenes ingresados denotamos que la deformación es ELÁSTICA");
    }else if(estabilidad > 2 and estabilidad < 4){
        ui->estabilidadTE->setText("Con los margenes ingresados denotamos que la deformación es ELASTO-PLÁSTICA");
    }else if(estabilidad > 4 and estabilidad < 6){
        ui->estabilidadTE->setText("Con los margenes ingresados denotamos que deformación es PLÁTICA");
    }else{
        ui->estabilidadTE->setText("El tunel está en peligro de COLAPSO");
    }
    cleanFrente();
}
void MainOndasWindow::cleanFrente(){
    ui->interiorLE->setText("");
    ui->sobrecargaLE->setText("");
    ui->densidadLE->setText("");
    ui->coberturaLE->setText("");
    ui->diametroLE->setText("");
    ui->resistenciaLE->setText("");
}
void MainOndasWindow::on_frenteBB_rejected(){
    cleanFrente();
    ui->estabilidadTE->setText("");
    ui->estabilidadTE->hide();
}

#include "maintuneladorawindow.h"
#include "ui_maintuneladorawindow.h"

MainTuneladoraWindow::MainTuneladoraWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainTuneladoraWindow){
    ui->setupUi(this);
    enableButtonBitacora();
    QRegExp rx("[0-9]*");
    QValidator*validador = new QRegExpValidator(rx);
    ui->PVMLE->setValidator(validador);
    ui->PVSCLE->setValidator(validador);
    ui->PVSSLE->setValidator(validador);
}

MainTuneladoraWindow::~MainTuneladoraWindow(){
    delete ui;
}

void MainTuneladoraWindow::on_botonRegresaPB_clicked(){
    delete ui;
}
void MainTuneladoraWindow::cleanBitacora(){
    ui->resolucionTE->setText("Parametros aceptados.");
    ui->PVMLE->setEnabled(true);
    ui->PVMLE->setText("");
    ui->PVSCLE->setEnabled(true);
    ui->PVSCLE->setText("");
    ui->PVSSLE->setText("");
    ui->bitacoraCB->setCurrentIndex(0);
}
void MainTuneladoraWindow::enableButtonBitacora(){
    if(ui->PVSSLE->text().size() > 0 && ui->PVSCLE->text().size() > 0 && ui->PVMLE->text().size() > 0 && ui->bitacoraCB->currentIndex() != 0){
        ui->bitacoraBB->button(QDialogButtonBox::Ok)->setEnabled(true);
    }else{
        ui->bitacoraBB->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}
void MainTuneladoraWindow::on_PVSSLE_textChanged(const QString &arg1){
    Q_UNUSED (arg1);
    enableButtonBitacora();
}

void MainTuneladoraWindow::on_PVSCLE_textChanged(const QString &arg1){
    Q_UNUSED (arg1);
    enableButtonBitacora();
}

void MainTuneladoraWindow::on_PVMLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    enableButtonBitacora();
}

void MainTuneladoraWindow::on_bitacoraCB_currentIndexChanged(int index){
    switch(index){
    case 1:
        ui->PVSCLE->setText("1600");
        ui->PVSCLE->setEnabled(false);
        ui->PVMLE->setText("1500");
        ui->PVMLE->setEnabled(false);
        ui->resolucionTE->setEnabled(false);
        break;
    case 2:
        ui->PVSCLE->setText("1120 - 1200");
        ui->PVSCLE->setEnabled(false);
        ui->PVMLE->setText("1350");
        ui->PVMLE->setEnabled(false);
        ui->resolucionTE->setEnabled(false);
        break;
    case 3:
        ui->PVSCLE->setText("1110");
        ui->PVSCLE->setEnabled(false);
        ui->PVMLE->setText("1350- 1400");
        ui->PVMLE->setEnabled(false);
        ui->resolucionTE->setEnabled(false);
        break;
    case 4:
        ui->PVSCLE->setText("1150 - 1200");
        ui->PVSCLE->setEnabled(false);
        ui->PVMLE->setText("1400");
        ui->PVMLE->setEnabled(false);
        ui->resolucionTE->setEnabled(false);
        break;
    case 5:
        ui->PVSCLE->setText("750 - 900");
        ui->PVSCLE->setEnabled(false);
        ui->PVMLE->setText("1000 - 1180");
        ui->PVMLE->setEnabled(false);
        ui->resolucionTE->setEnabled(false);
        break;
    case 6:
        ui->PVSCLE->setText("800 - 1000");
        ui->PVSCLE->setEnabled(false);
        ui->PVMLE->setText("1150 - 1280");
        ui->PVMLE->setEnabled(false);
        ui->resolucionTE->setEnabled(false);
        break;
    case 7:
        ui->PVSCLE->setText("750 - 1000");
        ui->PVSCLE->setEnabled(false);
        ui->PVMLE->setText("1100 - 1250");
        ui->PVMLE->setEnabled(false);
        ui->resolucionTE->setEnabled(false);
        break;
    case 8:
        ui->PVSCLE->setText("1050 - 1100");
        ui->PVSCLE->setEnabled(false);
        ui->PVMLE->setText("1500 - 1600");
        ui->PVMLE->setEnabled(false);
        ui->resolucionTE->setEnabled(false);
        break;
    default:
        ;
    }
    enableButtonBitacora();
}

void MainTuneladoraWindow::on_bitacoraBB_accepted(){
    int auxOpc = ui->bitacoraCB->currentIndex();
    switch(auxOpc){
    case 1:
        if(ui->PVSSLE->text().toDouble() < 1400){
            ui->resolucionTE->setText("El peso para la arena de rio es muy bajo, intente de nuevo.");
        }else if(ui->PVSSLE->text().toDouble() > 1500){
            ui->resolucionTE->setText("El peso de la arena del rio es muy pesada, intente de nuevo.");
        }else{
            cleanBitacora();
        }
        break;
    case 2:
        if(ui->PVSSLE->text().toDouble() < 1000){
            ui->resolucionTE->setText("El peso para la arena amarilla es muy bajo, intente de nuevo.");
        }else if(ui->PVSSLE->text().toDouble() > 1350){
            ui->resolucionTE->setText("El peso de la arena amarilla es muy pesada, intente de nuevo.");
        }else{
            cleanBitacora();
        }
        break;
    case 3:
        if(ui->PVSSLE->text().toDouble() < 990){
            ui->resolucionTE->setText("El peso para la arena tepetate color rosa es muy bajo, intente de nuevo.");
        }else if(ui->PVSSLE->text().toDouble() > 1400){
            ui->resolucionTE->setText("El peso de la arena tepetate color rosa es muy pesada, intente de nuevo.");
        }else{
            cleanBitacora();
        }
        break;
    case 4:
        if(ui->PVSSLE->text().toDouble() < 1050){
            ui->resolucionTE->setText("El peso para la arena tepetate color blanco es muy bajo, intente de nuevo.");
        }else if(ui->PVSSLE->text().toDouble() > 1400){
            ui->resolucionTE->setText("El peso de la arena tepetate color blanco es muy pesada, intente de nuevo.");
        }else{
            cleanBitacora();
        }
        break;
    case 5:
        if(ui->PVSSLE->text().toDouble() < 600){
            ui->resolucionTE->setText("El peso para la arena jal grueso es muy bajo, intente de nuevo.");
        }else if(ui->PVSSLE->text().toDouble() > 1180){
            ui->resolucionTE->setText("El peso de la arena jal grueso es muy pesada, intente de nuevo.");
        }else{
            cleanBitacora();
        }
        break;
    case 6:
        if(ui->PVSSLE->text().toDouble() < 650){
            ui->resolucionTE->setText("El peso para la arena jal mediano es muy bajo, intente de nuevo.");
        }else if(ui->PVSSLE->text().toDouble() > 1280){
            ui->resolucionTE->setText("El peso de la arena jal mediano es muy pesada, intente de nuevo.");
        }else{
            cleanBitacora();
        }
        break;
    case 7:
        if(ui->PVSSLE->text().toDouble() < 600){
            ui->resolucionTE->setText("El peso para la arena jal fino es muy bajo, intente de nuevo.");
        }else if(ui->PVSSLE->text().toDouble() > 1250){
            ui->resolucionTE->setText("El peso de la arena jal fino es muy pesada, intente de nuevo.");
        }else{
            cleanBitacora();
        }
        break;
    case 8:
        if(ui->PVSSLE->text().toDouble() < 920){
            ui->resolucionTE->setText("El peso para la arcilla negra es muy bajo, intente de nuevo.");
        }else if(ui->PVSSLE->text().toDouble() > 1600){
            ui->resolucionTE->setText("El peso de la arcilla negra es muy pesada, intente de nuevo.");
        }else{
            cleanBitacora();
        }
        break;
    default:
        ;
    }
}

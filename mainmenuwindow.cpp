#include "mainmenuwindow.h"
#include "ui_mainmenuwindow.h"

MainMenuWindow::MainMenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenuWindow){
    ui->setupUi(this);
    //Inicializacion de parametros de la interfaz e icono
    this->setFixedSize(this->size());
    setWindowIcon(QIcon("icon.png"));
    ui->descripcionTE->setEnabled(false);
    ui->descripcionTE->setText("Bienvenido al asistente de datos de la tuneladora.");
    ui->imagenLabel->setPixmap(QPixmap("icon.png"));
    ui->imagenLabel->setScaledContents(false);
}

MainMenuWindow::~MainMenuWindow(){
    delete ui;
}

void MainMenuWindow::on_eleccionCB_currentIndexChanged(int index){
    if(index == 1){
        ui->descripcionTE->setText("Esta interfaz permite al usuario la administración de los datos que arroje la tuneladora"
                                   ", dichos datos podran ser usados para calculos posteriores por el operario...");
        ui->imagenLabel->setPixmap(QPixmap("bitacora.png"));
        ui->imagenLabel->setScaledContents(true);

    }else if(index == 2){
        ui->descripcionTE->setText("Esta interfaz permitira al operario realizar operaciones referentes al tipo de suelo,"
                                   "bajo ciertas circunstancias la interfaz arrojara señales de aviso por si la tuneladora"
                                   "esta presentando un uso inadecuado o falta de mantenimiento....");
        ui->imagenLabel->setPixmap(QPixmap("calculos.png"));
        ui->imagenLabel->setScaledContents(true);

    }else if(index == 3){
        ui->descripcionTE->setText("Esta interfaz permitira al usuario calcular la resistencia del frente,"
                                   "bajo a ciertos parametros y arrojara advertencias"
                                   "en caso de daños a las aspas o un posible derrumbe.");
        ui->imagenLabel->setPixmap(QPixmap("mantenimientoFrente.png"));
        ui->imagenLabel->setScaledContents(true);
    }else{
        ui->descripcionTE->setText("Bienvenido al asistente de datos de la tuneladora.");
        ui->imagenLabel->setPixmap(QPixmap("icon.png"));
        ui->imagenLabel->setScaledContents(false);
    }
}

void MainMenuWindow::on_aceptarPb_clicked(){
    //Muestra el menu, ya sea para bitacora o para calculos
    if(ui->eleccionCB->currentIndex() == 1){
        ventanaBitacora = new MainTuneladoraWindow;
        ventanaBitacora->show();
        ui->eleccionCB->setCurrentIndex(0);
    }else if(ui->eleccionCB->currentIndex() == 2){
        ventanaCalculos = new MainCalculosWindow;
        ventanaCalculos->show();
        ui->eleccionCB->setCurrentIndex(0);
    }else if(ui->eleccionCB->currentIndex() == 3){
        ventanaFrente = new MainOndasWindow;
        ventanaFrente->show();
        ui->eleccionCB->setCurrentIndex(0);
    }else{
        QMessageBox::information(
                        this,
                        tr("Administracion de datos - Tuneladora"),
                        tr("El administrador de datos solo puede mostrar la opcion Bitacora, Calculos y Resistencia del frente, intente de nuevo.") );
    }
    ui->eleccionCB->setCurrentIndex(0);
    ui->descripcionTE->setText("Bienvenido al asistente de datos de la tuneladora.");
}

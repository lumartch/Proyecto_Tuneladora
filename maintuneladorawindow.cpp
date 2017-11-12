#include "maintuneladorawindow.h"
#include "ui_maintuneladorawindow.h"

MainTuneladoraWindow::MainTuneladoraWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainTuneladoraWindow){
    ui->setupUi(this);
    enableButtonBitacora();
}

MainTuneladoraWindow::~MainTuneladoraWindow(){
    delete ui;
}

void MainTuneladoraWindow::on_botonRegresaPB_clicked(){
    close();
}

void MainTuneladoraWindow::cleanBitacora(){
    ui->bitacoraCB->setCurrentIndex(0);
    ui->PVSSDSP->setMinimum(0);
    ui->PVSCDSP->setMinimum(0);
    ui->PVMDSP->setMinimum(0);
    camposEnable();
}

void MainTuneladoraWindow::camposEnable()
{
    ui->PVSSDSP->setEnabled(true);
    ui->PVSCDSP->setEnabled(true);
    ui->PVMDSP->setEnabled(true);
}

void MainTuneladoraWindow::guardarBitacora(const QString &suelo)
{
    //Da el nombre al archivo
    QDate fechaLocal = QDate::currentDate();
    QString archivo = suelo + "_" + QString::number(fechaLocal.day()) + "_" +
                        QString::number(fechaLocal.month()) + "_" + QString::number(fechaLocal.year()) + ".txt";

    //Busca los archivos existentes
    bool bandera = false;
    QString myTexto;
    QString auxiliar;
    QFile bitacoraLectura("Bitacora.txt");
    if(!bitacoraLectura.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No hay archivo para lectura Bitacora.txt...";
        bitacoraLectura.close();
    }
    QTextStream lecturaArchivo(&bitacoraLectura);
    while(!lecturaArchivo.atEnd()) {
        auxiliar = lecturaArchivo.readLine();
        myTexto += auxiliar + "\n";
        if(auxiliar == archivo){
            //qDebug() << auxiliar << " - " << archivo;
            bandera = true;
        }
    }
    bitacoraLectura.close();
    if(bandera == false){
        //Bitacora general guardado
        QFile bitacoraGeneral("Bitacora.txt");
        if (!bitacoraGeneral.open(QIODevice::WriteOnly | QIODevice::Text)){
            bitacoraGeneral.close();
            return;
        }
        QTextStream out(&bitacoraGeneral);
        out << archivo + "\n";
        out << myTexto;
        bitacoraGeneral.close();
    }


    //Tipos de suelos
    //Lectura de las bitacoras por dia de los suelos
    QFile bitacoraSueloLectura(archivo);
    QString auxStr;
    if(!bitacoraSueloLectura.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No hay archivo para lectura " << archivo << "...";
        bitacoraSueloLectura.close();
    }
    else{
        QTextStream lecturaSuelo(&bitacoraSueloLectura);
        while(!lecturaSuelo.atEnd()) {
            auxStr += lecturaSuelo.readLine() + "\n";
        }
        bitacoraSueloLectura.close();
    }

    //Bitacora por tipo de suelo guardado
    QTime horaLocal = QTime::currentTime();
    QFile bitacoraSuelo(archivo);
    if(!bitacoraSuelo.open(QIODevice::WriteOnly | QIODevice::Text)){
        bitacoraSuelo.close();
        return;
    }
    else{
        QTextStream salida(&bitacoraSuelo);
        QString horaStr = '[' + QString::number(horaLocal.hour()) + ':' + QString::number(horaLocal.minute()) + ']';
        salida << auxStr;
        salida << horaStr + "\n";
        salida << ui->PVSSDSP->text() << "\n";
        salida << ui->PVSCDSP->text() << "\n";
        salida << ui->PVMDSP->text() << "\n";
        bitacoraSuelo.close();
    }
}

void MainTuneladoraWindow::on_bitacoraCB_currentIndexChanged(int index){
    //Implementa maximos, minimos y constantes dentro de los campos para manejar los datos
    enableButtonBitacora();
    camposEnable();
    switch (index) {
    case 0:
        cleanBitacora();
        break;
    //Arena de rio
    case 1:
        ui->PVSSDSP->setMaximum(1500);
        ui->PVSSDSP->setMinimum(1400);

        ui->PVSCDSP->setMinimum(1600);
        ui->PVSCDSP->setDisabled(true);

        ui->PVMDSP->setMinimum(1500);
        ui->PVMDSP->setDisabled(true);
        break;
    //Arena amarilla
    case 2:
        ui->PVSSDSP->setMaximum(1000);
        ui->PVSSDSP->setMinimum(1100);

        ui->PVSCDSP->setMaximum(1200);
        ui->PVSCDSP->setMinimum(1120);

        ui->PVMDSP->setMinimum(1350);
        ui->PVMDSP->setDisabled(true);
        break;
    //Arena rosa
    case 3:
        ui->PVSSDSP->setMinimum(990);
        ui->PVSSDSP->setDisabled(true);

        ui->PVSCDSP->setMinimum(1100);
        ui->PVSCDSP->setDisabled(true);

        ui->PVMDSP->setMaximum(1350);
        ui->PVMDSP->setMinimum(1400);
        break;
    //Arena blanca
    case 4:
        ui->PVSSDSP->setMaximum(1050);
        ui->PVSSDSP->setMinimum(1100);

        ui->PVSCDSP->setMaximum(1200);
        ui->PVSCDSP->setMinimum(1150);

        ui->PVMDSP->setMinimum(1400);
        ui->PVMDSP->setDisabled(true);
        break;
    //Jal grueso
    case 5:
        ui->PVSSDSP->setMaximum(700);
        ui->PVSSDSP->setMinimum(600);

        ui->PVSCDSP->setMaximum(900);
        ui->PVSCDSP->setMinimum(780);

        ui->PVMDSP->setMaximum(1180);
        ui->PVMDSP->setMinimum(1000);
        break;
    //Jal mediano
    case 6:
        ui->PVSSDSP->setMaximum(750);
        ui->PVSSDSP->setMinimum(650);

        ui->PVSCDSP->setMaximum(1000);
        ui->PVSCDSP->setMinimum(300);

        ui->PVMDSP->setMaximum(1280);
        ui->PVMDSP->setMinimum(1150);
        break;
    //Jal fino
    case 7:
        ui->PVSSDSP->setMaximum(650);
        ui->PVSSDSP->setMinimum(600);

        ui->PVSCDSP->setMaximum(1000);
        ui->PVSCDSP->setMinimum(750);

        ui->PVMDSP->setMaximum(1250);
        ui->PVMDSP->setMinimum(1100);
        break;
    //Arcilla amarilla
    case 8:
        ui->PVSSDSP->setMaximum(1000);
        ui->PVSSDSP->setMinimum(920);

        ui->PVSCDSP->setMaximum(1100);
        ui->PVSCDSP->setMinimum(1050);

        ui->PVMDSP->setMaximum(1600);
        ui->PVMDSP->setMinimum(1500);
        break;
    default:
        break;
    }
}

void MainTuneladoraWindow::on_bitacoraBB_accepted(){
    //Lanza el nombre para el archivo que guarde los datos de tuneladora
    int auxOpc = ui->bitacoraCB->currentIndex();
    switch(auxOpc){
    case 1:
        guardarBitacora("Arena-Rio");
        break;
    case 2:
        guardarBitacora("Arena-Amarilla");
        break;
    case 3:
        guardarBitacora("Tepetate-Rosa");
        break;
    case 4:
        guardarBitacora("Tepetate-Blanco");
        break;
    case 5:
        guardarBitacora("Jal-Grueso");
        break;
    case 6:
        guardarBitacora("Jal-Mediano");
        break;
    case 7:
        guardarBitacora("Jal-Fino");
        break;
    case 8:
        guardarBitacora("Arcilla-Negra");
        break;
    }
    cleanBitacora();
}

void MainTuneladoraWindow::on_bitacoraBB_rejected(){
    cleanBitacora();
}

void MainTuneladoraWindow::enableButtonBitacora()
{
    if(ui->bitacoraCB->currentIndex() > 0){
        ui->bitacoraBB->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    else
    {
        ui->bitacoraBB->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

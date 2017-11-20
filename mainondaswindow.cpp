#include "mainondaswindow.h"
#include "ui_mainondaswindow.h"

MainOndasWindow::MainOndasWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainOndasWindow){
    ui->setupUi(this);
    //Inicializacion de parametros de la interfaz e icono
    this->setFixedSize(this->size());
    setWindowIcon(QIcon("icon.png"));
    habilitarFrente();
    //Expresion regular para flotantes
    QRegExp flotante("[+-]?([0-9]*[.])?[0-9]+");
    QValidator *validador = new QRegExpValidator(flotante);
    ui->interiorLE->setValidator(validador);
    ui->sobrecargaLE->setValidator(validador);
    ui->densidadLE->setValidator(validador);
    ui->coberturaLE->setValidator(validador);
    ui->diametroLE->setValidator(validador);
    ui->resistenciaLE->setValidator(validador);
    //Holders de texto
    ui->sobrecargaLE->setPlaceholderText("kPa");
    ui->interiorLE->setPlaceholderText("kPa");
    ui->densidadLE->setPlaceholderText("KN/m3");
    ui->coberturaLE->setPlaceholderText("m");
    ui->diametroLE->setPlaceholderText("m");
    ui->resistenciaLE->setPlaceholderText("kPa");
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
    QString alerta;
    if(resistencia < 1){
        QMessageBox::information(
                        this,
                        tr("Mantenimiento del frente - Tuneladora"),
                        tr("Por los margenes obtenidos el trabajo en estas medidas es DESPRECIABLE.") );
        alerta = "DESPRECIABLE";
    }else if(estabilidad > 1 and estabilidad < 2){
        QMessageBox::information(
                        this,
                        tr("Mantenimiento del frente - Tuneladora"),
                        tr("Con los margenes ingresados denotamos que la deformación es ELÁSTICA.") );
        alerta = "ELÁSTICA";
    }else if(estabilidad > 2 and estabilidad < 4){
        QMessageBox::information(
                        this,
                        tr("Mantenimiento del frente - Tuneladora"),
                        tr("Con los margenes ingresados denotamos que la deformación es ELASTO-PLÁSTICA.") );
        alerta = "ELASTO-PLÁSTICA";
    }else if(estabilidad > 4 and estabilidad < 6){
        QMessageBox::information(
                        this,
                        tr("Mantenimiento del frente - Tuneladora"),
                        tr("Con los margenes ingresados denotamos que deformación es PLÁTICA.") );
        alerta = "PLÁSTICA";
    }else{
        QMessageBox::information(
                        this,
                        tr("Mantenimiento del frente - Tuneladora"),
                        tr("El tunel está en peligro de COLAPSO.") );
        alerta = "COLAPSO";
    }
    guardarDatosFrente(alerta);
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
}

void MainOndasWindow::habilitarFrente(){
    if(ui->densidadLE->text() > 0 && ui->coberturaLE->text() > 0 && ui->diametroLE->text() > 0 && ui->interiorLE->text() > 0 && ui->sobrecargaLE->text() > 0 && ui->resistenciaLE->text() > 0 ){
        ui->frenteBB->button(QDialogButtonBox::Ok)->setEnabled(true);
    }else{
        ui->frenteBB->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

void MainOndasWindow::guardarDatosFrente(const QString &alerta)
{
    //Bitacora del Frente
    float presionInt = ui->interiorLE->text().toFloat();
    float presionSobrecarga = ui->sobrecargaLE->text().toFloat();
    float densidad = ui->densidadLE->text().toFloat();
    float cobertura = ui->coberturaLE->text().toFloat();
    float diametro = ui->diametroLE->text().toFloat();
    float resistencia = ui->resistenciaLE->text().toFloat();
    float estabilidad = (presionSobrecarga - presionInt + (densidad *(cobertura + (diametro/2))))/resistencia;

    //Lectura de las bitacoras del frente
    QFile bitacoraFrente("FrenteBitacora.txt");
    QString auxStr;
    if(!bitacoraFrente.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No hay archivo para lectura FrenteBitacora.txt...";
        bitacoraFrente.close();
    }else{
        QTextStream lecturaFrente(&bitacoraFrente);
        while(!lecturaFrente.atEnd()) {
            auxStr += lecturaFrente.readLine() + "\n";
        }
        bitacoraFrente.close();
    }

    //Bitacora Frente guardado
    QTime horaLocal = QTime::currentTime();
    QDate tiempoLocal = QDate::currentDate();
    QFile bitFrenteActualizada("FrenteBitacora.txt");
    if(!bitFrenteActualizada.open(QIODevice::WriteOnly | QIODevice::Text)){
        bitFrenteActualizada.close();
        return;
    }else{
        QTextStream salida(&bitFrenteActualizada);
        QString fechaStr = QString::number(tiempoLocal.day()) + "/"
                + QString::number(tiempoLocal.month()) + "/" + QString::number(tiempoLocal.year());
        QString horaStr = '[' + QString::number(horaLocal.hour()) + ':'
                + QString::number(horaLocal.minute()) + ']';
        salida << auxStr;
        salida << fechaStr + "\n";
        salida << horaStr + "\n";
        salida << ui->interiorLE->text() << "\n";
        salida << ui->sobrecargaLE->text() << "\n";
        salida << ui->densidadLE->text() << "\n";
        salida << ui->coberturaLE->text() << "\n";
        salida << ui->diametroLE->text() << "\n";
        salida << ui->resistenciaLE->text() << "\n";
        salida << QString::number(estabilidad) << "\n";
        salida << alerta << "\n";
        bitFrenteActualizada.close();
    }
}

void MainOndasWindow::on_sobrecargaLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarFrente();
}

void MainOndasWindow::on_interiorLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarFrente();
}

void MainOndasWindow::on_densidadLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarFrente();
}

void MainOndasWindow::on_coberturaLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarFrente();
}

void MainOndasWindow::on_diametroLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarFrente();
}

void MainOndasWindow::on_resistenciaLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarFrente();
}

void MainOndasWindow::on_historialPB_clicked()
{
    TablaFrenteDialog *historial = new TablaFrenteDialog;
    historial->show();
}

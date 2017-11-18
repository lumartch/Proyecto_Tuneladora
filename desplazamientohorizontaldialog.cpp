#include "desplazamientohorizontaldialog.h"
#include "ui_desplazamientohorizontaldialog.h"

DesplazamientoHorizontalDialog::DesplazamientoHorizontalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DesplazamientoHorizontalDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    setWindowIcon(QIcon("icon.png"));
    ui->informacionLabel->setText("Sh(y): Desplazamiento\n"
                                  "horizontal en el punto y(mm).\n\n"
                                  "y: Distancia horizontal\n"
                                  "desde el eje del túnel (m).\n\n"
                                  "H: profundidad hasta el\n"
                                  "eje del túnel (m).\n\n"
                                  "Sv: Asiento vertical en\n"
                                  "el punto y(mm).");
    cargarDatos();
}

DesplazamientoHorizontalDialog::~DesplazamientoHorizontalDialog()
{
    delete ui;
}

void DesplazamientoHorizontalDialog::cargarDatos()
{
    //Lee los datos que contiene la bitacora de desplazamiento
    QFile bitacoraLectura("DesplazamientoHorizontalBitacora.txt");
    if(!bitacoraLectura.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->historialTW->setRowCount(0);
        QMessageBox::information(
                        this,
                        tr("Cálculos - Tuneladora"),
                        tr("No hay archivo para lectura DesplazamientoHorizontalBitacora.txt...") );
        bitacoraLectura.close();
        return;
    }
    QList <QString> listaDeElementos;
    QTextStream lecturaArchivo(&bitacoraLectura);
    while(!lecturaArchivo.atEnd()) {
        listaDeElementos.append(lecturaArchivo.readLine());
    }
    bitacoraLectura.close();

    ui->historialTW->setRowCount(listaDeElementos.count()/6);
    for(int i = 0, x = 0, y = 0; i < listaDeElementos.count(); i++){
        QTableWidgetItem *auxItem = new QTableWidgetItem(listaDeElementos.at(i));
        ui->historialTW->setItem(x, y, auxItem);
        y++;
        if(y == 6){
            y = 0;
            x++;
        }
    }
}

void DesplazamientoHorizontalDialog::on_exportarPB_clicked()
{
    if(ui->historialTW->rowCount() == 0){
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("No hay datos por exportar.") );
        return;
    }
    QFile bitacoraLectura("DesplazamientoHorizontalBitacora.txt");
    if(!bitacoraLectura.open(QIODevice::ReadOnly | QIODevice::Text)) {
        bitacoraLectura.close();
        return;
    }
    QList <QString> listaDeElementos;
    QTextStream lecturaArchivo(&bitacoraLectura);
    while(!lecturaArchivo.atEnd()) {
        listaDeElementos.append(lecturaArchivo.readLine());
    }
    bitacoraLectura.close();
    QString nombreArchivo = QFileDialog::getSaveFileName(this, tr("Guardar archivo"), "", tr(".txt"));
    if (nombreArchivo.isEmpty()){
        return;
    }
    else {
        QFile file(nombreArchivo + ".txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::information(this, tr("No se pudo abrir el archivo."),
                file.errorString());
            return;
        }
        QTextStream out(&file);
        for(int i = 0; i < listaDeElementos.length(); i++){
            out << listaDeElementos.at(i) << "\n";
        }
        file.close();
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("Archivo exportado exitosamente.") );
    }
}

void DesplazamientoHorizontalDialog::on_regresarPB_clicked()
{
    this->close();
}

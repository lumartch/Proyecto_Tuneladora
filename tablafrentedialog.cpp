#include "tablafrentedialog.h"
#include "ui_tablafrentedialog.h"

TablaFrenteDialog::TablaFrenteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TablaFrenteDialog)
{
    ui->setupUi(this);
    //Inicializacion de parametros de la interfaz e icono
    this->setFixedSize(this->size());
    setWindowIcon(QIcon("icon.png"));
    ui->informacionLabel->setText("*Presión de sobrecarga en superficie (PSS).\n"
                                  "*Presión interior del túnel (PIT).\n"
                                  "*Densidad aparente del terreno (DAT).\n"
                                  "*Cobertura hasta clave del túnel (CCT).\n"
                                  "*Diámetro del túnel (DT).\n"
                                  "*Resistencia al corte sin drenaje (RCD).");
    cargarFrente();
}

TablaFrenteDialog::~TablaFrenteDialog()
{
    delete ui;
}

void TablaFrenteDialog::on_regresarPB_clicked()
{
    close();
}

void TablaFrenteDialog::cargarFrente()
{
    //Lee los datos que contiene la bitacora de rendimiento
    QFile bitacoraLectura("FrenteBitacora.txt");
    if(!bitacoraLectura.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->historialTW->setRowCount(0);
        QMessageBox::information(
                        this,
                        tr("Mantenimiento del frente - Tuneladora"),
                        tr("No hay archivo para lectura FrenteBitacora.txt...") );
        bitacoraLectura.close();
        return;
    }
    QList <QString> listaDeElementos;
    QTextStream lecturaArchivo(&bitacoraLectura);
    while(!lecturaArchivo.atEnd()) {
        listaDeElementos.append(lecturaArchivo.readLine());
    }
    bitacoraLectura.close();

    ui->historialTW->setRowCount(listaDeElementos.count()/10);
    for(int i = 0, x = 0, y = 0; i < listaDeElementos.count(); i++){
        QTableWidgetItem *auxItem = new QTableWidgetItem(listaDeElementos.at(i));
        ui->historialTW->setItem(x, y, auxItem);
        y++;
        if(y == 10){
            y = 0;
            x++;
        }
    }
}

void TablaFrenteDialog::on_exportarPB_clicked()
{
    if(ui->historialTW->rowCount() == 0){
        QMessageBox::information(
                            this,
                            tr("Mantenimiento del frente - Tuneladora"),
                            tr("No hay datos por exportar.") );
        return;
    }
    QFile bitacoraLectura("FrenteBitacora.txt");
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
                            tr("Mantenimiento del frente - Tuneladora"),
                            tr("Archivo exportado exitosamente.") );
    }
}

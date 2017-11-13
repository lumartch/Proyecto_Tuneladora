#include "maincalculoswindow.h"
#include "ui_maincalculoswindow.h"

MainCalculosWindow::MainCalculosWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainCalculosWindow){
    ui->setupUi(this);
    ui->tipoPiedraTE->hide();
    //Inicializador de los disables de PushButton
    habilitarAsientoVerticalPB();
    habilitarVolumenCubeta();
    habilitarDesplazamientoHorizontal();
    //Integración de validadores, para solo recibir numeros
    QRegExp rx("^[-+]?[0-9]*\.?[0-9]+$ or ^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$");
    QValidator *validadorNumeros = new QRegExpValidator(rx);
    ui->horasRealesLE->setValidator(validadorNumeros);
    ui->horasEfectivasLE->setValidator(validadorNumeros);
    ui->asientoVerticalMaxLE->setValidator(validadorNumeros);
    ui->distanciaHorizontalLE->setValidator(validadorNumeros);
    ui->puntoInflexionLE->setValidator(validadorNumeros);
    ui->profundidadLE->setValidator(validadorNumeros);
    ui->distanciaHorLE->setValidator(validadorNumeros);
    ui->asientoVerDesLE->setValidator(validadorNumeros);
    ui->ondasSLE->setValidator(validadorNumeros);
    ui->ondasPLE->setValidator(validadorNumeros);
    //Constructor del calculo del rendimiento
    ui->horasRealesLE->setPlaceholderText("m/hr");
    ui->horasEfectivasLE->setPlaceholderText("m/hr");
    ui->CULineEdit->setDisabled(true);
    //Constructor de las ondas P
    ui->ondasSLE->setPlaceholderText("m/s");
    ui->ondasPLE->setPlaceholderText("m/s");
    //Constructor del calculo del asiento vertical
    ui->informacionLabel->setText("Smáx:Asiento vertical\n"
                                  "máximo en el eje (mm).\n\n"
                                  "y: Distancia horizontal\n"
                                  "desde el eje del túnel (m).\n\n"
                                  "i: Distancia al punto\n"
                                  "de inflexión desde el\n"
                                  "eje del túnel (m).");
    ui->asientoVerticalMaxLE->setPlaceholderText("mm");
    ui->distanciaHorizontalLE->setPlaceholderText("m");
    ui->puntoInflexionLE->setPlaceholderText("m");
    ui->asientoVerticalResLE->setDisabled(true);
    //Constructor del calculo del volumen del asiento
    ui->informacionVolLabel->setText("Smáx:Asiento vertical\n"
                                     "máximo en el eje (mm).\n\n"
                                     "i: Distancia al punto\n"
                                       "de inflexión desde el\n"
                                       "eje del túnel (m).\n\n"
                                     "Sv: Asiento vertical\n(mm).");
    ui->asientoVerticalLE->setPlaceholderText("mm");
    ui->puntoInflexionLE_2->setPlaceholderText("m");
    ui->asientoVerticalResLE_2->setDisabled(true);
    //Constructor del calculo del desplazamiento horizontal
    ui->informacionDesLabel->setText("Sh(y): Desplazamiento\n"
                                     "horizontal en el punto y(mm).\n\n"
                                     "y: Distancia horizontal\n"
                                     "desde el eje del túnel (m).\n\n"
                                     "H: profundidad hasta el\n"
                                     "eje del túnel (m).\n\n"
                                     "Sv: Asiento vertical en\n"
                                     "el punto y(mm)");
    ui->distanciaHorLE->setPlaceholderText("m");
    ui->profundidadLE->setPlaceholderText("m");
    ui->asientoVerDesLE->setPlaceholderText("mm");
    ui->desplazamientoResLE->setDisabled(true);
}

MainCalculosWindow::~MainCalculosWindow(){
    delete ui;
}

void MainCalculosWindow::on_pushButton_clicked(){
    close();
}

void MainCalculosWindow::on_piedraBB_accepted(){
    //Revisar, no sirve NINGUN IF, sugerencia .toInt() o .toFloat()
    int ondasP = ui->ondasPLE->text().toInt();
    int ondasS = ui->ondasSLE->text().toInt();
    ui->tipoPiedraTE->show();
    if(ondasP > 4500 and ondasP < 7500 and ondasS > 3500 and ondasS < 4000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se está trabajando son Rocas Inglesas");
    }else if(ondasP > 1400 && ondasP < 1800 && ondasS > 50 &&ondasS < 100 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es cieno");
    }else if(ondasP > 300 && ondasP < 1400 && ondasS > 100 && ondasS < 500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es (Sedimentos no consolidados)");
    }else if(ondasP > 1800 && ondasP < 2500 && ondasS > 100 && ondasS < 500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es (Sedimentos no consolidados)");
    }else if(ondasP > 1400 && ondasP < 1800 && ondasS > 100 && ondasS < 300 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es cieno ó (Sedimentos no consolidados )");
    }else if(ondasP > 3000 && ondasP < 3500 && ondasS > 2000 && ondasS < 3000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Limos");
    }else if(ondasP > 1500 && ondasP < 5400 && ondasS > 800 && ondasS < 1500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es (Arenas compactas)");
    }else if(ondasP > 3500 && ondasP < 5400 && ondasS > 1500 && ondasS < 2000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Rocas sedimentarias ó (Arenas compactas)");
    }else if(ondasP > 5400 && ondasP < 5500 && ondasS > 1500 && ondasS < 2000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Rocas sedimentarias");
    }else if(ondasP > 4500 && ondasP < 6000 && ondasS > 3000 && ondasS < 3500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Rocas metamórficas");
    }else if(ondasP > 4500 && ondasP < 5500 && ondasS > 2500 && ondasS < 3000 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Limos ó Rocas sedimentarias ó Rocas Metamórficas");
    }else if(ondasP > 3000 && ondasP < 6000 && ondasS > 2000 && ondasS < 2500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Rocas sedimentarias o Limos");
    }else if(ondasP > 5500 && ondasP < 6000 && ondasS > 2000 && ondasS < 2500 ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Limos");
    }else if(ondasP == 1500  && ondasS > 0  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es agua");
    }else if(ondasP == 5200  && ondasS > 3000  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es granito");
    }else if(ondasP == 6400  && ondasS > 3200  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es basalto");
    }else if(ondasP == 2400  && ondasS > 1350  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es calizas");
    }else if(ondasP == 3500  && ondasS > 2150  ){
        ui->tipoPiedraTE->setText("Por las Ondas P y las Ondas S registradas el material con el que se esta trabajando es Areniscas");
    }else if(ondasP < 250){
        ui->tipoPiedraTE->setText("No hay registro de ondas P tan bajas para ningún material");
    }else if(ondasP > 750){
        ui->tipoPiedraTE->setText("No hay registro de ondas P tan altas para ningún material");
    }else if(ondasS > 4000){
        ui->tipoPiedraTE->setText("No hay registro de ondas S tan altas para ningún material");
    }else if(ondasP < 50){
        ui->tipoPiedraTE->setText("No hay registro de ondas S tan bajas para ningún material");
    }else{
        ui->tipoPiedraTE->setText("No hay registro de ondas P u ondas S para ningún material con esos parametros");
    }
}

void MainCalculosWindow::on_CuButtonBox_accepted()
{
    //Calcula el rendimiento
    float horasReales, horasEfectivas, cu;
    horasReales = ui->horasRealesLE->text().toFloat();
    horasEfectivas = ui->horasEfectivasLE->text().toFloat();
    cu = horasReales / horasEfectivas;
    ui->CULineEdit->setText(QString::number(cu));
    if(cu >= 0.46 and cu < 50){
        QMessageBox::information(
                            this,
                            tr("Administracion de datos - Calculos"),
                            tr("Condiciones de trabajo óptimas.\n"
                               "Roca de dureza media.\n"
                               "Equipos de apoyo optimos\n"
                               "Sin sostenimiento.") );
    }
    else if(cu >= 0.42 and cu < 0.46){
        QMessageBox::information(
                            this,
                            tr("Administracion de datos - Calculos"),
                            tr("Condiciones de trabajo buenas.\n"
                               "Roca de dureza media.\n"
                               "Sin sostenimiento.") );
    }
    else if(cu >= 0.34 and cu < 0.42){
        QMessageBox::information(
                            this,
                            tr("Administracion de datos - Calculos"),
                            tr("Condiciones de trabajo normales - duras.\n"
                               "Roca muy dura y abrasiva.\n"
                               "Sostenimiento ligero o muy ligero.\n"
                               "6 l/seg < Filtración de agua < 32 l/seg.") );
    }
    else if(cu >= 0 and cu < 0.20){
        QMessageBox::information(
                            this,
                            tr("Administracion de datos - Calculos"),
                            tr("Condiciones de trabajo muy duras.\n"
                               "Roca extremadamente dura y abrasiva.\n"
                               "Sostenimiento considerable\n"
                               "Filtración de agua alta > 32 l/seg.") );
    }
    //Posible guardado de datos
}

void MainCalculosWindow::on_CuButtonBox_rejected()
{
    limpiarCamposCU();
}

void MainCalculosWindow::limpiarCamposCU()
{
    //Limpia los campos
    ui->horasRealesLE->setText("");
    ui->horasEfectivasLE->setText("");
    ui->CULineEdit->setText("");
}

void MainCalculosWindow::habilitarAsientoVerticalPB()
{
    //Disable del boton para el calculo del asiento vertical
    if(ui->asientoVerticalMaxLE->text() > 0 and ui->distanciaHorizontalLE->text() > 0 and ui->puntoInflexionLE->text() > 0){
        ui->asientoVerticalPB->setEnabled(true);
    }
    else{
        ui->asientoVerticalPB->setDisabled(true);
    }
}

void MainCalculosWindow::habilitarVolumenCubeta()
{
    //Disable del boton para el calculo del volumen de cubeta
    if(ui->asientoVerticalLE->text() > 0 and ui->puntoInflexionLE_2->text() > 0){
        ui->asientoVerticalPB_2->setEnabled(true);
    }
    else{
        ui->asientoVerticalPB_2->setDisabled(true);
    }
}

void MainCalculosWindow::habilitarDesplazamientoHorizontal()
{
    //Disable del boton para el calculo del desplazamiento horizontal
    if(ui->profundidadLE->text() > 0 and ui->distanciaHorLE->text() > 0 and ui->asientoVerDesLE->text() > 0){
        ui->desplazamientoPB->setEnabled(true);
    }
    else{
        ui->desplazamientoPB->setDisabled(true);
    }
}

void MainCalculosWindow::on_asientoVerticalPB_clicked(){
    //Calculo del asiento vertical
    /*float e = 2.7182818284;
    float dmax = ui->asientoVerticalMaxLE->text().toFloat();
    int x = ui->distanciaHorizontalLE->text().toFloat();
    int i = ui->puntoInflexionLE->text().toFloat();
    int exp =(-(x^2)/(2*(i^2)));
    qDebug() << exp;
    float dv = dmax*e^exp;
    ui->asientoVerticalResLE->setText(QString::number(dv));*/
}

void MainCalculosWindow::on_asientoVerticalPB_2_clicked(){
    //Calculo de la perdida de volumen
    double vs = ui->asientoVerticalLE->text().toDouble();
    double i = ui->puntoInflexionLE_2->text().toDouble();
    double sMax = vs/sqrt(3.1426*2*i);
    ui->asientoVerticalResLE_2->setText(QString::number(sMax));
}

void MainCalculosWindow::on_desplazamientoPB_clicked(){
    //Calculo del desplazamiento Horizontal
    float h =ui->profundidadLE->text().toFloat();
    float y = ui->distanciaHorLE->text().toFloat();
    float sv = ui->asientoVerDesLE->text().toFloat();
    float dhY = (y/h)*sv;
    ui->desplazamientoResLE->setText(QString::number(dhY));
}

void MainCalculosWindow::on_asientoVerticalMaxLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarAsientoVerticalPB();
}

void MainCalculosWindow::on_distanciaHorizontalLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarAsientoVerticalPB();
}

void MainCalculosWindow::on_puntoInflexionLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarAsientoVerticalPB();
}

void MainCalculosWindow::on_asientoVerticalLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarVolumenCubeta();
}

void MainCalculosWindow::on_puntoInflexionLE_2_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarVolumenCubeta();
}


void MainCalculosWindow::on_profundidadLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarDesplazamientoHorizontal();
}

void MainCalculosWindow::on_distanciaHorLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarDesplazamientoHorizontal();
}

void MainCalculosWindow::on_asientoVerDesLE_textChanged(const QString &arg1){
    Q_UNUSED(arg1);
    habilitarDesplazamientoHorizontal();
}


void MainCalculosWindow::on_piedraBB_rejected(){
    ui->ondasPLE->setText("");
    ui->ondasSLE->setText("");
    ui->tipoPiedraTE->setText("");
    ui->tipoPiedraTE->hide();
}

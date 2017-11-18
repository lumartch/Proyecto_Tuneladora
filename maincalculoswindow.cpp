#include "maincalculoswindow.h"
#include "ui_maincalculoswindow.h"

MainCalculosWindow::MainCalculosWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainCalculosWindow){
    ui->setupUi(this);
    //Inicializacion de parametros de la interfaz e icono
    this->setFixedSize(this->size());
    setWindowIcon(QIcon("icon.png"));
    ui->rmrTE->hide();
    intemperizacion = 6;
    persistencia = 6;
    relleno = 6;
    apertura = 6;
    rugosidad = 6;
    agua = 15;
    resistencia = 15;
    rqd = 20;
    espaciamiento = 20;
    ajuste = 0;
    //Inicializador de los disables de PushButton
    habilitarAsientoVerticalPB();
    habilitarVolumenCubeta();
    habilitarDesplazamientoHorizontal();
    //Integración de validadores, para solo recibir numeros
    QRegExp rx("[+-]?([0-9]*[.])?[0-9]+");
    QValidator *validadorNumeros = new QRegExpValidator(rx);
    ui->horasRealesLE->setValidator(validadorNumeros);
    ui->horasEfectivasLE->setValidator(validadorNumeros);
    ui->asientoVerticalMaxLE->setValidator(validadorNumeros);
    ui->distanciaHorizontalLE->setValidator(validadorNumeros);
    ui->puntoInflexionLE->setValidator(validadorNumeros);
    ui->profundidadLE->setValidator(validadorNumeros);
    ui->distanciaHorLE->setValidator(validadorNumeros);
    ui->asientoVerDesLE->setValidator(validadorNumeros);
    //Constructor del calculo del rendimiento
    ui->horasRealesLE->setPlaceholderText("m/hr");
    ui->horasEfectivasLE->setPlaceholderText("m/hr");
    ui->CULineEdit->setDisabled(true);
    //Constructor de las ondas P
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

void MainCalculosWindow::on_CuButtonBox_accepted(){
    //Calcula el rendimiento
    float horasReales, horasEfectivas, cu;
    horasReales = ui->horasRealesLE->text().toFloat();
    horasEfectivas = ui->horasEfectivasLE->text().toFloat();
    cu = horasReales / horasEfectivas;
    ui->CULineEdit->setText(QString::number(cu));
    if(cu > 0.5){
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("Este dato es imposible.\n"
                               "El coeficiente de utilizacion\n"
                               "nunca supera el 50%.") );
        return;

    }
    else if(cu >= 0.46 and cu <= 0.5){
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("Condiciones de trabajo óptimas.\n"
                               "Roca de dureza media.\n"
                               "Equipos de apoyo optimos\n"
                               "Sin sostenimiento.") );
    }
    else if(cu >= 0.42 and cu < 0.46){
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("Condiciones de trabajo buenas.\n"
                               "Roca de dureza media.\n"
                               "Sin sostenimiento.") );
    }
    else if(cu >= 0.34 and cu < 0.42){
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("Condiciones de trabajo normales.\n"
                               "Roca dura.\n"
                               "Sostenimiento muy ligero.\n"
                               "Filtración de agua 6 l/seg.") );
    }
    else if(cu >= 0.20 and cu < 0.34){
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("Condiciones de trabajo duras.\n"
                               "Roca muy dura y abrasiva.\n"
                               "Sostenimiento ligero.\n"
                               "Filtración de agua < 32 l/seg.") );
    }
    else if(cu >= 0 and cu < 0.20){
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("Condiciones de trabajo muy duras.\n"
                               "Roca extremadamente dura y abrasiva.\n"
                               "Sostenimiento considerable\n"
                               "Filtración de agua alta > 32 l/seg.") );
    }
    //Guardado de datos
    guardadoRendimiento();
    QMessageBox::information(
                        this,
                        tr("Cálculos - Tuneladora"),
                        tr("Información guardada en bitacora.") );
}

void MainCalculosWindow::on_CuButtonBox_rejected(){
    limpiarCamposCU();
}

void MainCalculosWindow::limpiarCamposCU(){
    //Limpia los campos
    ui->horasRealesLE->setText("");
    ui->horasEfectivasLE->setText("");
    ui->CULineEdit->setText("");
}

void MainCalculosWindow::habilitarAsientoVerticalPB(){
    //Disable del boton para el calculo del asiento vertical
    if(ui->asientoVerticalMaxLE->text() > 0 and ui->distanciaHorizontalLE->text() > 0 and ui->puntoInflexionLE->text() > 0){
        ui->asientoVerticalPB->setEnabled(true);
    }else{
        ui->asientoVerticalPB->setDisabled(true);
    }
}

void MainCalculosWindow::habilitarVolumenCubeta(){
    //Disable del boton para el calculo del volumen de cubeta
    if(ui->asientoVerticalLE->text() > 0 and ui->puntoInflexionLE_2->text() > 0){
        ui->asientoVerticalPB_2->setEnabled(true);
    }else{
        ui->asientoVerticalPB_2->setDisabled(true);
    }
}

void MainCalculosWindow::habilitarDesplazamientoHorizontal(){
    //Disable del boton para el calculo del desplazamiento horizontal
    if(ui->profundidadLE->text() > 0 and ui->distanciaHorLE->text() > 0 and ui->asientoVerDesLE->text() > 0){
        ui->desplazamientoPB->setEnabled(true);
    }else{
        ui->desplazamientoPB->setDisabled(true);
    }
}

void MainCalculosWindow::guardadoRendimiento(){
    //Bitacora del rendimiento
    float horasReales = ui->horasRealesLE->text().toFloat();
    float horasEfectivas = ui->horasEfectivasLE->text().toFloat();
    float cu = horasReales / horasEfectivas;

    //Lectura de las bitacoras de rendimiento
    QFile bitacoraRendimiento("RendimientoBitacora.txt");
    QString auxStr;
    if(!bitacoraRendimiento.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //qDebug() << "No hay archivo para lectura RendimientoBitacora.txt...";
        bitacoraRendimiento.close();
    }else{
        QTextStream lecturaSuelo(&bitacoraRendimiento);
        while(!lecturaSuelo.atEnd()) {
            auxStr += lecturaSuelo.readLine() + "\n";
        }
        bitacoraRendimiento.close();
    }

    //Bitacora rendimiento guardado
    QTime horaLocal = QTime::currentTime();
    QDate tiempoLocal = QDate::currentDate();
    QFile bitRendActualizada("RendimientoBitacora.txt");
    if(!bitRendActualizada.open(QIODevice::WriteOnly | QIODevice::Text)){
        bitRendActualizada.close();
        return;
    }else{
        QTextStream salida(&bitRendActualizada);
        QString fechaStr = QString::number(tiempoLocal.day()) + "/"
                + QString::number(tiempoLocal.month()) + "/" + QString::number(tiempoLocal.year());
        QString horaStr = '[' + QString::number(horaLocal.hour()) + ':'
                + QString::number(horaLocal.minute()) + ']';
        salida << auxStr;
        salida << fechaStr + "\n";
        salida << horaStr + "\n";
        salida << ui->horasRealesLE->text() << "\n";
        salida << ui->horasEfectivasLE->text() << "\n";
        salida << QString::number(cu) << "\n";
        bitRendActualizada.close();
    }

}

void MainCalculosWindow::on_historialPB_clicked(){
    //Lee los datos que contiene la bitacora de rendimiento
    QFile bitacoraLectura("RendimientoBitacora.txt");
    if(!bitacoraLectura.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->historialTW->setRowCount(0);
        QMessageBox::information(
                        this,
                        tr("Cálculos - Tuneladora"),
                        tr("No hay archivo para lectura RendimientoBitacora.txt...") );

        //qDebug() << "No hay archivo para lectura RendimientoBitacora.txt...";
        bitacoraLectura.close();
        return;
    }
    QList <QString> listaDeElementos;
    QTextStream lecturaArchivo(&bitacoraLectura);
    while(!lecturaArchivo.atEnd()) {
        listaDeElementos.append(lecturaArchivo.readLine());
    }
    bitacoraLectura.close();

    ui->historialTW->setRowCount(listaDeElementos.count()/5);
    for(int i = 0, x = 0, y = 0; i < listaDeElementos.count(); i++){
        QTableWidgetItem *auxItem = new QTableWidgetItem(listaDeElementos.at(i));
        ui->historialTW->setItem(x, y, auxItem);
        y++;
        if(y == 5){
            y = 0;
            x++;
        }
    }
}

void MainCalculosWindow::on_asientoVerticalPB_clicked(){
    //Calculo del asiento vertical
    float dmax = ui->asientoVerticalMaxLE->text().toFloat();
    float x = ui->distanciaHorizontalLE->text().toFloat();
    float i = ui->puntoInflexionLE->text().toFloat();
    float exp =(-(pow(x,2))/(2*(pow(i,2)))); //cambie el operador "^" por la funcion pow
    qDebug() << exp;
    float dv = dmax*pow(2.71828182845,exp);  //puse el valor de "e" directo porque me provocaba un error y también use pow en vez del operador "^"
    ui->asientoVerticalResLE->setText(QString::number(dv));
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

void MainCalculosWindow::on_resistenciaCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            resistencia = 15;
        break;
        case 1:
            resistencia = 12;
        break;
        case 2:
            resistencia = 7;
        break;
        case 3:
            resistencia = 4;
        break;
        case 4:
            resistencia = 2;
        break;
        case 5:
            resistencia = 1;
        break;
        case 6:
            resistencia = 0;
        break;
        default:
            resistencia = 15;
        break;
    }
}

void MainCalculosWindow::on_rqdCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            rqd = 20;
        break;
        case 1:
            rqd = 17;
        break;
        case 2:
            rqd = 13;
        break;
        case 3:
            rqd = 8;
        break;
        case 4:
            rqd = 3;
        break;
        default:
            rqd = 20;
        break;
    }
}

void MainCalculosWindow::on_espaciamientoCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            espaciamiento = 20;
        break;
        case 1:
            espaciamiento = 15;
        break;
        case 2:
            espaciamiento = 10;
        break;
        case 3:
            espaciamiento = 8;
        break;
        case 4:
            espaciamiento = 5;
        break;
        default:
            espaciamiento = 20;
        break;
    }
}

void MainCalculosWindow::on_persistenciaCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            persistencia = 20;
        break;
        case 1:
            persistencia = 15;
        break;
        case 2:
            persistencia = 10;
        break;
        case 3:
            persistencia = 8;
        break;
        case 4:
            persistencia = 5;
        break;
        default:
            persistencia = 20;
        break;
    }
}

void MainCalculosWindow::on_aperturaCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            apertura = 20;
        break;
        case 1:
            apertura = 15;
        break;
        case 2:
            apertura = 10;
        break;
        case 3:
            apertura = 8;
        break;
        case 4:
            apertura = 5;
        break;
        default:
            apertura = 20;
        break;
    }
}

void MainCalculosWindow::on_rugosidadCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            rugosidad = 20;
        break;
        case 1:
            rugosidad = 15;
        break;
        case 2:
            rugosidad = 10;
        break;
        case 3:
            rugosidad = 8;
        break;
        case 4:
            rugosidad = 5;
        break;
        default:
            rugosidad = 20;
        break;
    }
}

void MainCalculosWindow::on_rellenoCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            relleno = 20;
        break;
        case 1:
            relleno = 15;
        break;
        case 2:
            relleno = 10;
        break;
        case 3:
            relleno = 8;
        break;
        case 4:
            relleno = 5;
        break;
        default:
            relleno = 20;
        break;
    }
}

void MainCalculosWindow::on_intemperizacionCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            intemperizacion = 20;
        break;
        case 1:
            intemperizacion = 15;
        break;
        case 2:
            intemperizacion = 10;
        break;
        case 3:
            intemperizacion = 8;
        break;
        case 4:
            intemperizacion = 5;
        break;
        default:
            intemperizacion = 20;
        break;
    }
}

void MainCalculosWindow::on_aguaCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            agua = 20;
        break;
        case 1:
            agua = 15;
        break;
        case 2:
            agua = 10;
        break;
        case 3:
            agua = 8;
        break;
        case 4:
            agua = 5;
        break;
        default:
            agua = 20;
        break;
    }
}

void MainCalculosWindow::on_rmrBB_accepted(){
    float total = resistencia + espaciamiento + persistencia + apertura + rugosidad + rqd + relleno + intemperizacion + agua + ajuste;
    ui->rmrTE->show();
    if(total > 80 ){
        ui->rmrTE->setText("Clase de macizo rocoso MUY BUENA");
    }else if(total < 80 and total > 60){
        ui->rmrTE->setText("Clase de macizo rocoso BUENA");
    }else if(total < 60 and total > 40){
        ui->rmrTE->setText("Clase de macizo rocoso REGULAR");
    }else if(total < 40 and total > 20){
        ui->rmrTE->setText("Clase de macizo rocoso MALA");
    }else if(total < 20){
        ui->rmrTE->setText("Clase de macizo rocoso MUY MALA");
    }else{
        ui->rmrTE->setText("Clase de macizo rocoso no encontrada");
    }
}

void MainCalculosWindow::cleanRMR(){
    resistencia =15;
    rqd = 20;
    espaciamiento = 20;
    persistencia = 6;
    apertura = 6;
    rugosidad = 6;
    relleno = 6;
    intemperizacion = 6;
    agua = 15;
    ajuste = 0;
    ui->discontinuidadCB->setCurrentIndex(0);
    ui->resistenciaCB->setCurrentIndex(0);
    ui->rqdCB->setCurrentIndex(0);
    ui->espaciamientoCB->setCurrentIndex(0);
    ui->persistenciaCB->setCurrentIndex(0);
    ui->aperturaCB->setCurrentIndex(0);
    ui->rugosidadCB->setCurrentIndex(0);
    ui->rellenoCB->setCurrentIndex(0);
    ui->intemperizacionCB->setCurrentIndex(0);
    ui->aguaCB->setCurrentIndex(0);
}

void MainCalculosWindow::on_rmrBB_rejected(){
    cleanRMR();
    ui->rmrTE->setText("");
    ui->rmrTE->hide();
}

void MainCalculosWindow::on_discontinuidadCB_currentIndexChanged(int index){
    switch(index){
        case 0:
            ajuste = 0;
        break;
        case 1:
            ajuste = -2;
        break;
        case 2:
            ajuste = -5;
        break;
        case 3:
            ajuste = -10;
        break;
        case 4:
            ajuste = -12;
        break;
    }
}

void MainCalculosWindow::on_exportarPB_clicked()
{
    QFile bitacoraLectura("RendimientoBitacora.txt");
    if(!bitacoraLectura.open(QIODevice::ReadOnly | QIODevice::Text)) {
        bitacoraLectura.close();
        QMessageBox::information(
                            this,
                            tr("Cálculos - Tuneladora"),
                            tr("No hay datos por exportar.") );
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

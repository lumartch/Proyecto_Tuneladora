#ifndef MAINCALCULOSWINDOW_H
#define MAINCALCULOSWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QIcon>
#include <qdebug.h>
#include <math.h>
#include <QFile>
#include <QFileDialog>
#include <QDate>
#include <QTextStream>

namespace Ui {
class MainCalculosWindow;
}

class MainCalculosWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainCalculosWindow(QWidget *parent = 0);
    ~MainCalculosWindow();

private slots:
    void on_pushButton_clicked();
    void on_CuButtonBox_accepted();
    void on_CuButtonBox_rejected();
    void on_asientoVerticalPB_clicked();
    void on_asientoVerticalMaxLE_textChanged(const QString &arg1);
    void on_distanciaHorizontalLE_textChanged(const QString &arg1);
    void on_puntoInflexionLE_textChanged(const QString &arg1);
    void on_asientoVerticalLE_textChanged(const QString &arg1);
    void on_puntoInflexionLE_2_textChanged(const QString &arg1);
    void on_asientoVerticalPB_2_clicked();
    void on_profundidadLE_textChanged(const QString &arg1);
    void on_distanciaHorLE_textChanged(const QString &arg1);
    void on_asientoVerDesLE_textChanged(const QString &arg1);
    void on_desplazamientoPB_clicked();
    void on_resistenciaCB_currentIndexChanged(int index);
    void on_rqdCB_currentIndexChanged(int index);
    void on_espaciamientoCB_currentIndexChanged(int index);
    void on_persistenciaCB_currentIndexChanged(int index);
    void on_aperturaCB_currentIndexChanged(int index);
    void on_rugosidadCB_currentIndexChanged(int index);
    void on_rellenoCB_currentIndexChanged(int index);
    void on_intemperizacionCB_currentIndexChanged(int index);
    void on_aguaCB_currentIndexChanged(int index);
    void on_rmrBB_accepted();
    void on_rmrBB_rejected();
    void on_historialPB_clicked();
    void on_discontinuidadCB_currentIndexChanged(int index);
    void on_exportarPB_clicked();

private:
    Ui::MainCalculosWindow *ui;
    void cleanRMR();
    void limpiarCamposCU();
    void habilitarAsientoVerticalPB();
    void habilitarVolumenCubeta();
    void habilitarDesplazamientoHorizontal();
    void guardadoRendimiento();
    float intemperizacion;
    float agua;
    float resistencia;
    float rqd;
    float apertura;
    float rugosidad;
    float relleno;
    float persistencia;
    float espaciamiento;
    float total;
    float ajuste;
};

#endif // MAINCALCULOSWINDOW_H

#ifndef MAINCALCULOSWINDOW_H
#define MAINCALCULOSWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <qdebug.h>
#include <math.h>

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
    void on_piedraBB_accepted();
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

private:
    Ui::MainCalculosWindow *ui;
    void limpiarCamposCU();
    void habilitarAsientoVerticalPB();
    void habilitarVolumenCubeta();
    void habilitarDesplazamientoHorizontal();
};

#endif // MAINCALCULOSWINDOW_H

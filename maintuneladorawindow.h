#ifndef MAINTUNELADORAWINDOW_H
#define MAINTUNELADORAWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDate>
#include <QMessageBox>
#include <QTextStream>
#include <qdebug.h>

namespace Ui {
class MainTuneladoraWindow;
}

class MainTuneladoraWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainTuneladoraWindow(QWidget *parent = 0);
    ~MainTuneladoraWindow();

private slots:
    void on_botonRegresaPB_clicked();
    void on_bitacoraCB_currentIndexChanged(int index);
    void on_bitacoraBB_accepted();
    void on_bitacoraBB_rejected();
    void on_registroCB_currentIndexChanged(int index);

    void on_registroPB_clicked();

private:
    Ui::MainTuneladoraWindow *ui;
    void enableButtonBitacora();
    void cleanBitacora();
    void camposEnable();
    void guardarBitacora(const QString&);
    void cargarBitacora(const QString&);
    void rellenarTabla(const QString &);
};

#endif // MAINTUNELADORAWINDOW_H

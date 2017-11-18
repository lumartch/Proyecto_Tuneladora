#ifndef MAINONDASWINDOW_H
#define MAINONDASWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QIcon>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDate>
#include <qdebug.h>
#include "tablafrentedialog.h"

namespace Ui {
class MainOndasWindow;
}

class MainOndasWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainOndasWindow(QWidget *parent = 0);
    ~MainOndasWindow();

private slots:
    void on_frentePB_clicked();
    void on_frenteBB_accepted();
    void on_frenteBB_rejected();
    void on_sobrecargaLE_textChanged(const QString &arg1);
    void on_interiorLE_textChanged(const QString &arg1);
    void on_densidadLE_textChanged(const QString &arg1);
    void on_coberturaLE_textChanged(const QString &arg1);
    void on_diametroLE_textChanged(const QString &arg1);
    void on_resistenciaLE_textChanged(const QString &arg1);

    void on_historialPB_clicked();

private:
    Ui::MainOndasWindow *ui;
    void cleanFrente();
    void habilitarFrente();
    void guardarDatosFrente(const QString &);
};

#endif // MAINONDASWINDOW_H

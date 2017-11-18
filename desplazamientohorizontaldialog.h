#ifndef DESPLAZAMIENTOHORIZONTALDIALOG_H
#define DESPLAZAMIENTOHORIZONTALDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class DesplazamientoHorizontalDialog;
}

class DesplazamientoHorizontalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DesplazamientoHorizontalDialog(QWidget *parent = 0);
    ~DesplazamientoHorizontalDialog();

private slots:
    void on_exportarPB_clicked();

    void on_regresarPB_clicked();

private:
    Ui::DesplazamientoHorizontalDialog *ui;
    void cargarDatos();
};

#endif // DESPLAZAMIENTOHORIZONTALDIALOG_H

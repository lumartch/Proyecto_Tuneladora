#ifndef ASIENTOVERTICALDIALOG_H
#define ASIENTOVERTICALDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class AsientoVerticalDialog;
}

class AsientoVerticalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AsientoVerticalDialog(QWidget *parent = 0);
    ~AsientoVerticalDialog();

private slots:
    void on_regresaPB_clicked();

    void on_exportarPB_clicked();

private:
    Ui::AsientoVerticalDialog *ui;
    void cargarDatos();
    void exportarArchivo();
};

#endif // ASIENTOVERTICALDIALOG_H

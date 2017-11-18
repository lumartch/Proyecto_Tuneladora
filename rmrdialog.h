#ifndef RMRDIALOG_H
#define RMRDIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class RMRDialog;
}

class RMRDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RMRDialog(QWidget *parent = 0);
    ~RMRDialog();

private slots:
    void on_exportarPB_clicked();
    void on_regresarPB_clicked();

private:
    Ui::RMRDialog *ui;
    void cargarDatos();
};

#endif // RMRDIALOG_H

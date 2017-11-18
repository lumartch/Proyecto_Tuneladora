#ifndef VOLUMENASIENTODIALOG_H
#define VOLUMENASIENTODIALOG_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class VolumenAsientoDialog;
}

class VolumenAsientoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VolumenAsientoDialog(QWidget *parent = 0);
    ~VolumenAsientoDialog();

private slots:
    void on_exportarPB_clicked();
    void on_regresarPB_clicked();

private:
    Ui::VolumenAsientoDialog *ui;
    void cargarDatos();
};

#endif // VOLUMENASIENTODIALOG_H

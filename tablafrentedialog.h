#ifndef TABLAFRENTEDIALOG_H
#define TABLAFRENTEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QIcon>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDate>
#include <qdebug.h>

namespace Ui {
class TablaFrenteDialog;
}

class TablaFrenteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TablaFrenteDialog(QWidget *parent = 0);
    ~TablaFrenteDialog();

private slots:
    void on_regresarPB_clicked();

private:
    Ui::TablaFrenteDialog *ui;
    void cargarFrente();
};

#endif // TABLAFRENTEDIALOG_H

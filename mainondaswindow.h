#ifndef MAINONDASWINDOW_H
#define MAINONDASWINDOW_H

#include <QMainWindow>

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

    void cleanFrente();

    void on_sobrecargaLE_textChanged(const QString &arg1);

    void on_interiorLE_textChanged(const QString &arg1);

    void on_densidadLE_textChanged(const QString &arg1);

    void on_coberturaLE_textChanged(const QString &arg1);

    void on_diametroLE_textChanged(const QString &arg1);

    void on_resistenciaLE_textChanged(const QString &arg1);

private:
    Ui::MainOndasWindow *ui;
    void habilitarFrente();
};

#endif // MAINONDASWINDOW_H

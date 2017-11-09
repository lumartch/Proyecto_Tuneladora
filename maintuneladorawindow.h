#ifndef MAINTUNELADORAWINDOW_H
#define MAINTUNELADORAWINDOW_H

#include <QMainWindow>

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

    void on_PVSSLE_textChanged(const QString &arg1);

    void on_PVSCLE_textChanged(const QString &arg1);

    void on_PVMLE_textChanged(const QString &arg1);

    void on_bitacoraCB_currentIndexChanged(int index);

    void on_bitacoraBB_accepted();

    void on_bitacoraBB_rejected();

private:
    Ui::MainTuneladoraWindow *ui;
    void enableButtonBitacora();
    void cleanBitacora();
};

#endif // MAINTUNELADORAWINDOW_H

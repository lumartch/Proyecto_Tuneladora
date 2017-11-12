#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainMenuWindow;
}

class MainMenuWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainMenuWindow(QWidget *parent = 0);
    ~MainMenuWindow();
    int contCalculos = 0;
    int contRegistro = 0;
private slots:
    void on_eleccionCB_currentIndexChanged(int index);
    void on_aceptarPb_clicked();

private:
    Ui::MainMenuWindow *ui;
    MainCalculosWindow *ventanaCalculos;
    MainTuneladoraWindow *ventanaBitacora;
};

#endif // MAINMENUWINDOW_H

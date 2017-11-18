#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QMainWindow>
#include "maintuneladorawindow.h"
#include "maincalculoswindow.h"
#include "mainondaswindow.h"
#include <QMessageBox>

namespace Ui {
class MainMenuWindow;
}

class MainMenuWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainMenuWindow(QWidget *parent = 0);
    ~MainMenuWindow();

private slots:
    void on_eleccionCB_currentIndexChanged(int index);
    void on_aceptarPb_clicked();

private:
    Ui::MainMenuWindow *ui;
    MainCalculosWindow *ventanaCalculos;
    MainTuneladoraWindow *ventanaBitacora;
    MainOndasWindow *ventanaFrente;
};

#endif // MAINMENUWINDOW_H

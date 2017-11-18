#ifndef MAINMENUWINDOW_H
#define MAINMENUWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QIcon>
#include "maintuneladorawindow.h"
#include "maincalculoswindow.h"
#include "mainondaswindow.h"

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
    //VersionProgramaDialog *ventanaVersion;
};

#endif // MAINMENUWINDOW_H

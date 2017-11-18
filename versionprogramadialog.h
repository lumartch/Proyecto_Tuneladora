#ifndef VERSIONPROGRAMADIALOG_H
#define VERSIONPROGRAMADIALOG_H

#include <QDialog>
#include "mainmenuwindow.h"

namespace Ui {
class VersionProgramaDialog;
}

class VersionProgramaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VersionProgramaDialog(QWidget *parent = 0);
    ~VersionProgramaDialog();

private slots:
    void on_aceptarPB_clicked();

private:
    Ui::VersionProgramaDialog *ui;
    MainMenuWindow *ventanaInicio;
};

#endif // VERSIONPROGRAMADIALOG_H

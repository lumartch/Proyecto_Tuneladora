#include "versionprogramadialog.h"
#include "ui_versionprogramadialog.h"

VersionProgramaDialog::VersionProgramaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionProgramaDialog)
{
    ui->setupUi(this);
    ui->informacionLabel->setText("Bienvenido al sistema de administración\n"
                                  "de datos, cálculos y alertas \n"
                                  "de la tuneladora.\n\n\n"
                                  "Version 1.0 - Version Beta.");
    ui->iconLabel->setPixmap(QPixmap("icon.png"));
    ui->iconLabel->setScaledContents(true);
    this->setFixedSize(this->size());
    setWindowIcon(QIcon("icon.png"));
    //inicializacion de la ventana del menú
    ventanaInicio = new MainMenuWindow;
    ventanaInicio->show();

}

VersionProgramaDialog::~VersionProgramaDialog()
{
    delete ui;
}

void VersionProgramaDialog::on_aceptarPB_clicked()
{
    this->close();
}

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

private:
    Ui::MainOndasWindow *ui;
};

#endif // MAINONDASWINDOW_H

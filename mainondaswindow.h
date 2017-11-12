#ifndef MAINONDASWINDOW_H
#define MAINONDASWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainOndasWindow;
}

class MainOndasWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainOndasWindow(QWidget *parent = 0);
    ~MainOndasWindow();

private:
    Ui::MainOndasWindow *ui;
};

#endif // MAINONDASWINDOW_H

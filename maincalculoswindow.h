#ifndef MAINCALCULOSWINDOW_H
#define MAINCALCULOSWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainCalculosWindow;
}

class MainCalculosWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainCalculosWindow(QWidget *parent = 0);
    ~MainCalculosWindow();

private:
    Ui::MainCalculosWindow *ui;
};

#endif // MAINCALCULOSWINDOW_H

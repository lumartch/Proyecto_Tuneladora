#ifndef MAINTUNELADORAWINDOW_H
#define MAINTUNELADORAWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainTuneladoraWindow;
}

class MainTuneladoraWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainTuneladoraWindow(QWidget *parent = 0);
    ~MainTuneladoraWindow();

private:
    Ui::MainTuneladoraWindow *ui;
};

#endif // MAINTUNELADORAWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "twopattern.h"
#include "threepattern.h"
#include "fourpattern.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPushButton two;
    QPushButton three;
    QPushButton four;
    void Twopattern();
    void Threepattern();
    void Fourpattern();
    void Notwo();
    void Nothree();
    void Nofour();
    twopattern t;
    threepattern h;
    fourpattern f;
    void paintEvent(QPaintEvent *);
private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H

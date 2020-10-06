#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,1000);
    two.setParent(this);
    two.setText("简单模式");
    two.move(450,200);
    two.setFixedSize(120,50);
    three.setParent(this);
    three.setText("中等模式");
    three.move(450,300);
    three.setFixedSize(120,50);
    four.setParent(this);
    four.setText("困难模式");
    four.move(450,400);
    four.setFixedSize(120,50);
    connect(&two, &QPushButton::pressed, this, &MainWindow::Twopattern);
    connect(&three, &QPushButton::pressed, this, &MainWindow::Threepattern);
    connect(&four, &QPushButton::pressed, this, &MainWindow::Fourpattern);
    connect(&t, &twopattern::goback, this, &MainWindow::Notwo);
    connect(&h, &threepattern::goback, this, &MainWindow::Nothree);
    connect(&f, &fourpattern::goback, this, &MainWindow::Nofour);
    QPainter p(this);
    p.drawPixmap(0,0,1000,1100,QPixmap("../picture/backgroud.jpg"));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,1000,1100,QPixmap("../picture/backgroud.jpg"));
}

void MainWindow::Twopattern()
{
    t.show();
    this->hide();
}

void MainWindow::Threepattern()
{
    h.show();
    this->hide();
}

void MainWindow::Fourpattern()
{
    f.show();
    this->hide();
}

void MainWindow::Notwo()
{
    this->show();
    t.hide();
}

void MainWindow::Nothree()
{
    this->show();
    h.hide();
}

void MainWindow::Nofour()
{
    this->show();
    f.hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

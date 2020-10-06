#ifndef TWOPATTERN_H
#define TWOPATTERN_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QLabel>

class twopattern : public QWidget
{
    Q_OBJECT
public:
    explicit twopattern(QWidget *parent = nullptr);
    QPushButton back;
    void Goback();
    void paintEvent(QPaintEvent *);
    int flag[2][2];             //2*2, 代表是否被翻
    int image[2][2];
    void mousePressEvent(QMouseEvent *);
    int chessx;
    int chessy;
    int now;    //标记有没有翻完两次
    int last;
    int Llastx;
    int Llasty;
    int lastx;
    int lasty;
    int timesum;
    void Restart();
    QLabel label;
    QTimer *timer;
    QTimer *mytime;
signals:
    void goback();
public slots:
    void MySlot();
    void handletimeout();

};

#endif // TWOPATTERN_H

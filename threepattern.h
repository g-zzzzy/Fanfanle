#ifndef THREEPATTERN_H
#define THREEPATTERN_H

#include <QWidget>
#include <QPushButton>

class threepattern : public QWidget
{
    Q_OBJECT
public:
    explicit threepattern(QWidget *parent = nullptr);
    QPushButton back;
    void Goback();
    void paintEvent(QPaintEvent *);
    int flag[3][2];     //3*2

signals:
    void goback();

public slots:
};

#endif // THREEPATTERN_H

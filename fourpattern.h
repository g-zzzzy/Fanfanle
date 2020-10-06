#ifndef FOURPATTERN_H
#define FOURPATTERN_H

#include <QWidget>
#include <QPushButton>

class fourpattern : public QWidget
{
    Q_OBJECT
public:
    explicit fourpattern(QWidget *parent = nullptr);
    QPushButton back;
    void Goback();
    void paintEvent(QPaintEvent *);
    int flag[4][3];     //4*3

signals:
    void goback();
public slots:
};

#endif // FOURPATTERN_H

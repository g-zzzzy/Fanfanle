#include "fourpattern.h"
#include <QPainter>

fourpattern::fourpattern(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1000,1100);
    back.setParent(this);
    back.setText("返回");
    back.move(445, 1000);
    connect(&back, &QPushButton::pressed, this, &fourpattern::Goback);
    for(int i=0;i<4;i++)
    {
        for(int j=0; j<3; j++)
        {
            flag[i][j]=0;
        }
    }
}

void fourpattern::paintEvent(QPaintEvent *)
{
    int startx=20;
    int starty=25;
    QPainter p(this);
    p.drawPixmap(0,0,1000,1100,QPixmap("../picture/backgroud.jpg"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    p.setBrush(brush);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
             p.drawRect(startx+225*i+20*i,starty+300*j+25*j, 225, 300);
        }
    }
}

void fourpattern::Goback()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0; j<3; j++)
        {
            flag[i][j]=0;
        }
    }
    emit goback();
}

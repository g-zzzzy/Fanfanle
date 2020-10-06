#include "threepattern.h"
#include <QPainter>

threepattern::threepattern(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1000,1100);
    back.setParent(this);
    back.setText("返回");
    back.move(445, 1000);
    connect(&back, &QPushButton::pressed, this, &threepattern::Goback);
    for(int i=0; i<3;i++)
    {
        for(int j=0; j<2; j++)
        {
            flag[i][j]=0;
        }
    }
}

void threepattern::paintEvent(QPaintEvent *)
{
    int startx=25;
    int starty=50;
    QPainter p(this);
    p.drawPixmap(0,0,1000,1100,QPixmap("../picture/backgroud.jpg"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    p.setBrush(brush);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
             p.drawRect(startx+300*i+25*i,starty+425*j+50*j, 300, 425);
        }
    }
}

void threepattern::Goback()
{
    for(int i=0; i<3;i++)
    {
        for(int j=0; j<2; j++)
        {
            flag[i][j]=0;
        }
    }
    emit goback();
}

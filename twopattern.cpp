#include "twopattern.h"
#include <QPainter>
#include <QTime>
#include <QMouseEvent>
#include <windows.h>
#include <QMessageBox>
#include <QTimer>
#include <QLabel>

twopattern::twopattern(QWidget *parent) : QWidget(parent)
{
    mytime=new QTimer(this);
    connect(mytime, SIGNAL(timeout()), this, SLOT(handletimeout()));
    timesum=0;      //计时
    label.setParent(this);
    label.move(0,1000);
    QFont font;
    font.setPointSize(14);
    label.setFont(font);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(MySlot()));
    timer->start(1000);
    this->setFixedSize(1000,1100);
    back.setParent(this);
    back.setText("返回");
    back.move(445, 1000);
    connect(&back, &QPushButton::pressed, this, &twopattern::Goback);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            flag[i][j]=0;
        }
    }

    int sumone=0;
    int sumzero=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));      //随机生成
            int num=qrand()%2;
            if(num==0)
            {
                sumzero+=1;
                if(sumzero<=2)
                    image[i][j]=0;
                else
                {
                    image[i][j]=1;
                    sumone+=1;
                }
            }                                                //每个框设置的序号代表图片
            if(num==1)
            {
                sumone+=1;
                if(sumone<=2)
                    image[i][j]=1;
                else
                {
                    image[i][j]=0;
                    sumzero+=1;
                }
            }

        }
    }

    now=0;  //第一次翻为0，第二次翻变为1
}

void twopattern::MySlot()
{
    timesum+=1;
    label.setText(QTime::currentTime().toString()+"   "+QString::number(timesum)+"  ");
}


void twopattern::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,1000,1100,QPixmap("../picture/backgroud.jpg"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    p.setBrush(brush);
    int startx=50;
    int starty=50;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            p.drawRect(startx+425*i+50*i,starty+425*j+50*j, 425, 425);
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0; j<2; j++)
        {
            if(flag[i][j]==1)
            {
                if(image[i][j]==0)
                {
                    p.drawPixmap(startx+425*i+50*i,starty+425*j+50*j,425,425,QPixmap("../picture/one.png"));
                }
                else if(image[i][j]==1)
                {
                    p.drawPixmap(startx+425*i+50*i,starty+425*j+50*j,425,425,QPixmap("../picture/two.png"));
                }
            }
            else if(flag[i][j]==0)
                 p.drawPixmap(startx+425*i+50*i,starty+425*j+50*j,425,425,QPixmap("../picture/zero.png"));
        }
    }

}

void twopattern::mousePressEvent(QMouseEvent *e)
{
    //获取鼠标点击的位置
    int x= e->x();
    int y= e->y();
    if(now==0&&((x>50&&x<475)||(x>525&&x<950))&&((y>50&&y<475)||(y>525&&y<950)))        //第一次翻
    {
        if(x>50&&x<475)
            chessx=0;
        if(x>525&&x<950)
            chessx=1;
        if(y>50&&y<475)
            chessy=0;
        if(y>525&&y<950)
            chessy=1;
        if(!flag[chessx][chessy])       //如果没被翻过
        {
            now=1;
            flag[chessx][chessy]=1;
            Llastx=chessx;
            Llasty=chessy;
            update();
        }
    }
    else if(now==1&&((x>50&&x<475)||(x>525&&x<950))&&((y>50&&y<475)||(y>525&&y<950)))     //第二次翻
    {
        if(x>50&&x<475)
            chessx=0;
        if(x>525&&x<950)
            chessx=1;
        if(y>50&&y<475)
            chessy=0;
        if(y>525&&y<950)
            chessy=1;
        if(!flag[chessx][chessy])       //如果没被翻过
        {
            now=0;
            flag[chessx][chessy]=1;
            Sleep(200);
            update();
            lastx=chessx;
            lasty=chessy;
            mytime->start(100);
        }
    }
    else
        return;

    int judge=1;        //judege=1表示结束
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(flag[i][j]==0)
                judge=0;
        }
    }
    if(judge)
    {
        QMessageBox over;
        over.setText("游戏结束！用时"+QString::number(timesum)+"秒\n是否重新开始?");
        over.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        int ret=over.exec();
        switch(ret)
        {
        case QMessageBox::Yes:
            Restart();
            break;
        case QMessageBox::No:
            Goback();
        default:
            break;
        }
    }
}

void twopattern::handletimeout()
{
    if(now==0&&image[lastx][lasty]!=image[Llastx][Llasty])
    {
        Sleep(500);
        flag[lastx][lasty]=0;
        flag[Llastx][Llasty]=0;
        update();
    }
    else
        return;
}


void twopattern::Restart()
{
    timesum=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            flag[i][j]=0;
            update();
        }
    }
}

void twopattern::Goback()
{
    timesum=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            flag[i][j]=0;
    }
    emit goback();
}

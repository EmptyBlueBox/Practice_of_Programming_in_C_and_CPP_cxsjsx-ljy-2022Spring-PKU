#include "board2.h"
#include "ui_board2.h"

Board2::Board2(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Board2)
{
    ui->setupUi(this);
    ava = true;
    rece = false;
    ang = 90.0;
    val = 0;
}

void Board2::getCenter()
{
    QRect rct = ui->receive->frameRect();
    cter = QPoint(rct.center());
}

void Board2::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(ava)//画发射的杆子
    {
        getCenter();
        painter.setPen(QPen(Qt::red,20,Qt::SolidLine,Qt::RoundCap));
        painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
        painter.drawLine(QPoint(cter.x(),cter.y()+37),QPoint(cter.x()+32*cos(ang/180*3.1415926),cter.y()+37-32*sin(ang/180*3.1415926)));
    }
    if(rece)//画黄光闪现效果
    {
        getCenter();
        painter.setPen(QPen(Qt::yellow,50,Qt::SolidLine,Qt::RoundCap));
        painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
        painter.drawLine(QPoint(cter.x(),cter.y()+37),QPoint(cter.x()+32*cos(ang/180*3.1415926),cter.y()+37-32*sin(ang/180*3.1415926)));
    }
}

void Board2::newinfo()//更新黄光效果
{
    if(!rece)
    {
        return;
    }
    val++;
    if(val < 30)
    {
        return;
    }
    val = 0;
    rece = false;
}

void Board2::keyPressEvent(QKeyEvent *event)//写在这里没用，可以删了
{
    if(event->key()==Qt::Key_Q)//按Q键倾角增大
    {
        ang+=2.0;
        if(ang>170.0)//限制倾角范围
        {
            ang=170.0;
        }
        update();//刷新绘图
    }
    if(event->key()==Qt::Key_E)//按E键倾角减小
    {
        ang-=2.0;
        if(ang<10.0)//限制倾角范围
        {
            ang=10.0;
        }
        update();//刷新绘图
    }
}

Board2::~Board2()
{
    delete ui;
}

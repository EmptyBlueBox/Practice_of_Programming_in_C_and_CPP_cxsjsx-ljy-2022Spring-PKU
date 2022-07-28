#include "pinball.h"
#include "ui_pinball.h"

int rr[13]={
    0,20,22,24,28,30,32,36,38,40,42,46,48
};//大致确定不同原子半径

int cr[13]={
    0,135,0,160,221,255,156,255,255,255,0,61,128
};

int cg[13]={
    0,206,255,32,160,192,102,97,153,255,255,145,128
};

int cb[13]={
    0,250,255,240,221,203,31,0,18,0,0,64,105
};//RGB值确定不同原子的颜色

Pinball::Pinball(int k, QWidget *parent, int L, int R) :
    QFrame(parent),
    ui(new Ui::Pinball)
{
    ui->setupUi(this);
    kind=k;
    this->resize(rr[k],rr[k]);
    col=QColor(cr[k],cg[k],cb[k]);
    vx = 0;
    vy = 0;
    ax = 0;
    ay = 0;
    left = L;
    right = R;
    mava = false;
    rece = false;
    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
}

void Pinball::remake(int k)//用于根据传入的原子序数重设原子的种类，大小，颜色属性
{
    kind=k;
    this->resize(rr[k],rr[k]);
    col=QColor(cr[k],cg[k],cb[k]);
}

void Pinball::make_bomb(int r)
{
    kind =13;
    this->resize(r,r);
    col=QColor(0,0,0);
}

void Pinball::get_speed(int v, double ang)//更新速度，第一个参数是总速度大小，第二个参数是和x轴正向的夹角（角度制）
{
    vx = v*cos(ang/180*3.1415926);
    vy = -v*sin(ang/180*3.1415926);
}

void Pinball::get_position(double x,double y)//更新位置，注意传入的是原子中心的坐标
{
    if(!mava)
    {
        return;
    }
    double mx = x - this->frameSize().width()/2.0;
    double my = y - this->frameSize().height()/2.0;
    this->move((int)mx,(int)my);
}

void Pinball::onTimeout(void)
{   if(!mava)
    {
        return;
    }
    ax += vx;
    ay += vy;//计时器事件每触发一次，更新精确位置
    if(ax > right - this->frameSize().width()/2.0)//限制范围，原子不移动到框外面
    {
        ax = right - this->frameSize().width()/2.0;
        vx = -vx;
    }
    if(ax < left + this->frameSize().width()/2.0)
    {
        ax = left + this->frameSize().width()/2.0;
        vx = -vx;
    }
    if(ay > 710 - this->frameSize().height()/2.0)
    {
        ay = 710 - this->frameSize().height()/2.0;
        if(kind == 1)
        {
            mava = false;
        }
        else
        {
            remake(kind - 1);//与底部碰撞代表没有接住，原子降级
            vy = - vy;
        }
    }
    if(ay < 40 + this->frameSize().height()/2.0)
    {
        ay = 40 + this->frameSize().height()/2.0;
        vy = -vy;
    }
    this->get_position(ax,ay);
    update();//更新位置并重新绘图
}

void Pinball::paintEvent(QPaintEvent *)
{   if(mava)//可以移动时绘图
    {
        QPainter painter(this);
        QBrush brush(col);
        painter.setBrush(brush);
        painter.drawEllipse(this->frameRect().center(),this->frameRect().width()/2-1,this->frameRect().height()/2-1);
    }
}

Pinball::~Pinball()
{
    delete ui;
}

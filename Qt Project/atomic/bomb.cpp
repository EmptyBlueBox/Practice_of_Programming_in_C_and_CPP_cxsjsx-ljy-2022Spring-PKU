#include "bomb.h"
#include "ui_bomb.h"

Bomb::Bomb(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Bomb)
{
    ui->setupUi(this);
    for(int i=1;i<=6;++i)
    {
        QString str = QString(":/image/bomb-%1.png").arg(i);
        pixarr.push_back(QPixmap(str));//导入图片
    }
    bava = false;
    picindex = 0;
    val = 0;
}

Bomb::~Bomb()
{
    delete ui;
}

void Bomb::newinfo()
{
    if(!bava)
    {
        return;
    }//不展示图片时跳过
    val++;
    if(val < 30)
    {
        return;
    }
    val = 0;
    picindex++;//切图
    if(picindex > 5)
    {
        bava = false;
        picindex = 0;//复原
    }
}

void Bomb::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(bava)//画爆炸图
    {
        painter.drawPixmap(0,0,pixarr[picindex]);
    }
}

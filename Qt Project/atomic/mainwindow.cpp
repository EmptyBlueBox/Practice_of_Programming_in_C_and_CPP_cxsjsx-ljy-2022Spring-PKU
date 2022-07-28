#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board2.h"
#include "ui_board2.h"
#include "pinball.h"
#include "ui_pinball.h"
#include "bomb.h"
#include "ui_bomb.h"
#include "shop.h"
#include "ui_shop.h"
#include "help.h"
#include "ui_help.h"
#include "achievements.h"
#include "ui_achievements.h"
#include <qdebug.h>

int atomheight[3]={70, 120, 170};
int const MainWindow::EXITCODE = -123456789;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bombva = 0;
    bombva1 = 0;
    bombva2 = 0;
    cscore = 0;
    score1 = 0;
    score2 = 0;
    bombti = 0;
    maxatom = 1;
    historymax = 1;
    targetva = 0;
    addva = 0;
    gamemode = 0;
    timerest = 30;
    ms50 = 0;
    qsrand(QTime::currentTime().msec());
    ui->score->display(bombva);
    ui->thistime->display(targetva);
    ui->atomtable->setSelectionMode(QAbstractItemView::NoSelection);//表格禁止选中
    ui->atomtable->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格禁止编辑
    ui->atomtable->setColumnWidth(0,60);
    ui->atomtable->setColumnWidth(2,60);
    ui->atomtable->setColumnWidth(4,60);
    ui->atomtable->setColumnWidth(1,30);
    ui->atomtable->setColumnWidth(3,30);
    ui->atomtable->setColumnWidth(5,30);
    ui->atomtable->setRowHeight(0,60);
    ui->atomtable->setRowHeight(1,60);
    ui->atomtable->setRowHeight(2,60);
    ui->atomtable->setRowHeight(3,60);//调整行列宽高
    ui->atomtable->setSelectionMode(QAbstractItemView::NoSelection);//表格禁止选中
    ui->itemtable->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格禁止编辑
    ui->itemtable->setColumnWidth(0,64);
    ui->itemtable->setColumnWidth(1,64);
    ui->itemtable->setColumnWidth(2,64);
    ui->itemtable->setRowHeight(0,64);
    ui->itemtable->setRowHeight(1,64);
    ui->itemtable->setRowHeight(2,64);//调整行列宽高
    b1 = new Board2(this);
    b1->move(-100,-100);
    setFocusPolicy(Qt::StrongFocus);
    ui->atomtable->setFocusPolicy(Qt::NoFocus);
    ui->itemtable->setFocusPolicy(Qt::NoFocus);//这三行让炮台随时可以用键盘操作
    ui->storeButton->setFocusPolicy(Qt::ClickFocus);
    ui->storeButton->setDisabled(true);
    sh = new Shop(this);
    sh->hide();
    hp = new Help(this);
    hp->hide();
    am = new Achievements(this);
    am->hide();
    for(int i=1;i<=3;++i)
    {
        p2[i] = new Pinball(1,this,10,960);
    }
    for(int i=1;i<=3;++i)
    {
        p2[3+i] = new Pinball(1,this,10,480);
    }
    for(int i=1;i<=3;++i)
    {
        p2[6+i] = new Pinball(1,this,490,960);
    }//以上是对界面上的原子的初始化，它们位于不同的轨道上
    np3 = 0;
    for(int i=1;i<=19;++i)
    {
        p3[i] = new Pinball(1,this,10,960);
    }//对将来碰撞产生的原子的初始化
    connect(&timer1,SIGNAL(timeout()),this,SLOT(onTimeout1()));
    connect(&timer2,SIGNAL(timeout()),this,SLOT(onTimeout2()));
    connect(sh->ui->end_button,SIGNAL(clicked()),this,SLOT(shopupdate()));
    for(int i=0;i<20;++i)
    {
        bb[i] = new Bomb(this);
    }//对爆炸效果的初始化
    for(int i=0;i<=9;++i)
    {
        pb[i] = new Pinball(1,this,10,960);
    }//对原子爆弹初始化
    for(int i=1;i<=9;++i)
    {
        mi[i] = 0;
        il[i] = 1;
        totalbuy[i] = 0;
    }
    for(int i=0;i<13;++i)
    {
        atomnum[i]=0;
    }
    atomnum[1]=2;
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->__label_1_0->hide();
    ui->__label_2_0->hide();
    ui->__label_2___2->hide();
    ui->__label_2_0_2->hide();
    ui->__label_3_0->hide();
    ui->__label_4_0->hide();
    ui->__label_5_0->hide();
    ui->__label_6_0->hide();
    ui->__label_7_0->hide();
    ui->__label_8_0->hide();
    ui->__label_9_0->hide();
    ui->menuBar->hide();
    ui->__button_6->hide();
    ui->__button_7->hide();
    ui->__button_8->hide();
    ui->__button_9->hide();
    ui->__re->hide();
    ui->__again_1->hide();
    ui->__again_2->hide();
    ui->__again_3->hide();
    ui->__win->hide();
    ui->__win__->hide();

    //playgame1();//开始经典模式游戏
    //playgame2();//开始限时模式游戏
    //playgame3();//开始双人模式游戏
}

void MainWindow::playgame1()
{
    for(int i=0;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            __p[i+j*4-3]=new Pinball(i+j*4-3,this,10,960);
            __p[i+j*4-3]->mava=true;
            __p[i+j*4-3]->get_position(921+j*90,252+i*59);
            __p[i+j*4-3]->show();
        }
    }
    ui->menuBar->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_2->setText("本次发射目标");
    gamemode = 1;
    bombva = 0;
    bombti = 0;
    maxatom = 1;
    historymax = 1;
    targetva = 0;
    addva = 0;
    for(int i=1;i<=9;++i)
    {
        mi[i] = 0;
        il[i] = 1;
        totalbuy[i] = 0;
    }
    for(int i=0;i<13;++i)
    {
        atomnum[i]=0;
    }
    atomnum[1]=2;
    b1->ang=90.0;
    pop_prepare();
}

void MainWindow::playgame2()
{
    for(int i=0;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            __p[i+j*4-3]=new Pinball(i+j*4-3,this,10,960);
            __p[i+j*4-3]->mava=true;
            __p[i+j*4-3]->get_position(921+j*90,252+i*59);
            __p[i+j*4-3]->show();
        }
    }
    ui->menuBar->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_2->setText("倒计时");
    gamemode = 2;
    timerest = 30;
    bombva = 0;
    bombti = 0;
    maxatom = 1;
    historymax = 1;
    for(int i=1;i<=9;++i)
    {
        mi[i] = 0;
        il[i] = 1;
        totalbuy[i] = 0;
    }
    for(int i=0;i<13;++i)
    {
        atomnum[i]=0;
    }
    atomnum[1]=2;
    b1->ang=90.0;
    pop_prepare();
}

void MainWindow::playgame3()
{
    for(int i=0;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            __p[i+j*4-3]=new Pinball(i+j*4-3,this,10,960);
            __p[i+j*4-3]->mava=true;
            __p[i+j*4-3]->get_position(921+j*90,252+i*59);
            __p[i+j*4-3]->show();
        }
    }
    ui->menuBar->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label->setText("当前玩家爆弹值");
    ui->label_2->setText("当前玩家得分");
    gamemode = 3;
    bombva = 0;
    bombva1 = 0;
    bombva2 = 0;
    cscore = 0;
    score1 = 0;
    score2 = 0;
    bombti = 0;
    maxatom = 1;
    historymax = 1;
    for(int i=1;i<=9;++i)
    {
        mi[i] = 0;
        il[i] = 1;
        totalbuy[i] = 0;
    }
    for(int i=0;i<13;++i)
    {
        atomnum[i]=0;
    }
    atomnum[1]=2;
    b1->ang=90.0;
    pop_prepare();
}

void MainWindow::onTimeout1()
{
    colli_detect1();
    colli_detect2();
    colli_detect3();
    colli_detect4();
    rece_detect1();
    rece_detect2();
    for(int i=0;i<20;++i)
    {
        if(bb[i]->bava)
        {
            bb[i]->newinfo();
        }
    }
    if(b1->rece)
    {
        b1->newinfo();
    }
    end_detect();
    if(gamemode == 2 && timerest <= 0)
    {
        p1->mava = false;
        for(int i=1;i<=19;++i)
        {
            p3[i]->mava = false;
        }
        end_pop();
    }
    update();
}

void MainWindow::onTimeout2()
{
    ms50++;
    if(ms50 == 20)
    {
        ms50 = 0;
        timerest--;
    }
    ui->thistime->display(timerest);
}

void MainWindow::update_atomnum()//更新原子数目，三消
{
    for(int i=1;i<=11;++i)
    {
        int a = atomnum[i] % 3;
        int b = atomnum[i] / 3;
        atomnum[i] = a;
        atomnum[i+1] += b;
    }
}

void MainWindow::update_atomtable()//将更新的原子数目显示到表格中去
{
    ui->atomtable->setItem(0,1,new QTableWidgetItem(QString::number(atomnum[1])));
    ui->atomtable->setItem(1,1,new QTableWidgetItem(QString::number(atomnum[2])));
    ui->atomtable->setItem(2,1,new QTableWidgetItem(QString::number(atomnum[3])));
    ui->atomtable->setItem(3,1,new QTableWidgetItem(QString::number(atomnum[4])));
    ui->atomtable->setItem(0,3,new QTableWidgetItem(QString::number(atomnum[5])));
    ui->atomtable->setItem(1,3,new QTableWidgetItem(QString::number(atomnum[6])));
    ui->atomtable->setItem(2,3,new QTableWidgetItem(QString::number(atomnum[7])));
    ui->atomtable->setItem(3,3,new QTableWidgetItem(QString::number(atomnum[8])));
    ui->atomtable->setItem(0,5,new QTableWidgetItem(QString::number(atomnum[9])));
    ui->atomtable->setItem(1,5,new QTableWidgetItem(QString::number(atomnum[10])));
    ui->atomtable->setItem(2,5,new QTableWidgetItem(QString::number(atomnum[11])));
    ui->atomtable->setItem(3,5,new QTableWidgetItem(QString::number(atomnum[12])));
    bool g = true;
    for(int i = 12;i >= 1;--i)
    {
        if(atomnum[i])
        {
            maxatom = i;
            g = false;
            break;
        }
    }
    if(g)
    {
        maxatom = 0;
    }
    historymax = qMax(historymax,maxatom);
}

int MainWindow::rand_atom()
{
    int ra = qrand() % 2022;
    if(ra > 2000)
    {
        return maxatom;
    }
    if(ra % 19 == 0)
    {
        return qMin(maxatom,6);
    }
    if(ra % 17 == 0)
    {
        return qMin(maxatom,5);
    }
    if(ra % 11 == 0)
    {
        return qMin(maxatom,4);
    }
    if(ra % 5 == 0)
    {
        return qMin(maxatom,3);
    }
    if(ra % 2 == 0)
    {
        return 2;
    }
    return 1;
}//随机决定轨道上原子的种类

void MainWindow::startatom(int i, int v)
{
    p2[i]->get_speed(v,0);//获取原子速度
    p2[i]->timer.start(50);//50ms刷新一次
}

void MainWindow::startbomb(int i, int v)
{
    pb[i]->get_speed(v,0);//获取原子速度
    pb[i]->timer.start(50);//50ms刷新一次
}

void MainWindow::startbomb2(int i)
{
    pb[i]->get_speed(0,0);//获取原子速度
    pb[i]->timer.start(50);//50ms刷新一次
}

void MainWindow::pop_prepare()//发射前准备
{
    shop_display();
    p1 = new Pinball(maxatom,this,10,960);//原子的初始化
    p1->move(-100,-100);//发射时会闪现原子在初始化的可见的位置，移出去就不可见
    b1->move(440,638);//炮台初始位置
    b1->ava = true;//炮台预备发射
    b1->show();
    bombti++;
    if(bombti % 6 == 0)
    {
        addva += 100;
    }
    targetva += addva;
    if(gamemode == 3)
    {
        if(bombti%2==1)
        {
            ui->label->setText("玩家1爆弹值");
            ui->label_2->setText("玩家1得分");
            bombva = bombva1;
            cscore = score1;
        }
        else
        {
            ui->label->setText("玩家2爆弹值");
            ui->label_2->setText("玩家2得分");
            bombva = bombva2;
            cscore = score2;
        }
        ui->thistime->display(cscore);
    }
    ui->score->display(bombva);
    if(gamemode == 1)
    {
        ui->thistime->display(targetva);//LCD显示
    }
    else if(gamemode == 2)
    {
        ui->thistime->display(timerest);//LCD显示
    }
    ui->storeButton->setEnabled(true);
    int ra = qrand() % 2022;
    switch (bombti%6) {//设计了6种原子轨道模式，不断循环，也有些像黄金矿工的机制
    case 0:
        p2[4]->mava = true;
        p2[5]->mava = true;
        p2[6]->mava = true;
        p2[7]->mava = true;
        p2[8]->mava = true;
        p2[9]->mava = true;
        p2[4]->remake(rand_atom());
        p2[5]->remake(rand_atom());
        p2[6]->remake(rand_atom());
        p2[7]->remake(rand_atom());
        p2[8]->remake(rand_atom());
        p2[9]->remake(rand_atom());
        p2[4]->show();
        p2[5]->show();
        p2[6]->show();
        p2[7]->show();
        p2[8]->show();
        p2[9]->show();
        p2[4]->ax = qrand() % 410 + 40;
        p2[5]->ax = qrand() % 410 + 40;
        p2[6]->ax = qrand() % 410 + 40;
        p2[7]->ax = qrand() % 410 + 520;
        p2[8]->ax = qrand() % 410 + 520;
        p2[9]->ax = qrand() % 410 + 520;//初始化x位置
        p2[4]->ay = atomheight[ra%3];
        p2[5]->ay = atomheight[(ra+1)%3];
        p2[6]->ay = atomheight[(ra+2)%3];
        p2[7]->ay = atomheight[(ra+1)%3];
        p2[8]->ay = atomheight[(ra+2)%3];
        p2[9]->ay = atomheight[ra%3];//初始化y位置
        startatom(4,30-qrand()%60);
        startatom(5,30-qrand()%60);
        startatom(6,30-qrand()%60);
        startatom(7,30-qrand()%60);
        startatom(8,30-qrand()%60);
        startatom(9,30-qrand()%60);
        break;
    case 1:
        p2[1]->mava = true;
        p2[2]->mava = true;
        p2[1]->show();
        p2[2]->show();
        p2[1]->remake(rand_atom());
        p2[2]->remake(rand_atom());
        p2[1]->ax = qrand() % 890 + 40;
        p2[2]->ax = qrand() % 890 + 40;
        p2[1]->ay = atomheight[ra%3];
        p2[2]->ay = atomheight[(ra+1)%3];//初始化位置
        startatom(1,30-qrand()%60);
        startatom(2,30-qrand()%60);
        break;
    case 2:
        p2[4]->mava = true;
        p2[7]->mava = true;
        p2[4]->show();
        p2[7]->show();
        p2[4]->remake(rand_atom());
        p2[7]->remake(rand_atom());
        p2[4]->ax = qrand() % 410 + 40;
        p2[7]->ax = qrand() % 410 + 520;
        p2[4]->ay = atomheight[ra%3];
        p2[7]->ay = atomheight[(ra+1)%3];//初始化位置       
        startatom(4,30-qrand()%60);
        startatom(7,30-qrand()%60);
        break;
    case 3:
        p2[4]->mava = true;
        p2[7]->mava = true;
        p2[8]->mava = true;
        p2[4]->show();
        p2[7]->show();
        p2[8]->show();
        p2[4]->remake(rand_atom());
        p2[7]->remake(rand_atom());
        p2[8]->remake(rand_atom());
        p2[4]->ax = qrand() % 410 + 40;
        p2[7]->ax = qrand() % 410 + 520;
        p2[8]->ax = qrand() % 410 + 520;
        p2[4]->ay = atomheight[ra%3];
        p2[7]->ay = atomheight[(ra+1)%3];//初始化位置
        p2[8]->ay = atomheight[(ra+2)%3];
        startatom(4,30-qrand()%60);
        startatom(7,30-qrand()%60);
        startatom(8,30-qrand()%60);
        break;
    case 4:
        p2[1]->mava = true;
        p2[2]->mava = true;
        p2[3]->mava = true;
        p2[1]->show();
        p2[2]->show();
        p2[3]->show();
        p2[1]->remake(rand_atom());
        p2[2]->remake(rand_atom());
        p2[3]->remake(rand_atom());
        p2[1]->ax = qrand() % 890 + 40;
        p2[2]->ax = qrand() % 890 + 40;
        p2[3]->ax = qrand() % 890 + 40;
        p2[1]->ay = atomheight[ra%3];
        p2[2]->ay = atomheight[(ra+1)%3];//初始化位置
        p2[3]->ay = atomheight[(ra+2)%3];
        startatom(1,30-qrand()%60);
        startatom(2,30-qrand()%60);
        startatom(3,30-qrand()%60);
        break;
    case 5:
        p2[4]->mava = true;
        p2[7]->mava = true;
        p2[8]->mava = true;
        p2[1]->mava = true;
        p2[4]->show();
        p2[7]->show();
        p2[8]->show();
        p2[1]->show();
        p2[4]->remake(rand_atom());
        p2[7]->remake(rand_atom());
        p2[8]->remake(rand_atom());
        p2[1]->remake(rand_atom());
        p2[4]->ax = qrand() % 410 + 40;
        p2[7]->ax = qrand() % 410 + 520;
        p2[8]->ax = qrand() % 410 + 520;
        p2[1]->ax = qrand() % 890 + 40;
        p2[4]->ay = atomheight[ra%3];
        p2[7]->ay = atomheight[(ra+1)%3];//初始化位置
        p2[8]->ay = atomheight[ra%3];
        p2[1]->ay = atomheight[(ra+2)%3];
        startatom(4,30-qrand()%60);
        startatom(7,30-qrand()%60);
        startatom(8,30-qrand()%60);
        startatom(1,30-qrand()%60);
        break;
    default:
        break;
    }
    switch (bombti%5) {
    case 0:
        pb[1]->mava = true;
        pb[1]->show();
        pb[1]->make_bomb(qrand() % 15 + 20);
        pb[1]->ax = qrand() % 890 + 40;
        pb[1]->ay = qrand() % 250 + 230;
        pb[2]->mava = true;
        pb[2]->show();
        pb[2]->make_bomb(qrand() % 15 + 25);
        pb[2]->ax = qrand() % 890 + 40;
        pb[2]->ay = qrand() % 250 + 230;
        pb[4]->mava = true;
        pb[4]->show();
        pb[4]->make_bomb(qrand() % 15 + 20);
        pb[4]->ax = qrand() % 890 + 40;
        pb[4]->ay = qrand() % 250 + 230;
        pb[5]->mava = true;
        pb[5]->show();
        pb[5]->make_bomb(qrand() % 15 + 25);
        pb[5]->ax = qrand() % 890 + 40;
        pb[5]->ay = qrand() % 250 + 230;
        pb[3]->mava = true;
        pb[3]->show();
        pb[3]->make_bomb(qrand() % 15 + 30);
        pb[3]->ax = qrand() % 890 + 40;
        pb[3]->ay = qrand() % 250 + 230;
        startbomb(1,30-qrand()%60);
        startbomb(2,30-qrand()%60);
        startbomb2(3);
        startbomb2(4);
        startbomb2(5);
        break;
    case 1:
        break;
    case 2:
        pb[1]->mava = true;
        pb[1]->show();
        pb[1]->make_bomb(qrand() % 15 + 20);
        pb[1]->ax = qrand() % 890 + 40;
        pb[1]->ay = qrand() % 250 + 230;
        startbomb2(1);
        break;
    case 3:
        pb[1]->mava = true;
        pb[1]->show();
        pb[1]->make_bomb(qrand() % 15 + 20);
        pb[1]->ax = qrand() % 890 + 40;
        pb[1]->ay = qrand() % 250 + 230;
        pb[2]->mava = true;
        pb[2]->show();
        pb[2]->make_bomb(qrand() % 15 + 25);
        pb[2]->ax = qrand() % 890 + 40;
        pb[2]->ay = qrand() % 250 + 230;
        pb[3]->mava = true;
        pb[3]->show();
        pb[3]->make_bomb(qrand() % 15 + 30);
        pb[3]->ax = qrand() % 890 + 40;
        pb[3]->ay = qrand() % 250 + 230;
        startbomb2(1);
        startbomb2(2);
        startbomb2(3);
        break;
    case 4:
        pb[1]->mava = true;
        pb[1]->show();
        pb[1]->make_bomb(qrand() % 15 + 20);
        pb[1]->ax = qrand() % 890 + 40;
        pb[1]->ay = qrand() % 250 + 230;
        pb[2]->mava = true;
        pb[2]->show();
        pb[2]->make_bomb(qrand() % 15 + 25);
        pb[2]->ax = qrand() % 890 + 40;
        pb[2]->ay = qrand() % 250 + 230;
        startbomb(1,30-qrand()%60);
        startbomb(2,30-qrand()%60);
        break;
    default:
        break;
    }
    update_atomnum();
    update_atomtable();
    timer1.start();
    if(gamemode ==2)
    {
        timer2.start(50);
    }
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)//A键炮台左移
    {
        if(mi[5]==0)
        {
            b1->move(b1->pos().x()-15,b1->pos().y());
        }
        else if(mi[5]==1)
        {
            b1->move(b1->pos().x()-30,b1->pos().y());
        }
        else
        {
            b1->move(b1->pos().x()-45,b1->pos().y());
        }
        if(b1->pos().x()<10)//限制移动范围
        {
            b1->move(10,b1->pos().y());
        }
    }
    if(event->key()==Qt::Key_D)//D键炮台右移
    {
        if(mi[5]==0)
        {
            b1->move(b1->pos().x()+15,b1->pos().y());
        }
        else if(mi[5]==1)
        {
            b1->move(b1->pos().x()+30,b1->pos().y());
        }
        else
        {
            b1->move(b1->pos().x()+45,b1->pos().y());
        }
        if(mi[3]==0&&b1->pos().x()>880)//限制移动范围
        {
            b1->move(880,b1->pos().y());
        }
        if(mi[3]==1&&b1->pos().x()>800)
        {
            b1->move(800,b1->pos().y());
        }
        if(mi[3]==2&&b1->pos().x()>640)
        {
            b1->move(640,b1->pos().y());
        }
    }
    if(event->key()==Qt::Key_Q)//board2.cpp里面有注释
    {
        b1->ang+=4.0;
        if(b1->ang>170.0)
        {
            b1->ang=170.0;
        }
        update();
    }
    if(event->key()==Qt::Key_E)
    {
        b1->ang-=4.0;
        if(b1->ang<10.0)
        {
            b1->ang=10.0;
        }
        update();
    }
    if(event->key()==Qt::Key_Space&&b1->ava)//当可以发射原子的时候，按空格发射原子
    {
        b1->getCenter();
        p1->ax = b1->pos().x()+b1->cter.x()+32*cos(b1->ang/180*3.1415926);
        p1->ay = b1->pos().y()+b1->cter.y()+37-32*sin(b1->ang/180*3.1415926);//原子的初始位置是炮台相应顶端
        p1->get_position(p1->ax,p1->ay);
        p1->get_speed(30,b1->ang);//获取原子速度
        p1->mava = true;//发射出原子，原子可以动了
        p1->show();
        p1->timer.start(50);//50ms刷新一次
        b1->ava = false;//炮台发射过一次，不能再次发射
        atomnum[maxatom]--;
        update_atomtable();
        ui->storeButton->setDisabled(true);
        update();
    }
}

void MainWindow::shopupdate()
{
    bombva = sh->money;
    ui->score->display(bombva);
    for(int i=1;i<=9;++i)
    {
        mi[i] += sh->ava[i];
        if(sh->ava[i])
        {
            totalbuy[i]++;
        }
    }
    shop_display();
    if(totalbuy[2]>=10)
    {
        il[2]=2;
    }
    if(totalbuy[3]>=10)
    {
        il[3]=2;
    }
    if(totalbuy[4]>=10)
    {
        il[4]=2;
    }
    if(totalbuy[5]>=10)
    {
        il[5]=2;
    }
    if(totalbuy[7]>=15)
    {
        il[7]=2;
    }
    if(totalbuy[8]>=15)
    {
        il[8]=2;
    }
    if(gamemode==1&&mi[2]==1)
    {
        for(int i=1;i<=9;++i)
        {
            if(p2[i]->mava)
            {
                p2[i]->vx /= 2;
            }
            if(pb[i]->mava)
            {
                pb[i]->vx /= 2;
            }
        }
    }
    if(gamemode==1&&mi[2]==2)
    {
        for(int i=1;i<=9;++i)
        {
            if(p2[i]->mava)
            {
                p2[i]->vx = 0;
            }
            if(pb[i]->mava)
            {
                pb[i]->vx = 0;
            }
        }
    }
    if(gamemode==2&&mi[2]==1)
    {
        timerest += 15;
    }
    if(gamemode==2&&mi[2]==2)
    {
        timerest += 30;
    }
    if(mi[3]==1)
    {
        b1->resize(160,60);
        b1->ui->receive->resize(160,20);
    }
    if(mi[3]==2)
    {
        b1->resize(320,60);
        b1->ui->receive->resize(320,20);
    }
    if(mi[6])
    {
        atomnum[historymax]++;
        update_atomnum();
        update_atomtable();
        p1->remake(maxatom);
    }
    if(gamemode == 2)
    {
        timer2.start(50);
    }
    sh->hide();
}

void MainWindow::colli_detect1()//检查发射出去的原子与轨道上原子的碰撞
{
    for(int i=1;i<=9;++i)//逐个检验
    {
        if(p1->mava == true&&p2[i]->mava == true)
        {
            if(QRect(p1->pos().x(),p1->pos().y(),p1->frameSize().width(),p1->frameSize().height()).intersects(QRect(p2[i]->pos().x(),p2[i]->pos().y(),p2[i]->frameSize().width(),p2[i]->frameSize().height())))
            {
                p1->mava = false;
                p2[i]->mava = false;//消失，不可用
                timerest+=2;
                for(int j=0;j<20;++j)//爆炸效果
                {
                    if(!bb[j]->bava)
                    {
                        bb[j]->bava = true;
                        bb[j]->move(p2[i]->pos());
                        bb[j]->show();//产生爆炸效果
                        get_new_atom(i,0);//产生新原子
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::colli_detect2()//检查碰撞产生的原子与轨道上原子的碰撞，具体同上
{
    for(int i=1;i<=9;++i)
    {
        if(p2[i]->mava == false)
        {
            continue;
        }
        for(int j=1;j<=19;++j)
        {
            if(p3[j]->mava == false)
            {
                continue;
            }
            if(QRect(p2[i]->pos().x(),p2[i]->pos().y(),p2[i]->frameSize().width(),p2[i]->frameSize().height()).intersects(QRect(p3[j]->pos().x(),p3[j]->pos().y(),p3[j]->frameSize().width(),p3[j]->frameSize().height())))
            {
                p3[j]->mava = false;
                p2[i]->mava = false;
                timerest+=2;
                for(int k=0;k<20;++k)
                {
                    if(!bb[k]->bava)
                    {
                        bb[k]->bava = true;
                        bb[k]->move(p2[i]->pos());
                        bb[k]->show();
                        get_new_atom(i,j);
                        break;
                    }
                }
                break;
            }
        }
    }
}

void MainWindow::colli_detect3()//检查发射出去的原子与原子爆弹的碰撞
{
    for(int i=1;i<=9;++i)//逐个检验
    {
        if(p1->mava == true&&pb[i]->mava == true)
        {
            if(QRect(p1->pos().x(),p1->pos().y(),p1->frameSize().width(),p1->frameSize().height()).intersects(QRect(pb[i]->pos().x(),pb[i]->pos().y(),pb[i]->frameSize().width(),pb[i]->frameSize().height())))
            {
                if(gamemode != 2)
                {
                    if(mi[1]==0)
                    {
                        p1->mava = false;
                    }
                    else
                    {
                        mi[1]--;
                        shop_display();
                    }
                }
                else if(gamemode == 2)
                {
                    if(mi[1] == 0)
                    {
                        timerest -= 3;
                    }
                    else
                    {
                        mi[1]--;
                        shop_display();
                    }
                }
                pb[i]->mava = false;//消失，不可用
                if(mi[4]==0)
                {
                    bombva ++;
                    cscore ++;
                }
                else if(mi[4]==1)
                {
                    bombva += 2;
                    cscore += 2;
                }
                else
                {
                    bombva += 4;
                    cscore += 4;
                }
                ui->score->display(bombva);
                if(gamemode == 3)
                {
                    ui->thistime->display(cscore);
                }
                for(int j=0;j<20;++j)//爆炸效果
                {
                    if(!bb[j]->bava)
                    {
                        bb[j]->bava = true;
                        bb[j]->move(pb[i]->pos());
                        bb[j]->show();//产生爆炸效果
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::colli_detect4()//检查碰撞产生的原子与轨道上原子的碰撞，具体同上
{
    for(int i=1;i<=9;++i)
    {
        if(pb[i]->mava == false)
        {
            continue;
        }
        for(int j=1;j<=19;++j)
        {
            if(p3[j]->mava == false)
            {
                continue;
            }
            if(QRect(pb[i]->pos().x(),pb[i]->pos().y(),pb[i]->frameSize().width(),pb[i]->frameSize().height()).intersects(QRect(p3[j]->pos().x(),p3[j]->pos().y(),p3[j]->frameSize().width(),p3[j]->frameSize().height())))
            {
                if(gamemode != 2)
                {
                    if(mi[1]==0)
                    {
                        p3[j]->mava = false;
                    }
                    else
                    {
                        mi[1]--;
                        shop_display();
                    }
                }
                else if(gamemode == 2)
                {
                    if(mi[1] == 0)
                    {
                        timerest -= 3;
                    }
                    else
                    {
                        mi[1]--;
                        shop_display();
                    }
                }
                pb[i]->mava = false;
                if(mi[4]==0)
                {
                    bombva ++;
                    cscore ++;
                }
                else if(mi[4]==1)
                {
                    bombva += 2;
                    cscore += 2;
                }
                else
                {
                    bombva += 4;
                    cscore += 4;
                }
                ui->score->display(bombva);
                if(gamemode == 3)
                {
                    ui->thistime->display(cscore);
                }
                for(int k=0;k<20;++k)
                {
                    if(!bb[k]->bava)
                    {
                        bb[k]->bava = true;
                        bb[k]->move(pb[i]->pos());
                        bb[k]->show();
                        break;
                    }
                }
                break;
            }
        }
    }
}

int MainWindow::produce_new_atom(int i, int k)//产生新的原子，传入的i是轨道上原子的编号，用于定位，k是赋给新原子的序数，传出k
{
    for(int l=1;l<20;++l)
    {
        if(!p3[l]->mava)//一些初始化
        {
            p3[l]->mava = true;
            p3[l]->remake(k);
            p3[l]->show();
            p3[l]->ax = p2[i]->ax;
            p3[l]->ay = p2[i]->ay;
            p3[l]->get_position(p3[l]->ax,p3[l]->ay);
            if(mi[2]==0)
            {
                p3[l]->get_speed((5 + qrand() % 25) * (1 - 2 * (qrand() % 2)), 150 - qrand() % 120);
            }
            else if(mi[2]==1)
            {
                p3[l]->get_speed((5 + qrand() % 10) * (1 - 2 * (qrand() % 2)), 150 - qrand() % 120);
            }
            else
            {
                p3[l]->get_speed(5 * (1 - 2 * (qrand() % 2)), 150 - qrand() % 120);
            }
            p3[l]->timer.start(50);
            return k+1;
        }
    }
    return 1;
}

void MainWindow::get_new_atom(int i, int j)//决定产生什么新原子，i是轨道上原子的编号，j是主动碰撞的原子编号，j=0代表p1
{
    if(j == 0)
    {
        int add = p1->kind * p2[i]->kind;//爆弹值的增量
        if(p1->kind+p2[i]->kind < 4)//原子序数和小于4，只生成一个原子
        {
            add *= produce_new_atom(i,p1->kind + p2[i]->kind);
        }
        else
        {   if(mi[8]==0)
            {
                int tmp = qrand() % 7;
                if(tmp < 3)//生成两个原子
                {
                    add *= produce_new_atom(i,(p1->kind + p2[i]->kind) / 2);
                    add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2);
                }
                else if(tmp < 5)//生成两个原子，序数与前种不同
                {
                    add *= produce_new_atom(i, (p1->kind + p2[i]->kind) / 2 - 1);
                    add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2 + 1);
                }
                else//生成三个原子
                {
                    add *= produce_new_atom(i, (p1->kind + p2[i]->kind) / 2);
                    add *= produce_new_atom(i,(p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2) / 2);
                    add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2 - (p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2) / 2);
                }
            }
            else if(mi[8]==1)
            {
                int tmp = qrand() % 7;
                if(tmp < 3)//生成两个原子
                {
                    add *= produce_new_atom(i,qMax((p1->kind + p2[i]->kind) / 2 - 2,1));
                    add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2 + 2);
                }
                else if(tmp < 6)//生成两个原子，序数与前种不同
                {
                    add *= produce_new_atom(i, qMax((p1->kind + p2[i]->kind) / 2 - 3,1));
                    add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2 + 3);
                }
                else//生成三个原子
                {
                    add *= produce_new_atom(i, (p1->kind + p2[i]->kind) / 2);
                    add *= produce_new_atom(i,(p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2) / 2);
                    add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2 - (p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2) / 2);
                }
            }
            else
            {
                int tmp = qrand() % 7;
                if(tmp < 4)//生成两个原子
                {
                    add *= produce_new_atom(i,1);
                    add *= produce_new_atom(i, qMin(p1->kind + p2[i]->kind - 1,10));
                }
                else//生成三个原子
                {
                    add *= produce_new_atom(i, 1);
                    add *= produce_new_atom(i, 1);
                    add *= produce_new_atom(i, qMin(p1->kind + p2[i]->kind - 2,10));
                }
            }
        }
        if(mi[4]==0)
        {
            bombva += add;
            cscore += add;
        }
        else if(mi[4]==1)
        {
            bombva += add*2;
            cscore += add*2;
        }
        else
        {
            bombva += add*4;
            cscore += add*4;
        }
        ui->score->display(bombva);//增加爆弹值，刷新LCD
        if(gamemode == 3)
        {
            ui->thistime->display(cscore);
        }
    }
    else//同上
    {
        int add = p2[i]->kind * p3[j]->kind;
        if(p3[j]->kind+p2[i]->kind < 4)
        {
            add *= produce_new_atom(i,p3[j]->kind + p2[i]->kind);
        }
        else
        {
            int tmp = qrand() % 7;
            if(tmp < 3)
            {
                add *= produce_new_atom(i,(p3[j]->kind + p2[i]->kind) / 2);
                add *= produce_new_atom(i, p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2);
            }
            else if(tmp < 5)
            {
                add *= produce_new_atom(i, (p3[j]->kind + p2[i]->kind) / 2 + 1);
                add *= produce_new_atom(i, p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2 - 1);
            }
            else
            {
                add *= produce_new_atom(i, (p3[j]->kind + p2[i]->kind) / 2);
                add *= produce_new_atom(i,(p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2) / 2);
                add *= produce_new_atom(i, p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2 - (p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2) / 2);
            }
        }
        if(mi[4]==0)
        {
            bombva += add;
            cscore += add;
        }
        else if(mi[4]==1)
        {
            bombva += add*2;
            cscore += add*2;
        }
        else
        {
            bombva += add*4;
            cscore += add*4;
        }
        ui->score->display(bombva);//增加爆弹值，刷新LCD
        if(gamemode == 3)
        {
            ui->thistime->display(cscore);
        }
    }
}

void MainWindow::end_pop()
{
    update_atomnum();
    update_atomtable();
    for(int i=1;i<=9;++i)
    {
        p2[i]->mava = false;
    }

    for(int i=0;i<=9;++i)
    {
        pb[i]->mava = false;
    }
    for(int i=2;i<=6;++i)
    {
        mi[i] = 0;
    }
    mi[8]=0;
    b1->resize(80,60);
    b1->ui->receive->resize(80,20);
    if(gamemode == 3)
    {
        if(bombti%2==1)
        {
            score1 = cscore;
            bombva1 = bombva;
        }
        else
        {
            score2 = cscore;
            bombva2 = bombva;
        }
    }
    int st = 0;
    if(maxatom == 0)
    {
        if(mi[7]==0)
        {
            st = 1;
            if(gamemode == 3)
            {
                if(bombti%2==1)
                {
                    score1=bombva1=0;
                    judge();
                }
                else
                {
                    score2=bombva2=0;
                    judge();
                }
            }
            else
            {
                gameover();
            }
        }
        else if(mi[7]==1)
        {
            for(int i=1;i<=12;++i)
            {
                atomnum[i]=0;
            }
            atomnum[1]=atomnum[2]=2;
            mi[7]=0;
            update_atomnum();
            update_atomtable();
        }
        else
        {
            for(int i=1;i<=12;++i)
            {
                atomnum[i]=0;
            }
            atomnum[1]=atomnum[2]=atomnum[3]=atomnum[4]=2;
            mi[7]=0;
            update_atomnum();
            update_atomtable();
        }
    }
    if(bombva < targetva && gamemode == 1)
    {
        if(mi[7]==0)
        {
            st = 1;
            gameover();
        }
        else if(mi[7]==1)
        {
            bombva = targetva + addva + 100;
            mi[7]=0;
            update_atomnum();
            update_atomtable();
        }
        else
        {
            bombva = targetva + addva + 1100;
            mi[7]=0;
            update_atomnum();
            update_atomtable();
        }
    }
    if(timerest <= 0 && gamemode == 2)
    {
        if(mi[7]==0)
        {
            st = 1;
            gameover();
        }
        else if(mi[7]==1)
        {
            mi[7]=0;
            timerest = 15;
        }
        else
        {
            mi[7]=0;
            timerest = 30;
        }
    }
    if(gamemode==1&&maxatom == 12)
    {
        st = 1;
        win(-1);
    }
    if(st == 0)
    {

        mi[7]=0;
        if(gamemode == 3 && bombti == 30)
        {
            judge();
        }
        else
        {
            delete p1;
            pop_prepare();
        }
    }
}

void MainWindow::rece_detect1()//检测p1的接收情况
{
    if(p1->mava&&QRect(b1->pos().x(),b1->pos().y()+40,b1->ui->receive->frameSize().width(),b1->ui->receive->frameSize().height()).intersects(QRect(p1->pos().x(),p1->pos().y(),p1->frameSize().width(),p1->frameSize().height())))
    {
        int lhj;
        if(mi[4]==0)
        {
            lhj=1;
        }
        else if(mi[4]==1)
        {
            lhj=2;
        }
        else
        {
            lhj=4;
        }
        p1->rece = true;//用于计数原子
        b1->rece = true;//用于产生接收的黄光效果
        p1->mava = false;//设置原子为不可用
        atomnum[p1->kind]++;
        update_atomtable();
        bombva += 100 * lhj * p1->kind;
        cscore += 100 * lhj * p1->kind;
        if(bombti < 4&&gamemode!=3)//新手奖励，在前三局接到每个球，分别奖励300,200,100爆弹值
        {
            bombva += (400 - 100 * bombti) * lhj;
            cscore += (400 - 100 * bombti) * lhj;
        }
        timerest += p1->kind;
        ui->score->display(bombva);//收到原子得到爆弹值是原子序数的100倍;
        if(gamemode == 3)
        {
            ui->thistime->display(cscore);
        }
    }
}

void MainWindow::rece_detect2()//检测p3系列的接收情况
{
    for(int i=1;i<=19;++i)
    {
        if(!p3[i]->mava)
        {
            continue;
        }
        if(QRect(b1->pos().x(),b1->pos().y()+40,b1->ui->receive->frameSize().width(),b1->ui->receive->frameSize().height()).intersects(QRect(p3[i]->pos().x(),p3[i]->pos().y(),p3[i]->frameSize().width(),p3[i]->frameSize().height())))
        {
            int lhj;
            if(mi[4]==0)
            {
                lhj=1;
            }
            else if(mi[4]==1)
            {
                lhj=2;
            }
            else
            {
                lhj=4;
            }
            p3[i]->rece = true;
            b1->rece = true;
            p3[i]->mava = false;
            atomnum[p3[i]->kind]++;
            update_atomtable();
            bombva += 100 * lhj * p3[i]->kind;
            cscore += 100 * lhj * p3[i]->kind;
            if(bombti < 4&&gamemode!=3)//新手奖励，在前三局接到每个球，分别奖励300,200,100爆弹值
            {
                bombva += (400 - 100 * bombti) * lhj;
                cscore += (400 - 100 * bombti) * lhj;
            }
            timerest += p3[i]->kind;
            ui->score->display(bombva);
            if(gamemode == 3)
            {
                ui->thistime->display(cscore);
            }
        }
    }
}

void MainWindow::end_detect()//检测本次发射产生的效果是否结束
{
    if(p1->mava)
    {
        return;
    }
    for(int i=1;i<=19;++i)
    {
        if(p3[i]->mava)
        {
            return;
        }
    }
    if(!b1->ava)
    {
        end_pop();
    }
}

void MainWindow::win(int k)
{
    b1->move(-100,-100);
    ui->__win->show();
    if(gamemode==1)
    {
        ui->__win__->setText("You Win!");
    }
    else
    {
        switch(k)
        {
        case 1:
            ui->__win__->setText("玩家1获胜");
            break;
        case 2:
            ui->__win__->setText("玩家2获胜");
            break;
        case 0:
            ui->__win__->setText(" 平  局 ");
            break;
        }
    }
    ui->__win__->show();
    switch(gamemode)
    {
    case 1:
            ui->__again_1->show();
            break;
    case 3:
            ui->__again_3->show();
            break;
    }
    ui->__re->show();
}

void MainWindow::gameover()//失败的效果展示
{
    int hh[4]={
        148,278,408,538
    };
    int ww[5]={
        153,303,453,603,753
    };
    if(gamemode == 2)
    {
        timer2.stop();
    }
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<5;++j)
        {
            bb[5*i+j]->bava = true;
            bb[5*i+j]->move(ww[j],hh[i]);
            bb[5*i+j]->show();
        }
    }
    b1->move(-100,-100);
    switch(gamemode)
    {
    case 1:
            ui->__again_1->show();
            break;
    case 2:
            ui->__again_2->show();
            break;
    case 3:
            ui->__again_3->show();
            break;
    }
    ui->__re->show();
}

void MainWindow::judge()
{
    ui->score->display(score1);
    ui->thistime->display(score2);
    ui->label->setText("玩家1最终得分");
    ui->label_2->setText("玩家2最终得分");
    if(score1>score2)
    {
        win(1);
        //玩家1获胜界面
    }
    else if(score2>score1)
    {
        win(2);
        //玩家2获胜界面
    }
    else
    {
        win(0);
        //平局界面
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_storeButton_clicked()
{
    sh->money = bombva;
    sh->ui->rest->setText(QString::number(sh->money));
    for(int i=1;i<=9;++i)
    {
        sh->level[i] = il[i];
        sh->ava[i] = 0;
    }
    int lhj,whf;
    if(mi[9]==0)
    {
        lhj = 10;
        whf = 2;
    }
    else if(mi[9]==1)
    {
        lhj = 9;
        whf = 2;
    }
    else if(mi[9]==2)
    {
        lhj = 7;
        whf = 3;
    }
    else
    {
        lhj = 5;
        whf = 4;
    }
    for(int i=1;i<=8;++i)
    {
        if(qrand() % whf == 0)
        {
            sh->pri[i] = bombva+1;
        }
        else if(qrand() % 3 == 0)
        {
            sh->pri[i] = lhj * (qrand() % 300 + 1) / 10;
        }
        else
        {
            sh->pri[i] = lhj * (qrand() % 300 + 301) / 10;
        }
    }
    if(mi[9]==0)
    {
        sh->pri[9] = 1000;
    }
    else if(mi[9]==1)
    {
        sh->pri[9] = 2000;
    }
    else if(mi[9]==2)
    {
        sh->pri[9] = 3000;
    }
    else
    {
        sh->pri[9] = bombva + 1;
    }
    sh->pri[10] = lhj * (qrand() % 600 + 1) / 10;
    sh->ui->pr1->setText(QString::number(sh->pri[1]));
    sh->ui->pr2->setText(QString::number(sh->pri[2]));
    sh->ui->pr3->setText(QString::number(sh->pri[3]));
    sh->ui->pr4->setText(QString::number(sh->pri[4]));
    sh->ui->pr5->setText(QString::number(sh->pri[5]));
    sh->ui->pr6->setText(QString::number(sh->pri[6]));
    sh->ui->pr7->setText(QString::number(sh->pri[7]));
    sh->ui->pr8->setText(QString::number(sh->pri[8]));
    sh->ui->pr9->setText(QString::number(sh->pri[9]));
    sh->ui->prran->setText(QString::number(sh->pri[10]));
    sh->ui->buy1->setEnabled(true);
    sh->ui->buy2->setEnabled(true);
    sh->ui->buy3->setEnabled(true);
    sh->ui->buy4->setEnabled(true);
    sh->ui->buy5->setEnabled(true);
    sh->ui->buy6->setEnabled(true);
    sh->ui->buy7->setEnabled(true);
    sh->ui->buy8->setEnabled(true);
    sh->ui->buy9->setEnabled(true);
    if(mi[9]==3)
    {
        sh->ui->buy9->setDisabled(true);
    }
    sh->ui->buyrandom->setEnabled(true);
    ui->storeButton->setDisabled(true);
    if(gamemode == 2)
    {
        timer2.stop();
    }
    sh->show();
    if(gamemode!=2)
    {
        sh->ui->pic2_2->hide();
        sh->ui->pic2->show();
    }
    else
    {
        sh->ui->pic2->hide();
        sh->ui->pic2_2->show();
    }
}

void MainWindow::shop_display()
{
    if(mi[1])
    {
        ui->__label_1_0->hide();
        ui->__label_1->show();
        ui->__num_1->show();
        ui->__num_1->setText(QString::number(mi[1]));
    }
    else
    {
        ui->__label_1->hide();
        ui->__num_1->hide();
        ui->__label_1_0->show();
    }

    if(mi[2])
    {
        if(gamemode!=2)
        {
            ui->__label_2___2->hide();
            ui->__label_2_0_2->hide();
            ui->__label_2_0->hide();
            ui->__label_2->show();
        }
        else
        {
            ui->__label_2->hide();
            ui->__label_2_0->hide();
            ui->__label_2_0_2->hide();
            ui->__label_2___2->show();
        }
        ui->__num_2->show();
        ui->__num_2->setText(QString::number(mi[2]));
    }
    else
    {
        ui->__num_2->hide();
        if(gamemode!=2)
        {
            ui->__label_2___2->hide();
            ui->__label_2_0_2->hide();
            ui->__label_2->hide();
            ui->__label_2_0->show();
        }
        else
        {
            ui->__label_2->hide();
            ui->__label_2_0->hide();
            ui->__label_2___2->hide();
            ui->__label_2_0_2->show();
        }
    }

    if(mi[3])
    {
        ui->__label_3_0->hide();
        ui->__label_3->show();
        ui->__num_3->show();
        ui->__num_3->setText(QString::number(mi[3]));
    }
    else
    {
        ui->__label_3->hide();
        ui->__num_3->hide();
        ui->__label_3_0->show();
    }

    if(mi[4])
    {
        ui->__label_4_0->hide();
        ui->__label_4->show();
        ui->__num_4->show();
        ui->__num_4->setText(QString::number(mi[4]));
    }
    else
    {
        ui->__label_4->hide();
        ui->__num_4->hide();
        ui->__label_4_0->show();
    }

    if(mi[5])
    {
        ui->__label_5_0->hide();
        ui->__label_5->show();
        ui->__num_5->show();
        ui->__num_5->setText(QString::number(mi[5]));
    }
    else
    {
        ui->__label_5->hide();
        ui->__num_5->hide();
        ui->__label_5_0->show();
    }

    if(mi[6])
    {
        ui->__label_6_0->hide();
        ui->__label_6->show();
        ui->__num_6->show();
        ui->__num_6->setText(QString::number(mi[6]));
    }
    else
    {
        ui->__label_6->hide();
        ui->__num_6->hide();
        ui->__label_6_0->show();
    }

    if(mi[7])
    {
        ui->__label_7_0->hide();
        ui->__label_7->show();
        ui->__num_7->show();
        ui->__num_7->setText(QString::number(mi[7]));
    }
    else
    {
        ui->__label_7->hide();
        ui->__num_7->hide();
        ui->__label_7_0->show();
    }

    if(mi[8])
    {
        ui->__label_8_0->hide();
        ui->__label_8->show();
        ui->__num_8->show();
        ui->__num_8->setText(QString::number(mi[8]));
    }
    else
    {
        ui->__label_8->hide();
        ui->__num_8->hide();
        ui->__label_8_0->show();
    }

    if(mi[9])
    {
        ui->__label_9_0->hide();
        ui->__label_9->show();
        ui->__num_9->show();
        ui->__num_9->setText(QString::number(mi[9]));
    }
    else
    {
        ui->__label_9->hide();
        ui->__num_9->hide();
        ui->__label_9_0->show();
    }
}

void MainWindow::on___button_1_clicked()
{
    ui->__button_1->hide();
    ui->__button_2->hide();
    ui->__button_3->hide();
    ui->__button_5->hide();
    ui->__button_6->show();
    ui->__button_7->show();
    ui->__button_8->show();
    ui->__button_9->show();
}

void MainWindow::on___button_2_clicked()
{
    hp->move(this->x()+80,this->y()+100);
    hp->show();
}

void MainWindow::on___button_3_clicked()
{
    int tmp1=qrand()%2;
    if(tmp1)
    {
        am->cnt_gamemode1=1+qrand()%9;
    }
    else
    {
        am->cnt_gamemode1=10+qrand()%120;
    }
    int tmp2=qrand()%2;
    if(tmp2)
    {
        am->cnt_gamemode2=1+qrand()%9;
    }
    else
    {
        am->cnt_gamemode2=10+qrand()%120;
    }
    int tmp3=qrand()%2;
    if(tmp3)
    {
        am->cnt_gamemode3=1+qrand()%9;
    }
    else
    {
        am->cnt_gamemode3=10+qrand()%120;
    }
    int tmp4=qrand()%2;
    if(tmp4)
    {
        am->cnt_win=qrand()%10;
    }
    else
    {
        am->cnt_win=10+qrand()%120;
    }
    if(am->cnt_win>am->cnt_gamemode1)
    {
        am->cnt_win=am->cnt_gamemode1;
    }
    am->move(this->x()+80,this->y()+100);
    am->show();
    am->achievementsupdate();
}

void MainWindow::on___button_5_clicked()
{
    qApp->quit();
}

void MainWindow::on___button_6_clicked()
{
    ui->__button_6->hide();
    ui->__button_7->hide();
    ui->__button_8->hide();
    ui->__button_9->hide();
    ui->__background->hide();
    playgame1();
}

void MainWindow::on___button_7_clicked()
{
    ui->__button_6->hide();
    ui->__button_7->hide();
    ui->__button_8->hide();
    ui->__button_9->hide();
    ui->__background->hide();
    playgame2();
}

void MainWindow::on___button_8_clicked()
{
    ui->__button_6->hide();
    ui->__button_7->hide();
    ui->__button_8->hide();
    ui->__button_9->hide();
    ui->__background->hide();
    playgame3();
}

void MainWindow::on___button_9_clicked()
{
    ui->__button_6->hide();
    ui->__button_7->hide();
    ui->__button_8->hide();
    ui->__button_9->hide();
    ui->__button_1->show();
    ui->__button_2->show();
    ui->__button_3->show();
    ui->__button_5->show();
}

void MainWindow::on___re_clicked()
{
    qApp->exit(MainWindow::EXITCODE);
}

void MainWindow::on___again_1_clicked()
{
    ui->__again_1->hide();
    ui->__re->hide();
    ui->__win->hide();
    ui->__win__->hide();
    playgame1();
}

void MainWindow::on___again_2_clicked()
{
    ui->__again_2->hide();
    ui->__re->hide();
    playgame2();
}

void MainWindow::on___again_3_clicked()
{
    ui->__again_3->hide();
    ui->__re->hide();
    ui->__win->hide();
    ui->__win__->hide();
    playgame3();
}

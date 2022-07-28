#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board2.h"
#include "pinball.h"
#include "bomb.h"
#include "shop.h"
#include "help.h"
#include "achievements.h"
#include <QFrame>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void playgame1();
    void playgame2();
    void playgame3();
    void keyPressEvent(QKeyEvent *);
    int rand_atom();
    void pop_prepare();
    void colli_detect1();
    void colli_detect2();
    void colli_detect3();
    void colli_detect4();
    void get_new_atom(int,int);
    int produce_new_atom(int,int);
    void rece_detect1();
    void rece_detect2();
    void end_detect();
    void end_pop();
    void gameover();
    void win(int);
    void update_atomnum();
    void update_atomtable();
    void startatom(int,int);
    void startbomb(int,int);
    void startbomb2(int);
    void shop_display();
    void judge();

private slots:
    void onTimeout1(void);
    void onTimeout2(void);
    void shopupdate(void);

    void on_storeButton_clicked();

    void on___button_1_clicked();

    void on___button_2_clicked();

    void on___button_3_clicked();

    void on___button_5_clicked();

    void on___button_6_clicked();

    void on___button_7_clicked();

    void on___button_8_clicked();

    void on___button_9_clicked();

    void on___re_clicked();

    void on___again_1_clicked();

    void on___again_2_clicked();

    void on___again_3_clicked();

public:
    QTimer timer1;
    QTimer timer2;
    static int const EXITCODE;

private:
    Ui::MainWindow *ui;
    Board2 *b1 = nullptr;
    Pinball *p1 = nullptr;//发射出的原子
    Pinball *p2[10];//界面上的原子
    Pinball *p3[20];//通过碰撞产生的原子
    Pinball *pb[10];//原子爆弹
    Pinball *__p[13];//右侧的样例原子
    Bomb *bb[20];
    Shop *sh;
    Help *hp;
    Achievements *am;
    int bombva;//爆弹值
    int bombva1;
    int bombva2;
    int cscore;
    int score1;
    int score2;
    int bombti;//次数
    int maxatom;//目前所获得的最大原子
    int historymax;
    int atomnum[13];//各种原子的数量
    int mi[10];//表示持有道具的等级或数目
    int il[10];//表示道具的等级
    int totalbuy[10];
    int np3;
    int targetva;
    int addva;
    int gamemode;
    int timerest;
    int ms50;
};

#endif // MAINWINDOW_H

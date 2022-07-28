#ifndef PINBALL_H
#define PINBALL_H

#include <QFrame>
#include <QPainter>
#include <QTimer>

namespace Ui {
class Pinball;
}

class Pinball : public QFrame
{
    Q_OBJECT
private:
    void paintEvent(QPaintEvent *);
private slots:
    void onTimeout(void);
public:
    QColor col;//颜色
    int kind;//种类
    int left;
    int right;
    double vx;//x方向速度
    double vy;//y方向速度
    double ax;//精确的x位置
    double ay;//精确的y位置，它们不断刷新
    bool mava;//原子是否移动和显示
    bool rece;//原子是否被回收
    QTimer timer;//计时器
public:
    explicit Pinball(int k = 1, QWidget *parent = 0,int L = 10,int R = 960);
    ~Pinball();
    void get_speed(int,double);//获取初始速度
    void get_position(double,double);//改变原子位置
    void remake(int);
    void make_bomb(int);

private:
    Ui::Pinball *ui;
};

#endif // PINBALL_H

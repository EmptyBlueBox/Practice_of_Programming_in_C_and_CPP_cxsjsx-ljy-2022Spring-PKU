#ifndef BOARD2_H
#define BOARD2_H

#include <QFrame>
#include <QPainter>
#include <QKeyEvent>

namespace Ui {
class Board2;
}

class Board2 : public QFrame
{
    Q_OBJECT
private:
    void paintEvent(QPaintEvent *);  

public:
    explicit Board2(QWidget *parent = 0);
    ~Board2();
    void keyPressEvent(QKeyEvent *);
    void getCenter();//得到下面那块板的中心坐标
    void newinfo();//更新信息
    double ang;//发射角度
    bool ava;//炮台的状态，可以发射为true，只能接收为false
    bool rece;//是否接收到原子的状态
    int val;//间隔,同bomb
    QPoint cter;//下面那块板的中心
public:
    Ui::Board2 *ui;
};

#endif // BOARD2_H

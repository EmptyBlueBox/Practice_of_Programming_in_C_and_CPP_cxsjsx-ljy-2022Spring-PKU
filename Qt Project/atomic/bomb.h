#ifndef BOMB_H
#define BOMB_H

#include <QFrame>
#include <QPixmap>
#include <QPainter>
#include <QVector>

namespace Ui {
class Bomb;
}

class Bomb : public QFrame
{
    Q_OBJECT
private:
    void paintEvent(QPaintEvent *);

public:
    explicit Bomb(QWidget *parent = 0);
    ~Bomb();
    void newinfo();//更新图片信息

public:
    QVector<QPixmap> pixarr;//存储爆炸图片
    bool bava;//是否爆炸
    int picindex;//图片编号
    int val;

private:
    Ui::Bomb *ui;
};

#endif // BOMB_H

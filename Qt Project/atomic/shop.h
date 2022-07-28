#ifndef SHOP_H
#define SHOP_H

#include <QDialog>
#include "nomoney.h"

namespace Ui {
class Shop;
}

class Shop : public QDialog
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent = 0);
    ~Shop();

private slots:
    void on_end_button_clicked();

    void on_buy1_clicked();

    void on_buy2_clicked();

    void on_buy3_clicked();

    void on_buy4_clicked();

    void on_buy5_clicked();

    void on_buy6_clicked();

    void on_buy7_clicked();

    void on_buy8_clicked();

    void on_buy9_clicked();

    void on_buyrandom_clicked();

public:
    Ui::Shop *ui;

public:
    int money;
    int pri[11];
    int level[11];
    int ava[11];
    Nomoney *dia;
};

#endif // SHOP_H

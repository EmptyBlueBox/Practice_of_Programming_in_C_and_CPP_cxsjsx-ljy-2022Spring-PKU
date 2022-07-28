#include "shop.h"
#include "ui_shop.h"
#include "nomoney.h"
#include "ui_nomoney.h"

Shop::Shop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint);
    money=0;
    for(int i=0;i<=10;++i)
    {
        pri[i]=0;
        level[i]=1;
        ava[i]=0;
    }
    dia = new Nomoney(this);
}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_end_button_clicked()
{
    this->hide();
}

void Shop::on_buy1_clicked()
{
    if(money < pri[1])
    {
        dia->show();
    }
    else
    {
        money -= pri[1];
        ava[1] = level[1];
        ui->buy1->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buy2_clicked()
{
    if(money < pri[2])
    {
        dia->show();
    }
    else
    {
        money -= pri[2];
        ava[2] = level[2];
        ui->buy2->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buy3_clicked()
{
    if(money < pri[3])
    {
        dia->show();
    }
    else
    {
        money -= pri[3];
        ava[3] = level[3];
        ui->buy3->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buy4_clicked()
{
    if(money < pri[4])
    {
        dia->show();
    }
    else
    {
        money -= pri[4];
        ava[4] = level[4];
        ui->buy4->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buy5_clicked()
{
    if(money < pri[5])
    {
        dia->show();
    }
    else
    {
        money -= pri[5];
        ava[5] = level[5];
        ui->buy5->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buy6_clicked()
{
    if(money < pri[6])
    {
        dia->show();
    }
    else
    {
        money -= pri[6];
        ava[6] = level[6];
        ui->buy6->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buy7_clicked()
{
    if(money < pri[7])
    {
        dia->show();
    }
    else
    {
        money -= pri[7];
        ava[7] = level[7];
        ui->buy7->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buy8_clicked()
{
    if(money < pri[8])
    {
        dia->show();
    }
    else
    {
        money -= pri[8];
        ava[8] = level[8];
        ui->buy8->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buy9_clicked()
{
    if(money < pri[9])
    {
        dia->show();
    }
    else
    {
        money -= pri[9];
        ava[9] = level[9];
        ui->buy9->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}

void Shop::on_buyrandom_clicked()
{
    if(money < pri[10])
    {
        dia->show();
    }
    else
    {
        money -= pri[10];
        int tmp = qrand() % 8 + 1;
        ava[tmp] = level[tmp];
        ui->buyrandom->setDisabled(true);
        ui->rest->setText(QString::number(money));
    }
}


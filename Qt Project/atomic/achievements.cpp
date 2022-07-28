#include "achievements.h"
#include "ui_achievements.h"

Achievements::Achievements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Achievements)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint);
}

Achievements::~Achievements()
{
    delete ui;
}

void Achievements::on___ach_1_clicked()
{
    this->hide();
}

void Achievements::achievementsupdate()
{
    if(cnt_gamemode1<1)
    {
        ui->__ach_1_1->hide();
        ui->__ach_1_4->hide();
        ui->__ach_1_7->hide();
        ui->__ach_2_1->show();
        ui->__ach_2_4->show();
        ui->__ach_2_7->show();
    }
    else if(cnt_gamemode1<10)
    {
        ui->__ach_2_1->hide();
        ui->__ach_1_4->hide();
        ui->__ach_1_7->hide();
        ui->__ach_1_1->show();
        ui->__ach_2_4->show();
        ui->__ach_2_7->show();
    }
    else if(cnt_gamemode1<100)
    {
        ui->__ach_2_1->hide();
        ui->__ach_2_4->hide();
        ui->__ach_1_7->hide();
        ui->__ach_1_1->show();
        ui->__ach_1_4->show();
        ui->__ach_2_7->show();
    }
    else
    {
        ui->__ach_2_1->hide();
        ui->__ach_2_4->hide();
        ui->__ach_2_7->hide();
        ui->__ach_1_1->show();
        ui->__ach_1_4->show();
        ui->__ach_1_7->show();
    }
    if(cnt_gamemode2<1)
    {
        ui->__ach_1_2->hide();
        ui->__ach_1_5->hide();
        ui->__ach_1_8->hide();
        ui->__ach_2_2->show();
        ui->__ach_2_5->show();
        ui->__ach_2_8->show();
    }
    else if(cnt_gamemode2<10)
    {
        ui->__ach_2_2->hide();
        ui->__ach_1_5->hide();
        ui->__ach_1_8->hide();
        ui->__ach_1_2->show();
        ui->__ach_2_5->show();
        ui->__ach_2_8->show();
    }
    else if(cnt_gamemode2<100)
    {
        ui->__ach_2_2->hide();
        ui->__ach_2_5->hide();
        ui->__ach_1_8->hide();
        ui->__ach_1_2->show();
        ui->__ach_1_5->show();
        ui->__ach_2_8->show();
    }
    else
    {
        ui->__ach_2_2->hide();
        ui->__ach_2_5->hide();
        ui->__ach_2_8->hide();
        ui->__ach_1_2->show();
        ui->__ach_1_5->show();
        ui->__ach_1_8->show();
    }
    if(cnt_gamemode3<1)
    {
        ui->__ach_1_3->hide();
        ui->__ach_1_6->hide();
        ui->__ach_1_9->hide();
        ui->__ach_2_3->show();
        ui->__ach_2_6->show();
        ui->__ach_2_9->show();
    }
    else if(cnt_gamemode3<10)
    {
        ui->__ach_2_3->hide();
        ui->__ach_1_6->hide();
        ui->__ach_1_9->hide();
        ui->__ach_1_3->show();
        ui->__ach_2_6->show();
        ui->__ach_2_9->show();
    }
    else if(cnt_gamemode3<100)
    {
        ui->__ach_2_3->hide();
        ui->__ach_2_6->hide();
        ui->__ach_1_9->hide();
        ui->__ach_1_3->show();
        ui->__ach_1_6->show();
        ui->__ach_2_9->show();
    }
    else
    {
        ui->__ach_2_3->hide();
        ui->__ach_2_6->hide();
        ui->__ach_2_9->hide();
        ui->__ach_1_3->show();
        ui->__ach_1_6->show();
        ui->__ach_1_9->show();
    }
    if(cnt_win<1)
    {
        ui->__ach_1_10->hide();
        ui->__ach_1_11->hide();
        ui->__ach_1_12->hide();
        ui->__ach_2_10->show();
        ui->__ach_2_11->show();
        ui->__ach_2_12->show();
    }
    else if(cnt_win<10)
    {
        ui->__ach_2_10->hide();
        ui->__ach_1_11->hide();
        ui->__ach_1_12->hide();
        ui->__ach_1_10->show();
        ui->__ach_2_11->show();
        ui->__ach_2_12->show();
    }
    else if(cnt_win<100)
    {
        ui->__ach_2_10->hide();
        ui->__ach_2_11->hide();
        ui->__ach_1_12->hide();
        ui->__ach_1_10->show();
        ui->__ach_1_11->show();
        ui->__ach_2_12->show();
    }
    else
    {
        ui->__ach_2_10->hide();
        ui->__ach_2_11->hide();
        ui->__ach_2_12->hide();
        ui->__ach_1_10->show();
        ui->__ach_1_11->show();
        ui->__ach_1_12->show();
    }
}

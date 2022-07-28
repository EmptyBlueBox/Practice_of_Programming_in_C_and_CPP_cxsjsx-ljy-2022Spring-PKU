#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint);
    ui->__help_1->show();
    ui->__help_2->show();
    ui->__help_3->show();
    ui->__help_4->show();
    ui->__help_5->show();
    ui->__right->hide();
    ui->__left->hide();
    ui->__back->hide();
    ui->__h_1_1->hide();
    ui->__h_1_2->hide();
    ui->__h_1_3->hide();
    ui->__h_1_4->hide();
    ui->__h_1_5->hide();
    ui->__h_1_6->hide();
    ui->__h_1_7->hide();
    ui->__h_1_8->hide();
    ui->__h_2_1->hide();
    ui->__h_3_1->hide();
    ui->__h_4_1->hide();
    ui->__h_4_2->hide();
    ui->__h_4_3->hide();
    ui->__h_4_4->hide();
    ui->__h_4_5->hide();
    ui->__h_4_6->hide();
    ui->__h_4_7->hide();
    ui->__h_4_8->hide();
    ui->__h_4_9->hide();
    ui->__h_4_10->hide();
    ui->__h_4_11->hide();
    ui->__h_4_12->hide();
    choice=0;
    now1=0;
    now2=0;
    now3=0;
    now4=0;
}

Help::~Help()
{
    delete ui;
}

void Help::on___help_1_clicked()
{
    ui->__help_1->hide();
    ui->__help_2->hide();
    ui->__help_3->hide();
    ui->__help_4->hide();
    ui->__help_5->hide();
    ui->__right->show();
    ui->__left->show();
    ui->__back->show();
    choice=1;
    now1=1;
    display_1();
}

void Help::display_1()
{
    switch(now1){
    case 1:
        ui->__h_1_2->hide();
        ui->__h_1_1->show();
        break;
    case 2:
        ui->__h_1_1->hide();
        ui->__h_1_3->hide();
        ui->__h_1_2->show();
        break;
    case 3:
        ui->__h_1_2->hide();
        ui->__h_1_4->hide();
        ui->__h_1_3->show();
        break;
    case 4:
        ui->__h_1_3->hide();
        ui->__h_1_5->hide();
        ui->__h_1_4->show();
        break;
    case 5:
        ui->__h_1_4->hide();
        ui->__h_1_6->hide();
        ui->__h_1_5->show();
        break;
    case 6:
        ui->__h_1_5->hide();
        ui->__h_1_7->hide();
        ui->__h_1_6->show();
        break;
    case 7:
        ui->__h_1_6->hide();
        ui->__h_1_8->hide();
        ui->__h_1_7->show();
        break;
    case 8:
        ui->__h_1_7->hide();
        ui->__h_1_8->show();
        break;
    }
}

void Help::on___help_2_clicked()
{
    ui->__help_1->hide();
    ui->__help_2->hide();
    ui->__help_3->hide();
    ui->__help_4->hide();
    ui->__help_5->hide();
    ui->__right->show();
    ui->__left->show();
    ui->__back->show();
    choice=2;
    now2=1;
    display_2();
}

void Help::display_2()
{
    ui->__h_2_1->show();
}

void Help::on___help_3_clicked()
{
    ui->__help_1->hide();
    ui->__help_2->hide();
    ui->__help_3->hide();
    ui->__help_4->hide();
    ui->__help_5->hide();
    ui->__right->show();
    ui->__left->show();
    ui->__back->show();
    choice=3;
    now3=1;
    display_3();
}

void Help::display_3()
{
    ui->__h_3_1->show();
}

void Help::on___help_4_clicked()
{
    ui->__help_1->hide();
    ui->__help_2->hide();
    ui->__help_3->hide();
    ui->__help_4->hide();
    ui->__help_5->hide();
    ui->__right->show();
    ui->__left->show();
    ui->__back->show();
    choice=4;
    now4=1;
    display_4();
}

void Help::display_4()
{
    switch(now4){
    case 1:
        ui->__h_4_2->hide();
        ui->__h_4_1->show();
        break;
    case 2:
        ui->__h_4_1->hide();
        ui->__h_4_3->hide();
        ui->__h_4_2->show();
        break;
    case 3:
        ui->__h_4_2->hide();
        ui->__h_4_4->hide();
        ui->__h_4_3->show();
        break;
    case 4:
        ui->__h_4_3->hide();
        ui->__h_4_5->hide();
        ui->__h_4_4->show();
        break;
    case 5:
        ui->__h_4_4->hide();
        ui->__h_4_6->hide();
        ui->__h_4_5->show();
        break;
    case 6:
        ui->__h_4_5->hide();
        ui->__h_4_7->hide();
        ui->__h_4_6->show();
        break;
    case 7:
        ui->__h_4_6->hide();
        ui->__h_4_8->hide();
        ui->__h_4_7->show();
        break;
    case 8:
        ui->__h_4_7->hide();
        ui->__h_4_9->hide();
        ui->__h_4_8->show();
        break;
    case 9:
        ui->__h_4_8->hide();
        ui->__h_4_10->hide();
        ui->__h_4_9->show();
        break;
    case 10:
        ui->__h_4_9->hide();
        ui->__h_4_11->hide();
        ui->__h_4_10->show();
        break;
    case 11:
        ui->__h_4_10->hide();
        ui->__h_4_12->hide();
        ui->__h_4_11->show();
        break;
    case 12:
        ui->__h_4_11->hide();
        ui->__h_4_12->show();
        break;
    }
}

void Help::on___help_5_clicked()
{
    this->hide();
}

void Help::on___right_clicked()
{
    switch(choice){
    case 1:
        ++now1;
        if(now1==9)
        {
            now1=8;
        }
        display_1();
        break;
    case 2:
        display_2();
        break;
    case 3:
        display_3();
        break;
    case 4:
        ++now4;
        if(now4==13)
        {
            now4=12;
        }
        display_4();
        break;
    }
}

void Help::on___left_clicked()
{
    switch(choice){
    case 1:
        --now1;
        if(now1==0)
        {
            now1=1;
        }
        display_1();
        break;
    case 2:
        display_2();
        break;
    case 3:
        display_3();
        break;
    case 4:
        --now4;
        if(now4==0)
        {
            now4=1;
        }
        display_4();
        break;
    }
}

void Help::on___back_clicked()
{
    ui->__help_1->show();
    ui->__help_2->show();
    ui->__help_3->show();
    ui->__help_4->show();
    ui->__help_5->show();
    ui->__right->hide();
    ui->__left->hide();
    ui->__back->hide();
    ui->__h_1_1->hide();
    ui->__h_1_2->hide();
    ui->__h_1_3->hide();
    ui->__h_1_4->hide();
    ui->__h_1_5->hide();
    ui->__h_1_6->hide();
    ui->__h_1_7->hide();
    ui->__h_1_8->hide();
    ui->__h_2_1->hide();
    ui->__h_3_1->hide();
    ui->__h_4_1->hide();
    ui->__h_4_2->hide();
    ui->__h_4_3->hide();
    ui->__h_4_4->hide();
    ui->__h_4_5->hide();
    ui->__h_4_6->hide();
    ui->__h_4_7->hide();
    ui->__h_4_8->hide();
    ui->__h_4_9->hide();
    ui->__h_4_10->hide();
    ui->__h_4_11->hide();
    ui->__h_4_12->hide();
    choice=0;
    now1=0;
    now2=0;
    now3=0;
    now4=0;
}

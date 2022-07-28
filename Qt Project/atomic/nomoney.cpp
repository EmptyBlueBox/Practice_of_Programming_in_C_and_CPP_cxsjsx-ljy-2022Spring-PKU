#include "nomoney.h"
#include "ui_nomoney.h"

Nomoney::Nomoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nomoney)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint);
}

Nomoney::~Nomoney()
{
    delete ui;
}

void Nomoney::on_pushButton_clicked()
{
    this->hide();
}

#ifndef NOMONEY_H
#define NOMONEY_H

#include <QDialog>

namespace Ui {
class Nomoney;
}

class Nomoney : public QDialog
{
    Q_OBJECT

public:
    explicit Nomoney(QWidget *parent = 0);
    ~Nomoney();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Nomoney *ui;
};

#endif // NOMONEY_H

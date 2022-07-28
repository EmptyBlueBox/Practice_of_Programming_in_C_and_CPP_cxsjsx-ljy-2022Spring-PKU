#ifndef HELP_H
#define HELP_H

#include <QDialog>

namespace Ui {
class Help;
}

class Help : public QDialog
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = 0);
    ~Help();
    void display_1();
    void display_2();
    void display_3();
    void display_4();

private slots:
    void on___help_1_clicked();

    void on___help_2_clicked();

    void on___help_3_clicked();

    void on___help_4_clicked();

    void on___help_5_clicked();

    void on___right_clicked();

    void on___left_clicked();

    void on___back_clicked();

public:
    int choice;
    int now1;
    int now2;
    int now3;
    int now4;

private:
    Ui::Help *ui;
};

#endif // HELP_H

#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

#include <QDialog>

namespace Ui {
class Achievements;
}

class Achievements : public QDialog
{
    Q_OBJECT

public:
    explicit Achievements(QWidget *parent = 0);
    ~Achievements();
    void achievementsupdate();

private slots:
    void on___ach_1_clicked();

private:
    Ui::Achievements *ui;

public:
    int cnt_gamemode1;
    int cnt_gamemode2;
    int cnt_gamemode3;
    int cnt_win;
};

#endif // ACHIEVEMENTS_H

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int nexitcode = 0;
    do
    {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        nexitcode = a.exec();
    }
    while(nexitcode == MainWindow::EXITCODE);

    return nexitcode;
}

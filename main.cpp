#include "chatwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatwindow w;
    w.show();

    return a.exec();
}

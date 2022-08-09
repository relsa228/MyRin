#include "Forms/indexview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IndexView w;
    w.show();
    return a.exec();
}

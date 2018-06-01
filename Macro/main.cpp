#include "macro.h"
#include <QApplication>
#include"QIcon"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Macro w;
    w.show();
    return a.exec();
}

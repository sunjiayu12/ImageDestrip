#include "ImageDestrip.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageDestrip w;
    w.show();
    return a.exec();
}

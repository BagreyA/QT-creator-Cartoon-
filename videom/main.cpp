
#include "loadwindows.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadwindows w;
    w.setWindowTitle("Загрузочный экран");
    w.show();
    return a.exec();
}

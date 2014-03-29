#include "main/MainController.h"
#include "QtGui/qapplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainController *w =  new MainController();
    return a.exec();
}

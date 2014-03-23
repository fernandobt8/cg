#include "first.view/Widget.h"
#include "QtGui/qapplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *w =  new Widget();
    w->show() ;
    
    return a.exec();
}

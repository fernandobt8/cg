#include "main.view/MainView.h"
#include "QtGui/qapplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView *w =  new MainView();
    w->show() ;
    
    return a.exec();
}

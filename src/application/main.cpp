#include "Application.h"
int main(int argc, char *argv[])
{
    Application* a = new Application(argc, argv);
    return a->exec();
}

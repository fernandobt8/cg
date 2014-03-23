#ifndef WIDGET_H
#define WIDGET_H

#include "QtGui/qwidget.h"
#include "QtCore/qvariant.h"
#include "QtGui/qaction.h"
#include "QtGui/qapplication.h"
#include "QtGui/qbuttongroup.h"
#include "QtGui/qheaderview.h"
#include "QtGui/qpushbutton.h"
#include "QtGui/qboxlayout.h"
#include "QtGui/qwidget.h"

class Widget : public QWidget
{
public:
     Widget(QWidget *parent = 0);
    ~Widget();

private:
   QPushButton *upButton;
   QPushButton *leftButton;
   QPushButton *rightButton;
   QPushButton *downButton;
   QPushButton *zoomInButton;
   QPushButton *zoomOutButton;
   QWidget *verticalLayoutWidget;
   QVBoxLayout *verticalLayout;
};

#endif // WIDGET_H

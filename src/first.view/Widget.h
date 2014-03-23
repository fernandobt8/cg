#ifndef WIDGET_H
#define WIDGET_H

#include <stdio.h>
#include "QtGui/qwidget.h"
#include "QtCore/qvariant.h"
#include "QtGui/qaction.h"
#include "QtGui/qapplication.h"
#include "QtGui/qbuttongroup.h"
#include "QtGui/qheaderview.h"
#include "QtGui/qpushbutton.h"
#include "QtGui/qboxlayout.h"
#include "QtGui/qwidget.h"
#include "QtGui/qmessagebox.h"
#include "QtGui/qmainwindow.h"


class Widget : public QMainWindow
{
	Q_OBJECT
public:
	explicit Widget();
    ~Widget();

public slots:
    void onUpClick();
    void onRightClick();
    void onDownClick();
    void onLeftClick();
    void onZoomInClick();
    void onZoomOutClick();

private:
   QPushButton *leftButton;
   QPushButton *upButton;
   QPushButton *rightButton;
   QPushButton *downButton;
   QPushButton *zoomInButton;
   QPushButton *zoomOutButton;
   QWidget *verticalLayoutWidget;
   QVBoxLayout *verticalLayout;
};

#endif // WIDGET_H

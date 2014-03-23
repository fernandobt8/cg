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
#include "QtGui/qmessagebox.h"
#include "QtGui/qmainwindow.h"


class Widget : public QMainWindow
{
	Q_OBJECT
public:
	explicit Widget();
    ~Widget();

public slots:
    void clickeedSlot();
    void clicked();
    void clickeds();
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

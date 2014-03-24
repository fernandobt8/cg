#ifndef WIDGET_H
#define WIDGET_H

#include <stdio.h>
#include "QtGui/qpainter.h"
#include "QtGui/qwidget.h"
#include "QtCore/qvariant.h"
#include "QtGui/qaction.h"
#include "QtGui/qbuttongroup.h"
#include "QtGui/qheaderview.h"
#include "QtGui/qpushbutton.h"
#include "QtGui/qboxlayout.h"
#include "QtGui/qwidget.h"
#include "QtGui/qlistwidget.h"
#include "QtGui/qmessagebox.h"
#include "QtGui/qmainwindow.h"
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include "AdicionarWindow.h"

class Widget: public QMainWindow {
Q_OBJECT
public:
	explicit Widget();
	~Widget();
	virtual void paintEvent(QPaintEvent*);
public slots:
	void onUpClick();
	void onRightClick();
	void onDownClick();
	void onLeftClick();
	void onZoomInClick();
	void onZoomOutClick();
	void onAdicionarButtonClicked();

private:
	QPushButton *upButton;
	QPushButton *leftButton;
	QPushButton *rightButton;
	QPushButton *downButton;
	QPushButton *zoomInButton;
	QPushButton *zoomOutButton;
	QWidget *verticalLayoutWidget;
	QVBoxLayout *verticalLayout;
	QListWidget *listaObjetos;
	QPushButton *adicionarButton;
	QLineEdit *lineEdit;
	QLabel *passoLabel;
	AdicionarWindow adicionarWindow;
};

#endif // WIDGET_H

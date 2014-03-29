#ifndef MAINVIEW_H
#define MAINVIEW_H

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
#include "adicionar/AdicionarTipoObjetoView.h"
#include "modelo.interno/ModeloInterno.h"
#include "MainController.h"
#include "viewport/ViewPort.h"
class MainView: public QWidget ,virtual public  OnAdicionarObjetoTipoEvent{
	Q_OBJECT
public:
	MainView(class MainController* controller);
	~MainView();
	virtual void OnAdicionarObjetoTipoClick(class ObjetoGeometrico *objeto);
	void updateWindow(Window* window);
public slots:
	void on_upButton_clicked();
	void on_rightButton_clicked();
	void on_downButton_clicked();
	void on_leftButton_clicked();
	void on_zoomInButton_clicked();
	void on_zoomOutButton_clicked();
	void on_adicionarButton_clicked();

private:
	QPushButton *upButton;
	QPushButton *leftButton;
	QPushButton *rightButton;
	QPushButton *downButton;
	QPushButton *zoomInButton;
	QPushButton *zoomOutButton;
	QListWidget *listaObjetos;
	QPushButton *adicionarButton;
	QLineEdit *lineEdit;
	QLabel *passoLabel;
	AdicionarTipoObjetoView *adicionarWindow;
	MainController* controller;
	ViewPort* viewPort;

	void renderControleWindowPanel();
	void renderListaObjetosPanel();
};

#endif

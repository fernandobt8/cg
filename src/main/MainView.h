#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <stdio.h>
#include <string>
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
#include "QtGui/qframe.h"
#include "../adicionar/AdicionarTipoObjetoView.h"
#include "../modelo.interno/ModeloInterno.h"
#include "MainController.h"
#include "../viewport/ViewPort.h"
#include "TipoMovimento.h"
#include "../transformacao/TransformacaoView.h"
#include "../api/OnOkTransformcaoEvent.h"
#include "../dto/transformacao/Transformacao.h"
#include "../utils/Utils.h"

using namespace std;

class MainView: public QWidget ,virtual public  OnAdicionarObjetoTipoEvent , virtual public OnOkTransformcaoEvent{
	Q_OBJECT
public:
	MainView(class MainController* controller);
	~MainView();
	virtual void OnAdicionarObjetoTipoClick(class ObjetoGeometrico *objeto);
	virtual void onOkTransformacaoClick(list<Transformacao* >* transformacoes);
	void updateWindow(Window* window);
public slots:
	void on_upButton_clicked();
	void on_rightButton_clicked();
	void on_downButton_clicked();
	void on_leftButton_clicked();
	void on_zoomInButton_clicked();
	void on_zoomOutButton_clicked();
	void on_adicionarButton_clicked();
	void on_transformarButton_clicked();
	void on_windowOkButton_clicked();
	void on_rotacionarButton_clicked();

private:
	MainController* controller;
	QFrame* listObjetosFrame;
	QListWidget *listObjetosPanel;
	AdicionarTipoObjetoView *addObjetoWindow;
	TransformacaoView *transformarWindow;
	QFrame* WindowFrame;
	QLineEdit* windowHeightEdit;
	QLineEdit* windowWidthEdit;
	QLineEdit* windowRotacaoEdit;
	QFrame* viewPortFrame;
	ViewPort* viewPort;

	void renderListaObjetosPanel();
	void renderWindowPanel();
	void renderControleWindowPanel();
	void renderViewPortPanel();
};

#endif

/*
 * AdicionarWindow.h
 *
 *  Created on: 23/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARWINDOW_H_
#define ADICIONARWINDOW_H_

#include <QtCore/QVariant>
#include <QtGui/qaction.h>
#include "QtGui/qpainter.h"
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
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include "QtGui/qlistwidget.h"
#include "../../api/OnAdicionarObjetoTipoEvent.h"
#include "../../dto/Ponto.h"
#include "../../dto/Reta.h"
#include "../../dto/Poligono.h"
#include <list>
#include <string.h>
#include "ponto/AdicionarPonto.h"
#include "reta/AdicionarReta.h"

using namespace std;

class AdicionarTipoObjetoView: public QMainWindow {
Q_OBJECT
public:
	AdicionarTipoObjetoView(OnAdicionarObjetoTipoEvent *event, Coordenada *orientation);
	~AdicionarTipoObjetoView();

public slots:
	void on_tabWindow_currentChanged(int index);
	void on_cancelarButton_clicked();
	void on_removerCoordenada_clicked();
	void on_adicionarCoordenada_clicked();

private:
	QWidget *centralwidget;
	QTabWidget *tabWindow;
	QWidget *poligonoWidget;
	QPushButton *okButton;
	QPushButton *cancelarButton;
	QListWidget *coordenadasList;
	QPushButton *adicionarCoordenada;
	QLineEdit *xTextFieldPoligono;
	QLineEdit *yTextFieldPoligono;
	QLabel *label_7;
	QLabel *label_8;
	QPushButton *removerCoordenada;
	list<Coordenada*> coordenadasPoligono;

	ObjetoGeometrico* getPoligono();
};

#endif /* ADICIONARWINDOW_H_ */

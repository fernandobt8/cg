/*
 * AdicionarWindow.h
 *
 *  Created on: 23/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARWINDOW_H_
#define ADICIONARWINDOW_H_

#include "QtGui/qwidget.h"
#include "QtGui/qwidget.h"
#include "QtGui/qmainwindow.h"
#include "objetos/ponto/AdicionarPonto.h"
#include "objetos/reta/AdicionarReta.h"
#include "objetos/poligono/AdicionarPoligono.h"

using namespace std;

class AdicionarTipoObjetoView: public QMainWindow {
Q_OBJECT
public:
	AdicionarTipoObjetoView(OnAdicionarObjetoTipoEvent *event,
			Coordenada *orientation);
	~AdicionarTipoObjetoView();

private:
	QWidget *centralwidget;
	QTabWidget *tabWindow;
};

#endif /* ADICIONARWINDOW_H_ */

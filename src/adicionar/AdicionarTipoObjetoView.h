/*
 * AdicionarWindow.h
 *
 *  Created on: 23/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARWINDOW_H_
#define ADICIONARWINDOW_H_

#include "QtGui/qwidget.h"
#include "QtGui/qmainwindow.h"
#include <QtGui/qapplication.h>
#include <QtGui/qdesktopwidget.h>
#include "objetos/ponto/AdicionarPonto.h"
#include "objetos/reta/AdicionarReta.h"
#include "objetos/poligono/AdicionarPoligono.h"
#include "objetos/curva/AdicionarCurva.h"
#include "objetos/curva/AdicionarCurva3d.h"

using namespace std;

class AdicionarTipoObjetoView: public QMainWindow {
public:
	AdicionarTipoObjetoView(OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarTipoObjetoView();
	virtual void closeEvent(QCloseEvent* event);

private:
	QTabWidget *tabWindow;

};

#endif /* ADICIONARWINDOW_H_ */

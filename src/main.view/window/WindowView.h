/*
 * WindowView.h
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#ifndef WINDOWVIEW_H_
#define WINDOWVIEW_H_
#include "QtGui/qpalette.h"
#include "QtGui/qwidget.h"
#include "../../dto/Coordenada.h"
#include "../../dto/ObjetoGeometrico.h"
#include "../../dto/Reta.h"
#include "../modelo.interno/ModeloInterno.h"
#include "QtGui/qpainter.h"
#include <list>
using namespace std;

class WindowView : public QWidget{
	Q_OBJECT
public:
	WindowView(QWidget* parent);
	virtual ~WindowView();
	Coordenada* getStart();
	Coordenada* getEnd();
	Coordenada* getCenter();
	virtual void paintEvent(QPaintEvent* event);
	void addObjeto(ObjetoGeometrico* objeto);
private:
	Coordenada* start;
	Coordenada* end;
	Coordenada* center;
	ModeloInterno *modeloInterno;

	bool isBetweenWindow(Coordenada* coordenada);
	Coordenada** drawReta(Reta* reta);

};

#endif /* WINDOWVIEW_H_ */

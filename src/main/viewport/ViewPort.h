/*
 * ViewPort.h
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#ifndef VIEWPORT_H_
#define VIEWPORT_H_
#include "QtGui/qwidget.h"
#include "QtGui/qpalette.h"
#include "../../dto/Coordenada.h"
#include "../../dto/Ponto.h"
#include "../../dto/Poligono.h"
#include "../../dto/Reta.h"
#include "QtGui/qpainter.h"
#include "../window/Window.h"
#include <list>

using namespace std;
class ViewPort : public QWidget{
	Q_OBJECT
public:
	ViewPort(QWidget* parent);
	virtual ~ViewPort();
	void renderWindow(Window* window);
	virtual void paintEvent(QPaintEvent* event);

private:
	Window* window;
	Coordenada* start;
	Coordenada* end;
	Coordenada* calculeCoordenadaVP(Coordenada* pontoObjeto, Coordenada* startWindow, Coordenada* endWindow);
};

#endif /* VIEWPORT_H_ */

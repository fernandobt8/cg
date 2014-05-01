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
#include "../dto/geometrico/Coordenada.h"
#include "../dto/geometrico/Ponto.h"
#include "../dto/geometrico/Poligono.h"
#include "../dto/geometrico/Reta.h"
#include "../dto/geometrico/Curva.h"
#include "QtGui/qpainter.h"
#include <QtGui/qbrush.h>
#include "../modelo.interno/window/Window.h"
#include <list>

using namespace std;

class ViewPort : public QWidget{
	Q_OBJECT
public:
	ViewPort(QWidget* parent);
	virtual ~ViewPort();
	void renderWindow(Window* window);
	virtual void paintEvent(QPaintEvent* event);
	void drawPonto(QPainter* painter, Ponto* ponto);
	void drawPoligono(QPainter* painter, Poligono* poligono);
	void drawReta(QPainter* painter, Reta* reta);
	void drawCurva(QPainter* painter, Curva* curva);
	void drawViewPort(QPainter* painter);

private:
	Window* window;
	Coordenada* start;
	Coordenada* end;
	void calculeCoordenadaVP(Coordenada* pontoObjeto);
};

#endif /* VIEWPORT_H_ */

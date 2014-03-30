/*
 * WindowView.h
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#ifndef WINDOW_H_
#define WINDOW_H_
#include "../../dto/Coordenada.h"
#include "../../dto/ObjetoGeometrico.h"
#include "../../dto/Reta.h"
#include "../../dto/Poligono.h"
#include "../../dto/Ponto.h"
#include "../modelo.interno/ModeloInterno.h"
#include <list>
using namespace std;

class Window{
public:
	Window(ModeloInterno* modelo);
	virtual ~Window();
	Coordenada* getStart();
	Coordenada* getEnd();
	Coordenada* getCenter();
	list<ObjetoGeometrico* >* getWindowObjetos();
	void update();
	void move(double x, double y);

private:
	Coordenada* start;
	Coordenada* end;
	Coordenada* center;
	ModeloInterno* modelo;
	list<ObjetoGeometrico* >* windowObjetos;
	void clearWindowObjetos();

};

#endif /* WINDOWVIEW_H_ */

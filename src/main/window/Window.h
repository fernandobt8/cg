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
	list<ObjetoGeometrico* >* getWindowObjetos();
	void update();
	void move(double x, double y);
	void zoom(double zoom);
	void setTamanhoWindow(double width, double height);
	double getWidth();
	double getHeight();

private:
	Coordenada* start;
	Coordenada* end;
	ModeloInterno* modelo;
	void clearWindowObjetos();

};

#endif /* WINDOWVIEW_H_ */

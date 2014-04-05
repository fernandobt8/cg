/*
 * WindowView.h
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#ifndef WINDOW_H_
#define WINDOW_H_
#include "../../dto/geometrico/Coordenada.h"
#include "../../dto/geometrico/ObjetoGeometrico.h"
#include "../../dto/geometrico/Reta.h"
#include "../../dto/geometrico/Poligono.h"
#include "../../dto/geometrico/Ponto.h"
#include "../../modelo.interno/ModeloInterno.h"
#include <list>
using namespace std;

class Window{
public:
	Window();
	virtual ~Window();
	Coordenada* getStart();
	Coordenada* getEnd();
	list<ObjetoGeometrico* >* getWindowObjetos();
	void updateObjetos(list<ObjetoGeometrico* >* objetos);
	void move(double x, double y);
	void zoom(double zoom);
	void setTamanhoWindow(double width, double height);
	double getWidth();
	double getHeight();

private:
	Coordenada* start;
	Coordenada* end;
	list<ObjetoGeometrico* >* objetos;
	void clearWindowObjetos();

};

#endif /* WINDOWVIEW_H_ */

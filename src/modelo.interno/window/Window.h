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
#include "../../dto/Matriz.h"
#include "../../modelo.interno/ModeloInterno.h"
#include <list>
using namespace std;

class Window{
public:
	Window();
	virtual ~Window();
	list<ObjetoGeometrico* >* getWindowObjetos();
	void setWindowObjetos(list<ObjetoGeometrico*>* objetos);
	void mutiplyCoordenadas(Matriz* matriz);
	void mutiplyCoordenadasToCPP(Matriz* matriz);
	void move(double x, double y);
	void zoom(double zoomX, double zoomY);
	void rotacione(double angulo);
	double getWidth();
	double getHeight();
	Coordenada* getCenter();
	Coordenada* getCenterCPP();
	Coordenada* CPPstart;
	Coordenada* CPPend;
	double angulo;

private:
	Coordenada* start;
	Coordenada* end;
	list<ObjetoGeometrico* >* objetos;

};

#endif /* WINDOWVIEW_H_ */

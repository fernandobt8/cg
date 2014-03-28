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
	void update();

private:
	Coordenada* start;
	Coordenada* end;
	Coordenada* center;
	ModeloInterno* modelo;

	Coordenada** drawReta(Reta* reta);

};

#endif /* WINDOWVIEW_H_ */

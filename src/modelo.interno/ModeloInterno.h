/*
 * ModeloInterno.h
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#ifndef MODELOINTERNO_H_
#define MODELOINTERNO_H_

#include "../dto/geometrico/ObjetoGeometrico.h"
#include "window/Window.h"
#include <list>

using namespace std;

class ModeloInterno {
public:
	ModeloInterno(class Window* window);
	virtual ~ModeloInterno();
	void addObjeto(ObjetoGeometrico *objeto);
	void updateWindow();
	list<ObjetoGeometrico*>* getObjetos();
	Window* window;

private:
	list<ObjetoGeometrico*> *objetos;
};

#endif /* MODELOINTERNO_H_ */

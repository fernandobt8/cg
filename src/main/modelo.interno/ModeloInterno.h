/*
 * ModeloInterno.h
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#ifndef MODELOINTERNO_H_
#define MODELOINTERNO_H_

#include "../../dto/ObjetoGeometrico.h"
#include <list>

using namespace std;

class ModeloInterno {
public:
	ModeloInterno();
	virtual ~ModeloInterno();
	void addObjeto(ObjetoGeometrico *objeto);
	list<ObjetoGeometrico*>* getObjetos();

private:
	list<ObjetoGeometrico*> *objetos;
	list<ObjetoGeometrico*>::iterator it;
};

#endif /* MODELOINTERNO_H_ */

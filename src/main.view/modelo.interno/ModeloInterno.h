/*
 * ModeloInterno.h
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#ifndef MODELOINTERNO_H_
#define MODELOINTERNO_H_

#include "../../dto/ObjetoGeometrico.h"
#include <vector>

using namespace std;

class ModeloInterno {
public:
	ModeloInterno();
	virtual ~ModeloInterno();
	void addObjeto(ObjetoGeometrico *objeto);
	vector<ObjetoGeometrico*> getObjetos();

private:
	vector<ObjetoGeometrico*> objetos;
};

#endif /* MODELOINTERNO_H_ */

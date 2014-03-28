/*
 * Reta.h
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#ifndef RETA_H_
#define RETA_H_

#include "ObjetoGeometrico.h"
#include <list>

using namespace std;

class Reta: public ObjetoGeometrico {
public:
	Reta(char *nome, list<Coordenada*>* coordenadas);
	Reta(char *nome);
	virtual ~Reta();
};

#endif /* RETA_H_ */

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

class Reta: public ObjetoGeometrico {
public:
	Reta(char *nome, Coordenada** coordenadas);
	virtual ~Reta();
};

#endif /* RETA_H_ */

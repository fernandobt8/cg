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
	Reta(int x1, int y1, int x2, int y2);
	virtual ~Reta();
	virtual Coordenada* getCoordenadasParaDesenho();

private:
	Coordenada *coordenadaFinal;
};

#endif /* RETA_H_ */

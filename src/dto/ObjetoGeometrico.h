/*
 * ObjetoGeometrico.h
 *
 *  Created on: 24/03/2014
 *      Author: fernandobt8
 */

#ifndef OBJETOGEOMETRICO_H_
#define OBJETOGEOMETRICO_H_

#include "Coordenada.h"
#include <list>

class ObjetoGeometrico {
public:
	ObjetoGeometrico(int x, int y);
	virtual ~ObjetoGeometrico();
	Coordenada* getCoordenada();
	virtual Coordenada* getCoordenadasParaDesenho() = 0;

private:
	Coordenada *coordenada;
};

#endif /* OBJETOGEOMETRICO_H_ */

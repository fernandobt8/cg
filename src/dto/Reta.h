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
	Reta(char *nome, Coordenada** coordenada);
	virtual ~Reta();
	virtual Coordenada** getCoordenadasParaDesenho();

private:
	Coordenada *coordenadaFinal;
};

#endif /* RETA_H_ */

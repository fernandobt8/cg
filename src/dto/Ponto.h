/*
 * Ponto.h
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#ifndef PONTO_H_
#define PONTO_H_

#include "ObjetoGeometrico.h"

class Ponto: public ObjetoGeometrico {
public:
	Ponto(char* nome, Coordenada** coordenadas);
	virtual ~Ponto();
};

#endif /* PONTO_H_ */

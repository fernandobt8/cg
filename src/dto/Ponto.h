/*
 * Ponto.h
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#ifndef PONTO_H_
#define PONTO_H_

#include "ObjetoGeometrico.h"
#include <string>

class Ponto: public ObjetoGeometrico {
public:
	Ponto(char* nome, list<Coordenada*>* coordenadas);
	Ponto(char* nome);
	virtual ~Ponto();
	Ponto* clone();
};

#endif /* PONTO_H_ */

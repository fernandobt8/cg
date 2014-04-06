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
	Ponto(const char* nome, list<Coordenada*>* coordenadas);
	Ponto(const char* nome);
	virtual ~Ponto();
};

#endif /* PONTO_H_ */

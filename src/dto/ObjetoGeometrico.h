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
	ObjetoGeometrico(char* nome, Coordenada** coordenadas);
	virtual ~ObjetoGeometrico();
	char* getNome();
	Coordenada** getCoordenadas();

protected:
	char* nome;
	Coordenada **coordenadas;
};

#endif /* OBJETOGEOMETRICO_H_ */

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
	ObjetoGeometrico(char* nome, Coordenada** coordenada);
	virtual ~ObjetoGeometrico();
	Coordenada** getCoordenada();
	virtual Coordenada** getCoordenadasParaDesenho() = 0;

protected:
	Coordenada **coordenada;
	char* nome;
};

#endif /* OBJETOGEOMETRICO_H_ */

/*
 * Curva.h
 *
 *  Created on: 27/04/2014
 *      Author: alisson
 */

#ifndef CURVA_H_
#define CURVA_H_

#include <list>
#include "ObjetoGeometrico.h"

class Curva : public ObjetoGeometrico{
public:
	Curva(const char* nome, list<Coordenada*> *coordenadas);
	Curva(const char* nome);
	void addPontoControle(Coordenada *coordenada);
	list<Coordenada*> *pontosControle;
	virtual ~Curva();
};

#endif /* CURVA_H_ */

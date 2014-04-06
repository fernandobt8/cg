/*
 * Poligono.h
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#ifndef POLIGONO_H_
#define POLIGONO_H_

#include <list>
#include "Reta.h"
#include "ObjetoGeometrico.h"

using namespace std;

class Poligono: public ObjetoGeometrico {
public:
	Poligono(const char* nome, list<Coordenada*> *coordenadas);
	virtual ~Poligono();
};

#endif /* POLIGONO_H_ */

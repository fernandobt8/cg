/*
 * Poligono.cpp
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#include "Poligono.h"

Poligono::Poligono(const char* nome, list<Coordenada*> *coordenadas) : ObjetoGeometrico(nome, coordenadas){
}

Poligono::~Poligono() {
	delete color;
}



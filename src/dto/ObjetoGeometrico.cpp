/*
 * ObjetoGeometrico.cpp
 *
 *  Created on: 24/03/2014
 *      Author: fernandobt8
 */

#include "ObjetoGeometrico.h"

ObjetoGeometrico::ObjetoGeometrico(int x, int y) {
	this->coordenada = new Coordenada(x, y);
}

ObjetoGeometrico::~ObjetoGeometrico() {
	// TODO Auto-generated destructor stub
}

Coordenada* ObjetoGeometrico::getCoordenada(){
	return this->coordenada;
}




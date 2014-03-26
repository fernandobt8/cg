/*
 * ObjetoGeometrico.cpp
 *
 *  Created on: 24/03/2014
 *      Author: fernandobt8
 */

#include "ObjetoGeometrico.h"

ObjetoGeometrico::ObjetoGeometrico(char* nome, Coordenada** coordenada) {
	this->coordenada = coordenada;
}

ObjetoGeometrico::~ObjetoGeometrico() {
	// TODO Auto-generated destructor stub
}

Coordenada** ObjetoGeometrico::getCoordenada() {
	return this->coordenada;
}


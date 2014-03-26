/*
 * Coordenada.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Coordenada.h"

Coordenada::Coordenada(int x, int y) {
	this->x = x;
	this->y = y;
}

Coordenada::~Coordenada() {
	// TODO Auto-generated destructor stub
}

int Coordenada::getX(){
	return this->x;
}

int Coordenada::getY(){
	return this->y;
}

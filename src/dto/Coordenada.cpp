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

Coordenada::Coordenada() {

}

Coordenada::~Coordenada() {
	// TODO Auto-generated destructor stub
}

void Coordenada::setX(int x) {
	this->x = x;
}

void Coordenada::setY(int y) {
	this->y = y;
}

int Coordenada::getX() {
	return this->x;
}

int Coordenada::getY() {
	return this->y;
}

char* Coordenada::toString() {
}

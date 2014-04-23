/*
 * Coordenada.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Coordenada.h"

Coordenada::Coordenada(double x, double y) {
	this->x = x;
	this->y = y;
}

Coordenada::Coordenada() {
	x = 0;
	y = 0;
}

Coordenada::~Coordenada() {
}

void Coordenada::multiplyByMatriz(Matriz* matriz){
	Matriz coordenada = Matriz(this);
	coordenada.multiply(matriz);
	x = coordenada.getMatriz()[0][0];
	y = coordenada.getMatriz()[0][1];
}

void Coordenada::addCoordenada(Coordenada* coordenada){
	this->x += coordenada->getX();
	this->y += coordenada->getY();
}

void Coordenada::setX(double x) {
	this->x = x;
}

void Coordenada::setY(double y) {
	this->y = y;
}

double Coordenada::getX() {
	return this->x;
}

double Coordenada::getY() {
	return this->y;
}

Coordenada* Coordenada::clone(){
	return new Coordenada(x, y);
}


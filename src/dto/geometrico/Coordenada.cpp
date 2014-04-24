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

bool Coordenada::isVisitado() {
	return visitado;
}

void Coordenada::setVisitado(bool isVisitado) {
	this->visitado = isVisitado;
}

Coordenada* Coordenada::clone(){
	return new Coordenada(x, y);
}

bool Coordenada::equal(Coordenada* coordenada) {
	if(this->x == coordenada->x && this->y == coordenada->y)
		return true;
	return false;
}

bool Coordenada::isInterseccao() {
	return this->interseccao;
}

void Coordenada::setInterseccao(bool isInterseccao) {
	this->interseccao = isInterseccao;
}
